#include<ftsream.h>
#include<conio.h>
#include<stdio.h>

class phonelist{
char name[20],address[20],area[20],phone[20];
	public:
	void Reg();
	void show();
	int checkcode(char a[])
	{	return strcmp(area a);}
};
void phonelist::reg(){
	cout<<"enter name, address, phone:";
	gets(name);
	gets(address);
	gets(area);
	gets(phone);}
void phonelist::show(){
	cout<<"NAME "<<name<<endl;
	cout<<"address"<<address<<endl;
	cout<<"area"<<area<<endl;
	cout<<"phone no"<<phone<<endl;}
void main(){
	phonelist p;
	ofstream fio;
	fio.open("Phone.dat",ios::in|ios::binary);
	ifstream fin;
	fin.open("PhoneDelhi.dat",ios::out|ios::binary);
	char ch='y';
	while(ch=='y')
	{	p.Reg();
		fio.write((char*)&p,sizeof(p));
		cout<<"want more:";
		cin>>ch; }
	fin.seekg(0);
	while(!fin.eof)
	{	fin.read((char*)p,sizeof(p));
		if(p.checkcode("Delhi")==0)
			p.show();
		else
			;
	}
	fio.close();
	fin.close();
	}