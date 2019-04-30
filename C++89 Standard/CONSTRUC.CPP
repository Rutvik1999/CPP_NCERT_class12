#include<conio.h>  //Multiple inheritance 
#include<iostream.h>
class A {
	 protected:
		   int a ;
	 public:
		   int get_a(int);
	 };
class B {
	  protected:
		    int b;
	  public:
		void get_b(int);
	};

class C : public A,public B

{ public:
void display(void);
};
int A::get_a(int x)
{a=x;
return a;}
void B :: get_b(int y)
{
cout<<"a = "<<a<<endl;
cout<<"b = "<<b<<endl;
cout<<"a*b = "<<a*b<<endl;
}
int main()
{
system("cls");
C c;
c.get_b(10);
c.get_b(20);
c.display();
cout<<endl<<"size of C"<<sizeof(c);
getch();
return 0;
}