#include "CircularDoubleDirectedList.h"
#include <iostream>
#include <string>

using namespace std;
template <typename T>
void printList(CircularDoubleDirectedList<T>& list)
{
	for (int i=0; i<list.size(); i++)
	{
		cout<<list.getElementAtCurrent()<<" ";
		list.moveCurrent();
	}
}

int main()
{
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	CircularDoubleDirectedList<int> aList;

	cout<<"********** Testing addAtCurrent, get and move function: **********"<<endl;
	aList.addAtCurrent(100);
	cout<<endl<<"Expected output: 100"<<endl<<"Your output: ";
	printList(aList);


	aList.addAtCurrent(50);
	cout<<endl;
	system("pause");
	cout<<endl<<"Expected output: 50 100"<<endl<<"Your output: ";
	printList(aList);

	aList.addAtCurrent(10);

	cout<<endl;
	system("pause");
	cout<<endl<<"Expected output: 10 100 50"<<endl<<"Your output: ";
	printList(aList);

	cout<<endl;
	system("pause");
	
	cout<<endl<<"**************  Testing the changeDirection function: *************"<<endl;
	aList.changeDirection();
	
	cout<<endl<<"Expected output: 10 50 100"<<endl<<"Your output: ";
	printList(aList);

	aList.changeDirection();
	
	cout<<endl;
	system("pause");
	cout<<endl<<"Expected output: 10 100 50"<<endl<<"Your output: ";
	printList(aList);
	
	cout<<endl;
	system("pause");
	cout<<endl<<"**************  Testing the remove function: *************"<<endl;
	
	aList.removeAtCurrent();

	cout<<endl<<"Expected output: 100 50"<<endl<<"Your output: ";
	printList(aList);

	aList.removeAtCurrent();

	cout<<endl;
	system("pause");
	cout<<endl<<"Expected output: 50 "<<endl<<"Your output: ";
	printList(aList);
	
	
	aList.removeAtCurrent();

	cout<<endl;
	system("pause");
	cout<<endl<<"Expected output: "<<endl<<"Your output: ";
	printList(aList);

	cout<<endl;
	system("pause");

	cout<<endl<<"**************  Testing excpetion of get function: *************"<<endl;

	cout<<endl<<"Expected output: Exception: call of getElementAtCurrrent on empty list"<<endl<<"Your output: ";
	try
	{
		cout<<aList.getElementAtCurrent();
	}
	catch (char* e)
	{
		cout<<e<<endl;
	}

	cout<<endl;
	system("pause");

	cout<<endl<<"**************  Testing excpetion of remove function: *************"<<endl;

	cout<<endl<<"Expected output: Exception: call of removeAtCurrent on empty list"<<endl<<"Your output: ";
	try
	{
		aList.removeAtCurrent();
	}
	catch (char* e)
	{
		cout<<e<<endl;
	}

	cout<<endl;
	system("pause");

	cout<<endl<<"**************  Testing directions: *************"<<endl;

	cout<<endl<<"Expected output: FORWARD\nBACKWARD"<<endl<<"Your output: ";

	if (aList.getCurrentDirection() == ICircularDoubleDirectedList<int>::FORWARD)
	{
		cout<<"FORWARD"<<endl;
	}
	else
	{
		cout<<"BACKWARD"<<endl;
	}

	aList.changeDirection();

	if (aList.getCurrentDirection() == ICircularDoubleDirectedList<int>::FORWARD)
	{
		cout<<"FORWARD"<<endl;
	}
	else
	{
		cout<<"BACKWARD"<<endl;
	}

	getchar();
	return 0;
}