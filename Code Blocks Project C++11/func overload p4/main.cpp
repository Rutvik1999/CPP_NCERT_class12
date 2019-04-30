#include <iostream>


using namespace std;
int sum(int a[],int n);
int sum(int a);
void main()
{
    int n,result;
        int a[100];
        cout<<"how many values you want to add as an argument ";
        cin>>n;
        for(int i=0;i<n;i++)
        {
          cin>>a[i];
        }
        cout<<"Sum of entered values is: "<<sum(a,n)<<endl;
        cout<<"square of entered values is: "<<sum(n)<<endl;

}
int sum(int a[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
        sum = sum + a[i];
    return sum;
}
int sum(int a){return a*a;}

