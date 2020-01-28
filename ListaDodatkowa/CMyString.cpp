#include "pch.h"
#include "CMyString.h"
#include "functions.h"
#include <iostream>


CMyString::CMyString()
{
	i_length = INT_DEFAULT_SIZE;
	pc_string = new char[i_length]();
}

CMyString::CMyString(const CMyString & pcString)
{
	i_length = pcString.i_length;
	pc_string = new char[i_length]();

	for (int i = 0; i < i_length; i++)
	{
		pc_string[i] = pcString.pc_string[i];
	}
}

CMyString::CMyString(const std::string & psString)
{
	i_length = psString.length();

	pc_string = new char[i_length + 1]();

	for (int i = 0; i < i_length; i++)
	{
		pc_string[i] = psString.at(i);
	}
}

CMyString::~CMyString()
{
	if(pc_string!=nullptr) delete[] pc_string;
}

void CMyString::vPrint()
{
	std::cout << pc_string;
}

bool CMyString::bSetLength(int iLength)
{
	if (iLength < 0) return false;

	char *pc_changed_string = new char[iLength + 1]();

	for (int i = 0; i < i_length && i < iLength; i++)
	{
		pc_changed_string[i] = pc_string[i];
	}

	if (pc_string != nullptr) delete[] pc_string;

	pc_string = pc_changed_string;

	i_length = iLength + 1;

	return true;
}

int CMyString::iGetLength()
{
	return i_length - 1;
}

bool CMyString::bSetCharAt(char cNewChar, int iOffset)
{
	bool b_is_set = false;

	if (iOffset < 0 || iOffset > iGetLength()) return false;

	else if (iOffset == iGetLength())
	{
		b_is_set = bSetLength(iOffset + 1);

		if (b_is_set) pc_string[iOffset] = cNewChar;
		else return false;
	}
	else pc_string[iOffset] = cNewChar;

	return true;
}

void CMyString::operator=(const CMyString &pcOther)
{
	bSetLength(pcOther.i_length - 1);

	for (int i = 0; i < i_length; i++)
	{
		pc_string[i] = pcOther.pc_string[i];
	}
}

void CMyString::operator=(const char* pcOther)
{
	int i_string_size = iStringSize(pcOther);

	bSetLength(i_string_size);

	for (int i = 0; i < i_string_size; i++)
	{
		pc_string[i] = pcOther[i];
	}
}

CMyString CMyString::operator+(const char * pcOther)
{
	int i_string_size = iStringSize(pcOther);
	CMyString pc_new_string;

	pc_new_string.bSetLength(iGetLength() + i_string_size);

	for (int i = 0; i < iGetLength(); i++)
	{
		pc_new_string.bSetCharAt(pc_string[i], i);
	}

	for (int i = iGetLength(); i < i_string_size + iGetLength(); i++)
	{
		pc_new_string.bSetCharAt(pcOther[i - iGetLength()], i);
	}

	return pc_new_string;
}

CMyString CMyString::operator-(char cDelete)
{
	CMyString pc_new_string;
	int i_id = -1;
	bool b_is_find = false;
	for (int i = 0; i < iGetLength(); i++)
	{
		if (pc_string[i] == cDelete && !b_is_find)
		{
			i_id = i;
			b_is_find = true;
		}
	}

	if(i_id==-1) return *this;

	pc_new_string.bSetLength(iGetLength()-1);

	for (int i = 0; i < i_id; i++)
	{
		pc_new_string.bSetCharAt(pc_string[i], i);
	}

	for (int i = i_id+1; i < iGetLength(); i++)
	{
		pc_new_string.bSetCharAt(pc_string[i], i-1);
	}

	return pc_new_string;
}

void CMyString::operator+=(const char * pcOther)
{
	int i_new_string_size = iStringSize(pcOther);
	int i_current_size = iGetLength();

	bSetLength(i_new_string_size + i_current_size);

	for (int i = i_current_size; i < iGetLength(); i++)
	{
		pc_string[i] = pcOther[i - i_current_size];
	}
}

void CMyString::operator+=(const CMyString& pcOther)
{
	int i_current_size = iGetLength();
	int i_addend_size = pcOther.i_length - 1;

	bSetLength(i_current_size + i_addend_size);

	for (int i = i_current_size; i < iGetLength(); i++)
	{
		pc_string[i] = pcOther.pc_string[i - i_current_size];
	}
}

CMyString::operator bool()
{
	for (int i = 0; i < i_length; i++)
	{
		if (pc_string[i] != '\0') return true;
	}
	return false;
}

std::string CMyString::sToStandard()
{
	std::string s_new_string(pc_string);

	return s_new_string;
}

CMyString operator+(const char * pcCharAddend, const CMyString & pcStringAddend)
{
	int i_char_addend_size = iStringSize(pcCharAddend);
	int i_string_addend_size = pcStringAddend.i_length;

	CMyString pc_new_string;

	pc_new_string = pcCharAddend;

	pc_new_string += pcStringAddend;

	return pc_new_string;
}

