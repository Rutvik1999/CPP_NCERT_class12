#include <iostream>


using namespace std;

float si(long p,double n, float r);
float si(long p, int n = 8, float r = 12.0)
{
    cout << "P is " << p << "N is" << n << "R is" << r << endl;
    return (p * n * r);
}
void main()
{
    system("cls");
    double p,n,r;
    cout<<" Enter p,n,r "<<endl;
    cin>>p>>n>>r;
    cout<<" SI with default argument "<<si(p)<<endl<<endl;
    cout<<" Si with parameters :"<<si(p,n,r)<<endl;
}
float si(long p,int n,float r)
{
    cout<<" P is "<<p<<" N is "<<n<<" R is "<<r<<endl;
    return (p*n*r);

}
float si(long p,double n,float r)
{
    cout<<"P is "<<p<<"N is"<<n<<"R is"<<r<<endl;
    return (p*n*r);
}
