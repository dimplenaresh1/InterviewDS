#include"BST.h"

using namespace data_structure;


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

	retVal = ERROR_SUCCESS;
	BSTNode<T> *newNode;

	newNode = new BSTNode;
	newNode->val = num;

	if(NULL == root)
	{
		root = newNode;
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
		}
		else
		{
			prevNode->right = newNode;
		}

	}
	return retVal;
	//error_ds retVal;
	//bool isTreeEmptyRetVal;
	//isTreeEmptyRetVal = isTreeEmpty();

	//if(isTreeEmptyRetVal == false)
	//{
	//	BSTNode<T> *temp;
	//	temp = root;

	//	if(num > temp->val)
	//	{
	//		if(temp->right != NULL)
	//		{
	//			temp = temp->right;
	//		}
	//		else
	//		{
	//			retVal = push_right(num, temp);
	//		}
	//	}
	//	else
	//	{
	//		if(temp->left != NULL)
	//		{
	//			temp = temp->left;
	//		}
	//		else
	//		{
	//			retVal = push_left(num, temp);
	//		}
	//	}

	//	if(num == temp->val)
	//	{
	//		cout << "BST can not contain duplicate values. Try Again! ";
	//	}

	//}

	//else
	//{
	//	root = new BSTNode<T>;
	//	root->left == NULL;
	//	root->right == NULL;
	//	root->val = num;
	//	retVal = DS_ERROR_SUCCESS;
	//}

	//if(retVal==DS_ERROR_SUCCESS)
	//{
	//	counter++;
	//}

	//return retVal;
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

	return retrunval;
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
	cout<<"\n\nPrinting Inorder **********************************";
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
	cout<<"\n\nPrinting preorder **********************************";
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
	cout<<"\n\nPrinting postorder **********************************";
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

