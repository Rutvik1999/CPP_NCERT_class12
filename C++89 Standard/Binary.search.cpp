
#define max 100
int Bsearch(int a[],int s,int ele)
{	int beg=0,last = size -1,mid;
      for(int i =0;i<size;i++)
         {   mid = (beg + last)/2;
             if(ele==a[mid])
                 return mid;
             elseif(ele>a[mid])
                 beg = mid + 1;
             else
                 last = mid -1;
         }
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
    index=Bsearch(a,size,ele);
     if(index==-1)
	cout<<"ele not found.....";
     else
    cout<<"Ele found at position"<<index+1;
return 0;
}