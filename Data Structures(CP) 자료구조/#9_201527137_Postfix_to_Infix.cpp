#include<bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
struct et
{
    string value;
    et* left, *right;
};
bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    return false;
}
et* newNode(string v)
{
    et *temp = new et;
    temp->left = temp->right = NULL;
    temp->value = v;
    return temp;
};
 
et* constructTree(string postfix)
{
    stack<et *> st;
    et *t, *t1, *t2;
    string temp;
 
    for (int i=0; i<postfix.length(); i++)
    {
        if (!isOperator(postfix[i]))
        {	
        	temp=postfix[i];
            t = newNode(temp);
            st.push(t);
        }
        else
        {
        	temp=postfix[i];
 
            string op1 = st.top()->value;
            t1 = st.top();
            st.pop();
            string op2 = st.top()->value;
            t2 = st.top();
            st.pop();
            
            t = newNode("(" + op2 + temp + op1 + ")");
 
            t->right = t1;
            t->left = t2;
 
            st.push(t);
        }
    }
    t = st.top();
    st.pop();
    return t;
}
 
int main()
{
	int count, i;
	cin >> count;
	string postfix,temps;
	char temp,c;
	
	for(i=0;i<count;i++){
		cin >> temp;
		postfix+=temp;
	}
    et* r = constructTree(postfix);
    cout << r->value;
    return 0;
}
