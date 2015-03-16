/*
You are given an unsorted array with both positive and negative elements. You have to find the smallest positive number missing from the array in O(n) time using constant extra space. You can modify the original array.

Examples

 Input:  {2, 3, 7, 6, 8, -1, -10, 15}
 Output: 1

 Input:  { 2, 3, -7, 6, 8, 1, -10, 15 }
 Output: 4

 Input: {1, 1, 0, -1, -2}
 Output: 2 
*/
#include <iostream>
using namespace std; 

#define SIZE(a) sizeof(a)/sizeof(a[0])

int FindMissing_sub(int*,int);
int Regrouping(int*,int);
void Swap(int*,int,int);

int FindMissing(int* a,int n){
//find the first missing positive integer from unsorted array where negative and zeros can exist.
//Complexity O(n)
	int m=Regrouping(a,n);
	return FindMissing_sub(a,m);
}

int FindMissing_sub(int* a,int n){
//find the first missing positive integer from unsorted array where all elements are positive
//complexity O(n)
int index;
for(int i=0;i<n;i++)
	{int index=abs(a[i])-1;
	 if(index<n and a[index]>0)a[index]=-a[index];
	}
for(int i=0;i<n;i++)
	{if(a[i]>0){return i+1;}}
return n+1;
}

int Regrouping(int *a, int n){
//all positives to the left, and all zeroes and negatives to the right
//return the number of positives
	int left=0;int right=n-1;
	while(left<right)
		{if(a[left]<=0)
			{Swap(a,left,right--);}
		 else
			{left++;}
		}
	return left+1;
}


void Swap(int*a,int i,int j){
	int tmp=a[i];a[i]=a[j];a[j]=tmp;
}

int main()
{
int a1[]={2, 3, 7, 6, 8, -1, -10, 15};
int n1=SIZE(a1);
cout<<FindMissing(a1,n1)<<" = "<<1<<endl;
int a2[]={ 2, 3, -7, 6, 8, 1, -10, 15 };
int n2=SIZE(a2);
cout<<FindMissing(a2,n2)<<" = "<<4<<endl;
int a3[]={1, 1, 0, -1, -2};
int n3=SIZE(a3);
cout<<FindMissing(a3,n3)<<" = "<<2<<endl;
}
