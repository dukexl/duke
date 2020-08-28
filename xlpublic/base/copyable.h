// ***********************************************************************
// Filename         : copyable.h
// Author           : XULI
// Created          : 2020-8-28
// Description      : 可拷贝类
// ***********************************************************************
#ifndef XL_BASE_COPYABLE_H
#define XL_BASE_COPYABLE_H

namespace XL {
	class copyable {
	protected:
		copyable() = default;
		~copyable() = default;
	};	
}

#endif  /* XL_BASE_COPYABLE_H */
