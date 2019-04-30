#include <iostream>

using namespace std;

class product
{
    int number;
    float cost;
public:
    void getdata(int a,float b);
    void displaydata();
};
void product :: getdata(int a, float b)
{number=a;
cost=b;
}
void product :: displaydata()
{
    cout<<"\n Product Number is :"<<number;
    cout<<"\n Product cost is :"<<cost;
}
product i;

int main()
{
    system("cls");
    int a;float b;
    cin>>a>>b;
    i.getdata(a,b);
    i.displaydata();
    return 0;}
