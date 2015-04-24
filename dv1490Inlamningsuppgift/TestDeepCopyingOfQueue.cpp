#include "Queue.h"
#include <iostream>

using namespace std;

int main()
{
	Queue<int> aQueue;
	Queue<int> bQueue = aQueue;

	aQueue.enqueue(10);
	aQueue.enqueue(30);

	bQueue.enqueue(55);
	cout<<"**** Test of copy constructor ****"<<endl<<endl;
	cout<<"Expected output: 10 30 55"<<endl<<endl;
	cout<<"Your output: ";

	while (!aQueue.isEmpty())
		cout<<aQueue.dequeue()<<" ";
	while (!bQueue.isEmpty())
		cout<<bQueue.dequeue()<<" ";
	
	cout<<endl;
	system("pause");
	cout<<endl;

	aQueue.enqueue(10);
	aQueue.enqueue(20);
	Queue<int> cQueue = aQueue;

	cQueue.dequeue();

	cout<<endl<<"Expected output: 10 20 20 "<<endl<<endl;
	cout<<"Your output: ";

	while (!aQueue.isEmpty())
		cout<<aQueue.dequeue()<<" ";
	while (!cQueue.isEmpty())
		cout<<cQueue.dequeue()<<" ";
	cout<<endl;

	cout<<endl;
	system("pause");
	cout<<endl;
	cout<<endl<<" **** Test of assignment operator *****"<<endl<<endl;

	Queue<int> dQueue;
	Queue<int> eQueue;

	dQueue.enqueue(30);
	dQueue.enqueue(20);
	dQueue.enqueue(10);

	eQueue.enqueue(50);
	eQueue.enqueue(40);

	dQueue = eQueue;

	cout<<endl<<"Expected output: 50 40 50 40"<<endl<<endl;
	cout<<"Your output: ";

	while (!dQueue.isEmpty())
		cout<<dQueue.dequeue()<<" ";
	while (!eQueue.isEmpty())
		cout<<eQueue.dequeue()<<" ";
	cout<<endl;


	getchar();
	return 0;
}