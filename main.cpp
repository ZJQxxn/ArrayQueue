//main.cpp : Main funtion to test class:'MyQueue'
#include "MyQueue.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void test1()
{
	MyQueue queue;
	//test enque
	for (int i = 0; i < 10; i++)
	{
		queue.enque(i);
	}
	cout << "Queue1 :";
	queue.print();
	//test deque
	for (int i = 0; i < 5; i++)
	{
		cout << "Deque:" << queue.deque() << endl;
	}

	cout << "Queue1 after deque:";
	queue.print();
}

void test2()
{
	MyQueue queue;
	//test enque
	for (int i = 0; i < 10; i++)
	{
		queue.enque(i);
	}
	cout << "Queue2 :";
	queue.print();
	//test deque
	for (int i = 0; i < 10; i++)
	{
		cout << "Deque:" << queue.deque() << endl;
	}

	cout << "Queue2 after deque:";
	queue.print();
}

void test_split()
{
	MyQueue queue;
	for (int i = 0; i < 10; i++)
	{
		queue.enque(i);
	}
	queue.deque();
	queue.deque();
	queue.enque(15);
	cout << "Queue:";
	queue.print();

	QueuePair pair = queue.split();
	cout << "After split:\n";
	pair.first.print();
	pair.second.print();
}
int main()
{
	//test1();
	//cout << "=============\n";
	//test2();
	test_split();

	system("pause");
	return 0;
}