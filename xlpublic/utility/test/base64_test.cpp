#include "../base64.h"
#include <iostream>
#include <string>
using namespace std;
using namespace XL::UTILITY;

int main()
{
	string str = "dukexl2020中国";
	string strdes = base64Encode(str);
	cout << "str:" << str << "  strEncode:" << strdes << "  length:" << strdes.length() << endl;
	string strDecode = base64Decode(strdes);
	cout << "str:" << str << "  strEncode:" << strdes << "  strDecode:" << strDecode << endl;

	return 0;
}
/*
str:dukexl2020中国  strEncode:ZHVrZXhsMjAyMOS4reWbvQ==  length:24
str:dukexl2020中国  strEncode:ZHVrZXhsMjAyMOS4reWbvQ==  strDecode:dukexl2020中国
*/