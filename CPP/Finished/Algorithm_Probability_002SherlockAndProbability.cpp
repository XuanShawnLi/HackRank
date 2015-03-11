/*
Watson gave a string S to Sherlock. It is N characters long and consists of only 1s and 0s. Now he asks: Given an integer K, I'll pick two indices i and j at random between 1 and N, both inclusive. What's the probability that both S[i] and S[j] are 1 and |i−j|≤K?

Input Format 
First line contains T, the number of testcases. Each testcase consists of N(the length of S) and K in one line and string in second line.

Output Format 
Print the required probability as an irreducible fraction. If required answer is 0, output 0/1.

Constraints 
1≤T≤105 
1≤N≤105 
1≤K≤N 
1≤Sum of N over all testcases in one file≤105

Sample input

2
4 3
1011
4 1
1011
Sample output

9/16
5/16
Explanation 
test1: Out of 16 choices, 9 pairs of (i,j) satisfy our condition.

(0,0), (0,2), (0,3), (2,0), (2,2), (2,3), (3,0), (3,2), (3,3)      
test2: Out of 16 choices, 5 pairs of (i,j) satisfy our condition.

(0,0), (2,2), (3,3), (3,4), (4,3)  
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

template<class T>
T GCD(T a,T b)
{//a=q*b+r
//int q=a/b;
//int r=a-q*b;
T r=a%b;
if(r==0)
    {return b;}
else
    {return GCD(b,r);}
}

string Prob_Slow(string s,int K){
	int n=s.length();
	vector<int> positions;
	for(int i=0;i<n;i++)
		{if(s[i]=='1'){positions.push_back(i);}
		}
	int m=positions.size();
	int count=0;
	for(int i=0;i<m;i++)
		{
		 for(int j=i+1;j<m;j++)
			{if(positions[j]-positions[i]<=K){count++;}
			 else{break;}
			}
		}
	unsigned long long numerator=(unsigned long long)(count)*2+m;
	unsigned long long denomenator=(unsigned long long)n*n;
	unsigned long long com=GCD(numerator,denomenator);
	stringstream ss1,ss2;
	ss1<<(numerator/com);
	ss2<<(denomenator/com);
	if(numerator==0){return "0/1";}
	return ss1.str()+"/"+ss2.str();
}

string Prob(string s,int K){
    int n=s.length();
    vector<int> positions;
    for(int i=0;i<n;i++)
        {if(s[i]=='1'){positions.push_back(i);}
        }
    int m=positions.size();
    unsigned long long count=0;int previous=1;
    for(int i=0;i<m;i++)
        {int j;
         for(j=previous;j<m;j++)
            {
			 if(positions[j]-positions[i]>K){previous=j;break;}
			}
		 if(j==m){previous=m;}
		 count+=previous-i-1;
        }
    unsigned long long numerator=(unsigned long long)(count)*2+m;
    unsigned long long denomenator=(unsigned long long)n*n;
    unsigned long long com=GCD(numerator,denomenator);
	stringstream ss1,ss2;
    ss1<<(numerator/com);
    ss2<<(denomenator/com);
    if(numerator==0){return "0/1";}
    return ss1.str()+"/"+ss2.str();
}

int main() {
	int T;cin>>T;
	time_t t1=clock();
	for(int i=0;i<T;i++)
		{int N,K;cin>>N>>K;
		 string s;cin>>s;
		 cout<<Prob(s,K)<<endl;
		}	
	cout<<"CPU time="<<clock()-t1<<endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

