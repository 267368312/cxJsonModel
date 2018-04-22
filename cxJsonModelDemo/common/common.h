#ifndef __CXJSONMODEL_COMMON_H__
#define __CXJSONMODEL_COMMON_H__

#include <cstring>

template<typename T>
inline size_t
length(T* str, size_t countOfTerminator = 1)
{
	size_t numberOfTerminator = countOfTerminator * sizeof(T);
	std::string terminator(numberOfTerminator, 0);

	size_t length = 0;
	while (memcmp(str + length * sizeof(T), terminator.data(),
		numberOfTerminator)) ++length;

	return length;
}

template<typename T>
inline size_t
lengthOfBytes(T* str, size_t countOfTerminator = 1)
{
	return length(str, countOfTerminator) * sizeof(T);
}

#endif //__CXJSONMODEL_COMMON_H__