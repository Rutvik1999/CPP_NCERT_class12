#include<iostream.h>
void Selsort(int arr[],int size)
{  int small,pos,temp;
	for(int i=0;i<size;i++)
	{
		small=arr[i];     pos=i;
		for(int j = i + 1 ; j<size;j++)
		{	if(arr[j]<small)
			{  small=arr[j];    pos=j;    }      }
		temp=arr[i];   arr[j]=arr[pos];     arr[pos]=temp;
		cout<<"\n \n Array after pass - "<<i+1<<"- is : ";
		for(j=0;j<size;j++)
		   cout<<arr[j]<<"  ";
                }
        }

int main()
{
	int arr[50],size;
	cout<<"Enter array size : ";
	cin>>size;
	for(int i = 0; i <size;i++ )
	{
		cin>>arr[i];
	}
	Selsort(arr,size);
	cout<<"\n Sort array is ... \n";
        for(i=0;i<size;i++)
	cout<<arr[i]<<" ";
	return 0;
}
		