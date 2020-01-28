#include "pch.h"
#include "functions.h"

int iStringSize(const char * pcString)
{
	int i_string_size = 0;

	for (int i = 0; pcString[i] != '\0'; i++)
	{
		i_string_size++;
	}

	return i_string_size;
}
