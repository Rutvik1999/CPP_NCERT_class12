#include <iostream>

using namespace std;

 void prn(int x)
 {
char c = '#';
         for(int i =0 ; i<x ;i++)
         cout<<c;

 }
 void pnr(char ch,int x)
 {
     for(int i = 0;i<x;i++)
        cout<<ch;
 }
 int main()
 {  char ch;
 int x;
     cin>>ch>>x;
     pnr(ch,x);
 }
