#ifndef __CXJSONMODEL_TUTORIAL_4_H__
#define __CXJSONMODEL_TUTORIAL_4_H__

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
* @brief 双'\0'结束且带下标的字符串指针转换 
*
* 此类字符串基本要求与双'\0'结束的字符串相同，除此之外，还要求其下表以
* 0开始，且必须以“1”为步长连续递增，格式如下：
* key1[0]=value0\0...key1[N]=valueN\0\0，模型库会将其转换为数据，其
* 元素是包含键值（不含索引）的JSON对象。
* @note '='号右边如果有等号，会被视为内容保留。
*/
void sample4()
{
	WFSPTRPRINTFORM ptrPrintFrome = { 0, };
	ptrPrintFrome.lpszFields = 
		"key1[0]=value01\0key2[0]=value02\0key1[1]=value11\0key2[2]=value22\0";

	// 使用模型库将结构体转换成json字符串
	const char* json =
		cxObjectToJson(&ptrPrintFrome, "WFSPTRPRINTFORM");

	// 打印出来看看效果
	std::cout << "这是双'\\0'字符串结构体转换成的json字符串：";
	std::cout << std::endl << json << std::endl << std::endl;

	// 再使用模型库将json转成结构体
	WFSPTRPRINTFORM* object = (WFSPTRPRINTFORM*)
				cxJsonToObject(json, "WFSPTRPRINTFORM");

	// 打印机出来看看结构体中字符串的值
	std::string lpszFields(object->lpszFields,
		object->lpszFields + lengthOfBytes(object->lpszFields, 2));
	std::cout << "这里是json转换成结构体后的值：" << std::endl;
	std::cout << "WFSPTRPRINTFORM.lpszFields: " 
			  << lpszFields << std::endl;

	// 记得释放内存
	cxFreeObjOrJson(object);
	cxFreeObjOrJson(json);
}

#define sample sample4

#endif