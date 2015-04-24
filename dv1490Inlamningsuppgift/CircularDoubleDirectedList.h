#ifndef CDDLIST_H
#define CDDLIST_H

#include "ICircularDoubleDirectedList.h"

#pragma region DECLARATION
template <typename T>
class CircularDoubleDirectedList
	: public ICircularDoubleDirectedList<T>
{
public:

	CircularDoubleDirectedList();
	CircularDoubleDirectedList(CircularDoubleDirectedList const &other);
	virtual ~CircularDoubleDirectedList();
	CircularDoubleDirectedList& operator=(CircularDoubleDirectedList const &other);

	void addAtCurrent(const T& element);
	T& getElementAtCurrent() const;
	void removeAtCurrent();
	int size() const;
	void changeDirection();
	void moveCurrent();
	direction getCurrentDirection() const;

private:
	class Node
	{
	public:
		Node* next;
		Node* prev;
		T data;
		Node(T data)
		{
			next = nullptr;
			prev = nullptr;
			this->data = data;
		}
	};

	int nrOfElements;
	Node* current;
	direction currentDirection;
};

#pragma endregion 

#pragma region CONSTRUCTORS/DESTRUCTOR/OPERATOR OVERLOADS
template <typename T>
CircularDoubleDirectedList<T>::CircularDoubleDirectedList()
{
	this->nrOfElements = 0;
	current = nullptr;
	currentDirection = FORWARD;
}

template <typename T>
CircularDoubleDirectedList<T>::~CircularDoubleDirectedList()
{
	Node* currPtr = current;
	
	for (int i = 0; i < nrOfElements; i++)
	{
		current = current->next;
		delete currPtr;
		currPtr = current;
	}

}

template <typename T>
CircularDoubleDirectedList<T>::CircularDoubleDirectedList(CircularDoubleDirectedList const &other)
{

	current = nullptr;
	currentDirection = FORWARD;
	nrOfElements = 0;

	if (other.nrOfElements > 0)
	{
		Node* othCurr = other.current;

		for (int i = 0; i < other.nrOfElements; i++)
		{
			this->addAtCurrent(othCurr->data);
			othCurr = othCurr->next;
		}

		this->current = this->current->next;
	}
}



template <typename T>
CircularDoubleDirectedList<T>& CircularDoubleDirectedList<T>::operator=(CircularDoubleDirectedList const &other)
{
	if (this != &other)
	{
		if (this->nrOfElements > 0)
		{
			Node* thisCurr = this->current;
			for (int i = 0; i < this->nrOfElements; i++)
			{
				this->current = this->current->next;
				delete thisCurr;
				thisCurr = this->current;
			}
		}

			//Reset to 0 because of addToCurrent iteratation of nrOfElements 
		this->nrOfElements = 0;

		if (other.nrOfElements > 0)
		{
			Node* othCurr = other.current;

			for (int i = 0; i < other.nrOfElements; i++)
			{
				this->addAtCurrent(othCurr->data);
				othCurr = othCurr->next;
			}

			this->current = this->current->next;
		}
	}
	return *this;
}
#pragma endregion

#pragma region METHOD DEFINITIONS
template <typename T>
void CircularDoubleDirectedList<T>::addAtCurrent(const T& element)
{
	Node* node = new Node(element);

	if (nrOfElements == 0)
	{
		current = node;
		current->prev = current;
		node->next = current;
	}
	else
	{
		node->next = current->next;
		node->prev = current;
		current->next = node;
		node->next->prev = node;
		current = node;
	}
	this->nrOfElements++;
}

template <typename T>
T& CircularDoubleDirectedList<T>::getElementAtCurrent() const
{
	if (nrOfElements == 0)
		throw "Exception: call of getElementAtCurrent on empty list.";

	else
	return current->data;
}

template <typename T>
void CircularDoubleDirectedList<T>::removeAtCurrent()
{
	if (nrOfElements == 0)
		throw "Exception: call of removeAtCurrent on empty list.";

	else
	{
		Node* currPtr = current;

		current->prev->next = current->next;	//point the pointer which points to this node pointer to this pointer's next pointer. Pointer.
		current->next->prev = currPtr->prev;	//point the node pointer after this pointer's prev pointer to the pointer before the current pointer. Pointer.
			
		if (currentDirection == FORWARD)
			current = currPtr->next;
		else
			current = currPtr->prev;

		delete currPtr;
		nrOfElements--;
	}
}

template <typename T>
int CircularDoubleDirectedList<T>::size() const
{
	return nrOfElements;
}

template <typename T>
void CircularDoubleDirectedList<T>::changeDirection()
{
	if (currentDirection == FORWARD)
		currentDirection= BACKWARD;
	else
		currentDirection = FORWARD;
}

template <typename T>
void CircularDoubleDirectedList<T>::moveCurrent()
{
	if (nrOfElements == 0)
		throw "Exception: call of moveCurrent on empty list.";
	else
	{
		if (currentDirection == FORWARD)
			current = current->next;
		else
			current = current->prev;
	}
}

template <typename T>
typename ICircularDoubleDirectedList<T>::direction CircularDoubleDirectedList<T>::getCurrentDirection() const
{
	return currentDirection;
}
#pragma endregion

#endif 