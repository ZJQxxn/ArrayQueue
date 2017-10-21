//MyQueue.cpp : Implementations of class:'MyQueue'
#include "MyQueue.h"
#include <iostream>
using std::cout;
using std::endl;
#define INIT_SIZE	10

//Constructor
MyQueue::MyQueue()
	:front(0)
	, rear(-1)
	, capacity(INIT_SIZE)
	, lastOp(false)
{
	queue = new int[capacity];
}


//operations
/*
	Determine whether queue is full.

	Return:bool
*/
bool MyQueue::isFull()
{
	//if rear catch up with front and last operation is enqueue,queue is full.
	return ((rear+1)%capacity == front) && (lastOp == true);
}

/*
Determine whether queue is full.

Return:bool
*/
bool MyQueue::isEmpty()
{
	int relRear = (rear + 1) % capacity;
	int realFront = (front + 1) % capacity;
	return (relRear == (realFront - 1)) && (lastOp == false);
}

/*
	Enqueue an element.

	Parameter:num	int		The element.

	Return:void
*/
void MyQueue::enque(int num)
{
	if (isFull())
	{
		cout << "Queue full!" << endl;
		return;
	}
	else
	{
		rear = (rear + 1) % capacity;
		queue[rear] = num;
		lastOp = true;
	}
}

/*
	Dequeue an element.

	Return:int	 The element dequeued.
*/
int MyQueue::deque()
{
	if (isEmpty())
	{
		cout << "Queue empty!" << endl;
		return INT_MIN;
	}
	else
	{
		lastOp = false;
		int num = queue[front];
		front = (front + 1) % capacity;
		return num;
	}
}

/*
	Print queue from front to rear.

	Return:void
*/
void MyQueue::print()
{
	/*	If a queue is empty, just print message .
		Because in deque operation, we do not 
		delete the number, just move the front 
		pointer,so we can't print a empty queue 
		as usual.
	*/
	if (isEmpty())
	{
		cout << "queue empty" << endl;
		return;
	}
	int i = front;
	while (i !=rear)
	{
		cout << queue[i] << "  ";
		i = (i + 1) % capacity;
	}
	cout << queue[rear] << endl;
}

/*
	Split a queue into two queues.

	Return:type:'QueuePair'	  A pair of queues.
*/
QueuePair MyQueue::split()
{
	if (isEmpty())
	{
		cout << "Empty queue can't be splited!" << endl;
		return QueuePair();
	}

	MyQueue first;
	MyQueue second;
	//calculate half size of queue
	int halfSize = (rear < front) ? ((rear + capacity) - front + 1) / 2 : (rear - front + 1) / 2;
	
	//split into iwo queues
	int i = front;
	
	//just copy 'halfSize' elements no matter the location of front
	while (i < (front + halfSize))
	{
		first.enque(queue[i%capacity]);
		i++;
	}
	//reset 'i' if 'i' exceed capacity
	i %= capacity;

	//loop times depend on the location of rear
	while (i <= ((rear<i)?(rear+capacity):rear))
	{
		second.enque(queue[i%capacity]);
		i++;
	}

	return QueuePair(first, second);
}