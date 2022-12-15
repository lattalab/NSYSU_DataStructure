//Author�G���M�@ B103040045
//Date�GSept. 19, 2022
//Purpose�G�L�X���N�@���M�h����n*n���ѽL���ǡA�����ϥ�recursion�A�ӬO�ϥ�stack���覡
#include <iostream>
using namespace std;
//�Hlinked list���覡��@stack�Anode����m(i,j)�B�H�Ψ�����V�B�H�Τ@�ӫ��Vnode������
struct node{
    int i,j,pos;
    struct node* next;
};
node* head=NULL; //stack�ݭn���D����head
void push(int I,int J,int Pos) //push function ,�ѼƬ��n�s���ܼ�(i,j,������V)
{
    //���Ы���@�ӷsnode�A����(i,j,������V) ��next�����
    node* news=new node;
    news->i=I; news->j=J; news->pos=Pos; 
    news->next=NULL;
    //���|
    news->next=head;
    head=news;
}
int pop() //�Nstack���������X��pop function
{
    if(head==NULL) //boundary condition ,����ӭ��k�^�ǭ� 
    return -1;

    int num=head->pos; //���s�Ĥ@�Ӥ����Ҧs��������m
    struct node* temp=head; //�s���Ы���head
    head=head->next; //head���V�U�@�ӡA��ܭ�Ӧb�W���w���Xstack
    delete temp; //delete memory
    return num; //�^�� ������V
}
int getI() //���oi��function
{
    if(head==NULL)
    return -1;
    int I=head->i;
    return I;
}
int getJ() //���oj��function
{
    if(head==NULL)
    return -1;
    int J=head->j;
    return J;
}
void popAll() //�Nhead pop���������� �O����V�Ū�function
{
    while(head!=NULL) //����head=NULL����
    {
    struct node* temp=head;
    head=head->next;
    delete temp;
    }
}
int already[36][8]={0}; //�������B�ƨ��L����V
//ex: �ĤG�B�ɡA���ĤG�Ӥ�V�A�Nalready[1][1]=1��w���L

//�B�z�M�h���ѽL��function 
//parameter :**a :�@�ӤG���}�C(�ѽL), I :i �_�l��m , J : j�_�l��m , n : n*n�ѽL��n
//�^��bool�ȽT�{�O�_����
bool sol(int **a,int I,int J,int n) 
{
    int step=1; //�Ĥ@�B�Astep�ܼƬO �A���ĴX�B���N��
    int temp_i=I,temp_j=J,temp_pos,re_pos=0; //temp_i�����ثe����mi�Atemp_j�����ثe����mj�Atemp_pos�w�p�n������V�Are_pos ����pop�^�Ǫ���
    a[temp_i-1][temp_j-1]=step; //�ѽL�Ĥ@�������1
    for(int j=0;j<n*n;j++) //�N�����O�_�w���L���B�ƪ��}�C �����k�s
    {
        for(int k=0;k<8;k++)
        already[j][k]=0;
    }

    while(step) //step���ȴN�~��
    {
    if(step>=n*n) //�̦h��n*n�B => ������ �^��1
    {
        return 1;
    }
    //�C�Ӥ�V������Ҷ����� 1<=i<=n',1<=j'<=n ,�B�Ӥ�V�����L
    if(((temp_i-2)>=1)&&((temp_j+1)>=1)&&((temp_i-2)<=n)&&((temp_j+1)<=n)&&(already[step-1][0]==0))
    {
        
    if(a[temp_i-2-1][temp_j+1-1]==0) //����S����(0)�~�~��
     {
    temp_pos=1; //�Ĥ@�Ӥ�V
    push(temp_i,temp_j,temp_pos); //��Jstack
    temp_i-=2; temp_j+=1; //���ʦ�m
    already[step-1][0]=1; //��w���L
    step++; //�����U�@�B
    a[temp_i-1][temp_j-1]=step; //��J�ѽL
    continue; //�]�U���j��
     }
    }

    if(((temp_i-1)>=1)&&((temp_j+2)>=1)&&((temp_i-1)<=n)&&((temp_j+2)<=n)&&(already[step-1][1]==0))
    {
        
        if(a[temp_i-1-1][temp_j+2-1]==0) //����S����(0)�~�~��
        {
    temp_pos=2; //�ĤG�Ӥ�V
    push(temp_i,temp_j,temp_pos); //��Jstack
    temp_i-=1; temp_j+=2; //���ʦ�m
    already[step-1][1]=1; //��w���L
    step++; //�����U�@�B
    a[temp_i-1][temp_j-1]=step; //��J�ѽL
    continue; //�]�U���j��
        }
    }

    if(((temp_i+1)>=1)&&((temp_j+2)>=1)&&((temp_i+1)<=n)&&((temp_j+2)<=n)&&(already[step-1][2]==0))
    { 
        if(a[temp_i+1-1][temp_j+2-1]==0) //����S����(0)�~�~��
        {
    temp_pos=3;  //�ĤT�Ӥ�V
    push(temp_i,temp_j,temp_pos);  //��Jstack
    temp_i+=1; temp_j+=2; //���ʦ�m
    already[step-1][2]=1; //��w���L
    step++; //�����U�@�B
    a[temp_i-1][temp_j-1]=step; //��J�ѽL
    continue; //�]�U���j��
        }
    }

    if(((temp_i+2)>=1)&&((temp_j+1)>=1)&&((temp_i+2)<=n)&&((temp_j+1)<=n)&&(already[step-1][3]==0))
    {
        if(a[temp_i+2-1][temp_j+1-1]==0) //����S����(0)�~�~��
        { 
    temp_pos=4; //�ĥ|�Ӥ�V
    push(temp_i,temp_j,temp_pos);  //��Jstack
    temp_i+=2; temp_j+=1;  //���ʦ�m
    already[step-1][3]=1; //��w���L
    step++;  //�����U�@�B
    a[temp_i-1][temp_j-1]=step;  //��J�ѽL
    continue; //�]�U���j��
        }
    }

    if(((temp_i+2)>=1)&&((temp_j-1)>=1)&&((temp_i+2)<=n)&&((temp_j-1)<=n)&&(already[step-1][4]==0))
    { 
        if(a[temp_i+2-1][temp_j-1-1]==0) //����S����(0)�~�~��
        {
    temp_pos=5; //�Ĥ��Ӥ�V
    push(temp_i,temp_j,temp_pos);  //��Jstack
    temp_i+=2; temp_j-=1; //���ʦ�m
    already[step-1][4]=1;  //��w���L
    step++;  //�����U�@�B
    a[temp_i-1][temp_j-1]=step;  //��J�ѽL
    continue; //�]�U���j��
        }
    }

    if(((temp_i+1)>=1)&&((temp_j-2)>=1)&&((temp_i+1)<=n)&&((temp_j-2)<=n)&&(already[step-1][5]==0))
    { 
        if(a[temp_i+1-1][temp_j-2-1]==0) //����S����(0)�~�~��
        { 
    temp_pos=6; //�Ĥ��Ӥ�V
    push(temp_i,temp_j,temp_pos); //��Jstack
    temp_i+=1; temp_j-=2; //���ʦ�m
    already[step-1][5]=1; //��w���L
    step++;  //�����U�@�B
    a[temp_i-1][temp_j-1]=step; //��J�ѽL
    continue;  //�]�U���j��
        }
    }

    if(((temp_i-1)>=1)&&((temp_j-2)>=1)&&((temp_i-1)<=n)&&((temp_j-2)<=n)&&(already[step-1][6]==0))
    { 
        if(a[temp_i-1-1][temp_j-2-1]==0) //����S����(0)�~�~��
        {
    temp_pos=7; //�ĤC�Ӥ�V
    push(temp_i,temp_j,temp_pos); //��Jstack
    temp_i-=1; temp_j-=2; //���ʦ�m
    already[step-1][6]=1; //��w���L
    step++; //�����U�@�B
    a[temp_i-1][temp_j-1]=step; //��J�ѽL
    continue; //�]�U���j��
        }
    }

    if(((temp_i-2)>=1)&&((temp_j-1)>=1)&&((temp_i-2)<=n)&&((temp_j-1)<=n)&&(already[step-1][7]==0))
    {
        if(a[temp_i-2-1][temp_j-1-1]==0) //����S����(0)�~�~��
        { 
    temp_pos=8; //�ĤK�Ӥ�V
    push(temp_i,temp_j,temp_pos); //��Jstack
    temp_i-=2; temp_j-=1; //���ʦ�m
    already[step-1][7]=1; //��w���L
    step++; //�����U�@�B
    a[temp_i-1][temp_j-1]=step;  //��J�ѽL
    continue; //�]�U���j��
        }
    }

    //�]��o�� �N��S����V�i���A�N�{�b������m�אּ�s
    a[temp_i-1][temp_j-1]=0;
    temp_i=getI(); //�o��W�@�Ӧ�mi
    temp_j=getJ(); //�o��W�@�Ӧ�mj
    re_pos=pop(); //�N����node pop�X��
    step--; //�^�W�@�B
    for(int j=step;j<n*n;j++) //�^�W�@�B�A�N����B�Ƥw���L��V�k�s
    {
        for(int k=0;k<8;k++)
        {
            already[j][k]=0;
        }
    }

    }
    return 0; //�S���i����V �^��0
}
int main()
{
    for(int i=1;i<=6;i++) //��ܱqn=1��n=6���ѽL
    {
        if(i==1) //1 is boundary condition
        {
            cout<<"n=1 :\n"<<" 1"<<endl<<endl;
            continue;
        }
        //�إ߰ʺA�G���}�C (i*i)
        int **arr2D=new int* [i];
        for(int j=0;j<i;j++)
        {
            arr2D[j]=new int [i];
        }
        //�ѽL�k�s
        for(int k=0;k<i;k++)
        {
            for(int m=0;m<i;m++)
            arr2D[k][m]=0;
        }
        bool temp =sol(arr2D,1,1,i); //�Ntemp����sol �^�Ǫ��ܼơA(1,1)���_�l�I 
        cout<<"n="<<i<<" : "<<endl; //output :
        if(temp) //temp=1�i�J(����)
        {
            for(int k=0;k<i;k++) //�L�X�ѽL
         {
            for(int m=0;m<i;m++)
            cout<<arr2D[k][m]<<" ";

            cout<<endl;
         }
         cout<<endl;
        }
        else //�L��
        cout<<"no solution.\n\n";

        for(int l=0;l<i;l++) //�Χ��ʺA�}�C�n�R��
        {
            delete [] arr2D[l];
        }
        delete [] arr2D;

        popAll(); //���� i*i �ѽL�����n�Nstack�k�s�A�H�K�U�@���ѽL�s�J
    }
    return 0;
}
