//queue.h -- implementation for abstract data type - ADT

#ifndef QUEUE_H_
#define QUEUE_H_
#include <string>
#include "customer.h"
using std::string;
typedef struct Customer Item;

class Queue
{
private:
	//Node is a nested structure definition local to this class
	struct Node{Item item; Node * next;};
	Node * head;			//pointer to head of Queue
	Node * rear;			//pointer to rear of Queue
	int items;				//current number of items in Queue
	const int qsize;			//maximum number of items in Queue
	const static int Q_SIZE = 10;		//default maximum of items in Queue

	//copy constructor and assignment operator preemptive definition
	Queue(const Queue &q) :qsize{Q_SIZE} {}
	Queue & operator=(const Queue &q) {return *this;}
public:
	Queue(int size);			//create Queue with a limit - Q_SIZE
	~Queue();
	bool IsEmpty() const;
	bool IsFull() const;
	int QueueCount() const;
	bool EnQueue(const Item & item);	//add item to Queue in the end
	bool DeQueue(Item & item);		//remove front 'Node' from the front, pass
					//the item of the 'Node' to item in parameter list
};

#endif
