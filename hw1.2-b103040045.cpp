//Author: ���M�@ B103040045
//Date: sept. 7, 2022
//Purpose: ��¥��ܼ�(ex.int)�䶥�h���i��o��overflow�A�]���Τ@���}�C�����ⶥ�h
#include <iostream>
#include <vector>
using namespace std;
int ptr; //���D���̶}�l�W�L��Ʀr�d���ܼ� (ex.01145 ��ptr�|����0)
//�ŧi�禡factorial�A�ت����ΰ}�C��X�U���h �ñq�@�����num��
//parameter: num �����ĴX���h���̲׼Ʀr
void factorial(int num); 
int main()
{
    int N; //�t�d���� �ϥΪ̿�J�ƻ� ���ܼ�
    //�]�i�঳�h�աA�G��vector�s��
    //vector�w�q�b �禡�w<vector>
    vector<int> data; 
    //��J���(��J�s�|�פ�)
   do
    {
    cin>>N;
    if(N!=0) //�s����J
    data.push_back(N);
    } while (N!=0); //�j����򪺱���O �S���J��s

    cout<<endl; //����A�ö}�l��X

    //�M��q�Ĥ@����J����ƶ}�l�A����J��̫��J�����
    //i�N��index
    for(int i=0;i<data.size();i++) 
    {
        ptr=1; //�@�}�l�@�w�O�Ӧ�� �A�]�����D�Ʀr�d�򪺷��������
        factorial(data[i]); //call function
        cout<<endl; //��X����n����A�ð���X�U�@�����G
    }
    return 0;
}
void factorial(int num)
{
    int digit[70]={0}; //�]�w���������}�C �ê�l�Ƭ��s
    //1!��1�A�����i�{�X��
    digit[0]=1; 
    cout<<"1!="<<digit[0]<<endl;

    //�q2!�}�l���O�L�X ����num!����
    for(int i=2;i<=num;i++)
    {
        cout<<i<<"!="; //��Xi!= (�Yi=3,�h�L�X3!=)

        //�]���w���W�� ���Ʀr�x�}�C�Ӧ�Ƴ����U�@��� (ex.�w��1!�A���ļƦr����2��2!)
        for(int index=0;index<70,ptr>index;index++) //���󬰤��i�W�X (�x�}��ɥH�Φ��ļƦr���)
        {
            digit[index]*=i;
        }
        //�i��
        for(int Index=0;Index<70,ptr>Index;Index++)
        {
            if(digit[Index]>=10) //�Y��ƭn����b0~9�����A�]���j��10�~�n�S�O���B�z
            {
                //�N�Ӧ��(digit[Index])�d�U�Ӧ�ơA��l�i��U�@���
                digit[Index+1]+=digit[Index]/10; 
                digit[Index]=digit[Index]%10;
                if(digit[ptr]!=0) //��ɦ��Ʀr�F�A�~�n����
                ptr++;
            }
        }
        //�Ʀr�n�q�j����ƨ���}�l�L (ex.14445 digit[0]�O5�Bdigit[ptr-1]�O1)
        for(int j=ptr-1;j>=0;j--) 
        {cout<<digit[j];}

        cout<<endl; 
    }
}