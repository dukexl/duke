// ***********************************************************************
// Filename         : Base64.h
// Author           : XULI
// Created          : 2020-8-28
// Description      : Base64 加解密
// ***********************************************************************
#ifndef XL_BASE64_H
#define XL_BASE64_H
#include <string>
namespace XL
{
	namespace UTILITY
	{
		// len == strlen(src), and strlen(dst) >= len * 4 / 3
		// 加密
		size_t base64Encode(const char *src, size_t len, char *dst);
		size_t base64Encode(const char *src, size_t len, std::string &dst);
		size_t base64Encode(const std::string &src, std::string &dst);
		std::string base64Encode(const char *src, size_t len);
		std::string base64Encode(const std::string &src);

		// len == strlen(src), and strlen(dst) >= len * 3 / 4
		// 解密
		size_t base64Decode(const char *src, size_t len, char *dst);
		size_t base64Decode(const char *src, size_t len, std::string &dst);
		size_t base64Decode(const std::string &src, std::string &dst);
		std::string base64Decode(const char *src, size_t len);
		std::string base64Decode(const std::string &src);
	}
}

#endif /* XL_BASE64_H */
