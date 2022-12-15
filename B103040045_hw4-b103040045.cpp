// Author：楊貽婷 B103040045
//Date： Sept. 21, 2022
// Purpose：用recursion的方式秀出騎士走n*n棋盤的任意一組解
#include <iostream>
#include <iomanip>
using namespace std;
int step; //算步數的變數

//recursion走棋盤的function
//parameter **a表棋盤(以二維陣列表示) 、I表要走的i值、J表要走的j值、n表棋盤是 幾乘幾
//回傳0代表繼續走，回傳1代表走完了
bool sol(int **a,int I,int J,int n) 
{
    int temp_i=I,temp_j=J; //暫時紀錄位置的變數，temp_i紀錄I，temp_j紀錄J
    bool temp=0; //記錄回傳函式的布林值 的變數，預設為零
    a[I-1][J-1]=step; //將該位置所表示的棋盤位置設為該步數
    if(step>=n*n) //跳出條件，步數最大為n*n
    return 1;

    if(temp==1) //temp==1 表示 已走完，並告知這次的recursion可提早結束
        return 1;
    
    //以下條件皆為走的方法不能超過棋盤邊界
    if(((temp_i-2)>=1)&&((temp_j+1)>=1)&&((temp_i-2)<=n)&&((temp_j+1)<=n))
    {   
        if(a[temp_i-2-1][temp_j+1-1]==0) //該位置沒有值才放
        {
            step++; //步數加一
            temp=sol(a,temp_i-2,temp_j+1,n); //用recursion執行下一步 並回傳值給temp
            if(temp==1) //temp==1 代表成功走完 下面程式不需要執行，提早結束這次function
            return 1;
        }
    }
    if(((temp_i-1)>=1)&&((temp_j+2)>=1)&&((temp_i-1)<=n)&&((temp_j+2)<=n))
    {
        if(a[temp_i-1-1][temp_j+2-1]==0) //該位置沒有值才放
        {
            step++; //步數加一
            temp=sol(a,temp_i-1,temp_j+2,n); //用recursion執行下一步 並回傳值給temp
            if(temp==1) //temp==1 代表成功走完 下面程式不需要執行，提早結束這次function
            return 1;
        }
    }
    if(((temp_i+1)>=1)&&((temp_j+2)>=1)&&((temp_i+1)<=n)&&((temp_j+2)<=n))
    {
        if(a[temp_i+1-1][temp_j+2-1]==0)  //該位置沒有值才放
        {
            step++; //步數加一
            temp=sol(a,temp_i+1,temp_j+2,n); //用recursion執行下一步 並回傳值給temp
            if(temp==1) //temp==1 代表成功走完 下面程式不需要執行，提早結束這次function
            return 1;
        }
    }
    if(((temp_i+2)>=1)&&((temp_j+1)>=1)&&((temp_i+2)<=n)&&((temp_j+1)<=n))
    {
        if(a[temp_i+2-1][temp_j+1-1]==0) //該位置沒有值才放
        {
            step++; //步數加一
            temp=sol(a,temp_i+2,temp_j+1,n); //用recursion執行下一步 並回傳值給temp
            if(temp==1) //temp==1 代表成功走完 下面程式不需要執行，提早結束這次function
            return 1;
        }
    }
    if(((temp_i+2)>=1)&&((temp_j-1)>=1)&&((temp_i+2)<=n)&&((temp_j-1)<=n))
    {
        if(a[temp_i+2-1][temp_j-1-1]==0) //該位置沒有值才放
        {
           step++; //步數加一
           temp=sol(a,temp_i+2,temp_j-1,n); //用recursion執行下一步 並回傳值給temp
           if(temp==1) //temp==1 代表成功走完 下面程式不需要執行，提早結束這次function
            return 1;
        }
    }
    if(((temp_i+1)>=1)&&((temp_j-2)>=1)&&((temp_i+1)<=n)&&((temp_j-2)<=n))
    {
        if(a[temp_i+1-1][temp_j-2-1]==0) //該位置沒有值才放
        {
            step++; //步數加一
            temp=sol(a,temp_i+1,temp_j-2,n);  //用recursion執行下一步 並回傳值給temp
            if(temp==1) //temp==1 代表成功走完 下面程式不需要執行，提早結束這次function
            return 1;
        }
    }
    if(((temp_i-1)>=1)&&((temp_j-2)>=1)&&((temp_i-1)<=n)&&((temp_j-2)<=n))
    { 
        if(a[temp_i-1-1][temp_j-2-1]==0) //該位置沒有值才放
        {
            step++; //步數加一
            temp=sol(a,temp_i-1,temp_j-2,n); //用recursion執行下一步 並回傳值給temp
            if(temp==1) //temp==1 代表成功走完 下面程式不需要執行，提早結束這次function
            return 1;
        }
    }
    if(((temp_i-2)>=1)&&((temp_j-1)>=1)&&((temp_i-2)<=n)&&((temp_j-1)<=n))
    {
        if(a[temp_i-2-1][temp_j-1-1]==0) //該位置沒有值才放
        {
            step++; //步數加一
            temp=sol(a,temp_i-2,temp_j-1,n); //用recursion執行下一步 並回傳值給temp
            if(temp==1) //temp==1 代表成功走完 下面程式不需要執行，提早結束這次function
            return 1; 
        }
    }
    //走到這代表沒路可走
    a[temp_i-1][temp_j-1]=0; //該棋盤位置改為零 並準備退回去
    step--; //步數減一
    return 0; //死路回傳零，要繼續走
}
int main()
{
    for(int i=1;i<=6;i++) //表示從n=1到n=6的棋盤
    {
        if(i==1) //1 is boundary condition
        {
            cout<<"n=1 :\n"<<" 1"<<endl<<endl;
            continue;
        }
        //建立動態二維陣列 (i*i)
        int **arr2D=new int* [i];
        for(int j=0;j<i;j++)
        {
            arr2D[j]=new int [i](); //建立的同時順便將二維陣列歸零
        }
        step=1; //將步數初始化為 1
        sol(arr2D,1,1,i); //跑recursion function
        cout<<"n = "<<i<<" :"<<endl; //output
        //如果有走完第一個位置必有數字，反之則為零
       if(arr2D[0][0]) //成功走完的情況
        {
          for(int k=0;k<i;k++) //印出棋盤
         {
            for(int m=0;m<i;m++)
            cout<<setw(2)<<arr2D[k][m]<<" ";
            //setw()在函式庫<iomanip>可找到，在這裡用途為空兩格，之後要輸出的數字要控制在這兩格內(靠右)
            cout<<endl;
         }
         cout<<endl;  
        }
        else //沒走完的情況
        cout<<"no solution."<<endl<<endl;
         
        for(int l=0;l<i;l++) //用完動態陣列要刪除
        {
            delete [] arr2D[l];
        }
        delete [] arr2D;

    }
    return 0;
}