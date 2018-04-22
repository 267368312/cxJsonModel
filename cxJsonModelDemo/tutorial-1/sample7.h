#ifndef __CXJSONMODEL_TUTORIAL_7_H__
#define __CXJSONMODEL_TUTORIAL_7_H__

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
* @brief 有长度限制的指针类型转换成数组 
*
* 转换成json后，表示长度限制的字段不会出现在json字符串
*/
inline void sample7()
{
	USHORT testData[] = { 0,1,2,3,4,5,6,7,8,9 };
	WFSCDMSTARTEX cdmStartEx = { 0, };
	cdmStartEx.lpusCUNumList = testData;
	cdmStartEx.usCount = 5;

	// 使用模型库将结构体转换成json字符串
	const char* json =
		cxObjectToJson(&cdmStartEx, "WFSCDMSTARTEX");

	// 打印出来看看效果
	std::cout << "这是有长度限制的USHORT指针转换成的JSON字符串：";
	std::cout << std::endl << json << std::endl << std::endl;

	// 再使用模型库将json转成结构体
	WFSCDMSTARTEX* object =
		(WFSCDMSTARTEX*)cxJsonToObject(json, "WFSCDMSTARTEX");
	std::string data;
	for (int i = 0; i < object->usCount; ++i) {
		char buffer[32] = { 0, };
		sprintf(buffer, "%d ", object->lpusCUNumList[i]);
		data += buffer;
	}
	std::cout << "这里是json转换成结构体后的值：" << std::endl;
	std::cout << "WFSCDMSTARTEX.lpusCUNumList: "
		<< data << std::endl;

	// 记得释放内存
	cxFreeObjOrJson(object);
	cxFreeObjOrJson(json);
}

#define sample sample7

#endif