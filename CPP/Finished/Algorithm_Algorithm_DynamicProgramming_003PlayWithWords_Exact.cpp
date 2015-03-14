/*
Problem Statement

Shaka and his brother have created a boring game which is played like this:

They take a word composed of lowercase English letters and try to get the maximum possible score by building exactly 2 palindromic subsequences. The score obtained is the product of the length of these 2 subsequences.

Let's say A and B are two subsequences from the initial string. If Ai & Aj are the smallest and the largest positions (from the initial word) respectively in A ; and Bi & Bj are the smallest and the largest positions (from the initial word) respectively in B, then the following statements hold true:
Ai≤Aj,
Bi≤Bj, &
Aj<Bi.
i.e., the positions of the subsequences should not cross over each other.

Hence the score obtained is the product of lengths of subsequences A & B. Such subsequences can be numerous for a larger initial word, and hence it becomes harder to find out the maximum possible score. Can you help Shaka and his brother find this out?

Input Format
Input contains a word S composed of lowercase English letters in a single line.

Output Format
Output the maximum score the boys can get from S.

Constraints
1<|S|≤3000
each character will be a lower case english alphabet.

Sample Input:

eeegeeksforskeeggeeks

Sample Output:

50

Explanation

A possible optimal solution is eee-g-ee-ksfor-skeeggeeks being eeeee the one subsequence and skeeggeeks the other one. We can also select eegee in place of eeeee, as both have the same length.
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

//This solution does not allow skip over letters
//e.g. "eee-g-ee" can't be taken as eeeee


int LongestPalindrome_BF(string &word,int left,int right){
	if(right-left==0){return 1;}
	int result=1;
	int c=left+1;//odd length parlindrome: c is the center
	while(c<right)
		{int l=c-1;int r=c+1;
		 while(l>=left and r<=right and word[l]==word[r]){l--;r++;}
		 if(r-l-1>result){result=r-l-1;}
		 c++;
		}
	c=left;//even length parlindrom: c is the left center
	while(c<right-1)
        {if(word[c]==word[c+1]){
		 	int l=c-1;int r=c+2;
         	while(l>=left and r<=right and word[l]==word[r]){l--;r++;}
         	if(r-l-1>result){result=r-l-1;}
		 }
         c++;
        }
	return result;
}


void LongestPalindrome(string &word,int* dp_odd_left, int* dp_odd_right, int* dp_even_left, int* dp_even_right){
//precomputes all the left and right boundaries of odd-length centers and even-length centers: O(n^2)
	int n=word.length();
	int c=1;
	while(c<n)//odd
		{int l=c-1;int r=c+1;
         while(l>=0 and r<n and word[l]==word[r]){l--;r++;}
		 dp_odd_left[c]=l+1;dp_odd_right[c]=r-1;
         c++;
        }
	c=0;
	while(c<n-1)//even
        {if(word[c]==word[c+1]){
			int l=c-1;int r=c+2;
         	while(l>=0 and r<n and word[l]==word[r]){l--;r++;}
         	dp_even_left[c]=l+1;dp_even_right[c]=r-1;
			}
         	c++;
        }
}

int MaxProduct_left(string &word,int right, int* dp_odd_left, int* dp_odd_right, int* dp_even_left, int* dp_even_right){
	int result=1;
	for(int c=1;c<=right;c++)//odd
		{if(dp_odd_right[c]<=right)
			{if(dp_odd_right[c]-dp_odd_left[c]+1>result){result=dp_odd_right[c]-dp_odd_left[c]+1;}}
		}
	for(int c=1;c<right;c++)//even
        {if(dp_even_right[c]>0 and dp_even_right[c]<=right)
            {if(dp_even_right[c]-dp_even_left[c]+1>result){result=dp_even_right[c]-dp_even_left[c]+1;}}
        }
	return result;
}

int MaxProduct_right(string &word,int left, int* dp_odd_left, int* dp_odd_right, int* dp_even_left, int* dp_even_right){
	int n=word.length();
    int result=1;
    for(int c=left;c<n;c++)//odd
        {if(dp_odd_left[c]>=left)
            {if(dp_odd_right[c]-dp_odd_left[c]+1>result){result=dp_odd_right[c]-dp_odd_left[c]+1;}}
        }
    for(int c=left;c<n-1;c++)//even
        {if(dp_even_left[c]>0 and dp_even_left[c]>=left)
            {if(dp_even_right[c]-dp_even_left[c]+1>result){result=dp_even_right[c]-dp_even_left[c]+1;}}
        }
    return result;
}


int MaxProduct(string word){
	int n=word.length();
    if(n<2){return 0;}
    if(n==2){return 1;}
	int result=1;
	int* dp_odd_left=new int[n];
	int* dp_odd_right=new int[n];
	int* dp_even_left=new int[n-1];
	int* dp_even_right=new int[n-1];
	for(int c=0;c<n;c++){dp_odd_left[c]=c;dp_odd_right[c]=c;}
	for(int c=0;c<n-1;c++){dp_even_left[c]=-1;dp_even_right[c]=-1;}
	LongestPalindrome(word,dp_odd_left, dp_odd_right, dp_even_left,dp_even_right);
	for(int mid=1;mid<n;mid++)
		{int left=MaxProduct_left(word,mid-1,dp_odd_left, dp_odd_right, dp_even_left,dp_even_right);
		 int right=MaxProduct_right(word,mid,dp_odd_left, dp_odd_right, dp_even_left,dp_even_right);
		if(left*right>result){result=left*right;}
		}
	delete[] dp_odd_left;delete[] dp_odd_right;delete dp_even_left;delete[] dp_even_right;
	return result;
}

int MaxProduct_BF(string &word){
	int n=word.length();
	if(n<2){return 0;}
	if(n==2){return 1;}
	int result=1;
	for(int mid=1;mid<n;mid++)
		{int left=LongestPalindrome_BF(word,0,mid-1);
		 int right=LongestPalindrome_BF(word,mid,n-1);
		 if(left*right>result){result=left*right;}
		}
	return result;
}





int main() {
	string word;getline(cin,word);
	time_t t1=clock();
	cout<<MaxProduct_BF(word)<<endl;
	cout<<"BF cputime="<<clock()-t1<<endl;
	t1=clock();
	cout<<MaxProduct(word)<<endl;
	cout<<"cputime="<<clock()-t1<<endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

