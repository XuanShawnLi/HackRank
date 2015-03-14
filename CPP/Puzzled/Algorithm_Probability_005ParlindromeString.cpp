/*
Problem Statement

Given a string, you keep swapping any two characters in the string randomly till the string becomes a palindrome. What is the expected number of swaps you will make? There will always be at least one palindrome which can be formed with the letters of the given string.

Input: 
The first line contains the number of test cases T. Each of the next T lines contains a string each.

Output: 
Output T lines containing the answer for the corresponding test case. Print the answer rounded to exactly 4 decimal places.

Constraints: 
T <= 10000 
The length of the string will be at most 8 characters. 
The string will consist of only lower-case letters 'a'-'z'.

Sample Input:

4  
b  
bb  
abb  
cbaabbb
Sample Output:

0.0000  
0.0000  
3.0000  
59.3380
Explanation:

For the first two cases, the string is already a palindrome so no swaps are needed.

For the third case, there are 3 possible swaps. The string will become "bab","bba" or remain "abb" with 1/3rd probability each. It's easy to see that the expected number of swaps needed is 3.0000

For the last case, the answer is 59.337962..., which should be printed as 59.3380
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

