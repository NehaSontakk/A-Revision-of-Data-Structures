// Queue : FIFO
#include<stdio.h>
#include<iostream>
using namespace std;

struct Node{								// Create node structure of element in queue
	int data;
	Node *next;
};

class Queue{
	public:
	Node *front,*rear;						// maintain two pointers: pointing to front and rear
	Queue(){							// initialise with NULL
		front = NULL;
		rear = NULL;
	}
	
	void enqueue(int value){					// Fill the queue up with some value
		Node *temp = new Node();				// Create a temporary node
		temp->data = value;					
		temp->next = NULL;
		if(front == NULL){					// If the queue had no elements in it
			front=rear=temp;				// The front and rear pointers will point to this newly added element
			rear->next = NULL;				//The rear will point to NULL
		}
		else{							//Otherwise
			rear->next = temp;				// new element added after rear pointer element
			rear = temp;					// this new element becomes rear
			rear->next =NULL;				// next of rear position is empty
		}
	}
	
	void dequeue(){							//Remove elements : first element in is first element out
		Node *temp=new Node();
		if(!isEmpty()){						// as long as the queue is not empty
			temp=front;					// Point to the first element i.e. front
			front=front->next;				// Then move the front to next element
			delete(temp);					// delete the one we want to
		}
		else{
			cout<<"Empty";
		}
	}
	void display(){							// function to show data from start/first element added to end/last
		Node *temp = new Node();
		temp=front;
		while(temp != NULL){
			cout<<temp->data<<"\t";
			temp = temp->next;
		}
	}
	
	void peek(){							// display what the front pointer contains
		cout<<front->data;
	}
	int isEmpty(){							// check if queue is empty
		return(front==NULL);
	}
};

int main(){
	Queue q;
	cout<<"Enque Operation test: \n";
	q.enqueue(8);
	q.enqueue(3);
	q.enqueue(1);
	q.display();
	cout<<"\nDequeue(delete the element added first) Operation test: \n";
	q.dequeue();
	q.display();
	cout<<"\nPeek operation: \n";
	q.peek();
	cout<<"\n";
	return 0;
}

/*
OUTPUT
Enque Operation test: 
8	3	1	
Dequeue(delete the element added first) Operation test: 
3	1	
Peek operation: 
3

*/
