
#include <iostream.h>
#include <conio.h>
class student
{	protected:
		int rno;
	public:
		void get_no(int);
		void put_no(void);
};
void student::get_no(int a)
{
	rno=a;
}
void student::put_no(void)
{
	cout<<"Roll Number :"<<rno<<endl;
}

class test:public student
{
	protected:
		float sub1,sub2;
	public:
		void get_marks(float,float);
		void put_marks(void);
};
void test::get_marks(float x,float y)
{      sub1=x;  sub2=y;   }
void test::put_marks()
{
	cout<<"Marks in Sub1 ="<<sub1<<endl;
	cout<<"Marks in Sub2 ="<<sub2<<endl;
}
class result:public test
{
	float total;
public:
	void display(void);
};
void result::display(void)
{
	total = sub1 + sub2;
	put_no();
	put_marks();
	cout<<"Total = "<<total<<endl;
};
int main()
{
	clrscr();
	result student1;
	student1.get_no(11);
	student1.get_marks(75.0,59.6);
	student1.display();
	cout<<endl<<endl;
	cout<<sizeof(student1);
	getch();
	return 0;
}

