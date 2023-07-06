# include <iostream>
# include <queue>
# include <fstream>
# include <map>
# include <cstring>
# include <string>
# include <cstdio>
# include <errno.h>

using namespace std;
typedef long long int LONG;

struct HuffmanNode{
    unsigned char value;
    LONG frequency;
    HuffmanNode* left;
    HuffmanNode* right;
    bool root;

    HuffmanNode()
    {
        left = NULL;
        right = NULL;
        root = 0;
    }
    HuffmanNode(unsigned char val, LONG freq)
    {
        value = val;
        frequency = freq;
        left = NULL;
        right = NULL;
        root = 0;
    }

    void set_root()
    {
        root = 1;
    }
    // operator overloading for output
    friend ostream& operator<< (ostream& out, const HuffmanNode* n) 
    {
        out << n->value << " " << n->frequency <<" " 
         << (n->left ? n->left->value : ' ') << " " << (n->right ? n->right->value : ' ') << endl;
        return out;
    }
};

// 比較器用於priority_queue
    struct Compare {
    bool operator()(const HuffmanNode* left, const HuffmanNode* right) const {
        if (left->frequency == right->frequency) // same frequency，照字典序
            return left->value >= right->value;

        return left->frequency > right->frequency;
    }
    };

// 用於比較字典序
unsigned char lex_order(const HuffmanNode* a, const HuffmanNode* b)
    {
        if (a->value >= b->value)
        return b->value;
        else
        return a->value;
    }

HuffmanNode* Huffman_tree(const char* filename) // get frequency table and huffman nodes
{
    FILE* fp = fopen(filename, "rb");
    if (!fp)
    {
        perror("Error opening file\n");
        exit(EXIT_FAILURE);
    }
    unsigned char ch;
    map<unsigned char ,LONG> arr; // used to store character & frequency
    while (fread(&ch ,sizeof(unsigned char) ,1 ,fp) == 1) //讀完整個檔案
    {
        if (arr.find(ch) != arr.end()) // not first time occured
            arr[ch] += 1;
        else
            arr[ch] = 1;
    }
    fclose(fp);

    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;
    map<unsigned char, LONG>::iterator it;
    for(it = arr.begin(); it != arr.end(); it++)
    {
        pq.push(new HuffmanNode(it->first, it->second)); // push all Nodes
    }
    
    while (pq.size() != 1) // combine nodes
    {
        HuffmanNode* left = pq.top();
        pq.pop();
        HuffmanNode* right = pq.top();
        pq.pop();
        HuffmanNode* parent = new HuffmanNode(lex_order(left,right), left->frequency+right->frequency);
        parent->set_root(); 
        if (left->value < right ->value)
        {
            parent->left = left;
            parent->right = right;
        }
        else
        {
            parent->left = right;
            parent->right = left;
        }
        pq.push(parent);
    }
    return pq.top();
}

// 遍歷Huffman樹並生成huffman code
void generateCodes(HuffmanNode* root, const string& code, map<unsigned char, string>& codes) {
    if (root == nullptr) {
        return;
    }

    if (root->root != 1) {
        codes[root->value] = code;
    }

    generateCodes(root->left, code + "0", codes);
    generateCodes(root->right, code + "1", codes);
}

LONG total_table_size(map<unsigned char, string> &codes)
{
    map<unsigned char, string>::iterator it;
    LONG total_byte = 0;
    for(it = codes.begin(); it!=codes.end();it++)
    {
        total_byte += sizeof(unsigned int); // bits length
        total_byte += 1; // character
        total_byte += (it->second.length() + 7) / 8; // encoding bytes
    }
    return total_byte; // return total_byte require for the encoding table
}

string encoded_data(const char* filename, map<unsigned char, string> &codes)
{
    FILE* fp = fopen(filename,"rb");
    if (!fp)
    {
        perror("Error opening file\n");
        exit(EXIT_FAILURE);
    }
    unsigned char ch;
    string str = "";
    while(fread(&ch,sizeof(unsigned char),1,fp) == 1)
    {
        str += codes[ch];
    }
    fclose(fp);
    return str;
}

LONG filesize(const char* filename)
{
    std::ifstream file(filename, std::ios::binary | std::ios::ate);
    if (!file) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return -1;
    }
    std::streampos fileSize = file.tellg(); //用tellg() 得到filesize
    file.close();
    return static_cast<LONG>(fileSize);
}

void compress(const char* filename, const char* outfile)
{
    cout << "Comperssion start!\n";
    HuffmanNode* a = Huffman_tree(filename);
    map<unsigned char, string> codes;
    if (!a->left && !a->right) // 當整個tree只有一個時
        codes[a->value] = "0";
    else
        generateCodes(a, "", codes);

    // 印出編碼表
    for(auto it : codes)
        cout << int(it.first) <<" " <<it.second <<endl;

    LONG total = total_table_size(codes);

    FILE* fp = fopen(outfile, "wb");
    fwrite(&total, sizeof(total),1,fp); //編碼表共需要幾 bytes
    map<unsigned char, string>::iterator it;
    for(it =codes.begin();it != codes.end(); it++)
    {
        unsigned int len = it->second.length();
        unsigned char ch = it->first;
        fwrite(&len, sizeof(unsigned int),1,fp); // write bits length
        fwrite(&ch, sizeof(unsigned char),1,fp); // write character
        unsigned char temp =0;
        int count = 0;
        for(auto i=0; i<it->second.length();i++) //每8個bit就寫進去
        {
            temp = (temp << 1) | (it->second[i] - '0');
           
            count +=1;
            if(count == 8)
            {
                fwrite(&temp, sizeof(unsigned char),1,fp);
                count=0;
                temp =0;
            }
        }
        if (count <8 && count > 0) // 如果有剩下的，補滿8bits再寫進去
        {
            temp = (temp << (8-count));
            fwrite(&temp, sizeof(unsigned char),1,fp);
        }
    }

    unsigned char ch = '\n'; //寫換行
    fwrite(&ch, sizeof(unsigned char),1,fp);

    LONG size = filesize(filename); //寫入filesize
    fwrite(&size, sizeof(size),1,fp);

    string str = encoded_data(filename, codes); // 寫入壓縮資料
    unsigned char tep =0;
    int cnt =0;
    for(int i=0;i<str.length();i++)
    {
        tep = (tep << 1) | (str[i] - '0');
        cnt++;

        if(cnt ==8)
        {
            fwrite(&tep, sizeof(unsigned char),1,fp);
            cnt=0;
            tep =0;
        }
    }

    while(cnt <8 && cnt >0)
    {
        tep <<= 1;
        cnt ++;
    }
    fwrite(&tep, sizeof(unsigned char),1,fp);
    fclose(fp);
    cout << "Compression end!\n";
}

// 將每個byte轉成binary string
string byteToBinaryString(unsigned char byte) {
    string binaryString = "";
    for (int i = 7; i >= 0; --i) {
        binaryString += ((byte >> i) & 1) ? '1' : '0';
    }
    return binaryString;
}

// 讀出壓縮檔案中的編碼表並還原huffman tree
HuffmanNode* rebuildHuffmanTree(const map<unsigned char, string>& codes) {
    HuffmanNode* root = new HuffmanNode(); // 建立根節點
    for (const auto& pair : codes) 
    {
        const unsigned char character = pair.first;
        const string& code = pair.second;
        HuffmanNode* currentNode = root;
        for (char bit : code) 
        {
            if (bit == '0') 
            {
                if (!currentNode->left) 
                {
                    currentNode->left = new HuffmanNode();
                }
                currentNode = currentNode->left;
            } 
            else 
            {
                if (!currentNode->right) 
                {
                    currentNode->right = new HuffmanNode();
                }
                currentNode = currentNode->right;
            }
        }
        currentNode->value = character;
    }
    return root;
}

void decompress(const char* filename, const char* outfile)
{
    cout << "Decompression start!\n";
    FILE* fp = fopen(filename, "rb");
    if (!fp)
    {
        perror("Error opening file\n");
        exit(EXIT_FAILURE);
    }

    // 先把huffman table 讀出來
    LONG tableSize;
    unsigned int bits_len;
    unsigned char ch;
    map<unsigned char, string> code;
    fread(&tableSize,sizeof(LONG),1,fp); //全部要讀的bytes數量
    do{
        fread(&bits_len, sizeof(bits_len), 1, fp); //之後讀出來要看幾個bits
        fread(&ch, sizeof(ch), 1, fp); //讀完character
        code[ch] = "";
        unsigned int bytes = (bits_len + 7) / 8; // 預計要讀幾個bytes
        unsigned char* buffer = new unsigned char[bytes];
        fread(buffer, sizeof(unsigned char), bytes, fp);
        string bits = "";
        for(auto i=0;i<bytes;i++)
        { 
            bits += byteToBinaryString(buffer[i]); //將讀出來的byte轉成String
        }
        delete buffer;

        for(auto i=0; i<bits_len ;i++)
        {
            code[ch] += bits[i]; //得到編碼表
        }
        tableSize = tableSize - 4 -1 -bytes;
    }
    while(tableSize);
    cout << "Huffman table ready!\n";

    fread(&ch, sizeof(ch), 1, fp); //讀掉換行
    LONG size;
    fread(&size, sizeof(size), 1, fp); //讀出原始檔案大小 (bytes)

    // 重建 Huffman 樹
    HuffmanNode* root = rebuildHuffmanTree(code);
    HuffmanNode* currentNode = root;
    cout << "huffman tree ready!\n";

    FILE* fp2 = fopen(outfile, "wb");
    while(fread(&ch ,sizeof(ch), 1, fp) == 1)
    {
        string data = byteToBinaryString(ch);
        for (char bit : data) 
        {
            if(size <= 0) // 還原完畢
                break;

            if (bit == '0') //往左走
            {
                currentNode = currentNode->left;
            } 
            else //往右走
            {
                currentNode = currentNode->right;
            }
            if (!currentNode->left && !currentNode->right) //leaf node
            {
                fwrite(&currentNode->value, sizeof(unsigned char), 1, fp2);
                currentNode = root;
                size -= 1;
            }
        }
    }
    cout << "End to decode data!\n";

    fclose(fp);
    fclose(fp2);
    cout << "Decompression end!\n";
}
