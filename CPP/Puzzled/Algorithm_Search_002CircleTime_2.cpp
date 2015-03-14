/*
Roy lives in a city that is circular in shape on a 2D plane and has radius r. The city center is located at origin (0,0) and it has suburbs lying on the lattice pounsigned long longs (pounsigned long longs with unsigned long longeger coordinates). The city Police Department Headquarters can only protect those suburbs which are located strictly inside the city. The suburbs located on the border of the city are still unprotected. So the police department decides to build at most k additional police stations at some suburbs. Each of these police stations can protect the suburb it is located in.

Given the square of radius, d(=r2), of the city, Roy has to determine if it is possible to protect all the suburbs.

Input Format
The first line of input contains unsigned long longeger t, t testcases follow.
Each of next t lines contains two space separated unsigned long longegers: d, the square of the radius of the city and k, the maximum number of police stations the headquarters is willing to build.

Constraunsigned long longs
1≤t≤103
1≤d≤2×109
0≤k≤2×109

Output Format
For each test case, prunsigned long long in a new line possible if it is possible to protect all the suburbs, otherwise prunsigned long long impossible.

Sample Input

5
1 3
1 4
4 4
25 11
25 12

Sample Output

impossible
possible
possible
impossible
possible

Explanation

    For d=1, there are 4 pounsigned long longs on circumference - [(0,1), (0,-1), (1,0), (-1,0)].
    For d=4, there are 4 pounsigned long longs on circumference - [(0,2), (0,-2), (2,0),(-2,0)].
    For d=25, there are 12 pounsigned long longs on circumference - [(0,5), (0,-5), (3,4), (-3,4), (3,-4), (-3,-4), (4,3), (-4,3), (4,-3), (-4,-3), (5,0), (-5,0)].

Test Case #01: There are 4 suburbs on the border, while we are allowed to construct max k=3 police stations.
Test Case #02: We can cover all the 4 suburbs as exactly 4 stations are allowed.
Test Case #03: We can cover all the 4 suburbs as exactly 4 stations are allowed.
Test Case #04: It is impossible to cover 12 suburbs, on the border, with 11 police stations.
Test Case #05: We can to cover all 12 suburbs, on the border, with 12 police stations.

Timelimits

Timelimits for this challenge are given here
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;

unordered_map<unsigned long long,unsigned long long> numbers;
unordered_map<unsigned long long,unsigned long long> Pythagorean;

void Generation(unsigned long long mmax){
	unsigned long long m,n;unsigned long long a,b,c;
	unordered_map<unsigned long long,unsigned long long>::iterator it;
	for(m=1;m<=mmax;m++)
		{for(n=1;n<m;n++)
			{
			 c=m*m+n*n;
			 c=c*c;
			 it=Pythagorean.find(c);
			 if(it!=Pythagorean.end()){Pythagorean[c]++;}
			 else{Pythagorean.insert(make_pair(c,1));}
			}
		}
}

bool Police(unsigned long long n,unsigned long long k){
	unordered_map<unsigned long long,unsigned long long>::iterator it;
	it=numbers.find(n);
	if(it!=numbers.end())
		{return k>=numbers[n];}
 	else
		{it=Pythagorean.find(n);
		 if(it==Pythagorean.end())//not Pythagorean number
			{numbers.insert(make_pair(n,4));return k>=4;}
		 else//Pythagorean number
			{unsigned long long tmp=Pythagorean[n]*8+4;
			 numbers.insert(make_pair(n,tmp));
			 return k>=tmp;
			}
		}
}

int main() {
	Generation(211);
	numbers.insert(make_pair(1,4));
	numbers.insert(make_pair(4,4));
	numbers.insert(make_pair(9,4));
	numbers.insert(make_pair(16,4));
	numbers.insert(make_pair(25,12));
	unsigned long long T;cin>>T;
	for(unsigned long long i=0;i<T;i++)
		{unsigned long long d,k;cin>>d>>k;
		 if(Police(d,k)){cout<<"possible"<<endl;}
		 else{cout<<"impossible"<<endl;}
//		 cout<<d<<" "<<numbers[d]<<endl;
		}
    /* Enter your code here. Read input from STDIN. Prunsigned long long output to STDOUT */   
    return 0;
}

