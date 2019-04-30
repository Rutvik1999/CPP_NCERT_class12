#include <fstream.h>

int main(){

	ofstream fout;
	fout.open("file10.txt",ios::out);
	cout<<"Enter contents in the file";
	char ch;
	ch = getchar();
	while(ch != '\n')
		{   fout<<ch;
		    ch = getchar();
		}
	fout.close()

	ifstream fin;
	int count = 0;
	fin.open("file10.txt",ios::in);
	while(fin)
		{  fin.get(ch);
		cout<<ch;
		count++;
		}
       cout<<"total = "<<count;
       }


