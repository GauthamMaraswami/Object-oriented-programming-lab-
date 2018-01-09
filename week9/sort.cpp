#include<iostream>
using namespace std;

#define msiz 100

class sort
{
        private:
                int arr[msiz];
                int temp;
        public:
                void insert(int *ar1,int size);
                void bubble(int);
                void insertion(int);
                void selection(int);
                void display(int);
                void mergesort(int);
                void merge(int st,int end,int *ar1);
                void swap(int *,int*);
                void quick(int,int);
                void heapify(int, int, int);
	        void hsort(int);
                void quicksort(int size)
                {
                quick(0,size-1);
                
                }
                
};
void sort::heapify(int i, int n, int dir)
{
	if(dir == 0)
	{
		if(i == 0)
			return;
		if(arr[i] > arr[(i - 1)/2])
		{
			int t = arr[i];
			arr[i] = arr[(i - 1)/2];
			arr[(i - 1)/2] = t;
			heapify((i - 1) / 2, n, 0);
		}
	}
	else if(dir == 1)
	{
		int maxi = i;
		if(2 * i + 1 < n && arr[2 * i + 1] > arr[maxi])
			maxi = 2 * i + 1;
		if(2 * i + 2 < n && arr[2 * i + 2] > arr[maxi])
			maxi = 2 * i + 2;
		if(maxi != i)
		{
			int x = arr[maxi];
			arr[maxi] = arr[i];
			arr[i] = x;
			heapify(maxi, n, 1);
		}
	}
}
void sort::hsort(int size)
{
	int i;
	// "Insert" elements into heap
	for(i = 0; i < size; ++i)
		heapify(i, size, 0);
	// "Delete" elements from heap
	for(i = size - 1; i > 0; --i)
	{
		int j = arr[i];
		arr[i] = arr[0];
		arr[0] = j;
		heapify(0, i, 1);
	}
	cout<<"Heap sort: ";
	
}

void sort::display(int size)
{
        for(int i=0;i<size;++i)
        cout<<arr[i]<<endl;
}
void sort::insert(int ar1[],int size)
{
        
        for(int i=0;i<size;++i)
        {
                arr[i]=ar1[i];
        }


}
void sort::swap(int* t1,int* t2)
{
       temp=*t1;
       *t1=*t2;
       *t2=temp;

}
void sort::bubble(int size)
{
        int i,j;
        for(i=0;i<size;++i)
        {
                for(j=0;j<size-i-1;++j)
          {
                if(arr[j]>arr[j+1])
                 {   temp=arr[j];
                     arr[j]=arr[j+1];
                     arr[j+1]=temp;
                }
          }
        
        }      
        
}

void sort::insertion(int size)
{
        int i,j;
        for(i=0;i<size;++i)
        {
                temp=arr[i];
                for(j=i-1;j>=0;--j)
          {
                if(temp>arr[j])
                 {   
                    break;
                }
                arr[j+1]=arr[j];
          }
                arr[j+1]=temp;
        
        }      

}
void sort::selection(int size)
{
        int i,j,t,pos;
      
        for(i=size-1;i>=0;--i)
        {
                  t=0;
                  pos=i;
                for(j=i;j>=0;--j)
                {
                        if(arr[j]>t)
                         {
                         t=arr[j];
                         pos=j;
                         }
                }
                arr[pos]=arr[i];
                arr[i]=t;
                
                
        }
}
void sort::mergesort(int size)
{

merge(0,size-1,arr);


}
void sort::merge(int st,int end,int ar1[])
{
        int mid=(st+end)/2;
        if(st!= end)
	{
		merge( st, mid,ar1);
		merge( mid + 1, end,ar1);
	}
	int i = st, j = mid + 1, c = 0;
	int temp[end-st+1];
	
	while(i <= mid && j <= end)
	{
		if(ar1[i] < ar1[j])
		{
			temp[c] = ar1[i];
			++c;
			++i;
		}
		else
		{
			temp[c] = ar1[j];
			++c;
			++j;
		}
	}
	while(i <= mid)
	{
		temp[c] = ar1[i];
		++c;
		++i;
	}
	while(j <= end)
	{
		temp[c] = ar1[j];
		++c;
		++j;
	}
	for(i = st, j = 0; i <= end; ++i, ++j)
		ar1[i] = temp[j];
}
void sort::quick(int st,int end)
{       int j,piv;
        if(st>=end)
            return;
        piv=arr[end];
        j=st;
        for(int i=st;i<=end;++i)
        {
                if(arr[i]<=piv)
                {
                    int te=arr[i];
                    arr[i]=arr[j];
                     arr[j]=te;
                    ++j;
                 
                 }
        }
        j--;
        quick(st,j-1);
        quick(j+1,end);
}
int main()
{
        class sort s1;
        int arr[100],si;
        cout<<"enter the size\n"<<endl;
        cin>>si;
        for(int i=0;i<si;++i)
                {
                cin>>arr[i];
                
                }
        s1.insert(arr,si);
        cout<<"insert succcessful";
         s1.insert(arr,si);
         cout<<"heapsort";
        s1.hsort(si);
        s1.display(si);
         s1.insert(arr,si);
         cout<<"quicksort";
        s1.quicksort(si);
        s1.display(si);
         s1.insert(arr,si);
         cout<<"mergesort";
        s1.mergesort(si);
        s1.display(si);
         s1.insert(arr,si);
         cout<<"insertion sort";
        s1.insertion(si);
        s1.display(si);
         s1.insert(arr,si);
         cout<<"selection sort";
        s1.selection(si);
        s1.display(si);
         s1.insert(arr,si);
         cout<<"bubblesort";
        s1.bubble(si);
        s1.display(si);
         s1.insert(arr,si);
        
return 0;
}
