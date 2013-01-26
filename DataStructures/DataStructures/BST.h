#ifndef __BST_h
#define __BST_h

#include"common.h"

namespace data_structure
{

	template <typename T>
	struct BSTNode
	{
		BSTNode *left;
		BSTNode *right;
		T val;

		BSTNode(): left(NULL), right(NULL), val(0) {}

	};

	enum bst_order
	{
		BST_PREORDER,
		BST_INORDER,
		BST_POSTORDER
	};

	template <typename T>
	class BST
	{
	public:
		bool isTreeEmpty();

		error_ds insert(T val);
		error_ds print(bst_order order);
		int numberOfNodes();

		BST(): root(NULL), counter(0) {}

	private:
		BSTNode<T> *root;
		int counter;

		error_ds push_left(T num, BSTNode<T> *temp);
		error_ds push_right(T num, BSTNode<T> *temp);
		error_ds print_inorder(BSTNode<T> *root);
		error_ds print_preorder(BSTNode<T> *root);
		error_ds print_postorder(BSTNode<T> *root);

	};




	template <typename T>
	bool BST<T> :: isTreeEmpty()
	{
		if(counter == 0)
			return true;
		else
			return false;
	}

	template <typename T>
	error_ds BST<T> :: insert(T num)
	{
		error_ds retVal;

		retVal = DS_ERROR_FAIL;
		BSTNode<T> *newNode;

		newNode = new BSTNode<T>;
		newNode->val = num;

		if(NULL == root)
		{
			root = newNode;
			retVal = DS_ERROR_SUCCESS;
		}
		else
		{
			BSTNode<T> *prevNode;
			BSTNode<T> *iter;

			iter = root;

			while(iter)
			{
				prevNode = iter;

				if(num < iter->val)
				{
					iter = iter->left;
				}
				else
				{
					iter = iter->right;
				}
			}

			if(num < prevNode->val)
			{
				prevNode->left = newNode;
				retVal = DS_ERROR_SUCCESS;
			}
			else
			{
				prevNode->right = newNode;
				retVal = DS_ERROR_SUCCESS;
			}

		}

		if(retVal == DS_ERROR_SUCCESS)
		{
			counter++;
		}
		return retVal;
	}

	template <typename T>
	error_ds BST<T> :: print(bst_order order)
	{
		error_ds returnval;

		if(order == BST_PREORDER)
			returnval =	print_preorder(root);
		if(order ==	BST_INORDER)
			returnval =	print_inorder(root);
		if(order ==	BST_POSTORDER)
			returnval =	print_postorder(root);

		return returnval;
	}

	template <typename T>
	int BST<T> :: numberOfNodes()
	{
		return counter;
	}

	template <typename T>
	error_ds BST<T> :: push_left(T num, BSTNode<T> *temp)
	{
		BSTNode<T> *temp1;
		temp1 = new BSTNode<T>;
		if(NULL == temp1)
		{
			return DS_ERROR_MEMORY_ALLOC_FAIL;
		}
		temp->left = temp1;
		temp1->left = NULL;
		temp1->right = NULL;
		temp1->val = num;
		return DS_ERROR_SUCCESS;
	}

	template <typename T>
	error_ds BST<T> ::  push_right(T num, BSTNode<T> *temp)
	{
		BSTNode<T> *temp1;
		temp1 = new (std::nothrow) BSTNode();
		if(NULL == temp1)
		{
			return DS_ERROR_MEMORY_ALLOC_FAIL;
		}
		temp->right = temp1;
		temp1->left = NULL;
		temp1->right = NULL;
		temp1->val = num;
		return DS_ERROR_SUCCESS;
	}

	template <typename T>
	error_ds BST<T> ::  print_inorder(BSTNode<T> *root)
	{
		//cout<<"\n\nPrinting Inorder **********************************";
		if(root == NULL)
			return DS_ERROR_SUCCESS;
		else
		{
			print_inorder(root->left);
			cout<< "\n" << root->val;
			print_inorder(root->right);
		}
		return DS_ERROR_SUCCESS;
	}

	template <typename T>
	error_ds BST<T> ::  print_preorder(BSTNode<T> *root)
	{
		if(root == NULL)
			return DS_ERROR_SUCCESS;
		else
		{
			cout<< "\n" << root->val;
			print_preorder(root->left);
			print_preorder(root->right);
		}
		return DS_ERROR_SUCCESS;
	}

	template <typename T>
	error_ds BST<T> ::  print_postorder(BSTNode<T> *root)
	{
		//cout<<"\n\nPrinting postorder **********************************";
		if(root == NULL)
			return DS_ERROR_SUCCESS;
		else
		{
			print_postorder(root->left);
			print_postorder(root->right);
			cout<< "\n" << root->val;
		}
		return DS_ERROR_SUCCESS;
	}
}



#endif