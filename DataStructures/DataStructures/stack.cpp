#include"stack.h"

using namespace data_structure;

template <typename T>
error_ds Stack<T> ::push(T value)
{

	stackNode<T> *newNode;
	newNode = new (std::nothrow) stackNode<T>;
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
			stackNode<T> *temp;
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
error_ds Stack<T>  :: pop(T &poppedelement)
{
	error_ds retval;
	retval = isEmpty();
	if (retval == DS_ERROR_EMPTY)
		return retval;

	int poppedelement;
	stackNode<T> *temp;
	temp = start;
	for(int i=0; i<top-1; i++)
	{
		temp = temp->next;
	}

	poppedelement = temp->next->val;
	delete temp->next->next;
	temp->next = NULL;
	top--;
	return DS_ERROR_SUCCCESS;
}

template <typename T>
error_ds Stack<T>  :: isEmpty()
{
	if (top == -1)
		return DS_ERROR_EMPTY;
	else
		return DS_ERROR_SUCCESS;
}

//template <typename T>
//error_ds Stack<T>  :: isFull()
//{
//
//	return DS_ERROR_STACK_FULL;
//	else
//		return DS_ERROR_STACK_SUCCESS;
//}

template <typename T>
error_ds Stack<T>  :: noOfMembers(int &counter)
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
error_ds Stack<T>  :: print()
{
	error_ds retval;
	retval = isEmpty();
	if (retval == DS_ERROR_EMPTY)
		return retval;
	else
	{
		stackNode<T> *temp;
		temp = start;
		cout <<"\n\n Printing Values in Stack *********************************************************\n";
		while(temp->next != NULL)
		{
			cout<< "\n " << temp->val;
			temp = temp->next;
		}
		cout<< "\n " << temp->val;
		return DS_ERROR_SUCCESS;
	}
}
