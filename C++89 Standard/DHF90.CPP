#include<stdlib.h>
#include<conio.h>
#include<fstream.h>
int main()
{
ofstream fout;
fout.open("country");
fout<<"UN STATES..............."<<endl<<"INDIA"<<endl<<"BANGLADESH"<<endl;
	fout.close();
	fout.open("capital")  ;


	char line[40];
	ifstream fin1,fin2;
	fin1.open("country");
	fin2.open("capital");
	fin1.seekg(0);//brings cursor to the start


for(int i =1;i<10;i++)
{
	if(fin1.eof()!=0)
			{
				cout<<"exit from the country";
				exit(1);
			}
	fin1.getline(line,size);
	cout<<"capital of"<<line<<" ";
	if(fin2.eof()!=0)
	{
		cout<<"Exit from capital\n";
		exit(1);
	}
	fin2.getline(line,size);
	cout<<line<<"\n";
	}
	getch();
}
