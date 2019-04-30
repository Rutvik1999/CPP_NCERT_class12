#include <iostream>

using namespace std;
void display(char a[]);
void display(char b[],char a[]);
int main()
{
   char first[20],sec[20];
   cout<<"enter first string :";
   gets(first);
   cout<<"Enter second string :";
   gets(sec);
   system("cls");
   display("DPS \, Bopal");
   display(first,sec);
   return 0;

}
void display(char s[])
{
    cout<<s<<endl;
}
void display(char a[],char b[])
{
    cout<<a<<endl;
    cout<<b<<endl;
}
