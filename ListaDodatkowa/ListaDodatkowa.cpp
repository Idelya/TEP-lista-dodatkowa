#include "pch.h"
#include "CMyString.h"
#include <iostream>

int main()
{
	std::string s_str1 = "kot";
	CMyString c_str, c_str1(s_str1), c_str2;
	std::string s_str;
	bool b_is_not_empty = false;

	std::cout << "Przeciazone operator: " << std::endl;

	c_str = "ala ma kota";

	c_str.vPrint();

	std::cout << std::endl;
	c_str = c_str - 'o';
	c_str = c_str - 'i';
	c_str = c_str - 'l';
	
	c_str.vPrint();

	return 0;
}
