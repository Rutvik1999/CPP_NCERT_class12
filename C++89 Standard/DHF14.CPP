#include<fstream.h>
#include<conio.h>
#include<stdio.h>
int main()
{
ifstream fin;
fin.open("file1.txt",ios::in);
char line[80];
int count = 0;


while(!fin.eof())
{          fin.getline(line,80);
		if(line[0] == 'A ')
		{
		count++;
		}
}
cout<<count;
getch();
return 0;
}
