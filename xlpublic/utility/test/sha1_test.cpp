#include "../sha1.h"
#include <iostream>
#include <string>
using namespace std;
using namespace XL::UTILITY;

int main()
{
	string str = "dukexl2020中国";
	SHA1 sha;
	string strdes = sha.hexDigest(str);
	cout << "str:" << str << "  strEncode:" << strdes << "  length:" << strdes.length() << endl;

	return 0;
}
/*
str:dukexl2020中国  strEncode:e70d2f0e87b800edce169af8f3396c01517b72e0  length:40
*/