//Author： B103040045
//Date：Oct. 27, 2022
//Purpose：練習各種排序演算法，並依據不同數量的測資看看演算法的效率
#include <iostream>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <iomanip>
using namespace std;
void insertion_sort(int *arr,int size) //parameter: 要排序的陣列以及陣列大小
{
    int temp,j,i; //temp暫存資料的變數、i,j跑迴圈
    for(i=1;i<size;i++) //從1開始
    {
        temp=arr[i]; //紀錄開始的元素
        for(j=i-1;j>=0;j--) //第n個會比n-1次
        {
            if(arr[j]>temp) //前面有比較大的就移到後面
            arr[j+1]=arr[j];
            else
            break;
        }
        arr[j+1]=temp; //將該值差進去
    }
}

void Merge(int *Array, int front, int mid, int end) //參數:要合體的陣列、開頭、中間、結尾
{
    int n1=mid-front+1; //front~mid的長度
    int n2=end-(mid+1)+1; //mid+1~end的長度
    //動態宣告
    int *leftsub= new int [n1]; 
    int *rightsub =new int [n2];
    // 把array[front]~array[mid]放進 leftsub[]
    // 把array[mid+1]~array[end]放進 rightsub[]
    for(int k=0;k<n1;k++)
    leftsub[k]=Array[front+k];
    for(int j=0;j<n2;j++)
    rightsub[j]=Array[j+mid+1];

    int idxLeft = 0, idxRight = 0, k=front; //左子陣列跟右子陣列的起始位置 跟 開頭
    // Merge two temp arrays back into arr[head..tail]
    while(idxLeft < n1 && idxRight < n2) //不能超過陣列的邊界
    {
        //將比較小的放進去
        if(leftsub[idxLeft] <= rightsub[idxRight])
        {
        Array[k] = leftsub[idxLeft];
        idxLeft++; //動指針
        }
        else
        {
        Array[k] = rightsub[idxRight];
        idxRight++; //動指針
        }
        k++; //位置改變
    }

    //Copy the remaing elements into arr[], if leftsub[] haven't finished scanning
    while(idxLeft < n1)
    {
    Array[k] = leftsub[idxLeft];
    //動指針
    idxLeft++;
    k++; 
    }
    //Copy the remaing elements into arr[], if rightsub[] haven't finished scanning
    while(idxRight < n2)
    {
    Array[k] = rightsub[idxRight];
    //動指針
    idxRight++;
    k++; 
    }
    //動態宣告要刪除
    delete [] leftsub; 
    delete [] rightsub;
}
void Merge_Sort(int *array, int front, int end) //參數:要排序的陣列、開頭跟結束位置
{
    // front與end為矩陣範圍
    //PS:利用recursion實作
    if (front < end) {                   // 表示目前的矩陣範圍是有效的
        int mid = (front+end)/2;         // mid是兩者的中間位置
        Merge_Sort(array, front, mid);    // divide矩陣的前半段subarray
        Merge_Sort(array, mid+1, end);    // divide矩陣的後半段subarray
        Merge(array, front, mid, end);   // 將兩個subarray做比較, 並合併出排序後的矩陣(conquer)
    }
}

void swap(int *a, int *b) //參數:要交換的兩個值，需用call by reference(or pointer)，不然沒有交換的效果
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int Partition(int *arr, int front, int end) //參數:一個陣列、開頭跟結束位置
{
    int pivot = arr[end]; //將最右邊設為基準值
    int i = front -1; //i設定最左邊-1
    for (int j = front; j < end; j++)  //跑到pivot之前
    {
        if (arr[j] < pivot) { //有比較小的就將它換到左邊的subarray
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i], &arr[end]); //將pivot換到中間
    return i; //得到下一個要跑的pivot值，並回傳
}
void Quick_Sort(int *arr, int front, int end) //parameter: 要排序的陣列以及陣列大小
{
    //PS:use recursion to complete quick sort
    if (front < end) //有效的陣列範圍
    {
        int pivot = Partition(arr, front, end); //紀錄function得到的pivot位置
        Quick_Sort(arr, front, pivot - 1); //leftsub做quick sort
        Quick_Sort(arr, pivot + 1, end); //rightsub做quick sort
    }
}

int compare(const void *a, const void *b)//此function是 qsort 所需的比較函式(根據qsort定義)
{
      int c = *(int *)a;
      int d = *(int *)b;
      if(c < d) {return -1;}               //傳回 -1 代表 a < b
      else if (c == d) 
      return 0;                             //傳回   0 代表 a = b
      else 
      return 1;                          //傳回  1 代表 a>b
}
int main()
{
    //part 1: 測試演算法功能並將output寫到檔案裡
    ifstream in; //input file
    in.open("input.txt");
    int num; //紀錄總共有幾個數字
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

    //part 2: 測試大量資料並看看各種排序演算法的執行時間
    clock_t start,stop; //算時間用的
    double duration; //要存 時間差

    //下面是怎麼得出執行時間的過程，以in1.txt為例
    ifstream in1("in1.txt");
    //in2("in2.txt"),in3("in3.txt"),in4("in4.txt"),in5("in5.txt"),in6("in6.txt"),in7("in7.txt"),in8("in8.txt"),in9("in9.txt"),in10("in10.txt");
    //are using the same method
    in1>>num; //紀錄總共有幾個數字
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
    //取到小數點第四位
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

    //用完刪除
    delete [] array;
    return 0;
}   
