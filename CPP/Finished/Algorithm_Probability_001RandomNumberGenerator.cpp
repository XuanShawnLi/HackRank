/*
Problem Statement

Random number generator

There is an ideal random number generator, which given a positive integer M can generate any real number between 0 to M, and probability density function is uniform in [0, M].

Given two numbers A and B and we generate x and y using the random number generator with uniform probability density function [0, A] and [0, B] respectively, what's the probability that x + y is less than C? where C is a positive integer.

Input Format

The first line of the input is an integer N, the number of test cases.

N lines follow. Each line contains 3 positive integers A, B and C.

Constraints

All the integers are no larger than 10000.

Output Format

For each output, output a fraction that indicates the probability. The greatest common divisor of each pair of numerator and denominator should be 1.

Sample Input

3
1 1 1
1 1 2
1 1 3
Sample Output

1/2
1/1
1/1
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

int GCD(int a,int b)
{//a=q*b+r
//int q=a/b;
//int r=a-q*b;
int r=a%b;
if(r==0)
    {return b;}
else
    {return GCD(b,r);}
}

string Prob(int A,int B,int C){
	if(C>=A+B){return "1/1";}
	if(A>B){return Prob(B,A,C);}
	int numerator,denomenator;
	if(C>=B){
		numerator=2*B*(C-B)+B*B-(A-C)*(A-C);
		denomenator=2*A*B;
	}
	else if(C>=A)
		{numerator=2*C-A;
		 denomenator=2*B;
		}
	else
		{numerator=C*C;
		 denomenator=2*A*B;
		}
	int com=GCD(numerator,denomenator);
	string s1,s2;
	stringstream ss1,ss2;
	ss1<<numerator/com;
	s1=ss1.str();
	ss2<<denomenator/com;
	s2=ss2.str();
	return s1+"/"+s2;
}

int main() {
	int N;cin>>N;
	for(int i=0;i<N;i++)
		{int A,B,C;
		 cin>>A>>B>>C;
		 cout<<Prob(A,B,C)<<endl;
		}    
/* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

