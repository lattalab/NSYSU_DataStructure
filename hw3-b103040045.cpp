//Author：楊貽婷 B103040045
//Date：Sept. 19, 2022
//Purpose：印出任意一組騎士走完n*n的棋盤順序，但不使用recursion，而是使用stack的方式
#include <iostream>
using namespace std;
//以linked list的方式實作stack，node有位置(i,j)、以及走的方向、以及一個指向node的指標
struct node{
    int i,j,pos;
    struct node* next;
};
node* head=NULL; //stack需要的主指標head
void push(int I,int J,int Pos) //push function ,參數為要存的變數(i,j,走的方向)
{
    //指標指到一個新node，內裝(i,j,走的方向) 跟next指到空
    node* news=new node;
    news->i=I; news->j=J; news->pos=Pos; 
    news->next=NULL;
    //推疊
    news->next=head;
    head=news;
}
int pop() //將stack的元素拿出的pop function
{
    if(head==NULL) //boundary condition ,不能照原方法回傳值 
    return -1;

    int num=head->pos; //先存第一個元素所存的走的位置
    struct node* temp=head; //新指標指到head
    head=head->next; //head指向下一個，表示原來在上面已拿出stack
    delete temp; //delete memory
    return num; //回傳 走的方向
}
int getI() //取得i的function
{
    if(head==NULL)
    return -1;
    int I=head->i;
    return I;
}
int getJ() //取得j的function
{
    if(head==NULL)
    return -1;
    int J=head->j;
    return J;
}
void popAll() //將head pop全部的元素 令其指向空的function
{
    while(head!=NULL) //做到head=NULL為止
    {
    struct node* temp=head;
    head=head->next;
    delete temp;
    }
}
int already[36][8]={0}; //紀錄此步數走過的方向
//ex: 第二步時，往第二個方向，將already[1][1]=1表已走過

//處理騎士走棋盤的function 
//parameter :**a :一個二維陣列(棋盤), I :i 起始位置 , J : j起始位置 , n : n*n棋盤的n
//回傳bool值確認是否有解
bool sol(int **a,int I,int J,int n) 
{
    int step=1; //第一步，step變數是 再走第幾步的意思
    int temp_i=I,temp_j=J,temp_pos,re_pos=0; //temp_i紀錄目前的位置i，temp_j紀錄目前的位置j，temp_pos預計要走的方向，re_pos 紀錄pop回傳的值
    a[temp_i-1][temp_j-1]=step; //棋盤第一格紀錄為1
    for(int j=0;j<n*n;j++) //將紀錄是否已走過的步數的陣列 全部歸零
    {
        for(int k=0;k<8;k++)
        already[j][k]=0;
    }

    while(step) //step有值就繼續
    {
    if(step>=n*n) //最多為n*n步 => 有走完 回傳1
    {
        return 1;
    }
    //每個方向的條件皆須滿足 1<=i<=n',1<=j'<=n ,且該方向未走過
    if(((temp_i-2)>=1)&&((temp_j+1)>=1)&&((temp_i-2)<=n)&&((temp_j+1)<=n)&&(already[step-1][0]==0))
    {
        
    if(a[temp_i-2-1][temp_j+1-1]==0) //那格沒有值(0)才繼續
     {
    temp_pos=1; //第一個方向
    push(temp_i,temp_j,temp_pos); //放入stack
    temp_i-=2; temp_j+=1; //移動位置
    already[step-1][0]=1; //表已走過
    step++; //換成下一步
    a[temp_i-1][temp_j-1]=step; //放入棋盤
    continue; //跑下次迴圈
     }
    }

    if(((temp_i-1)>=1)&&((temp_j+2)>=1)&&((temp_i-1)<=n)&&((temp_j+2)<=n)&&(already[step-1][1]==0))
    {
        
        if(a[temp_i-1-1][temp_j+2-1]==0) //那格沒有值(0)才繼續
        {
    temp_pos=2; //第二個方向
    push(temp_i,temp_j,temp_pos); //放入stack
    temp_i-=1; temp_j+=2; //移動位置
    already[step-1][1]=1; //表已走過
    step++; //換成下一步
    a[temp_i-1][temp_j-1]=step; //放入棋盤
    continue; //跑下次迴圈
        }
    }

    if(((temp_i+1)>=1)&&((temp_j+2)>=1)&&((temp_i+1)<=n)&&((temp_j+2)<=n)&&(already[step-1][2]==0))
    { 
        if(a[temp_i+1-1][temp_j+2-1]==0) //那格沒有值(0)才繼續
        {
    temp_pos=3;  //第三個方向
    push(temp_i,temp_j,temp_pos);  //放入stack
    temp_i+=1; temp_j+=2; //移動位置
    already[step-1][2]=1; //表已走過
    step++; //換成下一步
    a[temp_i-1][temp_j-1]=step; //放入棋盤
    continue; //跑下次迴圈
        }
    }

    if(((temp_i+2)>=1)&&((temp_j+1)>=1)&&((temp_i+2)<=n)&&((temp_j+1)<=n)&&(already[step-1][3]==0))
    {
        if(a[temp_i+2-1][temp_j+1-1]==0) //那格沒有值(0)才繼續
        { 
    temp_pos=4; //第四個方向
    push(temp_i,temp_j,temp_pos);  //放入stack
    temp_i+=2; temp_j+=1;  //移動位置
    already[step-1][3]=1; //表已走過
    step++;  //換成下一步
    a[temp_i-1][temp_j-1]=step;  //放入棋盤
    continue; //跑下次迴圈
        }
    }

    if(((temp_i+2)>=1)&&((temp_j-1)>=1)&&((temp_i+2)<=n)&&((temp_j-1)<=n)&&(already[step-1][4]==0))
    { 
        if(a[temp_i+2-1][temp_j-1-1]==0) //那格沒有值(0)才繼續
        {
    temp_pos=5; //第五個方向
    push(temp_i,temp_j,temp_pos);  //放入stack
    temp_i+=2; temp_j-=1; //移動位置
    already[step-1][4]=1;  //表已走過
    step++;  //換成下一步
    a[temp_i-1][temp_j-1]=step;  //放入棋盤
    continue; //跑下次迴圈
        }
    }

    if(((temp_i+1)>=1)&&((temp_j-2)>=1)&&((temp_i+1)<=n)&&((temp_j-2)<=n)&&(already[step-1][5]==0))
    { 
        if(a[temp_i+1-1][temp_j-2-1]==0) //那格沒有值(0)才繼續
        { 
    temp_pos=6; //第六個方向
    push(temp_i,temp_j,temp_pos); //放入stack
    temp_i+=1; temp_j-=2; //移動位置
    already[step-1][5]=1; //表已走過
    step++;  //換成下一步
    a[temp_i-1][temp_j-1]=step; //放入棋盤
    continue;  //跑下次迴圈
        }
    }

    if(((temp_i-1)>=1)&&((temp_j-2)>=1)&&((temp_i-1)<=n)&&((temp_j-2)<=n)&&(already[step-1][6]==0))
    { 
        if(a[temp_i-1-1][temp_j-2-1]==0) //那格沒有值(0)才繼續
        {
    temp_pos=7; //第七個方向
    push(temp_i,temp_j,temp_pos); //放入stack
    temp_i-=1; temp_j-=2; //移動位置
    already[step-1][6]=1; //表已走過
    step++; //換成下一步
    a[temp_i-1][temp_j-1]=step; //放入棋盤
    continue; //跑下次迴圈
        }
    }

    if(((temp_i-2)>=1)&&((temp_j-1)>=1)&&((temp_i-2)<=n)&&((temp_j-1)<=n)&&(already[step-1][7]==0))
    {
        if(a[temp_i-2-1][temp_j-1-1]==0) //那格沒有值(0)才繼續
        { 
    temp_pos=8; //第八個方向
    push(temp_i,temp_j,temp_pos); //放入stack
    temp_i-=2; temp_j-=1; //移動位置
    already[step-1][7]=1; //表已走過
    step++; //換成下一步
    a[temp_i-1][temp_j-1]=step;  //放入棋盤
    continue; //跑下次迴圈
        }
    }

    //跑到這裡 代表沒有方向可走，將現在走的位置改為零
    a[temp_i-1][temp_j-1]=0;
    temp_i=getI(); //得到上一個位置i
    temp_j=getJ(); //得到上一個位置j
    re_pos=pop(); //將那個node pop出來
    step--; //回上一步
    for(int j=step;j<n*n;j++) //回上一步，將之後步數已走過方向歸零
    {
        for(int k=0;k<8;k++)
        {
            already[j][k]=0;
        }
    }

    }
    return 0; //沒有可走方向 回傳0
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
            arr2D[j]=new int [i];
        }
        //棋盤歸零
        for(int k=0;k<i;k++)
        {
            for(int m=0;m<i;m++)
            arr2D[k][m]=0;
        }
        bool temp =sol(arr2D,1,1,i); //將temp紀錄sol 回傳的變數，(1,1)為起始點 
        cout<<"n="<<i<<" : "<<endl; //output :
        if(temp) //temp=1進入(有解)
        {
            for(int k=0;k<i;k++) //印出棋盤
         {
            for(int m=0;m<i;m++)
            cout<<arr2D[k][m]<<" ";

            cout<<endl;
         }
         cout<<endl;
        }
        else //無解
        cout<<"no solution.\n\n";

        for(int l=0;l<i;l++) //用完動態陣列要刪除
        {
            delete [] arr2D[l];
        }
        delete [] arr2D;

        popAll(); //本次 i*i 棋盤走完要將stack歸零，以便下一次棋盤存入
    }
    return 0;
}
