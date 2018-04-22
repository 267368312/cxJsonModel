#ifndef __CXJSONMODEL_TUTORIAL_2_H__
#define __CXJSONMODEL_TUTORIAL_2_H__

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
* @defgroup 指针类型成员 WOSA/XFS结构体中包含指针的结构体 
* @ingroup 基本使用方式
* 这里演示几种类型的指针转换
*/

/**
* @ingroup 指针类型成员
* @brief 带有字符串指针的结构体 
*
* 指针类型是普通窄字符串的转换，cxJsonModel对字符串类型的数据自动进行
* 编码转换，认为json字符串是UTF-8编码，而结构体中的字符串为GB18030编
* 码。即将接收到的JSON字符串键值与结构体中的成员名称相同，且是字符串类
* 型的数据从UTF-8转换为GB18030，所以返回的结构体中字符串是GB18030编码；
* 而将结构体转换为JSON字符串时，将成员为字符串类型的数据从GB18030编码
* 转换成UTF-8，支持生僻字。例程中不做演示。
*/
inline void sample2()
{
	WFSPTRQUERYFIELD ptrQueryField;
	ptrQueryField.lpszFieldName = "PtrField";
	ptrQueryField.lpszFormName = "PtrForm";

	// 使用模型库将结构体转换成json字符串
	const char* json = 
		cxObjectToJson(&ptrQueryField, "WFSPTRQUERYFIELD");

	// 打印出来看看效果
	std::cout << "这是简单字符串结构体转换成的json字符串：" << std::endl;
	std::cout << json << std::endl << std::endl;

	// 再使用模型库将json转成结构体
	WFSPTRQUERYFIELD* object = (WFSPTRQUERYFIELD*)
				cxJsonToObject(json, "WFSPTRQUERYFIELD");

	// 打印机出来看看结构体的值
	std::cout << "这里是json字符串转换成结构体后的值：" << std::endl;
	std::cout << "WFSPTRQUERYFIELD.lpszFormName: "
		<< object->lpszFormName << std::endl;
	std::cout << "WFSPTRQUERYFIELD.lpszFieldName: "
		<< object->lpszFieldName << std::endl << std::endl;

	// 记得释放内存
	cxFreeObjOrJson(object);
	cxFreeObjOrJson(json);
}

#define sample sample2

#endif