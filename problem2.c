/*  Program to find mth smallest element in unsorted array
 * Compilation : gcc problem2.c
 * Execution : ./a.out
 *
 * Ankush Chhabra 1910990144 19-08-2021
 * Assignment 8 - Algorithm
*/
#include<stdio.h>

void customswap(int a[],int i,int j)
{
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
int partition(int a[],int l,int r)
{
	int i=l-1;
	int pivot=a[r];
	for(int j=l;j<=r-1;j++)
	{
	    //a[j] is less than pivot then swap a[i+1] and a[j]
		if(a[j]<pivot)
		{
			i++;
			customswap(a,i,j);
		}
	}
	//swap a[i+1] and a[r] element ( placing the pivot element to its correct position)
	customswap(a,i+1,r);
	return i+1;
}
void quicksort(int a[] , int l , int r)
{
	if(l<r)
	{
		int pi=partition(a,l,r);
		//calling the left subarray from l to pi-1
		quicksort(a,l,pi-1);
		//calling the right subarray from pi+1 to r
		quicksort(a,pi+1,r);
	}
}
int main() {
    
    int n,m;
    //Take input of size of array and mth position
    scanf("%d%d",&n,&m);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    //apply quick sort to sort the array
    quicksort(a,0,n-1);
    printf("%d",a[m-1]);
}
