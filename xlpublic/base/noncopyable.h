// ***********************************************************************
// Filename         : noncopyable.h
// Author           : XULI
// Created          : 2020-8-28
// Description      : 不可拷贝类
// ***********************************************************************
#ifndef XL_BASE_NONCOPYABLE_H
#define XL_BASE_NONCOPYABLE_H

namespace XL
{
	class noncopyable
	{
	public:
		noncopyable(const noncopyable &) = delete;
		void operator=(const noncopyable &) = delete;

	protected:
		noncopyable() = default;
		~noncopyable() = default;
	};
}

#endif /* XL_BASE_NONCOPYABLE_H */
