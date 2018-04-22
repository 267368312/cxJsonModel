#ifndef __CXJSONMODEL_TUTORIAL_2_SAMPLE_2_H__
#define __CXJSONMODEL_TUTORIAL_2_SAMPLE_2_H__

#include <fstream>
#include <iostream>
#include <XFSIDC.H>
#include <cxJsonModel.h>

#include "../common/common.h"

/**
* @ingroup 字符串类型请求参数
* @brief 请求参数为双'\0'结束无索引的字符串 
*
* 这种请求参数需要传入JSON对象，但不是只支持这一种格式，你可以将不符合
* 双'\0'无索引格式的字符串转换成JSON看看结果，它的输出同样可以进行逆向
* 转换，因为作者不推荐使用不符合WOSA规定的格式，所以不在使用DEMO中进行
* 延时，如果您使用的双'\0'字符串确实不符合WOSA规定，您可以改写
* tutorial-1/sample3.h中lpszExtra参数为您实际使用的参数，来进行转换，
* 但必须保证是两个'\0'结束，否则会导致不确定的结果
*/
inline void sample2()
{
	std::ifstream stream("json/tutorial2-sample2.json");
	if (!stream.is_open()) {
		std::cerr << "没有找到rc目录的资源文件" << std::endl;
		return;
	}

	// 作者没有找到以此类指针作为输入（请求）参数指针，如果有，那么它应
	// 该是json/tutorial2-sample2.json的格式

// 	std::string json(std::istreambuf_iterator<char>(stream),
// 		std::istreambuf_iterator<char>());
// 
// 	const char* object = cxJsonToObjectEx(json.data(),)


}

#define sample sample2

#endif