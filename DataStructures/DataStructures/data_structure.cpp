#include "data_structure.h"

using namespace data_structure;

int main(int argc, char *argv[])
{
	//********************************************  bst  ************************************************
	BST<int> obj;

	error_ds chkretval;

	chkretval = obj.insert(4);
	chkretval = obj.insert(5);
	chkretval = obj.insert(9);
	chkretval = obj.insert(12);
	chkretval = obj.insert(6);
	chkretval = obj.insert(8);
	chkretval = obj.insert(2);
	chkretval = obj.insert(3);
	chkretval = obj.insert(1);
	if(chkretval == DS_ERROR_EMPTY)
		cout<< "\ninsertion in BST was not successful\n";
	else
		cout<< "\ninsertion in BST was successful\n";

	cout<<"\n\n************ printing bst in preorder ************\n\n";

	chkretval = obj.print(BST_PREORDER);
	if(chkretval == DS_ERROR_EMPTY)
		cout<< "\nthe preorder printing was not successful\n";
	else
		cout<< "\npreorder printing was successful\n";

	cout<<"\n\n************ printing bst in inorder ************\n\n";

	chkretval = obj.print(BST_INORDER);
	if(chkretval == DS_ERROR_EMPTY)
		cout<< "\nthe inorder printing was not successful\n";
	else
		cout<< "\ninorder printing was successful\n";

	cout<<"\n\n************ printing bst in postorder ************\n\n";

	chkretval = obj.print(BST_POSTORDER);
	if(chkretval == DS_ERROR_EMPTY)
		cout<< "\nthe postorder printing was not successful\n";
	else
		cout<< "\npostorder printing was successful\n";

	//******************************************** number of nodes *******************************************
	int non=0;
	non = obj.numberOfNodes();
	cout<< "\n\nnumber of nodes in bst:\t" << non <<"\n\n";

	//**********************************************  stack  **************************************************

	Stack<int>  obj1;
	error_ds retvalue;	
	retvalue=obj1.push(5);
	if (retvalue == DS_ERROR_SUCCESS)
		cout<<"\npush (5) succeeded";
	else
		cout<< "some error occured in pushing the element";

	retvalue=obj1.push(8);
	if (retvalue == DS_ERROR_SUCCESS)
		cout<<"\npush (8) succeeded";
	else
		cout<< "some error occured in pushing the element";
	retvalue=obj1.push(2);
	if (retvalue == DS_ERROR_SUCCESS)
		cout<<"\npush (2) succeeded";
	else
		cout<< "some error occured in pushing the element";
	retvalue=obj1.push(14);
	if (retvalue == DS_ERROR_SUCCESS)
		cout<<"\npush (14) succeeded";
	else
		cout<< "some error occured in pusing the element";


	retvalue = obj1.isEmpty();
	if(retvalue == DS_ERROR_EMPTY)
		cout<< "\n\nthe stack is empty";
	else
		cout<< "\n\nthe stack is not empty";

	int counter = -1;
	retvalue = obj1.noOfMembers(counter);
	if(retvalue == DS_ERROR_SUCCESS)
		cout<< "\n\nthere are "<< counter << "elements in the stack";                    
	else
		cout<< "\n\nthe stack is empty";

	retvalue = obj1.print();
	if(retvalue == DS_ERROR_EMPTY)
		cout<< "\n\nthe stack is empty";
	else
		cout<< "\n\nthe stack is not empty and values are printed successfully.";

	int popel;
	for(int i=0; i<4; i++)
	{
		chkretval = obj1.pop(popel);
		if(chkretval == DS_ERROR_EMPTY)
			cout<<"\npop operation failed";
		else
			cout<<"\n\n" << i+1 << " popped element is "<< popel;
	}

	//************************************Problem16 from Excel********************************************
	//********Deleting a given node when no other node info or head info is given*************************
	DoubleLL<int> DoubleLLObj;
	chkretval = DoubleLLObj.insert(12);
	chkretval = DoubleLLObj.insert(9);
	chkretval = DoubleLLObj.insert(15);
	chkretval = DoubleLLObj.insert(2);

	if(chkretval != DS_ERROR_SUCCESS)
		cout<< "\nDoubleLL insertion was not successful\n";
	else
		cout<< "\nDoubleLL insertion was successful\n";

	chkretval = DoubleLLObj.print();
	if(chkretval != DS_ERROR_SUCCESS)
		cout<< "\nDoubleLL print was not successful\n";
	else
		cout<< "\nDoubleLL print was successful\n";

	chkretval = DoubleLLObj.deleteIfOnlyOneNodeAddrIsGivenAndNoHeadWrapper();
	if(chkretval != DS_ERROR_SUCCESS)
		cout<< "\nDoubleLL deletion 'If Only One Node Addr Is Given And No Head info' was successful\n";
	else
		cout<< "\nDoubleLL deletion 'If Only One Node Addr Is Given And No Head info' was successful\n";

	chkretval = DoubleLLObj.print();
	if(chkretval != DS_ERROR_SUCCESS)
		cout<< "\nDoubleLL print was not successful\n";
	else
		cout<< "\nDoubleLL print was successful\n";

	chkretval = DoubleLLObj.deleteLLWrapper();
	if(chkretval != DS_ERROR_SUCCESS)
		cout<< "\nDoubleLL deletion 'Simple' was successful\n";
	else
		cout<< "\nDoubleLL deletion 'Simple' was successful\n";

	chkretval = DoubleLLObj.isEmpty();
		if(chkretval != DS_ERROR_SUCCESS)
		cout<< "\nDoubleLL deletion 'Simple' was successful\n";
	else
		cout<< "\nDoubleLL deletion 'Simple' was successful\n";

	chkretval = DoubleLLObj.noOfMembers(non);

	return 0;
}