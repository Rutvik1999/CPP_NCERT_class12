#define max 100
#include <iostream.h>
int Lsearch(int a[],int s,int ele)
{	for(int i=0;i<s;i++)
		if(a[i]==ele)
			return i++;
return -1;
}
int main(){
int a[max],size,ele,index;
cout<<"Enter size of array";
cin>>size;
for(int i=0;i<size;i++)
{	cout<<"Enter value "<<i+1<<":";
	cin>>a[i];
}
cout<<"Enter ele to be searched:"; cin>>ele;
index=Lsearch(a,size,ele);
if(index==-1)
	cout<<"ele not found.....";
else
cout<<"Ele found at position"<<index+1;
return 0;
}