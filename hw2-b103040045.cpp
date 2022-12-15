//Author�G���M�@ B103040045
//Date�GSept. 13, 2022
//Purpose�G�Q��C++��class�إߤ@�Ӷ��X�A�åi�����p���B�涰�B�t���B�]�t�B�ݩ󵥤��عB��
#include <iostream>
using namespace std;
//�s�@���X��class
class set{
    private:
    char array[256]; //�i�x�s��ƪ�char array
    public:
    set operator + (set &obj) //�p���B�� �A�ѼƬO�t�@��set �YA+B��B (A�O�ۤv�Aarray������)
    {
        bool temp[256]={0}; //�Ψӿ��ѬO�_�w�X�{��ASCII�X�� ���L�}�C
        for(int i=0;i<256;i++) //����A���X�����r���O�_�w�X�{���j��
        {
            if(array[i]!='\0')  //�S�J�쵲���N�@����
            {
            int index =static_cast<int>(array[i]); //�N�r���ন�Ʀr(�d��0~255)�A�æs��index��
            temp[index]=1; //�N�Ӧr�����������L�}�C ������1 ��w�X�{
            }
            //EX. a(char) �ܦ� 97(int) �Atemp[97]=1�Y�N�� 97�ҹ������r���w�X�{
            else //���쵲���B�Y�J��'\0'����
            break;
        }
        for(int i=0;i<256;i++) //����B���X�����r���O�_�w�X�{���j��
        {
            if(obj.array[i]!='\0') //�S�J�쵲���N�@����
            {
            int index =static_cast<int>(obj.array[i]); //�N�r���ন�Ʀr(�d��0~255)�A�æs��index��
            temp[index]=1; //�N�Ӧr�����������L�}�C ������1 ��w�X�{
            }
            else //���쵲���B�Y�J��'\0'����
            break;
        }
        //�W���N�䧹�Ҧ�A��B�ҥX�{������

        set back; //�إߤ@�ӭn�^�Ǫ����X back
        int count=0; //��@array��index��
        for(int i=0;i<256;i++) //�]temp���o�ӥ��L�}�C�ݥL����
        {
            if(temp[i]) //temp[i]=1�i�J����
            back.array[count++]=static_cast<char>(i); 
            //�Ni�ন�r���æs�iback���r���}�C��
            //�t�~[count++]������ �@�}�l�Oback.array[count] = static_cast<char>(i)�A����count+=1
            //EX. temp[97]=1�Y�N�� 97�ҹ������r���w�X�{�A97(int) �ܦ�a(char) �A�A�s�J�r���}�C
        }
        back.array[count]='\0';  //�����n��'\0'
        return back; //�^���p����set
    }
    set operator * (set &obj) //�涰�B�� �A�ѼƬO�t�@��set �YA*B��B (A�O�ۤv�Aarray������)
    {
        bool t1[256]={0},t2[256]={0}; //�Ψӿ��ѬO�_�w�X�{��ASCII�X�� ���L�}�C�A�@�ӰOA �@�ӰOB
        for(int i=0;i<256;i++) //����A���X�����r���O�_�w�X�{���j��
        {
            if(array[i]!='\0') //�S�J�쵲���N�@����
            {
            int index =static_cast<int>(array[i]); //�N�r���ন�Ʀr(�d��0~255)�A�æs��index��
            t1[index]=1; //�N�Ӧr�����������L�}�C ������1 ��w�X�{
            }
            else  //���쵲���B�Y�J��'\0'����
            break;
        }
        for(int i=0;i<256;i++) //����B���X�����r���O�_�w�X�{���j��
        {
            if(obj.array[i]!='\0') //�S�J�쵲���N�@����
            {
            int index =static_cast<int>(obj.array[i]);  //�N�r���ন�Ʀr(�d��0~255)�A�æs��index��
            t2[index]=1; //�N�Ӧr�����������L�}�C ������1 ��w�X�{
            }
            else //���쵲���B�Y�J��'\0'����
            break;
        }
        set back; //�إߤ@�ӭn�^�Ǫ����X back
        int count=0;  //��@array��index��
        for(int j=0;j<256;j++) //�]t1&t2���o�ӥ��L�}�C�ݥL����
        {
            if(t1[j]&&t2[j]) //A��B���X���r���ҥX�{�~�n��iback��array
            {
            back.array[count++]=static_cast<char>(j); //�Nj�ন�r���æs�iback���r���}�C��
            }
        }
        back.array[count]='\0'; //�����n��'\0'
        return back; //�^�ǥ涰��set
    }
    set operator - (set &obj) //�t���B�� �A�ѼƬO�t�@��set �YA-B��B (A�O�ۤv�Aarray������)
    {
        bool t1[256]={0},t2[256]={0}; //�Ψӿ��ѬO�_�w�X�{��ASCII�X�� ���L�}�C�A�@�ӰOA �@�ӰOB
        for(int i=0;i<256;i++) //����A���X�����r���O�_�w�X�{���j��
        {
            if(array[i]!='\0') //�S�J�쵲���N�@����
            {
            int index =static_cast<int>(array[i]); //�N�r���ন�Ʀr(�d��0~255)�A�æs��index��
            t1[index]=1; //�N�Ӧr�����������L�}�C ������1 ��w�X�{
            }
            else //���쵲���B�Y�J��'\0'����
            break;
        }
        for(int i=0;i<256;i++) //����B���X�����r���O�_�w�X�{���j��
        {
            if(obj.array[i]!='\0') //�S�J�쵲���N�@����
            {
            int index =static_cast<int>(obj.array[i]);  //�N�r���ন�Ʀr(�d��0~255)�A�æs��index��
            t2[index]=1; //�N�Ӧr�����������L�}�C ������1 ��w�X�{
            }
            else //���쵲���B�Y�J��'\0'����
            break;
        }
        set back; //�إߤ@�ӭn�^�Ǫ����X back
        int count=0; //��@array��index��
        for(int j=0;j<256;j++) //�]t1&t2���o�ӥ��L�}�C�ݥL����
        {
            if(t1[j]&&t2[j]==0) //A���X�n����B���X������ �Y�d�U A����B�S�� 
            {
            back.array[count++]=static_cast<char>(j); //�Nj�ন�r���æs�iback���r���}�C��
            }
        }
        back.array[count]='\0'; //�����n��'\0'
        return back; //�^�ǥ涰��set
    }
    bool operator >= (set &obj) //�]�t�B�� �A�ѼƬO�t�@��set �YA>=B��B (A�O�ۤv�Aarray������)
    {
        bool T=1; //���]�쥻����
        bool t1[256]={0},t2[256]={0}; //�Ψӿ��ѬO�_�w�X�{��ASCII�X�� ���L�}�C�A�@�ӰOA �@�ӰOB
        for(int i=0;i<256;i++)  //����A���X�����r���O�_�w�X�{���j��
        {
            if(array[i]!='\0') //�S�J�쵲���N�@����
            {
            int index =static_cast<int>(array[i]);  //�N�r���ন�Ʀr(�d��0~255)�A�æs��index��
            t1[index]=1; //�N�Ӧr�����������L�}�C ������1 ��w�X�{
            }
            else //���쵲���B�Y�J��'\0'����
            break;
        }
        for(int i=0;i<256;i++) //����B���X�����r���O�_�w�X�{���j��
        {
            if(obj.array[i]!='\0') //�S�J�쵲���N�@����
            {
            int index =static_cast<int>(obj.array[i]);  //�N�r���ন�Ʀr(�d��0~255)�A�æs��index��
            t2[index]=1; //�N�Ӧr�����������L�}�C ������1 ��w�X�{
            }
            else //���쵲���B�Y�J��'\0'����
            break;
        }
        for(int j=0;j<256;j++) //�]t1&t2���o�ӥ��L�}�C�ݥL����
        {
            if(t2[j]&&t1[j]==0) //A�]�tB �N��A�֦��Ҧ�B������ ����bB�s�b���r���o�bA���s�b �N������
            T=0; // set T to 0
        }
        return T; //�^�ǥ��L��
    }
    bool belong (char ch) //�ˬd�r��(�Y�Ѽ�ch) �O�_�b ���X�� �i���
    {
        for(int i=0;i<256;i++) //�����]�r���}�C
        {
            if(array[i]==ch) //�����N�^��1
            return 1;
            if(array[i]=='\0') //�J�쵲�����X�j��
            break;
        }
       
        return 0; //�S�����~�|����o��æ^��1
    }
    void input() //set����J�禡
    {
        char str[80]; //�]�D�ػ� �r����J���W�L80 �]���N�r���}�C�]��80
        cin.getline(str,80); //getline�i�s' '
        bool temp[256]={0}; //�����w�X�{�r����bool array
        int i=0; //�]while�j�骺�ܼ�
        while(str[i]!='\0') //�٨S�쵲�����e���n�~��
        {
            int index=static_cast<int>(str[i]); //�N�r���ন�Ʀr(�d��0~255)�A�æs��index��
            temp[index]=1; //�N�Ӧr�����������L�}�C ������1 ��w�X�{
            i++; //���W�A�ǳƶ}�l�U���j��
        }
        int arr_index=0; //���array��index���ܼ�
        for(int j=0;j<256;j++) //�]���L�}�C
        {
            if(temp[j]) //temp[j]=1�i�J �B�N����J�o�Ӧr
            array[arr_index++]=static_cast<char>(j); //�Nj�ন�r���æs�i�r���}�C��
            //�o�˰��O�ҭ��ƿ�J���r���u�X�{�@�� �B �i�H����ASCII�����Ǳ�
        }
        array[arr_index]='\0'; //������'\0'
    }
    friend ostream& operator<< (ostream& out,set &obj); //ostream��operator overloading�A�ѼƤ��O��ostream���X��set
};

ostream& operator<< (ostream& out,set &obj)
{
    out<<"{"<<obj.array<<"}"<<endl; //�ΩT�w�榡��X
    return out; //�̫ᶷ�^��ostream���ܼ�
}
int main()
{
    int N; //�s �|���X�ո�ƪ��ܼ�
    cin>>N; //��J
    char discard=cin.get(); //'\n'�nŪ���A���M�|�v�T���᪺�{�� �s��discard��
    //�إ߰ʺA�}�C���O�s�U���ܼ�
    set *test_A=new set [N],*test_B=new set [N],*test_C=new set [N],*test_D=new set [N],*test_E=new set [N];
    char ch[20]; //�H�r���}�C�s�r���A�̦h20�ո��
    int time=0; //�]�j��Ϊ��ܼ�
    while(time<N) //��JN�ժ��j��
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

        if(test_A[time].belong(ch[time])) // �r���O�_�b���XA�̭��i��� -�ݩ�
        cout<<"\'"<<ch[time]<<"\' is in A"<<endl;
        else
        cout<<"\'"<<ch[time]<<"\' is not in A"<<endl;

        if(test_B[time].belong(ch[time])) // �r���O�_�b���XB�̭��i��� -�ݩ�
        cout<<"\'"<<ch[time]<<"\' is in B"<<endl;
        else
        cout<<"\'"<<ch[time]<<"\' is not in B"<<endl;

        time++; //increment
        cout<<endl;
    }
    //�R���ʺA�}�C
    delete [] test_A; 
    delete [] test_B;
    delete [] test_C;
    delete [] test_D;
    delete [] test_E;
    return 0;
}