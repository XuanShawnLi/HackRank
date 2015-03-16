/*
Given a tree with N vertices numbered from 1 to N. The vertex 1 is the root of the tree. Each vertex is assigned with an integer weight. A remove operation can remove sub-tree rooted at an arbitrary vertex u. You must use at most K remove operations (possibly zero) so that the total weight of the remaining vertices is largest.

Input Format
The first line contains two integers N,K.
The second line contains N integers, the ith integer is the weight of the ith vertex.
Each of the next N−1 lines contains a pair of integers u and v, which represents an edge from vertex u to vertex v.

Output Format
Print out a single integer which is the largest total weight of the remaining vertices.

Constraints
2≤N≤105
1≤K≤200
−109≤weight≤109

Sample Input

5 2
1 1 -1 -1 -1
1 2
2 3
4 1
4 5

Sample Output

2

Explanation
We use 2 remove operations: one for the sub-tree rooted at 3 and the other one for the sub-tree rooted at 4. There are only 2 remaining vertices which are 1 and 2. The total weight is 1+1=2. 
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;

class Node
{public:
 vector<Node*> children;
 Node* parent;
 long long Sums;
 int weight;
 Node(int val):weight(val),Sums(-0xffffff),parent(NULL){};
 bool HasNegative()
	{int n=children.size();
	 for(int i=0;i<n;i++)
		{if(children[i]->HasNegative()){return true;}}
	 return false;
	}
 void RemoveChildren(Node* c)
	{vector<Node*>::iterator it;
	 it=find(children.begin(),children.end(),c);
	 children.erase(it);
	}
};

Node* BuildTree(int* W,pair<int,int>* Edges,int N){
	Node* tmp;
	vector<Node*> list;
	for(int i=0;i<N;i++)
		{tmp=new Node(W[i]);
		 list.push_back(tmp);
		}
	for(int i=0;i<N-1;i++)
		{int a1=Edges[i].first-1;
		 int a2=Edges[i].second-1;
		 if(a1==0){list[a1]->children.push_back(list[a2]);list[a2]->parent=list[a1];}
		 else if(a2==0){list[a2]->children.push_back(list[a1]);list[a1]->parent=list[a2];}
		 else//tricky part
			{if(list[a1]->parent==NULL)
				{list[a2]->children.push_back(list[a1]);list[a1]->parent=list[a2];}
			 else
				{list[a1]->children.push_back(list[a2]);list[a2]->parent=list[a1];}
			}
		}
	return list[0];
}

void PrintTree(Node* top){
	if(top==NULL){return;}
	cout<<top->weight<<" with Sums"<<top->Sums<<" ";
	if(top->parent==NULL){cout<<"has no parent"<<" ";}
	else{cout<<"has parent"<<top->parent->weight<<" ";}
	int n=top->children.size();
	if(n==0){cout<<"has no children"<<endl;return;}
	else{cout<<"has children"<<" ";}
	for(int i=0;i<n;i++)
		{cout<<top->children[i]->weight<<" ";
		}
	cout<<endl;
	for(int i=0;i<n;i++)
        {PrintTree(top->children[i]);
		}
}

long long BuildSums(Node* top, Node* &largest){
	long long result=top->weight;
	int n=top->children.size();
	for(int i=0;i<n;i++)
		{result+=BuildSums(top->children[i],largest);
		}
	top->Sums=result;
	if(result<0 and top->parent!=NULL)//non-head node with a negative sum
		{if(largest==NULL or largest->Sums>result){largest=top;}
		}
	return result;

}

int BestTree(int* W,pair<int,int>* Edges,int N,int K){
	//build the tree based on edges, it is not necessarily a binary tree
	Node* top=BuildTree(W,Edges,N);
	Node* largest=NULL;
	//build all the sums
	top->Sums=BuildSums(top,largest);
	PrintTree(top);exit(1);
	long long result=top->Sums;
	while(K>0 and largest!=NULL)
		{result-=largest->Sums;
		 largest->parent->RemoveChildren(largest);
		 largest=NULL;
		 top->Sums=BuildSums(top,largest);
		 K--;
		}
	return top->Sums;
}

int main() {
	int N,K;cin>>N>>K;
	int *W=new int[N];
	for(int i=0;i<N;i++){cin>>W[i];W[i]=W[i]/10000000;}
	pair<int,int> *Edges=new pair<int,int>[N-1];
	int tmp1,tmp2;
	for(int i=0;i<N;i++){cin>>tmp1>>tmp2;Edges[i].first=tmp1;Edges[i].second=tmp2;}
	cout<<BestTree(W,Edges,N,K)<<endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

