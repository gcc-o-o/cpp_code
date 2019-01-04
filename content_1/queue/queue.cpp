//queue.cpp -- implementation for class Queue
#include "queue.h"
#include <iostream>
using std::cout;

Queue::Queue(int size) : head(nullptr), rear(nullptr), items(0), qsize(size)
{
	//cout << "Queue constructor\n";
	;
}

Queue::~Queue()
{
	//cout << "Queue destructor\n";
	Node * current_Node = head, * next_Node;
	while (current_Node)
	{
		next_Node = current_Node -> next;
		//cout  << " deleted\n";
		delete current_Node;
		current_Node = next_Node;
	}
}

bool Queue::IsEmpty() const
{
	if (items)
		return false;
	return true;
}

bool Queue::IsFull() const
{
	if (items == qsize)
		return true;
	return false;
}

int Queue::QueueCount() const
{
	return items;
}

bool Queue::EnQueue(const Item & item)	//add item to Queue in the end
{
	//cout << "Queue::EnQueue()\n";
	if (IsFull())
		return false;
	//cout << "new Node\n";
	if (rear)
	{
		rear -> next = new Node;	//allot space for new Node in end of Queue
		rear = rear -> next;
	}
	else
	{
		rear = head = new Node;
	}
	//cout << "newed\n";		
	rear -> item = item;			//assignment item to new Node
	rear -> next = nullptr;		//set next pointer of new Node to nullptr
	//cout << "end Queue::EnQueue()\n";
	items++;				//increase 'items'
	return true;
}

bool Queue::DeQueue(Item & item)		//remove item from front
{
	if (IsEmpty())			//if Queue is empty, then return false
		return false;
	Node * temp = head;		//save location of the head item
	item = temp -> item;
	head = head -> next;		//make 'head' point to next Node
	delete temp;			//delete Node
	items--;				//decrease 'items'
	if (items == 0)
		head = rear = nullptr;
	//cout << "Queue::DeQueue()\n";
	return true;
}
