#include<iostream.h>
#include<conio.h>
//multilevel inheritance
class student{
protected
int rno;
public:
void get_no(int);
void put_no(void);
void student::get_no(int a){
rno=a;}
void student::put_no(void){
cout<<"Roll number:"<<rno<<endl;
class test:
public student{
protecterd float sub1,sub2;
public:
void get_marks(float,float);
void put_marks(void
};
void test::get_marks(float x,float y)
