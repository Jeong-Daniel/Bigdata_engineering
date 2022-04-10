#include <iostream>
#include <cassert>
#include <bits/stdc++.h>

using namespace std;

class Node {
    int   data;
    Node *next;
public:
    friend class Stack;
    Node(int d, Node *n): data(d), next(n) {}
};

class Stack {
    Node *fst;
public:
    Stack(): fst(nullptr) {}
    void push(int n) {
        Node *prev = fst;
        fst = new Node(n, prev);}
    void pop() {
        fst = fst->next;}
    int top() {
        return fst->data;}
    bool isEmpty() {
        return fst == nullptr;}

    class Iterator {
        Node *curr;
    public:
        Iterator(Node *np=nullptr): curr(np) {}
        Iterator& operator =(const Iterator &p) {
            curr = p.curr;
            return *this;
        }
        bool operator !=(const Iterator &p) {
            return this->curr != p.curr;
        }
        int operator *() {
            return curr->data;
        }
        Node* operator ++() {
            return (curr = curr->next);
        }
        Iterator operator +(int delta) {
            assert(delta >= 0);
            Node *p = curr;
            while (delta-- > 0) {
                p = p->next;
            }
            return p;
        }
    };

    Iterator begin() {
        return fst;}
    Iterator end() {
        return nullptr;}

    ostream& print(ostream& out) {
        for (Iterator p = begin(); p != end(); ++p) {
            out << *p << (p + 1 != end()? " ": "\n");}
        return out;
    }
};

int main() {
    Stack s, tmpStack;
    int count,i,number;
	cin >> count;
	for(i=0;i<count;i++)
	{
		cin >> number;
		s.push(number);
	}
    while (!s.isEmpty()) 
	{ 
	    int tmp = s.top(); 
	    s.pop(); 
	  
	    while (!tmpStack.isEmpty() && tmpStack.top() < tmp) 
	    { 
	        s.push(tmpStack.top()); 
	        tmpStack.pop(); 
	    } 
	    tmpStack.push(tmp); 
	}
	tmpStack.print(cout);
}
