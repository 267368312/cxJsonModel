#ifndef __CXJSONMODEL_TUTORIAL_12_H__
#define __CXJSONMODEL_TUTORIAL_12_H__

#include <string>
#include <iostream>
#include <XFSPTR.H>
#include <XFSPIN.H>
#include <XFSCDM.H>
#include <XFSIPM.H>
#include <XFSCIM.H>
#include <cxJsonModel.h>

#include "../common/common.h"

/**
* @ingroup 指针类型成员
* @brief 宽字符指针的结构体转换成JSON 
*
* 宽字符同样支持普通宽字符，双'\0'宽字符和三个'\0'结束的宽字符，这里以
* 普通宽字符做演示。宽字符执行UTF-16LE和UTF-8的编码转换。会将JSON中的
* Unicode编码字段认为是UTF-8编码，转换成UTF-16LE后从结构体输出，而将
* 结构体中的Unicode字段认为是UTF-16LE，转换成UTF-8后从JSON输出。
*/
inline void sample12()
{
	WFSCIMITEMINFO cimItemInfo = { 0, };
	cimItemInfo.lpszSerialNumber = L"SN1234567890";

	// 使用模型库将结构体转换成json字符串
	const char* json =
		cxObjectToJson(&cimItemInfo, "WFSCIMITEMINFO");

	// 打印出来看看效果
	std::cout << "这是结构体指针的指针转换成的JSON字符串：";
	std::cout << std::endl << json << std::endl << std::endl;

	// 再使用模型库将json转成结构体
	WFSCIMITEMINFO* object = (WFSCIMITEMINFO*)
		cxJsonToObject(json, "WFSCIMITEMINFO");

	std::wcout << object->lpszSerialNumber << std::endl;

	cxFreeObjOrJson(object);
	cxFreeObjOrJson(json);
}

#define sample sample12

#endif