#include <iostream> 
using namespace std; 

class Node{
	int data;
	Node *next;
	friend class Stack;
public:
	Node(int d, Node *p): data(d),next(p){}
};

class Stack{
	Node *fst;
	public:
		Stack(): fst(NULL){}
		void push(int n){
			Node *prev = fst;
			fst=new Node(n,prev);}
		void pop(){
			fst = fst->next;}
		int top(){
			return fst->data;}
		bool isEmpty(){
			return fst==NULL;}};
			
			
int main() 
{ 	int n;
	cin >> n;
	int in[n], out[n];
	for(int i =0 ; i<n ; i++){
		in[i] = i+1;
		cin >> out[i];}

	Stack s;
	int j =0;
	for(int i =0 ; i< n ; i++){
	s.push(in[i]);
		for(; !s.isEmpty()&&s.top()==out[j] ; j++){
			s.pop();
		}
	}
	if(j==n)
		cout << 1 << endl;
	else{
		cout << 0 << endl;}	
} 
