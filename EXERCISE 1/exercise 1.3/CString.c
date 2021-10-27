#include "CString.h"

int CStrlen(char word[])
{
	int size = 0;
	while (word[size])
		size++;
	return size;
}