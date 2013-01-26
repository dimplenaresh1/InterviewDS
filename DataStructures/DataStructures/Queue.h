#ifndef __Queue_h
#define __Queue_h

#include"common.h"

namespace data_structure
{

	template <typename T>
	struct queueNode
	{
		T val;
		queueNode<T> *next;
		queueNode(): next(NULL), val(0)
		{

		}
	};


	template <typename T>
	class Queue
	{

	public:
		error_ds push(const T value);
		error_ds pop(T &poparg);
		error_ds isEmpty();
		error_ds noOfMembers(int &counter);
		error_ds print();
		Queue(): start(NULL), top(-1)
		{

		}

	private:
		queueNode<T> *start;
		int top;


	};


	template <typename T>
	error_ds Queue<T> ::push(const T value)
	{

		queueNode<T> *newNode;
		newNode = new (std::nothrow) queueNode<T>;
		if (NULL == newNode)
		{
			return DS_ERROR_MEMORY_ALLOC_FAIL;
		}
		else
		{

			newNode->val = value;
			newNode->next = NULL;
			if(start == NULL)
			{
				start = newNode;
				top++;
			}
			else
			{
				queueNode<T> *temp;
				temp = start;
				while(temp->next != NULL)
				{
					temp = temp->next;
				}
				temp->next = newNode;
				top++;

			}
			return DS_ERROR_SUCCESS;
		}
	}

	template <typename T>
	error_ds Queue<T>  :: pop(T &poppedelement)
	{
		error_ds retval;
		retval = isEmpty();
		if (retval == DS_ERROR_EMPTY)
			return retval;

		int poppedelement;
		queueNode<T> *temp;
		temp = start->next;
		poppedelement = start->val;
		delete start;
		start = temp;
		top--;
		return DS_ERROR_SUCCCESS;
	}

	template <typename T>
	error_ds Queue<T>  :: isEmpty()
	{
		if (top == -1)
			return DS_ERROR_EMPTY;
		else
			return DS_ERROR_SUCCESS;
	}


	template <typename T>
	error_ds Queue<T>  :: noOfMembers(int &counter)
	{
		if(top == -1)
			return DS_ERROR_EMPTY;
		else
		{
			counter = top+1;
			return DS_ERROR_SUCCESS;
		}
	}

	template <typename T>
	error_ds Queue<T>  :: print()
	{
		error_ds retval;
		retval = isEmpty();
		if (retval == DS_ERROR_EMPTY)
			return retval;
		else
		{
			queueNode<T> *temp;
			temp = start;
			cout <<"\n\n Printing Values in queue *********************************************************\n";
			while(temp->next != NULL)
			{
				cout<< "\n " << temp->val;
				temp = temp->next;
			}
			cout<< "\n " << temp->val;
			return DS_ERROR_SUCCESS;
		}
	}
}

#endif