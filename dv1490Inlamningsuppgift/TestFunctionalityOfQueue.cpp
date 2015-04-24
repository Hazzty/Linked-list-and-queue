#include "Queue.h"
#include <iostream>

using namespace std;

int main()
{
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	cout<<"Expected output\n0\n1\nQueue is not empty.\nDequeued\n1\n2\nDequeued\n3\n4\n5\n6\nFront element\n7\nDequeued until empty:\n7\nQueue is empty \n\nException: empty queue\n\nException: empty queue\n\n"<<endl<<endl;
	system("pause");
	cout<<endl<<"Your output"<<endl;
	Queue<int> aQueue;

	for (int i=0; i<5; i++)
		aQueue.enqueue(i);

	cout << aQueue.dequeue() << endl;

	cout << aQueue.front() << endl;

	if (!aQueue.isEmpty())
	{
		cout<<"Queue is not empty."<<endl;
	}

	cout << "Dequeued: " << endl;
	cout << aQueue.dequeue() << endl;
	cout << aQueue.dequeue() << endl;

	aQueue.enqueue(5);
	aQueue.enqueue(6);
	aQueue.enqueue(7);

	cout << "Dequeued: " << endl;
	cout << aQueue.dequeue() << endl;
	cout << aQueue.dequeue() << endl;
	cout << aQueue.dequeue() << endl;
	cout << aQueue.dequeue() << endl;

	cout << "Front element: " << endl;
	cout << aQueue.front() << endl;

	cout << "Dequeued until empty: " << endl;
	while (!aQueue.isEmpty())
		cout << aQueue.dequeue() << endl;
	cout<<endl;

	if (aQueue.isEmpty())
		cout<<"Queue is empty"<<endl;
	try
	{
		cout << aQueue.front() << endl;
	}
	catch(char* e)
	{
		cout<<endl<<e<<endl;
	}
	try
	{
		cout << aQueue.dequeue() << endl;
	}
	catch(char* e)
	{
		cout<<endl<<e<<endl;
	}

	for (int i=0; i<200; i++)
		aQueue.enqueue(i);

	for (int i=0; i<190; i++)
		aQueue.dequeue();

	getchar();
	return 0;
}