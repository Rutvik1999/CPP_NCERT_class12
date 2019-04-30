#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#include<iomanip.h>

class inv
{
	char name[20];
	int code;
	float cost;

	public:

	void getdata(void)
		{
		  cout<<"Enter Name";
		  gets(name);
		  cout<<"Enter Code";
		  cin>>code;
		  cout<<"Enter Cost";
		  cin>>cost;
		}
	void putdata(void)
		{
		  cout<<setw(15)<<name<<setw(10)<<code<<setw(10)<<setprecision(2)<<cost<<endl;
		}
};

void main()
{
	inv item;
	fstream finout;

	finout.open("stack",ios::in|ios::out|ios::ate|ios::binary);
	cout<<"contents of file are : \n";

	item.getdata();

	finout.write((char*)&item,sizeof(item));
	clrscr();
	finout.seekg(0);
	finout.read((char*)&item,sizeof(item));
	item.putdata();
	finout.close();
}