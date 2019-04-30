#include<iostream.h>
#include<stdlib.h>

int Lsearch(int arr[],int size,int ele)
{	for(int i=0;i < size;i++)
	{    if(ele==arr[i])   return i;     }
	return -1; }
int main()
{
	int arr[50],size,ele,index;
	cout<<"Enter array size :";
	cin>>size;
	for(int i=0;i<size;i++)
	{	cin>>arr[i];      }
	char ch = 'y';
	while(ch == 'y' || ch == 'Y')
	{	cout<<"Underflow \n ";
		exit(1);
	}
	index = Lsearch(arr,size,ele);
	if(index!=-1)   arr[index]=0;

	else
	cout<<"Sorry !! No such element in array \n";
	cout<<" \n zero for deleted value : \n ";
	for(i=0;i<size;i++)
	{	cout<<arr[i]<<" \t"; }
	cout<<endl;
	for(i=index;i<size;i++)
	{        arr[i]=arr[i+1];    }
	size-=1;
	cout<<"\n Do you want to delete more elements";
	cin>>ch;
	cout<<"The array after shifting all emptied spaces towards right is ... \n";
	for(i=0;i<size;i++)
	    { cout<<arr[i]<<"\t";
	    }

return 0;
}