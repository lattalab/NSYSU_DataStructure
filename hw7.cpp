//Author�G���M�@ B103040045
//Date�GOct. 27, 2022
//Purpose�G�m�ߦU�رƧǺt��k�A�è̾ڤ��P�ƶq������ݬݺt��k���Ĳv
#include <iostream>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <iomanip>
using namespace std;
void insertion_sort(int *arr,int size) //parameter: �n�ƧǪ��}�C�H�ΰ}�C�j�p
{
    int temp,j,i; //temp�Ȧs��ƪ��ܼơBi,j�]�j��
    for(i=1;i<size;i++) //�q1�}�l
    {
        temp=arr[i]; //�����}�l������
        for(j=i-1;j>=0;j--) //��n�ӷ|��n-1��
        {
            if(arr[j]>temp) //�e��������j���N����᭱
            arr[j+1]=arr[j];
            else
            break;
        }
        arr[j+1]=temp; //�N�ӭȮt�i�h
    }
}

void Merge(int *Array, int front, int mid, int end) //�Ѽ�:�n�X�骺�}�C�B�}�Y�B�����B����
{
    int n1=mid-front+1; //front~mid������
    int n2=end-(mid+1)+1; //mid+1~end������
    //�ʺA�ŧi
    int *leftsub= new int [n1]; 
    int *rightsub =new int [n2];
    // ��array[front]~array[mid]��i leftsub[]
    // ��array[mid+1]~array[end]��i rightsub[]
    for(int k=0;k<n1;k++)
    leftsub[k]=Array[front+k];
    for(int j=0;j<n2;j++)
    rightsub[j]=Array[j+mid+1];

    int idxLeft = 0, idxRight = 0, k=front; //���l�}�C��k�l�}�C���_�l��m �� �}�Y
    // Merge two temp arrays back into arr[head..tail]
    while(idxLeft < n1 && idxRight < n2) //����W�L�}�C�����
    {
        //�N����p����i�h
        if(leftsub[idxLeft] <= rightsub[idxRight])
        {
        Array[k] = leftsub[idxLeft];
        idxLeft++; //�ʫ��w
        }
        else
        {
        Array[k] = rightsub[idxRight];
        idxRight++; //�ʫ��w
        }
        k++; //��m����
    }

    //Copy the remaing elements into arr[], if leftsub[] haven't finished scanning
    while(idxLeft < n1)
    {
    Array[k] = leftsub[idxLeft];
    //�ʫ��w
    idxLeft++;
    k++; 
    }
    //Copy the remaing elements into arr[], if rightsub[] haven't finished scanning
    while(idxRight < n2)
    {
    Array[k] = rightsub[idxRight];
    //�ʫ��w
    idxRight++;
    k++; 
    }
    //�ʺA�ŧi�n�R��
    delete [] leftsub; 
    delete [] rightsub;
}
void Merge_Sort(int *array, int front, int end) //�Ѽ�:�n�ƧǪ��}�C�B�}�Y�򵲧���m
{
    // front�Pend���x�}�d��
    //PS:�Q��recursion��@
    if (front < end) {                   // ��ܥثe���x�}�d��O���Ī�
        int mid = (front+end)/2;         // mid�O��̪�������m
        Merge_Sort(array, front, mid);    // divide�x�}���e�b�qsubarray
        Merge_Sort(array, mid+1, end);    // divide�x�}����b�qsubarray
        Merge(array, front, mid, end);   // �N���subarray�����, �æX�֥X�Ƨǫ᪺�x�}(conquer)
    }
}

void swap(int *a, int *b) //�Ѽ�:�n�洫����ӭȡA�ݥ�call by reference(or pointer)�A���M�S���洫���ĪG
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int Partition(int *arr, int front, int end) //�Ѽ�:�@�Ӱ}�C�B�}�Y�򵲧���m
{
    int pivot = arr[end]; //�N�̥k��]����ǭ�
    int i = front -1; //i�]�w�̥���-1
    for (int j = front; j < end; j++)  //�]��pivot���e
    {
        if (arr[j] < pivot) { //������p���N�N�����쥪�䪺subarray
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i], &arr[end]); //�Npivot���줤��
    return i; //�o��U�@�ӭn�]��pivot�ȡA�æ^��
}
void Quick_Sort(int *arr, int front, int end) //parameter: �n�ƧǪ��}�C�H�ΰ}�C�j�p
{
    //PS:use recursion to complete quick sort
    if (front < end) //���Ī��}�C�d��
    {
        int pivot = Partition(arr, front, end); //����function�o�쪺pivot��m
        Quick_Sort(arr, front, pivot - 1); //leftsub��quick sort
        Quick_Sort(arr, pivot + 1, end); //rightsub��quick sort
    }
}

int compare(const void *a, const void *b)//��function�O qsort �һݪ�����禡(�ھ�qsort�w�q)
{
      int c = *(int *)a;
      int d = *(int *)b;
      if(c < d) {return -1;}               //�Ǧ^ -1 �N�� a < b
      else if (c == d) 
      return 0;                             //�Ǧ^   0 �N�� a = b
      else 
      return 1;                          //�Ǧ^  1 �N�� a>b
}
int main()
{
    //part 1: ���պt��k�\��ñNoutput�g���ɮ׸�
    ifstream in; //input file
    in.open("input.txt");
    int num; //�����`�@���X�ӼƦr
    in>>num; //read
    //dynamic allocate
    int *arr =new int [num];
    //read number from input file
    for(int i=0;i<num;i++)
    {
        in>>arr[i];
    }
    in.close(); //close
    //output file:
    ofstream a("outputA.txt"),b("outputB.txt"),c("outputC.txt"),d("outputD.txt"),e("outputE.txt");
    a<<"Insertion Sort\n"; b<<"Merge Sort\n"; c<<"Quick Sort\n"; d<<"C qsort()\n"; e<<"C++ sort()\n";
    //do insertion
    insertion_sort(arr,num);
    for(int i=0;i<num;i++)
    a<<arr[i]<<"\n";
    a.close();

    //do merge sort
    Merge_Sort(arr,0,num-1);
    for(int i=0;i<num;i++)
    b<<arr[i]<<"\n";
    b.close();

    //do quick sort
    Quick_Sort(arr,0,num-1);
    for(int i=0;i<num;i++)
    c<<arr[i]<<"\n";
    c.close();

    //do qsort(define in <cstdlib>)
    qsort(arr,num,sizeof(arr[0]),compare);
    for(int i=0;i<num;i++)
    d<<arr[i]<<"\n";
    d.close();

    //do sort(define in algorithm)
    sort(arr,arr+num);
    for(int i=0;i<num;i++)
    e<<arr[i]<<"\n";
    e.close();
    //dynamic allocate need to delete if arr doesn't need anymore
    delete [] arr;

    //part 2: ���դj�q��ƨìݬݦU�رƧǺt��k������ɶ�
    clock_t start,stop; //��ɶ��Ϊ�
    double duration; //�n�s �ɶ��t

    //�U���O���o�X����ɶ����L�{�A�Hin1.txt����
    ifstream in1("in1.txt");
    //in2("in2.txt"),in3("in3.txt"),in4("in4.txt"),in5("in5.txt"),in6("in6.txt"),in7("in7.txt"),in8("in8.txt"),in9("in9.txt"),in10("in10.txt");
    //are using the same method
    in1>>num; //�����`�@���X�ӼƦr
    //dynamic allocate
    int *array =new int [num];
    //read number from input file
    for(int i=0;i<num;i++)
    in1>>array[i];
    //close after we needn't use it anymore
    in1.close();
    
    //get time with using insertion
    start=(double)clock()/CLOCKS_PER_SEC;
    insertion_sort(array,num);
    stop=(double)clock()/CLOCKS_PER_SEC;
    duration=stop-start;
    //����p���I�ĥ|��
    cout<<"insertion: "<<showpoint<<setprecision(5)<<duration<<endl;

    start=clock();
    Merge_Sort(array,0,num-1);
    stop=clock();
    duration=(stop-start)/(double)CLOCKS_PER_SEC;
    cout<<"Merge: "<<showpoint<<setprecision(5)<<duration<<endl;

    start=clock();
    Quick_Sort(array,0,num-1);
    stop=clock();
    duration=(stop-start)/(double) CLOCKS_PER_SEC;
    cout<<"Quick: "<<showpoint<<setprecision(5)<<duration<<endl;

    start=clock();
    qsort(array,num,sizeof(array[0]),compare);
    stop=clock();
    duration=(stop-start)/(double)CLOCKS_PER_SEC;
    cout<<"qsort: "<<showpoint<<setprecision(5)<<duration<<endl;

    start=clock();
    sort(array,array+num);
    stop=clock();
    duration=(stop-start)/(double)CLOCKS_PER_SEC;
    cout<<"sort: "<<showpoint<<setprecision(5)<<duration<<endl;

    //�Χ��R��
    delete [] array;
    return 0;
}   