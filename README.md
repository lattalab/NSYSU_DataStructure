# NSYSU_data_structure
2022 - fall semester

course website:  
https://par.cse.nsysu.edu.tw/~cbyang/course/ds/ds_index.htm  
  
About Huffman Compression with my acknowledge:  
https://hackmd.io/BwP5jaHsSrmeACfgukno8w

## HW description
### HW1: 基礎演算法 (Basic Algorithms)
這個作業包含兩個部分：
1.  **魔方陣 (Magic Square)**: 實作一個演算法來產生 N 階魔方陣，其中 N 為奇數。
2.  **大數階層 (Large Number Factorial)**: 由於使用標準 `int` 型別計算階層會導致溢位 (overflow)，此程式使用一個整數陣列來模擬計算過程，從而支援大數的階層運算。

### HW2: 集合運算 (Set Operations)
使用 C++ 的 `class` 建立一個集合 (Set) 資料結構。程式中重載 (overloading) 了 `+`, `*`, `-`, `>=` 等運算子，用以實作集合的五種基本運算：聯集 (Union)、交集 (Intersection)、差集 (Difference)、包含 (Contains) 以及判斷元素是否屬於 (Belong to) 集合。

### HW3: 騎士走訪 (Knight's Tour) - Stack 實作
解決騎士走訪 (Knight's Tour) 問題，目標是找出騎士走遍 n*n 棋盤的其中一組解。此版本的實作**不使用**遞迴 (recursion)，而是明確地使用 `stack`（以 `linked list` 實作）來進行迭代 (iterative) 的深度優先搜尋 (DFS)，以找到路徑。

### HW4: 騎士走訪 (Knight's Tour) - Recursion 實作
同樣是解決騎士走訪問題，但這個版本採用了更直觀的**遞迴 (recursion)** 方式。這是一種經典的回溯 (backtracking) 演算法實作。

### HW5: 多項式運算 (Polynomial Arithmetic)
使用鏈結串列 (Linked List) 來表示多項式。每個節點 (node) 儲存一個項的係數 (coefficient) 和指數 (exponent)。程式實作了多項式的加法和乘法，並重載了 `+` 和 `*` 運算子。

### HW6: Binary Search Tree 應用
應用二元搜尋樹 (Binary Search Tree, BST) 來解決一個有趣的問題：找出輸入的一連串數字中，所有**出現奇數次**的數字。其原理是：當一個數字被 `insert` 時，如果它已存在於樹中，則將其 `delete`；如果不存在，則將其加入。最終留在樹中的所有節點，即為出現奇數次的數字。

### HW7: 排序演算法比較 (Sorting Algorithm Comparison)
實作並比較多種排序演算法的執行效率。
* **實作的演算法**: `Insertion Sort`, `Merge Sort`, `Quick Sort`。
* **比較的對象**: 同時也納入 C 語言的 `qsort()` 和 C++ `std::sort()` 函式庫進行效能標竿測試 (benchmark)。
* **測試方式**: 程式會讀取不同大小的測試資料集 (如 `in1.txt` 至 `in9.txt`)，並使用 `clock()` 來測量每種演算法的執行時間。

### HW8 (Redo): 霍夫曼編碼 (Huffman Coding)
實作霍夫曼編碼 (Huffman Coding) 演算法，用於檔案的壓縮 (compression) 與解壓縮 (decompression)。
* **C++ 版本**: `Huffman.h` 和 `Huffman.cpp` 包含核心邏輯，能夠建立霍夫曼樹、產生編碼表、壓縮檔案 (將字元轉為位元流) 以及讀取編碼表和位元流來還原檔案。
* **Python 版本**: `huffman.py` 提供了 Python 的實作版本，功能與 C++ 版本相似。
* **GUI**: `gui.py` 使用 `Tkinter` 建立了一個簡單的圖形化使用者介面 (GUI)，讓使用者可以方便地選擇檔案，並執行壓縮或解壓縮的命令。
