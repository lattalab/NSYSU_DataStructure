//Author�G���M�@ B103040045
//Date�GSept. 22, 2022
//Purpose�G�Q��linked list���覡���X�h�����[�k�M���k
#include <iostream>
using namespace std;
//linked list�Hnode�s���Anode���s���ƤΫ��V�ۤv������
struct node{
    int coef,exp; //coef�N��h�����Y�ơAexp�N��h����������
    node* next; //����U��node������
    node() :coef(0),exp(0) {} //default constructor
    node(int Coef,int Exp); //constructor with parameter Coef(�n�񪺫Y��) and Exp(�n�񪺦���)
};
//��{linked list��class
class linked_list{
    private:
    node* head; //�@��node���ХN���linked list���Y(�̤j����)
    node* tail; //�@��node���ХN���linked list������(�̤p����)
    public:
    linked_list() :head(NULL),tail(NULL) {} //default constructor mean NULL linked list(Nothing in the linked list)
    //insert node to the linked list�C
    //parameter means the node we want to insert.
    void insert(node &N); 
    void traveral(); //trace the whole linked list and show the data in the node.
    void Delete(); //delete the node whose coef is zero in the whole linked list. 
    bool isempty(); //verify that this linked list is empty or not.
    //operator overloading for +�C
    //use friend function to pass two parameter�A�@�ӬO�Q�[�ơA�t�@�ӬO�[�ơA�æ^�Ǭۥ[�����G
    friend linked_list operator +(linked_list &a,linked_list &b); 
    //operator overloading for *�C
    //use friend function to pass two parameter�A�@�ӬO�Q���ơA�t�@�ӬO���ơA�æ^�Ǭۭ������G
    friend linked_list operator *(linked_list &a,linked_list &b);
};
int main()
{
    linked_list A[50],B[50]; //�إߦh��linked list(��J�i���h��)
    node temp; //�Ȧs�Ϊ��ܼ�
    //P and Q means the following input for coef and exp until input P time or Q time;
    //coef means �Y�ơAexp means ����
    //count �O���F�⦳�X�տ�J
    int P,Q,coef,exp,count=0; 

    do
    {
    cin>>P; //P��input
    for(int i=0;i<P;i++) //�]P��
        {
        cin>>coef>>exp; //input coef and exp
        //store in temp
        temp.coef=coef; 
        temp.exp=exp;
        //insert the node to A linked list
        A[count].insert(temp);
        }
    cin>>Q; //�]Q��
    for(int i=0;i<Q;i++)
        {
        cin>>coef>>exp; //input coef and exp
        //store in temp
        temp.coef=coef;
        temp.exp=exp;
        //insert the node to B linked list
        B[count].insert(temp);
        }
        count++; //�N����H�駹�@�� �n�[�@
    }
    while(!(P==0 && Q==0)); //P=0&&Q=0 end

    cout<<endl;

    count--; //end input (0,0) �|�h��@�� �n����
    //�إ߰ʺA�}�C (���X��input�N�شX��)
    linked_list *C=new linked_list [count]; //store the value of A+B
    linked_list *D=new linked_list [count]; //store the value of A*B
    //calculate the addition and multiplication and store in the dynamic array�Arun (count) time
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
        if(!(C[k].isempty())) //at least one element in linked list�Adisplay it
        C[k].traveral();
        else //by addition�Athe calculation is zero�Aand this time linked list is empty�Ashow 0 0 by question request
        cout<<"0 0"<<endl;

        cout<<"MULTIPLY\n";
        if(!(D[k].isempty())) //at least one element in linked list�Adisplay it
        D[k].traveral();
        else //by multiplication�Athe calculation is zero�Aand this time linked list is empty�Ashow 0 0 by question request
        cout<<"0 0"<<endl;
    }
    //end program need to delete the dynamic array
    delete [] C;
    delete [] D;
    return 0;
}
node::node(int Coef,int Exp) :coef(Coef),exp(Exp) //�إߤ@�Ӧ��S�w�Ȫ�node
{
    next=NULL;
}
void linked_list::insert(node &N) 
{
    node* news=new node(N.coef,N.exp); //�@��node���Ы��V�s�إߪ�node
    if(head==NULL) //linked list�٥������󤸯����ɭ�
    {
        head=tail=news; //�������L�h
        return; //��������
    }
    if(head==tail) //�u���@��node���ɭ�
    {
        if(head->exp > news->exp) //�쥻���Ӥ���������O�̤j�� ���ᱵ
        {
            //���ڧ���
            head->next=news;
            tail=news; 
            tail->next=NULL;
        }
        else if(head->exp < news->exp) //�쥻���Ӥ���������̤p ���e��
        {
            //�Y����
            news->next=head;
            head->next=NULL; 
            head=news;
        }
        else //�@�˪����� �Y�Ƭۥ[
        {
            head->coef+=news->coef;
        }
        return; //��������
    }
    //�H�U���h�Ӥ������ɭ�
    if(head->exp<news->exp) //���Y�j
    {
        //�����Y
        news->next=head;
        head=news;
        return;
    }
    if(tail->exp>news->exp) //����ڤp
    {
        //���ܧ���
        tail->next=news;
        tail=news;
        return;
    }
    node* temp=head; //�إߤ@��node���Ы��V�Y�A�ç�X�p��n����node�����誺 �B�blinked list�t�ȳ̤p��node
    while(temp!=NULL) //trace the linked list until all nodes have traced�CIn the end�Atemp=NULL
    {
        if(temp->exp==news->exp) //the same exp
        {
            temp->coef+=news->coef; //�Y�Ƭۥ[
            return; //�i��������
        }
        if(temp->exp > news->exp && temp->next->exp < news->exp) //���b�n�񪺦�m (linked list���@�ؤj�p����)
        break;
        else
        temp=temp->next;
    }
    //�ʫ��Ч��i�h
    news->next=temp->next;
    temp->next=news;
    return;
}
void linked_list::traveral() //trace linked list
{
    node* cur=head; //����cur����head
    while(cur!=NULL) //�@������̫�
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
    node* temp; //����n�R��node���Ȧs�ܼ�
    while(head!=NULL && head->coef==0) //�q�Y�}�l�R���s�Y�ƪ�node�A�ç���head�����V�Ahead����s�Y��node�~�R
    {
        //�����Y
        temp=head;
        head=temp->next;
        delete temp;
    }
    if(head==NULL) //�N��R�� => nothing in the linked list
    {
        tail=NULL;
        return;
    }
    node* before=head; //���tail���e�@��node��m�æs�U��
    while(tail->coef==0) //tail����s�Y��node�~�R
    {
        temp=tail;
        while(before->next!=tail) //��tail���e�@�Ӧ�m
        {
            before=before->next;
        }
        //���ܧ���
        tail=before;
        tail->next=NULL;
        delete temp;
    }
    node* cur=head; //�s�n�R���������e�@�Ӧ�m
    while(cur->next!=NULL) //��n�R���������e�@�Ӧ�m
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
    //a ������J c ��linked list ��
    node* temp=a.head;
    while(temp!=NULL)
    {
        c.insert(*temp);
        temp=temp->next;
    }
    //b ������J c ��linked list ��
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
    //�������j������h�������k
    while(cur_A!=NULL)
    {
      while(cur_B!=NULL)
        {
            //multiplication:
            //�Y�Ƭۭ��A����ۥ[
        temp_coff=cur_A->coef*cur_B->coef; 
        temp_exp=cur_A->exp+cur_B->exp;
        node *temp=new node(temp_coff,temp_exp); //�إ߷snode �s����n����
        c.insert(*temp); //��Jlinked list
        cur_B=cur_B->next;
        } 
        cur_A=cur_A->next;
        cur_B=b.head;
    }
    return c;
}