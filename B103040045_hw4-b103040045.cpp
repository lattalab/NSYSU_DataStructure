// Author�G���M�@ B103040045
//Date�G Sept. 21, 2022
// Purpose�G��recursion���覡�q�X�M�h��n*n�ѽL�����N�@�ո�
#include <iostream>
#include <iomanip>
using namespace std;
int step; //��B�ƪ��ܼ�

//recursion���ѽL��function
//parameter **a��ѽL(�H�G���}�C���) �BI��n����i�ȡBJ��n����j�ȡBn��ѽL�O �X���X
//�^��0�N���~�򨫡A�^��1�N�����F
bool sol(int **a,int I,int J,int n) 
{
    int temp_i=I,temp_j=J; //�Ȯɬ�����m���ܼơAtemp_i����I�Atemp_j����J
    bool temp=0; //�O���^�Ǩ禡�����L�� ���ܼơA�w�]���s
    a[I-1][J-1]=step; //�N�Ӧ�m�Ҫ�ܪ��ѽL��m�]���ӨB��
    if(step>=n*n) //���X����A�B�Ƴ̤j��n*n
    return 1;

    if(temp==1) //temp==1 ��� �w�����A�çi���o����recursion�i��������
        return 1;
    
    //�H�U����Ҭ�������k����W�L�ѽL���
    if(((temp_i-2)>=1)&&((temp_j+1)>=1)&&((temp_i-2)<=n)&&((temp_j+1)<=n))
    {   
        if(a[temp_i-2-1][temp_j+1-1]==0) //�Ӧ�m�S���Ȥ~��
        {
            step++; //�B�ƥ[�@
            temp=sol(a,temp_i-2,temp_j+1,n); //��recursion����U�@�B �æ^�ǭȵ�temp
            if(temp==1) //temp==1 �N���\���� �U���{�����ݭn����A���������o��function
            return 1;
        }
    }
    if(((temp_i-1)>=1)&&((temp_j+2)>=1)&&((temp_i-1)<=n)&&((temp_j+2)<=n))
    {
        if(a[temp_i-1-1][temp_j+2-1]==0) //�Ӧ�m�S���Ȥ~��
        {
            step++; //�B�ƥ[�@
            temp=sol(a,temp_i-1,temp_j+2,n); //��recursion����U�@�B �æ^�ǭȵ�temp
            if(temp==1) //temp==1 �N���\���� �U���{�����ݭn����A���������o��function
            return 1;
        }
    }
    if(((temp_i+1)>=1)&&((temp_j+2)>=1)&&((temp_i+1)<=n)&&((temp_j+2)<=n))
    {
        if(a[temp_i+1-1][temp_j+2-1]==0)  //�Ӧ�m�S���Ȥ~��
        {
            step++; //�B�ƥ[�@
            temp=sol(a,temp_i+1,temp_j+2,n); //��recursion����U�@�B �æ^�ǭȵ�temp
            if(temp==1) //temp==1 �N���\���� �U���{�����ݭn����A���������o��function
            return 1;
        }
    }
    if(((temp_i+2)>=1)&&((temp_j+1)>=1)&&((temp_i+2)<=n)&&((temp_j+1)<=n))
    {
        if(a[temp_i+2-1][temp_j+1-1]==0) //�Ӧ�m�S���Ȥ~��
        {
            step++; //�B�ƥ[�@
            temp=sol(a,temp_i+2,temp_j+1,n); //��recursion����U�@�B �æ^�ǭȵ�temp
            if(temp==1) //temp==1 �N���\���� �U���{�����ݭn����A���������o��function
            return 1;
        }
    }
    if(((temp_i+2)>=1)&&((temp_j-1)>=1)&&((temp_i+2)<=n)&&((temp_j-1)<=n))
    {
        if(a[temp_i+2-1][temp_j-1-1]==0) //�Ӧ�m�S���Ȥ~��
        {
           step++; //�B�ƥ[�@
           temp=sol(a,temp_i+2,temp_j-1,n); //��recursion����U�@�B �æ^�ǭȵ�temp
           if(temp==1) //temp==1 �N���\���� �U���{�����ݭn����A���������o��function
            return 1;
        }
    }
    if(((temp_i+1)>=1)&&((temp_j-2)>=1)&&((temp_i+1)<=n)&&((temp_j-2)<=n))
    {
        if(a[temp_i+1-1][temp_j-2-1]==0) //�Ӧ�m�S���Ȥ~��
        {
            step++; //�B�ƥ[�@
            temp=sol(a,temp_i+1,temp_j-2,n);  //��recursion����U�@�B �æ^�ǭȵ�temp
            if(temp==1) //temp==1 �N���\���� �U���{�����ݭn����A���������o��function
            return 1;
        }
    }
    if(((temp_i-1)>=1)&&((temp_j-2)>=1)&&((temp_i-1)<=n)&&((temp_j-2)<=n))
    { 
        if(a[temp_i-1-1][temp_j-2-1]==0) //�Ӧ�m�S���Ȥ~��
        {
            step++; //�B�ƥ[�@
            temp=sol(a,temp_i-1,temp_j-2,n); //��recursion����U�@�B �æ^�ǭȵ�temp
            if(temp==1) //temp==1 �N���\���� �U���{�����ݭn����A���������o��function
            return 1;
        }
    }
    if(((temp_i-2)>=1)&&((temp_j-1)>=1)&&((temp_i-2)<=n)&&((temp_j-1)<=n))
    {
        if(a[temp_i-2-1][temp_j-1-1]==0) //�Ӧ�m�S���Ȥ~��
        {
            step++; //�B�ƥ[�@
            temp=sol(a,temp_i-2,temp_j-1,n); //��recursion����U�@�B �æ^�ǭȵ�temp
            if(temp==1) //temp==1 �N���\���� �U���{�����ݭn����A���������o��function
            return 1; 
        }
    }
    //����o�N��S���i��
    a[temp_i-1][temp_j-1]=0; //�ӴѽL��m�אּ�s �÷ǳưh�^�h
    step--; //�B�ƴ�@
    return 0; //�����^�ǹs�A�n�~��
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
            arr2D[j]=new int [i](); //�إߪ��P�ɶ��K�N�G���}�C�k�s
        }
        step=1; //�N�B�ƪ�l�Ƭ� 1
        sol(arr2D,1,1,i); //�]recursion function
        cout<<"n = "<<i<<" :"<<endl; //output
        //�p�G�������Ĥ@�Ӧ�m�����Ʀr�A�Ϥ��h���s
       if(arr2D[0][0]) //���\���������p
        {
          for(int k=0;k<i;k++) //�L�X�ѽL
         {
            for(int m=0;m<i;m++)
            cout<<setw(2)<<arr2D[k][m]<<" ";
            //setw()�b�禡�w<iomanip>�i���A�b�o�̥γ~���Ũ��A����n��X���Ʀr�n����b�o��椺(�a�k)
            cout<<endl;
         }
         cout<<endl;  
        }
        else //�S���������p
        cout<<"no solution."<<endl<<endl;
         
        for(int l=0;l<i;l++) //�Χ��ʺA�}�C�n�R��
        {
            delete [] arr2D[l];
        }
        delete [] arr2D;

    }
    return 0;
}