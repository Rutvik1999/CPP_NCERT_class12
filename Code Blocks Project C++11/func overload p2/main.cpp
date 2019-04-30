#include <iostream>

using namespace std;
int vol(int a){return a*a*a;}
double vol(double r,int s){return 3.14*r*r*s;}
long vol(long l,int b, int h){return l*b*h;}
void main()
{
    float a,b,c;
    cin>>a>>b>>c;
    cout<<"1 para"<<vol(a)<<endl;
    cout<<"2 para"<<vol(a,b)<<endl;
    cout<<"3 para"<<vol(a,b,c)<<endl;


}

long sq(int a)
{
    cout<<"Long return type with int parameter "<<endl;
    return a;

}

