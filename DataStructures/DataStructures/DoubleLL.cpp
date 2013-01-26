#include"DoubleLL.h"

using namespace data_structure;

template <typename T>
error_ds DoubleLL<T> ::insert(const T value)
{

	LLNode<T> *newNode;
	newNode = new (std::nothrow) LLNode<T>;
	if (NULL == newNode)
	{
		return DS_ERROR_MEMORY_ALLOC_FAIL;
	}
	else
	{

		newNode->val = value;
		newNode->prev = NULL;
		newNode->next = NULL;

		if(start == NULL)
		{
			start = newNode;
			counter++;
		}
		else
		{
			LLNode<T> *temp;
			temp = start;
			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = newNode;
			newNode->prev = temp;
			counter++;

		}
		return DS_ERROR_SUCCESS;
	}
}

template <typename T>
error_ds DoubleLL<T>  :: deleteLL(T &delElement)
{
	error_ds retval;
	retval = isEmpty();
	if (retval == DS_ERROR_EMPTY)
		return retval;

	int delElement;
	LLNode<T> *temp;
	temp = start;
	for(int i=0; i<counter-1; i++)
	{
		temp = temp->next;
	}

	delElement = temp->next->val;
	delete temp->next->next;
	temp->next = NULL;
	counter--;
	return DS_ERROR_SUCCCESS;
}

template <typename T>
error_ds DoubleLL<T>  :: isEmpty()
{
	if (counter == -1)
		return DS_ERROR_EMPTY;
	else
		return DS_ERROR_SUCCESS;
}

template <typename T>
error_ds DoubleLL<T>  :: noOfMembers(int &counterVal)
{
	if(counter == -1)
		return DS_ERROR_EMPTY;
	else
	{
		counterVal = counter+1;
		return DS_ERROR_SUCCESS;
	}
}

template <typename T>
error_ds DoubleLL<T>  :: print()
{
	LLNode<T> *temp;
	temp = start;
	cout <<"\n\n Printing Values in DoubleLL *********************************************************\n";
	while(temp->next != NULL)
	{
		cout<< "\n " << temp->val;
		temp = temp->next;
	}
	cout<< "\n " << temp->val;
}
