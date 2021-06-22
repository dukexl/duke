#include "../stringhash.h"
#include <iostream>
#include <string>
using namespace std;
using namespace XL::UTILITY;

int main()
{
	string str = "dukexl2020中国";
	cout << "str:" << str << "  SDBMHash:" << SDBMHash(str.data()) << "  RSHash:" << RSHash(str.data()) << endl;
	return 0;
}

/*
str:dukexl2020中国  SDBMHash:1219490153  RSHash:321442315
*/