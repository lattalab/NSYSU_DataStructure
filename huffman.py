class HuffmanNode:
    def __init__(self, value, frequency):
        self.value = value
        self.frequency = frequency
        self.left = None
        self.right = None
        self.encode = None

def build_huffman_tree(data):
    frequency_table = {}
    # 用dictionaty統計字符的頻率
    for char in data:
        if char in frequency_table:
            frequency_table[char] += 1
        else:
            frequency_table[char] = 1

    # 建立每項元素的leaf node
    nodes = []
    for char, frequency in frequency_table.items():
        nodes.append(HuffmanNode(char, frequency))

    # 構建huffman tree
    while len(nodes) > 1:
        # 排序節點列表
        # 先以frequency排序，若frequency相同 則用value排序
        nodes = sorted(nodes, key=lambda x: (x.frequency, x.value) )
        # 取出頻率最低的兩個節點
        left_node = nodes.pop(0)
        right_node = nodes.pop(0)

        # 建立新節點，頻率為兩個子節點頻率之和
        # 左邊為字典序較小的，右邊為字典序較大的
        # 將parent node的value設為字典序較小的那一個
        if left_node.value <= right_node.value:
            parent_node = HuffmanNode(left_node.value, left_node.frequency + right_node.frequency)
            parent_node.left = left_node
            parent_node.right = right_node
        else:
            parent_node = HuffmanNode(right_node.value, left_node.frequency + right_node.frequency)
            parent_node.left = right_node
            parent_node.right = left_node

        # 將新節點添加回列表中
        nodes.append(parent_node)

    nodes[0].encode = "" # change root.encode to ""
    # return huffman tree root
    return nodes[0]

def huffman_tree_encoding(root): # 為huffman tree 編碼
    if root == None: # if node is None, return
        return
    
    if root.left != None: # 往左邊一步 就加0
        root.left.encode = root.encode + "0"

    if root.right != None: # 往右邊一步 就加1
        root.right.encode = root.encode + "1"
    
    # 最後將所有樹走過一遍
    huffman_tree_encoding(root.left)
    huffman_tree_encoding(root.right)

Code_table = {}
def huffman_code_table(root):
    # if node is None ,return
    if not root:
        return
    
    # if leaf node , no child
    if (not(root.left) and not(root.right)):
        Code_table[root.value] = root.encode

    huffman_code_table(root.left)
    huffman_code_table(root.right)

def huffman_compression(data):
    with open("compressed.txt", "wb") as file: # write huffman code table
        for char,coding in Code_table.items():
            file.write(len(coding).to_bytes()) # 要看的長度
            file.write(((len(coding)+7) //8).to_bytes()) # 看幾bytes
            file.write(ord(char).to_bytes(1, 'big')) # 寫字母
            file.write(int(coding, 2).to_bytes((len(coding)+7) //8 ,'big')) # 寫huffman code

        file.write(int(28).to_bytes()) # assign Ascii 28 to represent end character
        file.write(b'\n')

        # 之後要寫encoded的資料
        new_data = ""
        for ch in data: # 將資料轉換成huffman code
            new_data += Code_table[ch]

        file.write(len(new_data).to_bytes(2,'big')) # 寫入資料bits長度

        # 將編碼後的資料轉換為位元組
        # 抓出8-bit出來，用1-byte存進檔案中
        for bit in range(0, len(new_data), 8):
            one_byte = new_data[bit:bit+8]
            if len(one_byte) == 8:
                file.write(int(one_byte,2).to_bytes())

        while len(one_byte) <8 and len(one_byte)>0:
            one_byte += '0'
        file.write(int(one_byte,2).to_bytes())

import os
def huffman_decompression():
    table = {}
    file_size = os.path.getsize('D:/python_tra/compression/compressed.txt')
    with open ("compressed.txt", "rb") as file: # 還原huffman Table
        for i in range(file_size):
            element =int.from_bytes(file.read(1))
            if element== 28: # 代表讀完了
                break
            else:
                byte_num = int.from_bytes(file.read(1))
                ch = chr(int.from_bytes(file.read(1)))
                
                byte_set = bin(int.from_bytes(file.read(1)))

                zero_set = "0" * element
                coding = zero_set[:element-len(byte_set[2:])] + byte_set[2:]
                table[coding] = ch

        file.read(1) # 讀掉換行
        bit_length = int.from_bytes(file.read(2)) # bits總長度
       
        data = file.read() # 讀取編碼的資料
    
        encoded_data = ""
        decoded_data = ""
        bit = ""
        for byte in data: # 每次得到 1 byte
            bit += format(byte, '#010b')[2:]

        
        for i in range(len(bit)):
            encoded_data += bit[i]
            if encoded_data in table and i<bit_length:
                decoded_data += table[encoded_data]
                encoded_data = ""
       
        with open ("decompressed.txt","w") as files:
            files.write(decoded_data)


with open ("input.txt","r", encoding='ascii') as file:
    data = file.read()

r= build_huffman_tree(data)
huffman_tree_encoding(r)
huffman_code_table(r)
print(Code_table)
huffman_compression(data)
huffman_decompression()