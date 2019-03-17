#include<stdio.h>
#include<iostream>
using namespace std;

// A single node structure contains node data and a pointer to the next node
struct node{
	int data;
	node *next;
};

// We'll create a linked list class 

class List{
	public:
	node *head,*tail;			// Point to the first and last element in the list 
	List(){
		head =NULL;
		tail =NULL;			// To avoid any garbage values the constructor makes our pointers point to NULL 
	}

	 
	void createnode(int value){		// Function to create a node which accepts data we want to put inside the node
		node *temp = new node();	// A pointer of node type 
		temp->data = value;		// We insert the value in it's data field
		temp->next =NULL;		// Coz this is the last node currently
		
		// What if the list is empty?
		if(head == NULL){
			head = temp;		// Since there's nothing in the list the first/head element is the node we're adding
			tail = temp;		// It's also the tail
			temp = NULL;		// temp's already been assigned so just empty it
		}
		else{
		// What if the list already has something?
			tail->next = temp;	// New node added after the last element (tail)
			tail = temp;		// temp is the new tail node
		}
	}


	void display(){				// Function to show everything in the list
		node *temp = new node();	// Make a temporary node
		temp = head;			// Pass the address of the head to it

		while(temp!=NULL){		// As long as temp is pointing to something
			cout<<temp->data<<"\t"; // Print data in current node
			temp = temp->next;	// Move on to the next node
		}
	}

	// Two main operations on the linked list are insertion and deletion 

	// Insertion: 3 Types: Start - Middle - End
	void Insert_Start(int value){
		node *temp = new node();	// Create the node we want to insert
		temp->data = value;		// Insert some value in data
		temp->next = head;		// temp is added to the very start of the list so the next node is the current head node
		head = temp;			// Now we make this new node as the head node
	}
	void Insert_End(int value){
		node *temp = new node();
		temp->data = value;
		tail->next = temp;
		tail = temp;			// This is just like the else case in createnode function
	}
	void Insert_Middle(int position,int value){
		// New node has to be inserted between a node we're pointing to i.e. current node and the previous node
		node *previous = new node();
		node *current = new node();
		node *temp = new node();
		current = head;			// Let's start from the head node
		for(int i=0;i<position;i++){	// From the 0th position till where we want to add our new node
			previous = current;	// The previous node is the current node
			current=current->next;	// current node is the one immediately after previous
		}
		temp->data = value;
		previous->next = temp;		// The previous node will point to 'temp' node we want to insert
		temp->next = current;		// And the inserted node will point to the current node
	}

	// Deletion: 3 Types: Start - Middle - End
	void Delete_Start(){
		node *temp = new node();	// Create a new node
		temp = head;			// Point the node to head position
		head = head->next;		// Move the head pointer to next node
		delete temp;			// Delete the temp/first node
	}
	void Delete_Last(){			// To delete the last node we need to know the second last node and the last node	
		node *previous = new node();	// After traversal of the list, the previous node will point to the second last node
		node *current = new node();	// The current node will point to the last node
		current = head;			// Start from the head node
		while(current->next!=NULL){	// Keep going as long as the current node doesn't cross the end
			previous = current;
			current = current->next;
		}
		tail = previous;		// Make the tail point to second last node
		previous->next = NULL;		// And then the second last one points to nothing
		delete current;			// The current node is still pointing to the last one so delete that shit
	}
	void Delete_Middle(int position){
		node *previous = new node();	// Points to node before the one to be deleted
		node *current = new node();	// Points to the node to be deleted
		current = head;			// Start from head
		for(int i=0;i<position;i++){	// Go to the position of node
			previous = current;	
			current = current->next;
		}
		previous->next = current->next;	// The previous node points to the next node after current
		delete current;			// Current node is now useless so delete it
		
	}	
};

int main()
{
	List l;
	cout<<"Check the working of createnode: \n";
	l.createnode(7);			// check if function createnode works
	l.display();				// check.
	cout<<"\nChecking Insert_start: \n";
	l.Insert_Start(8);			//insert 8 at the start
	l.display();
	cout<<"\nChecking Insert_end: \n";
	l.Insert_End(9);			//insert 9 at the end
	l.display();
	cout<<"\nChecking Insert_Middle: \n";
	l.Insert_Middle(1,3);			//insert 3 at position 1
	l.display();
	cout<<"\nDelete Middle Node: \n";
	l.Delete_Middle(2);			//delete node in position 2
	l.display();
	cout<<"\nDelete First Node: \n";
	l.Delete_Start();			// delete the first node in the list
	l.display();
	cout<<"\nDelete Last Node: \n";
	l.Delete_Last();			// delete the first node in the list
	l.display();
	cout<<"\n";
	return 0;
}
