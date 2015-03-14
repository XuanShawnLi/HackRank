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


void CalculateDP_recursive(string &word,int**  dp,int left,int right, int n){
	if(left>right){dp[left][right]=0;return;}//don't need to compute
	if(dp[left][right]>=0){return;}//has been computed before
	if(dp[left+1][right]<0){CalculateDP_recursive(word,dp,left+1,right,n);}
	if(dp[left][right-1]<0){CalculateDP_recursive(word,dp,left,right-1,n);}
	if(dp[left+1][right-1]<0){CalculateDP_recursive(word,dp,left+1,right-1,n);}
	if(word[left]==word[right])
		{dp[left][right]=2+dp[left+1][right-1];}
	else
		{dp[left][right]=max(dp[left+1][right],dp[left][right-1]);}
}

void CalculateDP_iterative(string &word,int** dp,int &n){
	int left,len,right;
	for(len=2;len<=n;len++)
		{for(left=0;left<=n-len;left++)
			{right=left+len-1;
			 if(word[left]==word[right])
				{dp[left][right]=2+dp[left+1][right-1];}
			 else
				{dp[left][right]=max(dp[left+1][right],dp[left][right-1]);}
			}
		}	
}

void CalculateDP(string &word,int**  dp, int n){
	CalculateDP_recursive(word,dp,0,n-1,n);
}

int MaxProduct_DP(string word){
	int n=word.length();
    if(n<2){return 0;}
    if(n==2){return 1;}
	int result=1;
	int** dp=new int*[n];
	for(int i=0;i<n;i++){
		dp[i]=new int[n];
		for(int j=0;j<n;j++){dp[i][j]=0;}
		dp[i][i]=1;
	}
//	CalculateDP(word,dp,n);//need to set dp=-1 for all cases
	CalculateDP_iterative(word,dp,n);
	for(int mid=1;mid<n;mid++)
		{int left=dp[0][mid-1];
		 int right=dp[mid][n-1];
		if(left*right>result){result=left*right;}
		}
	for(int i=0;i<n;i++){delete[] dp[i];}
	delete[] dp;
	return result;
}


int main() {
	string word;getline(cin,word);
	time_t t1=clock();
	cout<<MaxProduct_DP(word)<<endl;
	cout<<"cputime="<<clock()-t1<<endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

