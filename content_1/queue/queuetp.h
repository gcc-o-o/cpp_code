//queuetp.h -- queue template with nested class
#ifndef QUEUETP_H_
#define QUEUETP_H_

template <typename Item>
class Queue
{
private:
	enum {Q_SIZE=10};
	class Node
	{
	public:
		Item item;
		Node * next;
		Node (const Item & i);
	};
	Node * front;	//pointer to front of queue
	Node * rear;	//pointer to rear of queue
	int items;		//current number of items in queue
	const int qsize;//maximum of items in queue
	Queue(const Queue & qtp) {}
	Queue & operator=(const Queue & qtp) {return *this;}
public:
	Queue(int q = Q_SIZE);
	~Queue();
	bool isFull();
	bool isEmpty();
	bool enQueue(const Item & i);
	bool deQueue(Item & i);
};


//class Queue methods
template<typename Item>
Queue<Item>::Queue(int q)
: qsize(q)
{
	front = rear = nullptr;
	items = 0;
}

template<typename Item>
Queue<Item>::~Queue()
{
	Node * temp;
	while (front != 0)
	{
		temp = front;
		front = front -> next;
		delete temp;
	}
}

template<typename Item>
bool Queue<Item>::isFull()
{
	return items == qsize;
}

template<typename Item>
bool Queue<Item>::isEmpty()
{
	return items == 0;
}

template<typename Item>
bool Queue<Item>::enQueue(const Item & i)
{
	if (isFull())
		return false;
	Node * nd = new Node(i);
	if (front == nullptr)
		front = nd;
	else
	{
		rear -> next = nd;
	}
	rear = nd;
	items++;
}

template<typename Item>
bool Queue<Item>::deQueue(Item & i)
{
	if (isEmpty())
		return false;
	i = front -> item;
	Node * temp = front;
	front = front -> next;
	if (front == rear)
		rear = nullptr;
	items--;
	delete temp;
}


//nested class Node methods
template<typename Item>
Queue<Item>::Node::Node(const Item & i)
: item(i), next(nullptr) {}

#endif