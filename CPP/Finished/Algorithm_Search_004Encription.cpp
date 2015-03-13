/*


Problem Statement

An English text needs to be encrypted using the following encryption scheme.
First the spaces are removed from text, let L be the length of this text.
Then, characters are written into a grid, whose rows and columns have the following constraints:

    ⌊L‾‾√⌋≤rows≤column≤⌈L‾‾√⌉, where ⌊x⌋ is floor function and ⌈x⌉ is ceil function

For example, the sentence if man was meant to stay on the ground god would have given us roots after removing spaces is 54 characters long, so it is written in the form of a grid with 7 rows and 8 columns.

ifmanwas  
meanttos          
tayonthe  
groundgo  
dwouldha  
vegivenu  
sroots

    Ensure, rows×columns≥L
    If multiple grids satisfy the above conditions, choose the one with the minimum area i.e. rows×columns.

The encoded message is obtained by displaying the characters in a column, inserting a space, and then displaying the next column and inserting a space and so on.For example, the encoded message for the above rectangle is:

imtgdvs fearwer mayoogo anouuio ntnnlvt wttddes aohghn sseoau

You will be given a message in English with no spaces between the words. The maximum message length can be 81 characters. Print the encoded message.

Here are some more examples:

Sample Input:

haveaniceday

Sample Output:

hae and via ecy

Sample Input:

feedthedog    

Sample Output:

fto ehg ee dd

Sample Input:

chillout

Sample Output:

clu hlt io

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string Encription(string str){
	string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
	str.erase(end_pos, str.end());
	int L=str.length();
	int row=floor(sqrt(L));
	int col=ceil(sqrt(L));
	while(row*col<L){row++;}
	vector<string> container;
	int ir;
	for(ir=0;ir<row-1;ir++){container.push_back(str.substr(ir*col,col));}
	container.push_back(str.substr(ir*col));
	string result;
	for(int ic=0;ic<col;ic++)
		{string tmp="";
		 for(ir=0;ir<row-1;ir++){tmp+=container[ir][ic];}
		 if(ic<container[row-1].length()){tmp+=container[ir][ic];}
		 result+=tmp;
		 if(ic!=col-1){result+=" ";}
		}
	return result;
}

int main() {
	string str;
	getline(cin,str);
	cout<<Encription(str)<<endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

