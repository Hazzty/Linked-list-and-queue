#include "CircularDoubleDirectedList.h"
#include <iostream>

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

template <typename T>
void test(CircularDoubleDirectedList<T> list)
{
	list.addAtCurrent(55);
}

int main()
{
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	CircularDoubleDirectedList<int> aList;
	CircularDoubleDirectedList<int> bList = aList;

	cout<<"******** Testing copy constructor on empty list ********"<<endl;
	cout<<endl<<"Expected output: \nElements in aList: \nElements in bList"<<endl<<endl<<"Your output: "<<endl;
	cout<<"Elements in aList ";
	printList(aList);

	cout<<endl<<"Elements in bList ";
	printList(bList);
	cout<<endl;
	system("pause");
	cout<<endl<<"******** Testing copy constructor on list with content ********"<<endl;
	
	aList.addAtCurrent(10);
	aList.addAtCurrent(20);

	CircularDoubleDirectedList<int> cList = aList;

	cout<<endl<<"Expected output: \nElements in aList 20 10\nElements in cList 20 10"<<endl<<endl<<"Your output: "<<endl;
	cout<<"Elements in aList ";
	printList(aList);

	cout<<endl<<"Elements in cList ";
	printList(cList);
	
	aList.removeAtCurrent();
	cList.addAtCurrent(5);

	cout<<endl<<endl<<"Expected output: \nElements in cList 5 10 20"<<endl<<endl<<"Your output: "<<endl;
	
	test(cList);

	cout<<"Elements in cList ";
	printList(cList);

	cout<<endl;
	system("pause");
	
	CircularDoubleDirectedList<int> dList;
	CircularDoubleDirectedList<int> eList;


	cout<<endl<<endl<<"******** Testing assignment operator on empty list ********"<<endl;
	dList = eList;
	cout<<endl<<"Expected output: \nElements in dList \nElements in eList"<<endl<<endl<<"Your output: "<<endl;
	cout<<"Elements in dList ";
	printList(dList);

	cout<<endl<<"Elements in eList ";
	printList(eList);
	cout<<endl;
	system("pause");
	
	cout<<endl<<endl<<"**** Testing assignment operator on list with content assigned empty list****"<<endl;
	eList.addAtCurrent(20);
	eList.addAtCurrent(10);

	eList = dList;

	cout<<endl<<"Expected output: \nElements in dList\nElements in eList"<<endl<<endl<<"Your output: "<<endl;
	cout<<"Elements in dList ";
	printList(dList);

	cout<<endl<<"Elements in eList ";
	printList(eList);
	cout<<endl;
	system("pause");
	cout<<endl;

	cout<<endl<<"***** Testing assignment operator on empty list assigned list with content *****"<<endl;
	eList.addAtCurrent(20);
	eList.addAtCurrent(10);

	dList = eList;

	cout<<"Expected output: \nElements in dList 10 20 \nElements in eList 10 20"<<endl<<endl<<"Your output: "<<endl;
	cout<<"Elements in dList ";
	printList(dList);

	cout<<endl<<"Elements in eList ";
	printList(eList);
	cout<<endl;

	system("pause");

	dList.addAtCurrent(5);
	eList.removeAtCurrent();
	cout<<endl<<"Expected output: \nElements in dList 5 20 10 \nElements in eList 20"<<endl<<endl<<"Your output: "
		<<endl;
	cout<<"Elements in dList ";
	printList(dList);

	cout<<endl<<"Elements in eList ";
	printList(eList);
	cout<<endl;
	system("pause");

	cout<<endl<<"***** Testing assignment operator on lists with content *****"<<endl;
	
	eList = dList;

	cout<<"Expected output: \nElements in dList 5 20 10 \nElements in eList 5 20 10"<<endl<<endl<<"Your output: "<<endl;
	cout<<"Elements in dList ";
	printList(dList);

	cout<<endl<<"Elements in eList ";
	printList(eList);
	cout<<endl;

	system("pause");

	eList.addAtCurrent(1);
	dList.removeAtCurrent();

	cout<<endl;
	cout<<"Expected output: \nElements in dList 20 10 \nElements in eList 1 20 10 5"<<endl<<endl<<"Your output: "<<endl;
	cout<<"Elements in dList ";
	printList(dList);

	cout<<endl<<"Elements in eList ";
	printList(eList);
	cout<<endl;

	system("pause");

	cout<<endl<<"***** Testing assignment operator on a list assigned itself *****"<<endl;
	
	dList = dList;

	cout<<endl<<"Expected output: \nElements in dList 20 10 "<<endl<<endl<<"Your output: "<<endl;
	cout<<"Elements in dList ";
	printList(dList);
	cout<<endl;

	system("pause");
	cout<<endl<<"***** Testing destructor of list *****"<<endl;
	

	ICircularDoubleDirectedList<int>* fList = new CircularDoubleDirectedList<int>();
	
	fList->addAtCurrent(100);
	fList->addAtCurrent(50);

	delete fList;

	return 0;
}