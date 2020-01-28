#pragma once
#include "functions.h"
#include <iostream>

#define INT_DEFAULT_SIZE 1;

class CMyString
{
public:
	CMyString();
	CMyString(const CMyString& pcString);
	CMyString(const std::string& psString);
	~CMyString();
	std::string sToStandard();
	void vPrint();
	bool bSetLength(int iLength);
	int iGetLength();
	bool bSetCharAt(char cNewChar, int iOffset);
	void operator=(const CMyString &pcOther);
	void operator=(const char* pcOther);
	CMyString operator+(const char* pcOther);
	CMyString operator-(char cDelete);
	friend CMyString operator+(const char* pcCharAddend, const CMyString &pcStringAddend);
	void  operator+=(const char* pcOther);
	void  operator+=(const CMyString& pcOther);
	operator bool();
private:
	char* pc_string;
	int i_length;
};

