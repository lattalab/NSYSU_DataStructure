//Author: 楊貽婷 B103040045
//Date: sept. 7, 2022
//Purpose: 單純用變數(ex.int)找階層有可能發生overflow，因此用一維陣列模擬算階層
#include <iostream>
#include <vector>
using namespace std;
int ptr; //知道哪裡開始超過原數字範圍的變數 (ex.01145 那ptr會指到0)
//宣告函式factorial，目的為用陣列算出各階層 並從一階算到num階
//parameter: num 為算到第幾階層的最終數字
void factorial(int num); 
int main()
{
    int N; //負責紀錄 使用者輸入甚麼 的變數
    //因可能有多組，故用vector存取
    //vector定義在 函式庫<vector>
    vector<int> data; 
    //輸入資料(輸入零會終止)
   do
    {
    cin>>N;
    if(N!=0) //零不放入
    data.push_back(N);
    } while (N!=0); //迴圈持續的條件是 沒有遇到零

    cout<<endl; //換行，並開始輸出

    //尋找從第一次輸入的資料開始，直到遇到最後輸入的資料
    //i代表index
    for(int i=0;i<data.size();i++) 
    {
        ptr=1; //一開始一定是個位數 ，因此知道數字範圍的極限指到十
        factorial(data[i]); //call function
        cout<<endl; //算出之後要換行，並執行出下一次結果
    }
    return 0;
}
void factorial(int num)
{
    int digit[70]={0}; //設定足夠長的陣列 並初始化為零
    //1!為1，直接展現出來
    digit[0]=1; 
    cout<<"1!="<<digit[0]<<endl;

    //從2!開始分別印出 直到num!為止
    for(int i=2;i<=num;i++)
    {
        cout<<i<<"!="; //輸出i!= (若i=3,則印出3!=)

        //因為已知上階 此數字矩陣每個位數都乘下一位數 (ex.已知1!，有效數字都乘2變2!)
        for(int index=0;index<70,ptr>index;index++) //條件為不可超出 (矩陣邊界以及有效數字邊界)
        {
            digit[index]*=i;
        }
        //進位
        for(int Index=0;Index<70,ptr>Index;Index++)
        {
            if(digit[Index]>=10) //某位數要控制在0~9之間，因此大於10才要特別做處理
            {
                //將該位數(digit[Index])留下個位數，其餘進到下一位數
                digit[Index+1]+=digit[Index]/10; 
                digit[Index]=digit[Index]%10;
                if(digit[ptr]!=0) //邊界有數字了，才要改變
                ptr++;
            }
        }
        //數字要從大的位數那邊開始印 (ex.14445 digit[0]是5、digit[ptr-1]是1)
        for(int j=ptr-1;j>=0;j--) 
        {cout<<digit[j];}

        cout<<endl; 
    }
}