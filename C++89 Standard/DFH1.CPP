#include <fstream.h>

void main()
 {
	ofstream fout;
	fout.open("stu.dat",ios::app);
	int rno; float mks; char ch = 'y';
		while(ch=='y'|| ch=='Y')
		{cout<<"enter rno and mks";
		cin>>rno>>mks;
		fout<<rno<<"\t"<<mks<<endl;
	cout<<"want to enter more info";
		cin>>ch; }
	fout.close();

	ifstream fin;
	fin.open("stu.dat",ios::in);
	fin.seekg(0);
	while(fin)
	{
	fin.get(ch);
	cout<<ch;
	}
	fin.close();
 }