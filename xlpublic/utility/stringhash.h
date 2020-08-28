
#ifndef XL_STRINGHASH_H
#define XL_STRINGHASH_H

namespace XL {
	namespace UTILITY {
		//SDBM Hash Function
		unsigned int SDBMHash(const char *str);

		//RS Hash Function
		unsigned int RSHash(const char *str);

		//JS Hash Function
		unsigned int JSHash(const char *str);

		//BKDR Hash Function
		unsigned int BKDRHash(const char *str);

		//DJB Hash Function
		unsigned int DJBHash(const char *str);

		//FNV Hash Function
		unsigned int FNVHash(const char *str);
	}
}

#endif  /* XL_STRINGHASH_H */
