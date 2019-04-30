#include <iostream.h>
using namespace std;


    double sq(float a);
    long sq(int a);
    void main()

{
    float a;
    int b;
    cout<<"enter a & b";
    cin>>a>>b;
    cout<<sq(a)<<endl;
    cout<<sq(b)<<endl;
}
double sq(float a)
{
    cout<<"This func. call is double sq. with double para...."<<endl;
    return a*a;

}
long sq(int a)
{
    cout<<"long return type with int parameter"<<endl;

    return a;
}
