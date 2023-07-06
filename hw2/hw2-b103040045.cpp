//Author: B103040045
//Date：Sept. 13, 2022
//Purpose：利用C++的class建立一個集合，並可執行聯集、交集、差集、包含、屬於等五種運算
#include <iostream>
using namespace std;
//製作集合的class
class set{
    private:
    char array[256]; //可儲存資料的char array
    public:
    set operator + (set &obj) //聯集運算 ，參數是另一個set 即A+B的B (A是自己，array的部分)
    {
        bool temp[256]={0}; //用來辨識是否已出現該ASCII碼的 布林陣列
        for(int i=0;i<256;i++) //紀錄A集合中的字元是否已出現的迴圈
        {
            if(array[i]!='\0')  //沒遇到結尾就一直做
            {
            int index =static_cast<int>(array[i]); //將字元轉成數字(範圍0~255)，並存到index裡
            temp[index]=1; //將該字元對應的布林陣列 紀錄為1 表已出現
            }
            //EX. a(char) 變成 97(int) ，temp[97]=1即代表 97所對應的字元已出現
            else //做到結尾、即遇到'\0'為止
            break;
        }
        for(int i=0;i<256;i++) //紀錄B集合中的字元是否已出現的迴圈
        {
            if(obj.array[i]!='\0') //沒遇到結尾就一直做
            {
            int index =static_cast<int>(obj.array[i]); //將字元轉成數字(範圍0~255)，並存到index裡
            temp[index]=1; //將該字元對應的布林陣列 紀錄為1 表已出現
            }
            else //做到結尾、即遇到'\0'為止
            break;
        }
        //上面就找完所有A跟B皆出現的元素

        set back; //建立一個要回傳的集合 back
        int count=0; //當作array的index用
        for(int i=0;i<256;i++) //跑temp的這個布林陣列看他的值
        {
            if(temp[i]) //temp[i]=1進入條件
            back.array[count++]=static_cast<char>(i); 
            //將i轉成字元並存進back的字元陣列裡
            //另外[count++]的執行 一開始是back.array[count] = static_cast<char>(i)，之後count+=1
            //EX. temp[97]=1即代表 97所對應的字元已出現，97(int) 變成a(char) ，再存入字元陣列
        }
        back.array[count]='\0';  //結尾要放'\0'
        return back; //回傳聯集的set
    }
    set operator * (set &obj) //交集運算 ，參數是另一個set 即A*B的B (A是自己，array的部分)
    {
        bool t1[256]={0},t2[256]={0}; //用來辨識是否已出現該ASCII碼的 布林陣列，一個記A 一個記B
        for(int i=0;i<256;i++) //紀錄A集合中的字元是否已出現的迴圈
        {
            if(array[i]!='\0') //沒遇到結尾就一直做
            {
            int index =static_cast<int>(array[i]); //將字元轉成數字(範圍0~255)，並存到index裡
            t1[index]=1; //將該字元對應的布林陣列 紀錄為1 表已出現
            }
            else  //做到結尾、即遇到'\0'為止
            break;
        }
        for(int i=0;i<256;i++) //紀錄B集合中的字元是否已出現的迴圈
        {
            if(obj.array[i]!='\0') //沒遇到結尾就一直做
            {
            int index =static_cast<int>(obj.array[i]);  //將字元轉成數字(範圍0~255)，並存到index裡
            t2[index]=1; //將該字元對應的布林陣列 紀錄為1 表已出現
            }
            else //做到結尾、即遇到'\0'為止
            break;
        }
        set back; //建立一個要回傳的集合 back
        int count=0;  //當作array的index用
        for(int j=0;j<256;j++) //跑t1&t2的這個布林陣列看他的值
        {
            if(t1[j]&&t2[j]) //A跟B集合的字元皆出現才要丟進back的array
            {
            back.array[count++]=static_cast<char>(j); //將j轉成字元並存進back的字元陣列裡
            }
        }
        back.array[count]='\0'; //結尾要放'\0'
        return back; //回傳交集的set
    }
    set operator - (set &obj) //差集運算 ，參數是另一個set 即A-B的B (A是自己，array的部分)
    {
        bool t1[256]={0},t2[256]={0}; //用來辨識是否已出現該ASCII碼的 布林陣列，一個記A 一個記B
        for(int i=0;i<256;i++) //紀錄A集合中的字元是否已出現的迴圈
        {
            if(array[i]!='\0') //沒遇到結尾就一直做
            {
            int index =static_cast<int>(array[i]); //將字元轉成數字(範圍0~255)，並存到index裡
            t1[index]=1; //將該字元對應的布林陣列 紀錄為1 表已出現
            }
            else //做到結尾、即遇到'\0'為止
            break;
        }
        for(int i=0;i<256;i++) //紀錄B集合中的字元是否已出現的迴圈
        {
            if(obj.array[i]!='\0') //沒遇到結尾就一直做
            {
            int index =static_cast<int>(obj.array[i]);  //將字元轉成數字(範圍0~255)，並存到index裡
            t2[index]=1; //將該字元對應的布林陣列 紀錄為1 表已出現
            }
            else //做到結尾、即遇到'\0'為止
            break;
        }
        set back; //建立一個要回傳的集合 back
        int count=0; //當作array的index用
        for(int j=0;j<256;j++) //跑t1&t2的這個布林陣列看他的值
        {
            if(t1[j]&&t2[j]==0) //A集合要扣掉B集合的元素 即留下 A有但B沒有 
            {
            back.array[count++]=static_cast<char>(j); //將j轉成字元並存進back的字元陣列裡
            }
        }
        back.array[count]='\0'; //結尾要放'\0'
        return back; //回傳交集的set
    }
    bool operator >= (set &obj) //包含運算 ，參數是另一個set 即A>=B的B (A是自己，array的部分)
    {
        bool T=1; //假設原本成立
        bool t1[256]={0},t2[256]={0}; //用來辨識是否已出現該ASCII碼的 布林陣列，一個記A 一個記B
        for(int i=0;i<256;i++)  //紀錄A集合中的字元是否已出現的迴圈
        {
            if(array[i]!='\0') //沒遇到結尾就一直做
            {
            int index =static_cast<int>(array[i]);  //將字元轉成數字(範圍0~255)，並存到index裡
            t1[index]=1; //將該字元對應的布林陣列 紀錄為1 表已出現
            }
            else //做到結尾、即遇到'\0'為止
            break;
        }
        for(int i=0;i<256;i++) //紀錄B集合中的字元是否已出現的迴圈
        {
            if(obj.array[i]!='\0') //沒遇到結尾就一直做
            {
            int index =static_cast<int>(obj.array[i]);  //將字元轉成數字(範圍0~255)，並存到index裡
            t2[index]=1; //將該字元對應的布林陣列 紀錄為1 表已出現
            }
            else //做到結尾、即遇到'\0'為止
            break;
        }
        for(int j=0;j<256;j++) //跑t1&t2的這個布林陣列看他的值
        {
            if(t2[j]&&t1[j]==0) //A包含B 代表A擁有所有B的元素 那麼在B存在的字元卻在A不存在 就不成立
            T=0; // set T to 0
        }
        return T; //回傳布林值
    }
    bool belong (char ch) //檢查字元(即參數ch) 是否在 集合裡 可找到
    {
        for(int i=0;i<256;i++) //直接跑字元陣列
        {
            if(array[i]==ch) //有找到就回傳1
            return 1;
            if(array[i]=='\0') //遇到結尾跳出迴圈
            break;
        }
       
        return 0; //沒有找到才會執行這行並回傳1
    }
    void input() //set的輸入函式
    {
        char str[80]; //因題目說 字元輸入不超過80 因此將字元陣列設為80
        cin.getline(str,80); //getline可存' '
        bool temp[256]={0}; //紀錄已出現字元的bool array
        int i=0; //跑while迴圈的變數
        while(str[i]!='\0') //還沒到結尾之前都要繼續
        {
            int index=static_cast<int>(str[i]); //將字元轉成數字(範圍0~255)，並存到index裡
            temp[index]=1; //將該字元對應的布林陣列 紀錄為1 表已出現
            i++; //遞增，準備開始下次迴圈
        }
        int arr_index=0; //表示array的index的變數
        for(int j=0;j<256;j++) //跑布林陣列
        {
            if(temp[j]) //temp[j]=1進入 且代表有輸入這個字
            array[arr_index++]=static_cast<char>(j); //將j轉成字元並存進字元陣列裡
            //這樣做保證重複輸入的字元只出現一次 且 可以按照ASCII的順序排
        }
        array[arr_index]='\0'; //結尾補'\0'
    }
    friend ostream& operator<< (ostream& out,set &obj); //ostream的operator overloading，參數分別為ostream跟輸出的set
};

ostream& operator<< (ostream& out,set &obj)
{
    out<<"{"<<obj.array<<"}"<<endl; //用固定格式輸出
    return out; //最後須回傳ostream的變數
}
int main()
{
    int N; //存 會有幾組資料的變數
    cin>>N; //輸入
    char discard=cin.get(); //'\n'要讀掉，不然會影響之後的程式 存到discard裡
    //建立動態陣列分別存各組變數
    set *test_A=new set [N],*test_B=new set [N],*test_C=new set [N],*test_D=new set [N],*test_E=new set [N];
    char ch[20]; //以字元陣列存字元，最多20組資料
    int time=0; //跑迴圈用的變數
    while(time<N) //輸入N組的迴圈
    {
        test_A[time].input(); //key A set
        test_B[time].input(); // key B set
        cin.get(ch[time]); // key char
        discard=cin.get(); // discard '\n'
        time++; //increment
    }
    cout<<endl;
    time=0; //reset
    while(time<N)
    {
        cout<<"Test Case "<<time+1<<":\n"; //output which Test Case
        cout<<"A: "<<test_A[time]; //output set A
        cout<<"B: "<<test_B[time]; // output set B
        test_C[time]=test_A[time]+test_B[time]; //C=A+B
        cout<<"A+B: "<<test_C[time]; //output C
        test_D[time]=test_A[time]*test_B[time]; // D=A*B
        cout<<"A*B: "<<test_D[time]; //output D

        test_E[time]=test_A[time]-test_B[time]; //E=A-B
        cout<<"A-B: "<<test_E[time]; //output E
        test_E[time]=test_B[time]-test_A[time]; //E=B-A
        cout<<"B-A: "<<test_E[time]; //output E

        if(test_A[time]>=test_B[time]) // A contain B ? 
        cout<<"A contains B\n"; 
        else
        cout<<"A does not contain B\n";

        if(test_B[time]>=test_A[time]) // B contain A?
        cout<<"B contains A\n";
        else
        cout<<"B does not contain A\n";

        if(test_A[time].belong(ch[time])) // 字元是否在集合A裡面可找到 -屬於
        cout<<"\'"<<ch[time]<<"\' is in A"<<endl;
        else
        cout<<"\'"<<ch[time]<<"\' is not in A"<<endl;

        if(test_B[time].belong(ch[time])) // 字元是否在集合B裡面可找到 -屬於
        cout<<"\'"<<ch[time]<<"\' is in B"<<endl;
        else
        cout<<"\'"<<ch[time]<<"\' is not in B"<<endl;

        time++; //increment
        cout<<endl;
    }
    //刪掉動態陣列
    delete [] test_A; 
    delete [] test_B;
    delete [] test_C;
    delete [] test_D;
    delete [] test_E;
    return 0;
}
