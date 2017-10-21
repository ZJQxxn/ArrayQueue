//MyQueue.h : Declaretion of class:'MyQueue'
#ifndef MYQUEUE_H
#define MYQUEUE_H
#include <iostream>
using std::pair;

class MyQueue;
typedef pair<MyQueue, MyQueue> QueuePair;

//see implementations in MyQueue.cpp
class MyQueue
{
private:
	int front, rear;
	int capacity;
	int *queue;
	bool lastOp; //indicate what last operation is;false stand for deque.
public:
	MyQueue();
	bool isFull();
	bool isEmpty();
	void enque(int);
	int deque();
	void print();
	QueuePair split();
};
#endif