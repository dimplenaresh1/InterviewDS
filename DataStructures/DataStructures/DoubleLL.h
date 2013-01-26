// CIRCULAR DOUBLE LINKEDLIST

#ifndef __DoubleLL_h
#define __DoubleLL_h

#include "common.h"

namespace data_structure
{
	template <typename T>
	struct LLNode
	{
		T val;
		LLNode<T> *prev;
		LLNode<T> *next;
		LLNode(): prev(NULL), next(NULL), val(0)
		{

		}
	};


	template <typename T>
	class DoubleLL
	{

	public:
		error_ds insert(const T value);
		error_ds deleteLLWrapper();
		error_ds isEmpty();
		error_ds noOfMembers(int &counter);
		error_ds deleteIfOnlyOneNodeAddrIsGivenAndNoHeadWrapper();
		error_ds print();
		DoubleLL(): start(NULL), counter(-1)
		{

		}

	private:
		LLNode<T> *start;
		int counter;
		error_ds deleteIfOnlyOneNodeAddrIsGivenAndNoHead(LLNode<T> *x);
		error_ds deleteLL(LLNode<T> *temp, T &delarg);
	};

	template <typename T>
	error_ds DoubleLL<T> :: deleteLLWrapper()
	{
		error_ds retval;
		int n;
		cout<<"\nEnter the node to be deleted: ";
		cin>>n;
		LLNode<T> *temp;
		temp = start;
		for(int  i=0; ((i < n-1) && (temp->next != NULL)); i++ )
		{
			temp = temp->next;
		}
		int delnum;
		delnum = deleteLL(temp, delnum);
		cout<<"\ndeleted number is\t"<<delnum;
		return retval;
	}

	template <typename T>
	error_ds DoubleLL<T> :: deleteIfOnlyOneNodeAddrIsGivenAndNoHeadWrapper()
	{
		error_ds retval;
		retval = deleteIfOnlyOneNodeAddrIsGivenAndNoHead(start);
		return retval;
	}

	template <typename T>
	error_ds DoubleLL<T> :: deleteIfOnlyOneNodeAddrIsGivenAndNoHead(LLNode<T> *x)
	{
		LLNode<T> *temp;
		temp = x;
		if(temp->next == NULL)
		{
			cout<<"\nNode can not be deleted using this method";
		}
		else
		{
			temp = temp->next;
			x->val = temp->val;
			x->next = temp->next;
			delete temp;
		}

		//delete temp;
		return DS_ERROR_SUCCESS;
	}

	template <typename T>
	error_ds DoubleLL<T> :: insert(const T value)
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
	error_ds DoubleLL<T>  :: deleteLL(LLNode<T> *x, T &delElment)
	{
		error_ds retval;
		retval = isEmpty();
		if (retval == DS_ERROR_EMPTY)
			return retval;

		LLNode<T> *temp;
		temp = start;
		for(int i=0; i<counter-1; i++)
		{
			temp = temp->next;
		}

		delElment = temp->next->val;
		delete temp->next->next;
		temp->next = NULL;
		counter--;
		return DS_ERROR_SUCCESS;
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
		error_ds retval;
		LLNode<T> *temp;
		temp = start;
		cout <<"\n\nPrinting Values in DoubleLL *************\n";
		while(temp->next != NULL)
		{
			cout<< "\n" << temp->val;
			temp = temp->next;
		}
		cout<< "\n" << temp->val;
		retval = DS_ERROR_SUCCESS;
		return retval;
	}

}
#endif