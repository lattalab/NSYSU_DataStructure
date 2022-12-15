//Author�G���M�@ B103040045
//Date�GOct. 12, 2022�^
//Purpose�G����binary search tree �d�U�X�{�_�Ʀ����Ʀr
#include <iostream>
#include <vector>
using namespace std;
int node[100]={0},J=0; //node[100]�O�������tree�̪�node�AJ�Otrace_from_small()���������ܼ�
//trenode �ݭn�����СB�k���СB���
class treenode{
    public:
    int num;
    treenode* left;
    treenode* right;
    treenode() :num(0),left(NULL),right(NULL) {} //default constructor
    treenode(int nums) :num(nums),left(NULL),right(NULL) {} //constructor with one parameter to represent the node's data store the value of parameter.
};
class tree{
    public:
    treenode *root; //tree���̮ڥ����Y ����
    
    tree() :root(NULL) {} //default constructor
    void insert(int nums); //insert data to tree�Aparameter means the number you want to put in.
    treenode* search(int nums); //search tree's all data�Aparameter means the number you want to search.
    void deletes(int nums); //delete data to tree�Aparameter means the number you want to delete.

    //find the min value in the rightest subtree(find successor)
    //the parmeter means the tree's root you want to start with
    treenode* min_in_rightsub(treenode* r);
    //the function to record from the smallest node's data to the biggest one in the tree�Aand store in the array node[100].
    //and the parmeter means the tree's root you want to start with
    void trace_from_small(treenode* r); 
    
};
int main()
{
    vector<tree> a; //define tree
    tree temp; //�n��Jvector����
    a.push_back(temp); //�N��vector��a[0]�F
    int w=0; //to record how many groups
    int num=0; //temp parameter to store the data.
    while(cin>>num) //the condition:ctrl+z will end this loop.
    {
        if(num==-1) //-1 means the group's end input
        {
            w++; //1 group has already all input,plus 1 to represent there is at least one group.
            tree Temp; //�n��Jvector����
            a.push_back(Temp);
            continue; 
        }
        a[w].insert(num); //insert data to tree.
    }
    for(int j=0;j<w;j++) //trace every group
    {
        for(int k=0;k<100;k++) //reset to all zero
        node[k]=0;
        J=0; //reset to zero

        a[j].trace_from_small(a[j].root); //record nodes
        int count=0; //to count how many nodes in the tree.
        cout<<"node: ";
        for(int i=0;node[i]!=0;i++) //output tree node
        {
        cout<<node[i]<<" ";
        count++;
        }
        cout<<endl;

        treenode* b; //temp pointer
        cout<<"left: ";
        for(int i=0;i<count;i++)
        {
        b=a[j].search(node[i]); //record the node
        //find left's data�Aif left==NULL�Aouput 0
        if(b->left==NULL)
        cout<<"0 ";
        else
        cout<<b->left->num<<" ";
        }
        cout<<endl;

        cout<<"right: ";
        for(int i=0;i<count;i++)
        {
        b=a[j].search(node[i]); //record the node
        //find left's data�Aif left==NULL�Aouput 0
        if(b->right==NULL)
        cout<<"0 ";
        else
        cout<<b->right->num<<" ";
        }
        cout<<endl<<endl;

        for(int k=0;k<count;k++) //delete the data in tree
        a[j].deletes(node[k]);
    }
    return 0;
}
void tree::insert(int nums)
{
    if(search(nums)!=NULL) //if nums has already exist in tree�Adelete it and return.
    {
        deletes(nums);
        return;
    }

    treenode *news=new treenode(nums); //create a new node that store the nums
    if(root==NULL) //case 1: root==NULL�Adirectly insert it
    {
        root=news;
        return;
    }
    treenode *cur=root,*parent; //cur pointer to trace the tree�Aparent means the new node's parent node
    while(cur!=NULL)
    {
        parent=cur;
        if(news->num > cur->num) //�n�񪺤���j�A���k��
        cur=cur->right;
        else if(news->num < cur->num) //�n�񪺤���p�A������
        cur=cur->left;
    }
    //�̫�M�w�n�����
    if(news->num > parent->num)
    parent->right=news;
    else if(news->num < parent->num)
    parent->left=news;
}
treenode* tree::search(int nums)
{
    treenode* cur=root;
    while(cur!=NULL&&cur->num!=nums) //����:cur!=NULL �ӥB �٨S��쨺��nums���e ���n�~��]
    {
        if(nums > cur->num) //�n�䪺����j�A���k��
        cur=cur->right;
        else if(nums < cur->num) //�n�䪺����p�A������
        cur=cur->left;
    }
    return cur; //return pointer
}
treenode* tree::min_in_rightsub(treenode* r) 
{
    treenode* cur=r;
    //��̤p�A�ҥH�ɶq������
    while(cur!=NULL && cur->left!=NULL)
    {
        cur=cur->left;
    }
    return cur;
}
void tree::deletes(int nums)
{
    treenode* del=search(nums); //record the node address you want to delete
    if(del==NULL) //�䤣��ӭȡA��������
    return;

    if(root==del) //�n�R���ȭ�n�Oroot���쪺�a��Aroot�ݭn�ܰ�
    {
        if(root->left==NULL&&root->right==NULL) //case 1 : no child
        {
            root=NULL;
            delete del;
        }
        //case 2 : one child�A���@��
        else if(root->left!=NULL&&root->right==NULL) 
        {
            root=root->left;
            delete del;
        }
        else if(root->right!=NULL&&root->left==NULL)
        {
            root=root->right;
            delete del;
        }
        //case 3:two children
        else
        {
            //��successor �ñN��̭Ȥ����A�A���ӭn�R���R��
        treenode* temp1=min_in_rightsub(del->right);
        int t1=del->num;
        del->num=temp1->num;
        temp1->num=t1;
        if(temp1->left==NULL&&temp1->right==NULL) //if successor has no child
        {
            del->right=NULL;
            delete temp1;
        }
        else if(temp1->right!=NULL) //if successor has one child(PS:successor won's have two child.)
        {
            del->right=temp1->right;
            delete temp1;
        }
        }
        return;
    }
    treenode *cur=root,*parent; //cur pointer to trace the tree�Aparent means the new node's parent node
    while(cur->num!=del->num)
    {
    parent=cur;
    if(del->num > cur->num) //�n�񪺤���j�A���k��
    cur=cur->right;
    else if(del->num < cur->num) //�n�񪺤���p�A������
    cur=cur->left;
    }

    if(del->left==NULL&&del->right==NULL) //case 1 no child �����R
    {
        if(parent->num > del->num)
        parent->left=NULL;
        else
        parent->right=NULL;
        delete del;
    }
    else if(del->left==NULL||del->right==NULL) //case 2 one child ���@��
    {
        //�R��parent�k�䪺��node�A�A���^del����child
        if(del->num > parent->num && del->left!=NULL) 
        {
            parent->right=del->left; 
        }
        //�R��parent�k�䪺��node�A�A���^del���kchild
        else if(del->num > parent->num && del->right!=NULL)
        {
            parent->right=del->right;
        }
        //�R��parent���䪺��node�A�A���^del����child
        else if(del->num < parent->num && del->left!=NULL)
        {
            parent->left=del->left;
        }
        //�R��parent���䪺��node�A�A���^del���kchild
        else if(del->num < parent->num && del->right!=NULL)
        {
            parent->left=del->right;
        }
        delete del;
    }
    else //case 3 two children
    {
        //��successor �ñN��̭Ȥ����A�A���ӭn�R���R��
        treenode* temp=min_in_rightsub(del->right);
        int t=del->num;
        del->num=temp->num;
        temp->num=t;
        if(temp->left==NULL&&temp->right==NULL) //if successor has no child
        {
            del->right=NULL;
            delete temp;
        }
        else if(temp->right!=NULL) //if successor has one child(PS:successor won's have two child.)
        {
            del->right=temp->right;
            delete temp;
        }
    }
}
void tree::trace_from_small(treenode* r) //��recursion���覡��A�ҥH�|���I�p����
{
    treenode* temp; //record pointer

    //�੹���N����(����p)
    if(r->left!=NULL)
    trace_from_small(r->left);
    else //���੹���N����
    {
        node[J]=r->num;
        J++;

        if(r->right!=NULL) //�p�G��n�i�H���k�A�N�����k
        {
        trace_from_small(r->right);
        }
        return;
    }

    node[J]=r->num; //����root
    J++;

    if(r->right!=NULL) //��right subtree��
    {
        trace_from_small(r->right);
    }
}