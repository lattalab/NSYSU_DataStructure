#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <ctime>
using namespace std;
//this .cpp file is used to create 大量的資料(亂數資料)
int main()
{
    //生10個檔
    ofstream in1("in1.txt"),in2("in2.txt"),in3("in3.txt"),in4("in4.txt"),in5("in5.txt"),in6("in6.txt"),in7("in7.txt"),in8("in8.txt"),in9("in9.txt"),in10("in10.txt");
    srand(time(NULL));
    in1<<"100\n";
    for(int i=0;i<100;i++)
    in1<<rand()%INT16_MAX+1<<"\n";
    in1.close();

    in2<<"500\n";
    for(int i=0;i<500;i++)
    in2<<rand()%INT16_MAX+1<<"\n";
    in2.close();

    in3<<"1000\n";
    for(int i=0;i<1000;i++)
    in3<<rand()%INT16_MAX+1<<"\n";
    in3.close();

    in4<<"5000\n";
    for(int i=0;i<5000;i++)
    in4<<rand()%INT16_MAX+1<<"\n";
    in4.close();

    in5<<"10000\n";
    for(int i=0;i<10000;i++)
    in5<<rand()%INT16_MAX+1<<"\n";
    in5.close();

    in6<<"50000\n";
    for(int i=0;i<50000;i++)
    in6<<rand()%INT16_MAX+1<<"\n";
    in6.close();

    in7<<"100000\n";
    for(int i=0;i<100000;i++)
    in7<<rand()%INT16_MAX+1<<"\n";
    in7.close();

    in8<<"500000\n";
    for(int i=0;i<500000;i++)
    in8<<rand()%INT16_MAX+1<<"\n";
    in8.close();

    in9<<"1000000\n";
    for(int i=0;i<1000000;i++)
    in9<<rand()%INT16_MAX+1<<"\n";
    in9.close();

    in10<<"5000000\n";
    for(int i=0;i<5000000;i++)
    in10<<rand()%INT16_MAX+1<<"\n";
    in10.close();
    return 0;
}