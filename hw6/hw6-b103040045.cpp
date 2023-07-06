//Author： B103040045
//Date：Oct. 12, 2022）
//Purpose：應用binary search tree 留下出現奇數次的數字
#include <iostream>
#include <vector>
using namespace std;
int node[100]={0},J=0; //node[100]是之後紀錄tree裡的node，J是trace_from_small()的紀錄用變數
//trenode 需要左指標、右指標、資料
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
    treenode *root; //tree的最根本源頭 指標
    
    tree() :root(NULL) {} //default constructor
    void insert(int nums); //insert data to tree，parameter means the number you want to put in.
    treenode* search(int nums); //search tree's all data，parameter means the number you want to search.
    void deletes(int nums); //delete data to tree，parameter means the number you want to delete.

    //find the min value in the rightest subtree(find successor)
    //the parmeter means the tree's root you want to start with
    treenode* min_in_rightsub(treenode* r);
    //the function to record from the smallest node's data to the biggest one in the tree，and store in the array node[100].
    //and the parmeter means the tree's root you want to start with
    void trace_from_small(treenode* r); 
    
};
int main()
{
    vector<tree> a; //define tree
    tree temp; //要放入vector的樹
    a.push_back(temp); //代表vector有a[0]了
    int w=0; //to record how many groups
    int num=0; //temp parameter to store the data.
    while(cin>>num) //the condition:ctrl+z will end this loop.
    {
        if(num==-1) //-1 means the group's end input
        {
            w++; //1 group has already all input,plus 1 to represent there is at least one group.
            tree Temp; //要放入vector的樹
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
        //find left's data，if left==NULL，ouput 0
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
        //find left's data，if left==NULL，ouput 0
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
    if(search(nums)!=NULL) //if nums has already exist in tree，delete it and return.
    {
        deletes(nums);
        return;
    }

    treenode *news=new treenode(nums); //create a new node that store the nums
    if(root==NULL) //case 1: root==NULL，directly insert it
    {
        root=news;
        return;
    }
    treenode *cur=root,*parent; //cur pointer to trace the tree，parent means the new node's parent node
    while(cur!=NULL)
    {
        parent=cur;
        if(news->num > cur->num) //要放的比較大，往右走
        cur=cur->right;
        else if(news->num < cur->num) //要放的比較小，往左走
        cur=cur->left;
    }
    //最後決定要放哪邊
    if(news->num > parent->num)
    parent->right=news;
    else if(news->num < parent->num)
    parent->left=news;
}
treenode* tree::search(int nums)
{
    treenode* cur=root;
    while(cur!=NULL&&cur->num!=nums) //限制:cur!=NULL 而且 還沒找到那個nums之前 都要繼續跑
    {
        if(nums > cur->num) //要找的比較大，往右走
        cur=cur->right;
        else if(nums < cur->num) //要找的比較小，往左走
        cur=cur->left;
    }
    return cur; //return pointer
}
treenode* tree::min_in_rightsub(treenode* r) 
{
    treenode* cur=r;
    //找最小，所以盡量往左找
    while(cur!=NULL && cur->left!=NULL)
    {
        cur=cur->left;
    }
    return cur;
}
void tree::deletes(int nums)
{
    treenode* del=search(nums); //record the node address you want to delete
    if(del==NULL) //找不到該值，提早結束
    return;

    if(root==del) //要刪的值剛好是root指到的地方，root需要變動
    {
        if(root->left==NULL&&root->right==NULL) //case 1 : no child
        {
            root=NULL;
            delete del;
        }
        //case 2 : one child，接一邊
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
            //找successor 並將兩者值互換，再把原來要刪的刪掉
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
    treenode *cur=root,*parent; //cur pointer to trace the tree，parent means the new node's parent node
    while(cur->num!=del->num)
    {
    parent=cur;
    if(del->num > cur->num) //要放的比較大，往右走
    cur=cur->right;
    else if(del->num < cur->num) //要放的比較小，往左走
    cur=cur->left;
    }

    if(del->left==NULL&&del->right==NULL) //case 1 no child 直接刪
    {
        if(parent->num > del->num)
        parent->left=NULL;
        else
        parent->right=NULL;
        delete del;
    }
    else if(del->left==NULL||del->right==NULL) //case 2 one child 接一邊
    {
        //刪掉parent右邊的原node，再接回del的左child
        if(del->num > parent->num && del->left!=NULL) 
        {
            parent->right=del->left; 
        }
        //刪掉parent右邊的原node，再接回del的右child
        else if(del->num > parent->num && del->right!=NULL)
        {
            parent->right=del->right;
        }
        //刪掉parent左邊的原node，再接回del的左child
        else if(del->num < parent->num && del->left!=NULL)
        {
            parent->left=del->left;
        }
        //刪掉parent左邊的原node，再接回del的右child
        else if(del->num < parent->num && del->right!=NULL)
        {
            parent->left=del->right;
        }
        delete del;
    }
    else //case 3 two children
    {
        //找successor 並將兩者值互換，再把原來要刪的刪掉
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
void tree::trace_from_small(treenode* r) //用recursion的方式找，所以會有點小複雜
{
    treenode* temp; //record pointer

    //能往左就往左(左邊小)
    if(r->left!=NULL)
    trace_from_small(r->left);
    else //不能往左就紀錄
    {
        node[J]=r->num;
        J++;

        if(r->right!=NULL) //如果剛好可以往右，就先往右
        {
        trace_from_small(r->right);
        }
        return;
    }

    node[J]=r->num; //紀錄root
    J++;

    if(r->right!=NULL) //往right subtree走
    {
        trace_from_small(r->right);
    }
}
