#include <iostream.h>
#include <conio.h>
#include<process.h>
class stu{
int ron;
char name[20];
float marks;
char grade;
public:
void readstudent();    //mutator
void dispstudent();    //mutator
int getrno()    //accessor
{
return rno;
}
float getmarks()  //accessor
{

    return marks()
}
void calcgrade()  //mutator
{
    if(marks>=90) grade='A';
    else if(marks>=75)grade='B';
    else if(marks>=60)grade='C';
    else if(marks>=60)grade='D';
    else grade = 'E';
    }
};
void stu::readstudent(){
cout<<"\nEnter rno : ";
cin>>rno;
cout<<"\nEnter name : ";gets(name);
cout<<"\nEnter marks : ";
cin>>marks;
}
void stu::dispstudent(){
calcgrade();
cout<<"Roll no : "<<rno<<endl;
cout<<"Name : "<<name<<endl;
cout<<"Marks : "<<marks<<endl;
cout<<"Grade : "<<grade<<endl;
system("pause");
}
int main()
{
    system("cls");
    stu XIIZ[5];
    for(int i = 0;i<5;i++)
    {
        cout<<"Enter details of student:"<<i+1;
        XIIB[i].readstudent();
    }

    int choice,rno,pos=1,highmarks=0;

    do
    {
        system ("cls")
cout<<"n\n***Main Menu***\n";
cout<<"\n1.Specific student;
cout<<"\nTopper";
cout<<"\nExit";
cout<<"\n\nEnter choice:";
cin>>choice;
switch(choice)
{

    case 1:
        cout<,"Enter rno for sudentto see details";
    cin>>rono;
    for(i=0;i<10;i++)
{
    if(XIIZ[i].getrno()==rno) //accessor
     {
         XIIZ[i].dispstudent();
         break;
     }
    }
case 2:
    for(i=0;i<5;i++)
    {
        if(XIIZ[i].getmarks()>highmarks) //accessor
       {
           pos=1;
           highmarks=XIIZ[i].getmarks();
       }
       }
       XIIZ[pos].dispstudent();
       break;
case 3:
    exit(0);
    default:cout<<"Wrong Choice";
    break;
}}while(choice>=1&& choice<=3);
return 0; }
