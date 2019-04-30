//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************

#include<iostream.h>
#include<fstream.h>
#include<ctype.h>
#include<iomanip.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************
int numlength(double );
class account
{
	double acno;
	char name[50];
	long double deposit;
	char type;
public:
	void create_account();	//function to get data from user
	void show_account() const;	//function to show data on screen
	void modify();	//function to add new data
	void dep(int);	//function to accept amount and add to balance amount
	void draw(int);	//function to accept amount and subtract from balance amount
	void report() const;	//function to show data in tabular format
	int retacno() const;	//function to return account number
	int retdeposit() const;	//function to return balance amount
	char rettype() const;	//function to return type of account
};         //class ends here

void account::create_account()
{
	  begacc:
	  textattr(3);
	  clrscr();
	cout<<"\nEnter The account No. : ";
	cin>>acno;
	cout<<"\n\nEnter The Name of The account Holder : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\nEnter Type of The account (C/S) : ";
	cin>>type;
	type=toupper(type);
	cout<<"\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
	cin>>deposit;
	  if((type == 'C') &&( deposit < 999))
		{cout<<"error. Minimum deposit amount for current account is 1000 INR";
		 cout<<"\n press any key to re-enter account information";
		 getchar();
		 goto begacc;     }
	  else if((type == 'S') && (deposit <499))
		{ cout<<"error. Minimum deposit amount for savings account is 500 INR";
		  cout<<"\n press any key to re-enter account information";
		  getchar();
		  goto begacc;
		}

	cout<<"\n\n\nAccount Created Successfully ...";
}

void account::show_account() const
{    textattr(9);
	  clrscr();
	cout<<"\nAccount No. : "<<acno;
	cout<<"\nAccount Holder Name : ";
	cout<<name;
	cout<<"\nType of Account : "<<type;
	cout<<"\nBalance amount : "<<deposit;
}


void account::modify()
{   textattr(5);
	  clrscr();
	cout<<"\nAccount No. : "<<acno;
	cout<<"\nModify Account Holder Name : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\nModify Type of Account : ";
	cin>>type;
	type=toupper(type);
	cout<<"\nModify Balance amount : ";
	cin>>deposit;
}


void account::dep(int x)
{
	deposit+=x;
}

void account::draw(int x)
{
	deposit-=x;
}

void account::report() const
{   int l1 = strlen(name);
    int l2 = numlength(acno);
	textattr(6);
	cout<<setiosflags(ios::left);
	cout<<"   "<<acno<<setw(10 - (l2))<<" ";
	cout<<"       "<<name<<setw(15 - (l1))<<" ";
	cout<<"           "<<type<<setw(6)<<" ";
	cout<<"         "<<deposit<<setw(8)<<" "<<endl;
}

int account::retacno() const
{
	return acno;
}

int account::retdeposit() const
{
	return deposit;
}

char account::rettype() const
{
	return type;
}

int numlength(double u) {
      if (u < 10)   return 1;
      if (u < 100)  return 2;
      if (u < 1000) return 3;
	  if (u < 10000)   return 4;
      if (u < 100000)  return 5;
      if (u < 1000000) return 6;
      if (u < 10000000)   return 7;
      if (u < 100000000)  return 8;
      if (u < 1000000000) return 9;
	  if (u < 10000000000)   return 10;
      else { return 0; }
}

//***************************************************************
//    	function declaration
//****************************************************************
void write_account();	//function to write record in binary file
void display_sp(int);	//function to display account details given by user
void modify_account(int);	//function to modify record of file
void delete_account(int);	//function to delete record of file
void display_all();		//function to display all account details
void deposit_withdraw(int, int); // function to desposit/withdraw amount for given account
void intro();	//introductory screen function
void deleteall();  //delete everything

//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************

int main()
{
	char ch;
	int num;
	intro();
	do
	{    textattr(2);
	     clrscr();
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t1. CREATE NEW ACCOUNT";
		cout<<"\n\n\t2. DEPOSIT AMOUNT";
		textattr(2);
		cout<<"\n\n\t3. WITHDRAW AMOUNT";
		cout<<"\n\n\t4. BALANCE ENQUIRY";
		cout<<"\n\n\t5. ACCOUNT HOLDER's LIST";
		cout<<"\n\n\t6. CLOSE AN ACCOUNT";
		cout<<"\n\n\t7. MODIFY AN ACCOUNT";
		cout<<"\n\n\t8. ERASE ALL DATA";
		cout<<"\n\n\t9. EXIT";
		cout<<"\n\n\tSelect Action (1-9) ";
		cin>>ch;
	     //	clrscr();
		switch(ch)
		{
		case '1':
			write_account();
			break;
		case '2':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 1);
			break;
		case '3':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 2);
			break;
		case '4':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			display_sp(num);
			break;
		case '5':
			display_all();
			break;
		case '6':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			delete_account(num);
			break;
		 case '7':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			modify_account(num);

			break;
		case '8':
			deleteall();
			break;
		 case '9':
			cout<<"\n\n\tThank You For using this program. \n ----------------------------------------------------------------";
			cout<<"\nPress any key to Exit ";
			exit(0);
			break;
		 default :cout<<"\a";
		}
		cin.ignore();
		cin.get();
    }while(ch!='9');
	return 0;
}


//***************************************************************
//    	function to write in file
//****************************************************************

void write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("account.data",ios::binary|ios::app);
	ac.create_account();
	outFile.write((char *) (&ac), sizeof(account));
	outFile.close();
}

//***************************************************************
//    	function to read specific record from file
//****************************************************************

void display_sp(int n)
{textattr(30);
	  clrscr();
	account ac;
	int flag = 0;
	ifstream inFile;
	inFile.open("account.data",ios::binary);
	if(!inFile)
	{
		cout<<"unable to open File !! Press any Key...";
		return;
	}
	cout<<"\nBALANCE DETAILS\n";
	while(inFile.read((char *) (&ac), sizeof(account)))
	{
		if(ac.retacno()==n)
		{
			ac.show_account();
			flag=1;
		}
	}
    inFile.close();
	if(flag==0)
		cout<<"\n\nAccount does not exist";
}


//***************************************************************
//    	function to modify record of file
//****************************************************************

void modify_account(int n)
 {        textattr(5);
	  clrscr();
	int found=0;
	account ac;
	fstream File;
    File.open("account.data",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==0)
	{
		File.read((char*) (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			ac.show_account();
			cout<<"\n\nEnter The New Details of account"<<endl;
			ac.modify();
			int pos=(-1)*(sizeof(account));
			File.seekp(pos,ios::cur);
		    File.write((char *) (&ac), sizeof(account));
		    cout<<"\n\n\t Record Updated";
		    found=1;
		  }
	}
	File.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
}

//***************************************************************
//    	function to delete record of file
//****************************************************************



void delete_account(int n)
{       textattr(47);
	clrscr();
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read((char *) (&ac), sizeof(account)))
	{
		if(ac.retacno()!=n)
		{
			outFile.write((char *) (&ac), sizeof(account));
		}
	}
    inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	cout<<"\n\n\tRecord was deleted if it was present ..";
	getchar();
	clrscr();
}

//***************************************************************
//    	function to display all accounts deposit list
//****************************************************************

void display_all()
{       textattr(6);
	  clrscr();
	account ac;
	ifstream inFile;
	inFile.open("account.data",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be opened !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"=============================================================================\n";
	cout<<"   A/c no.          NAME                 Account Type         Balance\n";
	cout<<"==============================================================================\n";
	while(inFile.read((char*) (&ac), sizeof(account)))
	{
		ac.report();
	}
	inFile.close();
}

//***************************************************************
//    	function to deposit and withdraw amounts
//****************************************************************

void deposit_withdraw(int n, int option)
{       textattr(48);
	  clrscr();
	int amt;
	int found=0;
	account ac;
	fstream File;
    File.open("account.data", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be opened !! Press any Key...";
		return;
	}
	while(!File.eof() && found==0)
	{
		File.read((char *) (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			ac.show_account();
			if(option==1)
			{
				cout<<"\n\n\tTO DEPOSITE AMOUNT ";
				cout<<"\n\nEnter The amount to be deposited : ";
				cin>>amt;
				ac.dep(amt);
			}
		    if(option==2)
			{
				cout<<"\n\n\tTO WITHDRAW AMOUNT ";
				cout<<"\n\nEnter The amount to be withdrawn : ";
				cin>>amt;
				int bal = ac.retdeposit()-amt;
				if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
					cout<<"Insufficience balance";
				else
					ac.draw(amt);
		      }
			int pos=(-1)*(sizeof(ac));
			File.seekp(pos,ios::cur);
			File.write((char *) (&ac), sizeof(account));
			cout<<"\n\n\t Record Updated";
			found=1;
	       }
	 }
    File.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";

}


//***************************************************************
//    	INTRODUCTION FUNCTION
//****************************************************************

void intro()
{    textattr(9);
	  clrscr();
	cout<<endl;
	cout<<endl;
	cout<<"\n\n \t \t \t \t BANK";
	cout<<"\n\n \t \t \t \t MANAGEMENT";
	cout<<"\n\n \t \t \t \t  SYSTEM";
	cout<<"\n\n\n\n\n\n\n \t \t MADE BY : ISHAAN SAXENA AND RUTVIK PATEL";
	cin.get();
}

void deleteall()
{
remove("account.data");
cout<<"all data erased";
getchar();
}

//***************************************************************
//    			END OF PROJECT
//***************************************************************
