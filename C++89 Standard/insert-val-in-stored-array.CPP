#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
int findpos(int arr[],int size,int ele)
{
	int pos;
	if(ele<arr[0])
		pos=0;
	else
	{	for(int i = 0;i<size-1;i++)
		{	if(arr[i]<=ele && ele<arr[i+1])
			{    pos=i+1;
			     break;  }    }
		if(i==size-1)   pos=size;  }
	return pos;
}

int main()
      {
      int arr[50],size,ele,index;
      cout<<"How many values for array:";
      cin>>size;
      for(int i=0;i<size;i++)
       cin>>arr[i];
      char ch='y';
      while(ch=='y' || ch =='Y')
      {	       cout<<"\n Enter Element to be inserted...";
	       cin>>ele;
	if(size==50)
	{	cout<<"Overflow";
		exit(1);
	}
	index=findpos(arr,size,ele);
	for(i=size;i>index;i--)
	{	arr[i]=arr[i-1];
	}
	arr[index]=ele;
	size+=1;
	cout<<"Want to insert more(y/n) ";
	cin>>ch;
      }
     cout<<"The array now is as shown below ; \n";
     for(i=0;i<size;i++)
	 cout<<arr[i]<<"\t";
     getch();
     return 0;
}


