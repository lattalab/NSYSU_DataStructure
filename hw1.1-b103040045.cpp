//Author: ���M�@ B103040045
//Date: sept. 6, 2022
//Purpose: N���]��}����{(N���_��)
#include <iostream>
#include <iomanip>
using namespace std;
//this function is for create the magic square
//�Ѽ�n �N�� �ĴX���]��}
void magic(int n) 
{
    //1���]��}�u��1�Ӥw �i��������
    if(n==1) 
    {
        cout<<" 1"<<endl<<endl;
        return; 
    }
    //�إ߰ʺA�G���}�C:
    //�@�ӫ��Ъ����� ���V ��ƫ��Ъ��@���}�C
    //�o�Ǥ@���}�C�A ���� ��ƪ��@���}�C
    int **array2D = new int* [n];
    for(int i=0;i<n;i++)
    array2D[i]=new int [n] (); 

    int i=0,j=n/2,k=1; //i represent row , j represent col , k �N�� �n�񪺼Ʀr
    int temp_i,temp_j; //�s��ثe��m���ܼ�
    array2D[i][j]=k; //�Ĥ@�C������ 1
    
    k++; //k�ܦ�2 
    while(k <= n*n) //k�̤j��n*n �W�L���A�~��
    {
    //����k-1����m
    temp_i=i;
    temp_j=j;
    
    i--; //�ܬ��W�@�C
    j--; //�ܬ��e�@�� 
    if(i<0) //�W�L���(�S�����C)
    i=n-1; //�令�̫�@�C
    if(j<0)   //�W�L���(�S������)
    j=n-1; //�令�̫�@��
    if(array2D[i][j]!=0) //��m�w��L�A�n���bk-1���U��
    {
        i=temp_i+1; 
        j=temp_j;
    }
    array2D[i][j]=k; //��J�Ʀr
    k++; //���W����
    }
    //�L�X�]��}
    for(int row=0;row<n;row++) //�N��ĴX�C
    {
        for(int col=0;col<n;col++) //�N��ĴX��
        //setw(2)���F�ƪ��n��
        //setw() �w�q�biomanip �禡�w��
        {cout<<setw(2)<<array2D[row][col]<<" ";}
    cout<<endl; //�@�C�L�� �n����
    }

    //�ʺA�}�C�n�M��
    //�����ư}�C�M���A�A�M��ӫ��а}�C    
    for(int i=0;i<n;i++)
    {
        delete [] array2D[i];
    }
    delete array2D;
}
int main()
{
   //�q�Ĥ@���]��}�}�l�A�C�����W2�A����ĤE���]��}����
   //�j�鱱���ܼ�layer �N�� �ĴX��
    for(int layer=1;layer<=9;layer+=2)
    {
        switch(layer) //�����X�榡
        {
            case 1:
            cout<<"�@���]��}�p�U:\n";
            break;
            case 3:
            cout<<"�T���]��}�p�U:\n";
            break;
            case 5:
            cout<<"�����]��}�p�U:\n";
            break;
            case 7:
            cout<<"�C���]��}�p�U:\n";
            break;
            case 9:
            cout<<"�E���]��}�p�U:\n";
            break;
        }
        magic(layer); //call function
        cout<<endl; 
    }
    return 0;
}