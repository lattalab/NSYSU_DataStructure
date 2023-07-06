//Author： B103040045
//Date：Sept. 22, 2022
//Purpose：利用linked list的方式做出多項式加法和乘法
#include <iostream>
using namespace std;
//linked list以node連接，node有存放資料及指向自己的指標
struct node{
    int coef,exp; //coef代表多項式係數，exp代表多項次的次方
    node* next; //指到下個node的指標
    node() :coef(0),exp(0) {} //default constructor
    node(int Coef,int Exp); //constructor with parameter Coef(要放的係數) and Exp(要放的次方)
};
//實現linked list的class
class linked_list{
    private:
    node* head; //一個node指標代表該linked list的頭(最大次方)
    node* tail; //一個node指標代表該linked list的尾巴(最小次方)
    public:
    linked_list() :head(NULL),tail(NULL) {} //default constructor mean NULL linked list(Nothing in the linked list)
    //insert node to the linked list。
    //parameter means the node we want to insert.
    void insert(node &N); 
    void traveral(); //trace the whole linked list and show the data in the node.
    void Delete(); //delete the node whose coef is zero in the whole linked list. 
    bool isempty(); //verify that this linked list is empty or not.
    //operator overloading for +。
    //use friend function to pass two parameter，一個是被加數，另一個是加數，並回傳相加的結果
    friend linked_list operator +(linked_list &a,linked_list &b); 
    //operator overloading for *。
    //use friend function to pass two parameter，一個是被乘數，另一個是乘數，並回傳相乘的結果
    friend linked_list operator *(linked_list &a,linked_list &b);
};
int main()
{
    linked_list A[50],B[50]; //建立多組linked list(輸入可有多組)
    node temp; //暫存用的變數
    //P and Q means the following input for coef and exp until input P time or Q time;
    //coef means 係數，exp means 次方
    //count 是為了算有幾組輸入
    int P,Q,coef,exp,count=0; 

    do
    {
    cin>>P; //P個input
    for(int i=0;i<P;i++) //跑P次
        {
        cin>>coef>>exp; //input coef and exp
        //store in temp
        temp.coef=coef; 
        temp.exp=exp;
        //insert the node to A linked list
        A[count].insert(temp);
        }
    cin>>Q; //跑Q次
    for(int i=0;i<Q;i++)
        {
        cin>>coef>>exp; //input coef and exp
        //store in temp
        temp.coef=coef;
        temp.exp=exp;
        //insert the node to B linked list
        B[count].insert(temp);
        }
        count++; //代表剛剛以輸完一組 要加一
    }
    while(!(P==0 && Q==0)); //P=0&&Q=0 end

    cout<<endl;

    count--; //end input (0,0) 會多算一次 要扣掉
    //建立動態陣列 (有幾組input就建幾組)
    linked_list *C=new linked_list [count]; //store the value of A+B
    linked_list *D=new linked_list [count]; //store the value of A*B
    //calculate the addition and multiplication and store in the dynamic array，run (count) time
    //PS: there is in total (count) number inputs
    for(int j=0;j<count;j++)
    {
        C[j]=A[j]+B[j];
        D[j]=A[j]*B[j];
        //delete the zero element for both C and D
        C[j].Delete(); 
        D[j].Delete();
    }
    //run output for count time
    for(int k=0;k<count;k++)
    {
        cout<<"Case"<<k+1<<":"<<endl;

        cout<<"ADD\n";
        if(!(C[k].isempty())) //at least one element in linked list，display it
        C[k].traveral();
        else //by addition，the calculation is zero，and this time linked list is empty，show 0 0 by question request
        cout<<"0 0"<<endl;

        cout<<"MULTIPLY\n";
        if(!(D[k].isempty())) //at least one element in linked list，display it
        D[k].traveral();
        else //by multiplication，the calculation is zero，and this time linked list is empty，show 0 0 by question request
        cout<<"0 0"<<endl;
    }
    //end program need to delete the dynamic array
    delete [] C;
    delete [] D;
    return 0;
}
node::node(int Coef,int Exp) :coef(Coef),exp(Exp) //建立一個有特定值的node
{
    next=NULL;
}
void linked_list::insert(node &N) 
{
    node* news=new node(N.coef,N.exp); //一個node指標指向新建立的node
    if(head==NULL) //linked list還未有任何元素的時候
    {
        head=tail=news; //直接派過去
        return; //提早結束
    }
    if(head==tail) //只有一個node的時候
    {
        if(head->exp > news->exp) //原本那個元素的次方是最大的 往後接
        {
            //尾巴改變
            head->next=news;
            tail=news; 
            tail->next=NULL;
        }
        else if(head->exp < news->exp) //原本那個元素的次方最小 往前接
        {
            //頭改變
            news->next=head;
            head->next=NULL; 
            head=news;
        }
        else //一樣的次方 係數相加
        {
            head->coef+=news->coef;
        }
        return; //提早結束
    }
    //以下為多個元素的時候
    if(head->exp<news->exp) //比頭大
    {
        //改變頭
        news->next=head;
        head=news;
        return;
    }
    if(tail->exp>news->exp) //比尾巴小
    {
        //改變尾巴
        tail->next=news;
        tail=news;
        return;
    }
    node* temp=head; //建立一個node指標指向頭，並找出小於要插的node的次方的 且在linked list差值最小的node
    while(temp!=NULL) //trace the linked list until all nodes have traced。In the end，temp=NULL
    {
        if(temp->exp==news->exp) //the same exp
        {
            temp->coef+=news->coef; //係數相加
            return; //可提早結束
        }
        if(temp->exp > news->exp && temp->next->exp < news->exp) //夾在要放的位置 (linked list有一種大小順序)
        break;
        else
        temp=temp->next;
    }
    //動指標夾進去
    news->next=temp->next;
    temp->next=news;
    return;
}
void linked_list::traveral() //trace linked list
{
    node* cur=head; //指標cur指到head
    while(cur!=NULL) //一直走到最後
    {
        cout<<cur->coef<<" "<<cur->exp<<endl; //output coef and exp
        cur=cur->next; //move to next node
    }
}
bool linked_list::isempty() 
{
    if(head==NULL) //nothing in the linked list
    return 1;
    else
    return 0;
}
void linked_list::Delete()
{
    node* temp; //指到要刪的node的暫存變數
    while(head!=NULL && head->coef==0) //從頭開始刪有零係數的node，並改變head的指向，head指到零係數node才刪
    {
        //改變頭
        temp=head;
        head=temp->next;
        delete temp;
    }
    if(head==NULL) //代表刪完 => nothing in the linked list
    {
        tail=NULL;
        return;
    }
    node* before=head; //找到tail的前一個node位置並存下來
    while(tail->coef==0) //tail指到零係數node才刪
    {
        temp=tail;
        while(before->next!=tail) //找tail的前一個位置
        {
            before=before->next;
        }
        //改變尾巴
        tail=before;
        tail->next=NULL;
        delete temp;
    }
    node* cur=head; //存要刪的元素的前一個位置
    while(cur->next!=NULL) //找要刪的元素的前一個位置
    {
        if(cur->next->coef==0)
        {
            temp=cur->next;
            cur->next=temp->next;
            delete temp;
        }
        cur=cur->next;
    }
}
linked_list operator +(linked_list &a,linked_list &b)
{
    linked_list c; //a new linked list to stroe a+b
    //a 全部放入 c 的linked list 中
    node* temp=a.head;
    while(temp!=NULL)
    {
        c.insert(*temp);
        temp=temp->next;
    }
    //b 全部放入 c 的linked list 中
    temp=b.head;
    while(temp!=NULL)
    {
        c.insert(*temp);
        temp=temp->next;
    }
    //PS: insert function will automatically arrange the c linked list
    return c;
}
linked_list operator *(linked_list &a,linked_list &b)
{
    linked_list c; //a new linked list to stroe a*b
    int temp_coff,temp_exp; //store the current node's coef and exp
    node* cur_A=a.head; //A node pointer to trace a linked list
    node* cur_B=b.head; //A node pointer to trace b linked list
    //用雙重迴圈模擬多項式乘法
    while(cur_A!=NULL)
    {
      while(cur_B!=NULL)
        {
            //multiplication:
            //係數相乘，次方相加
        temp_coff=cur_A->coef*cur_B->coef; 
        temp_exp=cur_A->exp+cur_B->exp;
        node *temp=new node(temp_coff,temp_exp); //建立新node 存剛剛算好的值
        c.insert(*temp); //放入linked list
        cur_B=cur_B->next;
        } 
        cur_A=cur_A->next;
        cur_B=b.head;
    }
    return c;
}
