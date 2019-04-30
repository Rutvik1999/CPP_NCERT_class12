#include<iostream.h>
#include<string.h>

class student
{
	int rno;
	public:

	int get_rno() {return rno;}
	void display()
	{cout<<"roll no = " <<rno;}
	 student()
	{rno = 5;}
};
class test : public student
{
       float mks;
       char name[20];
       public:
	    test(){ mks=20;};


