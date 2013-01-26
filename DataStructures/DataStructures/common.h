#ifndef __common_h
#define __common_h

#include<iostream>

using namespace std;

namespace data_structure
{

	enum error_ds
	{
		DS_ERROR_SUCCESS,
		DS_ERROR_FAIL,
		DS_ERROR_FULL,
		DS_ERROR_EMPTY,
		DS_ERROR_MEMORY_ALLOC_FAIL
	};

}
#endif