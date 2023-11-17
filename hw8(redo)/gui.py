import tkinter as tk
from tkinter import filedialog # upload file
from tkinter.filedialog import askopenfile
from PIL import Image, ImageTk
import subprocess

window = tk.Tk() # base object
window.title('Huffman compression interface')
window.geometry('800x1200')

photo = None  # 全局變數用於存儲圖片

def uploadfile():
    file_path = tk.filedialog.askopenfilename()
    if file_path:
        if file_path.endswith('txt'):
            # 顯示文字內容
            with open(file_path, 'r', encoding='utf-8') as file:
                canvas.delete("all")  # 清空 canvas 上的內容
                text_content = file.read()
                text_area.delete("1.0", tk.END)  # 清空 Text 元件的內容
                text_area.insert(tk.END, text_content)  # 插入文本內容到 Text 元件
        elif file_path.endswith(('jpg', 'jfif', 'png')):
            # 顯示圖片
            global photo
            image = Image.open(file_path)
            photo = ImageTk.PhotoImage(image)
            print("Show image!\n")
            canvas.create_image(100, 150,anchor='center' ,image=photo) 


def run():
    command = command_entry.get()  # 讀取文字輸入元件的內容
    subprocess.run(command.split())  # 使用 subprocess.run() 執行命令


upload_button = tk.Button(window, text='選擇要查看的檔案', command=uploadfile, font=('Arial',14))
upload_button.pack()

# 創建一個文字輸入元件
command_entry = tk.Entry(window, width=50, font=("Arial", 12))
command_entry.pack()
command_button = tk.Button(window,text='Execute Command above line',command=run,font=("Arial", 14))
command_button.pack()

# 建立字體物件，設定字體為 Arial，字形為粗體，大小為 16
Label_image = tk.Label(window,text='Show image:', font= ("Arial", 16, "bold"))
Label_image.pack()
# 創建一個標籤用於顯示圖片
canvas = tk.Canvas(window, width = 350, height = 350)  
canvas.pack()

# 建立字體物件，設定字體為 Arial，字形為粗體，大小為 16
custom_font = ("Arial", 16, "bold")
Label = tk.Label(window,text='Content in file:', font= custom_font)
Label.pack()
# 創建一個 Text 元件用於顯示文字內容
text_area = tk.Text(window)
text_area.pack()

window.mainloop()