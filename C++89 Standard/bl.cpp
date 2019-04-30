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
#include "h.h"



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
