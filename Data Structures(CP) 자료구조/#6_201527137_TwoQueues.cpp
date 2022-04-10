#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
struct Node {
    int data;
    Node *next;};
class LinkedQueue {
private:
	int len;
public:
	Node *front, *rear;
	LinkedQueue() :len(0) {
        front = rear = NULL;}
	bool isEmpty()
		{return len == 0;}
    void enqueue(int data) {
        Node *node = (Node*)malloc(sizeof(Node));
        node->data = data;
        node->next = NULL;
        if (isEmpty())
            front = rear = node;
        else {
            rear->next = node;
            rear = rear->next;
        }
        len++;
    }
    int dequeue(){
        Node *delNode = front;
        int ret = delNode->data;
        front = delNode->next;
        free(delNode);
        len--;
        return ret;}
    ~LinkedQueue(){}
};
 
int main() {
    LinkedQueue q,p,temp;
    int num,num_A,num_B,i;
	int temp_a,temp_b;
	cin >> num;
	for(i=0;i<num;i++)
	{
		cin >> num_A >> num_B;
		q.enqueue(num_A);
		p.enqueue(num_B);
	}
    while(!q.isEmpty()||!p.isEmpty())
	{
		if(q.isEmpty()||p.isEmpty())
		{
			if(q.isEmpty())
				temp.enqueue(p.dequeue());
			if(p.isEmpty())
				temp.enqueue(q.dequeue());
		}
		else{
			temp_a = q.front->data;
			temp_b = p.front->data;
			if(temp_a>temp_b)
			{
				temp.enqueue(q.dequeue());
			}
			else if(temp_a<temp_b)
			{
				temp.enqueue(p.dequeue());
			}
		}
	}
	while (!temp.isEmpty())
    	cout << temp.dequeue() << endl;
}
