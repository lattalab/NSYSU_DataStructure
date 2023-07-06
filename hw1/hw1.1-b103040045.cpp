//Author: B103040045
//Date: sept. 6, 2022
//Purpose: N階魔方陣的實現(N為奇數)
#include <iostream>
#include <iomanip>
using namespace std;
//this function is for create the magic square
//參數n 代表 第幾階魔方陣
void magic(int n) 
{
    //1階魔方陣只有1而已 可提早結束
    if(n==1) 
    {
        cout<<" 1"<<endl<<endl;
        return; 
    }
    //建立動態二維陣列:
    //一個指標的指標 指向 整數指標的一維陣列
    //這些一維陣列再 指到 整數的一維陣列
    int **array2D = new int* [n];
    for(int i=0;i<n;i++)
    array2D[i]=new int [n] (); 

    int i=0,j=n/2,k=1; //i represent row , j represent col , k 代表 要放的數字
    int temp_i,temp_j; //存放目前位置的變數
    array2D[i][j]=k; //第一列中間為 1
    
    k++; //k變成2 
    while(k <= n*n) //k最大為n*n 超過不再繼續
    {
    //紀錄k-1的位置
    temp_i=i;
    temp_j=j;
    
    i--; //變為上一列
    j--; //變為前一行 
    if(i<0) //超過邊界(沒有那列)
    i=n-1; //改成最後一列
    if(j<0)   //超過邊界(沒有那行)
    j=n-1; //改成最後一行
    if(array2D[i][j]!=0) //位置已放過，要改放在k-1的下方
    {
        i=temp_i+1; 
        j=temp_j;
    }
    array2D[i][j]=k; //放入數字
    k++; //遞增條件
    }
    //印出魔方陣
    for(int row=0;row<n;row++) //代表第幾列
    {
        for(int col=0;col<n;col++) //代表第幾行
        //setw(2)為了排版好看
        //setw() 定義在iomanip 函式庫裡
        {cout<<setw(2)<<array2D[row][col]<<" ";}
    cout<<endl; //一列印完 要換行
    }

    //動態陣列要清除
    //先把整數陣列清掉，再清整個指標陣列    
    for(int i=0;i<n;i++)
    {
        delete [] array2D[i];
    }
    delete array2D;
}
int main()
{
   //從第一階魔方陣開始，每次遞增2，直到第九階魔方陣為止
   //迴圈控制變數layer 代表 第幾階
    for(int layer=1;layer<=9;layer+=2)
    {
        switch(layer) //控制輸出格式
        {
            case 1:
            cout<<"一階魔方陣如下:\n";
            break;
            case 3:
            cout<<"三階魔方陣如下:\n";
            break;
            case 5:
            cout<<"五階魔方陣如下:\n";
            break;
            case 7:
            cout<<"七階魔方陣如下:\n";
            break;
            case 9:
            cout<<"九階魔方陣如下:\n";
            break;
        }
        magic(layer); //call function
        cout<<endl; 
    }
    return 0;
}
