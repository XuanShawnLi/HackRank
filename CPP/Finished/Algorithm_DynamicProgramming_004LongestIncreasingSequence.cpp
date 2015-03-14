/*


Problem Statement

An Introduction to the Longest Increasing Subsequence Problems

The task is to find the length of the longest subsequence in a given array of integers such that all elements of the subsequence are sorted in ascending order. For example, the length of the LIS for { 15, 27, 14, 38, 26, 55, 46, 65, 85 } is 6 and the longest increasing subsequence is {15, 27, 38, 55, 65, 85}.

Here's a great Youtube video of a lecture from MIT's Open-Coursware, covering the topic.

Here is one approach which solves this in quadratic time using dynamic programming. A more efficient algorithm which solves the problem in N Log N time is available here.

In this challenge you simply have to find the length of the longest strictly increasing sub-sequence of the given sequence.

Input Format

In the first line of input, there is a single number N.
In the next N lines input the value of a[i].

Constraints
1 ≤ N ≤ 106
1 ≤ a[i] ≤ 105

Output Format

In a single line, output the length of the longest increasing sub-sequence.

Sample Input

5
2
7
4
3
8

Sample Output

3

Explanation

{2,7,8} is the longest increasing sub-sequence, hence the answer is 3 (the length of this sub-sequence).

*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//see http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
//Use an array to store the longest active lines: note this single line is NOT the best line...

int Search(int *b,int l, int r, int key){
	int m;
	while(r-l>1)
		{m=l+(r-l)/2;
		 (b[m]>=key? r:l)=m;
		}
	return r;
}

int LonestIncreasingSubsequence_ONLOGN(int *a,int N){
	int* dp=new int[N];
	fill(dp,dp+N,0);
	int len=1;
	dp[0]=a[0];
	for(int i=0;i<N;i++)
		{if(a[i]<dp[0])//smaller than the tail of the active line
			{dp[0]=a[i];}
		 else if(a[i]>dp[len-1])//bigger than the head of the active line
			{dp[len++]=a[i];}
		 else// put in the active line
			{dp[Search(dp,-1,len-1,a[i])]=a[i];}
		}
	return len;
}

int LonestIncreasingSubsequence_ON2(int *a,int N){
//DP[i] stores the length of the longest increasing subsequence starting from a[i]
//complexity O(n^2)
	int* dp=new int[N];
	for(int i=N-1;i>=0;i--)
		{int tmp=1;
		 for(int j=i+1;j<N;j++)
			{if(a[i]<a[j] and dp[j]+1>tmp){tmp=dp[j]+1;}}
		 dp[i]=tmp;
		}
	int result=1;
	for(int i=0;i<N;i++)
		{if(dp[i]>result){result=dp[i];}}
	delete[] dp;
	return result;
}

int main() {
	int N;cin>>N;
	int *a=new int[N];
	for(int i=0;i<N;i++)
		{cin>>a[i];}
	cout<<LonestIncreasingSubsequence_ONLOGN(a,N)<<endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

