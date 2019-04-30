#include<fstream.h>
#include<stdio.h>
#include<string.h>

class stu{
	int rno;
	char name[20];
	float mks;
	char grade;
public:
	void getdata();
	void display();
};
void stu::getdata()
{
	char ch;
	cout<<"enter rno:";
	cin>>rno;
	cin.get(ch); //clr the buffer
	cout<<"enter name ";
	gets(name);
	cout<<"enter mks ";cin>>mks;
	cout<<"enter grade ";cin>>grade;
}
void stu::display()
{	cout<<"\t"<<name<<"\t"<<mks<<"\t"<<grade<<endl; }
void main(){
	stu s[5];
	fstream filin;
	filin.open("studetails ",ios::in|ios::out|ios::binary);
	cout<<" enter the details of student "<<endl;
	for(int i=0;i<3;i++)
	{	s[i].getdata();
		filin.write((char*)&s[i], sizeof(s[i]));
	}
	filin.seekg(0);
	cout<<"details of students is "<<endl;
	for(i=0;i<3;i++)
		{
			 filin.read((char*)&s[i],sizeof(s[i]));
			s[i].display();
		}
		filin.close();
	}
