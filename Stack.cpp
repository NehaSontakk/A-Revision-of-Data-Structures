//stack : LIFO
#include<stdio.h>
#include<iostream>
using namespace std;

//Node structure of an element in stack
struct Node{
	int data;							// Stores data
	Node *next;							// Point to next node
};

class Stack{
	public:
	Node *top;							// Top points to the top element of the stack
	Stack(){							// Constructor to initialize top pointer to NULL
		top = NULL;
	}
	
	// Push element on top of stack
	void push(int value){
		Node *temp = new Node();				// Temporary node with value to push
		temp->data = value;
		if(top==NULL){		
			temp->next = NULL;				// If there's no node in the list then temp will point to nothing.
			top = temp;					// Since this is on top, make top point to it.
		}
		else{
			temp->next = top;				// If there are other elements then pushed element will point to top
			top = temp;					// Then it becomes the top
		}
	}
	
	// Remove topmost element with pop
	
	void pop(){
		Node *temp = new Node();
		if(top==NULL){
			cout<<"It's empty, can't pop.";
		}
		else{
			temp = top;					// temp points to the topmost element
			top = top->next;				// top pointer moves on to the next node
			delete temp;					// Delete the old top
		}
	}
	
	// Show all elements in stack
	
	void display(){
		Node *temp = new Node();
		if(top==NULL){
			cout<<"Nothing to see here.";
		}
		else{
			temp = top;					// The temp element points to top
			while(temp!=NULL){				// Print elements till the last node
				cout<<temp->data<<"\t";
				temp=temp->next;
			}
		}
		
	}
	
	//To check if the stack is empty
	
	int isEmpty(){
		return top==NULL;
	}
	
	//To check what the top points to
	void peek(){
		if(!isEmpty()){
			cout<<"Top points to:"<<top->data<<"\n";
		}
	}
	
};

int main(){
	Stack s;
	cout<<"Pushing the first element: ";
	s.push(7);
	s.display();
	cout<<"\n";
	cout<<"Pushing a few other elements: ";
	s.push(8);
	s.push(9);
	s.push(1);
	s.display();
	cout<<"\n";
	cout<<"Delete the top most element: ";
	s.pop();
	s.display();
	cout<<"\n";
	s.peek();
	return 0;
}


/*
OUTPUT
Pushing the first element: 7	
Pushing a few other elements: 1	9	8	7	
Delete the top most element: 9	8	7	
Top points to:9

*/
