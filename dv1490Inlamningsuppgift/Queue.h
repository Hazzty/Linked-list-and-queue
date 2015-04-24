#ifndef QUEUE_H
#define QUEUE_H

#include "IQueue.h"

#pragma region DECLARATION
template <typename T>
class Queue
	: public IQueue <T>
{
public:
	Queue();
	Queue(Queue const &other);
	Queue& operator= (Queue const &other);
	virtual ~Queue();
	void enqueue(const T& element);
	T dequeue();
	T& front() const;
	bool isEmpty() const;

private:
	class Node
	{
	public:
		Node* next;
		T data;

		Node(T data)
		{
			next = nullptr;
			this->data = data;
		}
	};
	int nrOfElements;
	Node* first;
	Node* last;
};
#pragma endregion 

#pragma region CONSTRUCTORS/DESTRUCTOR/OPERATOR OVERLOADS
template <typename T>
Queue<T>::Queue()
{
	nrOfElements = 0;
	first = nullptr;
	last = nullptr;
}

template <typename T>
Queue<T>::~Queue()
{
	while (!isEmpty())
	{
		dequeue();
	}
}

template <typename T>
Queue<T>::Queue(Queue const &other)
{
	if (!other.isEmpty())
	{
		Node* walker = other.first;

		for (int i = 0; i < other.nrOfElements; i++)
		{
			enqueue(walker->data);
			walker = walker->next;
		}
	}
}

template <typename T>
Queue<T>& Queue<T>::operator=(Queue const &other)
{

	if (this != &other)
	{

		while (!isEmpty())
			dequeue();

		if (!other.isEmpty())
		{
			Node* walker = other.first;

			for (int i = 0; i < other.nrOfElements; i++)
			{
				enqueue(walker->data);
				walker = walker->next;
			}
		}

	}
	return *this;
}
#pragma endregion 

#pragma region METHOD DEFINITIONS
template <typename T>
void Queue<T>::enqueue(const T& element)
{

	Node* node = new Node(element);

	if (isEmpty())
		first = last = node;
	else
	{
		last->next = node;
		last = node;
	}
	nrOfElements++;
}

template <typename T>
T Queue<T>::dequeue()
{

	if (isEmpty())
		throw "Exception: Empty queue.";

	else
	{
		/*
			"First in, first out" we need to be able to remove the "first" element to have entered the queue,
			therefore we create a pointer to that node. This in turn allows us to point the actual pointer "first" 
			in the queue to the element "behind" it in the queue.
		*/
		Node* firstPtr = first;		
		T firstData = first->data;	//Store the data of first as we will be deleting the current node at first.

		first = first->next;
		delete firstPtr;

		nrOfElements--;

		return firstData;

	}
}

template <typename T>
T& Queue<T>::front() const
{
	if (isEmpty())
		throw "Exception: Empty queue.";
	else
	return first->data;
}

template <typename T>
bool Queue<T>::isEmpty() const
{
	bool isEmpty;
	if (nrOfElements == 0)
		isEmpty = true;
	else
		isEmpty = false;

	return isEmpty;
}
#pragma endregion 

#endif