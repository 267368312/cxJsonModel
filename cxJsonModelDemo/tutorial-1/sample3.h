#ifndef __CXJSONMODEL_TUTORIAL_3_H__
#define __CXJSONMODEL_TUTORIAL_3_H__

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
* @brief 双'\0'结束的字符串指针转换 
*
* 双'\0'结束的字符串同样也会经过编码转换处理，并在其符合特定格式时被转
* 换成JSON对象或数组，这个例子演示转换成JSON对象的情况。这种特殊字符串
* 转换JSON对象，须满足："key1=value1\0...keyN=valueN\0\0",'='号左边
* 不能有空格，且<key>必须是字母、数字或下划线或其组合，<value>可以是任
* 何非'\0'值。
* @note '='号右边如果有等号，会被视为内容保留。转换成json后，<value>
* 均为字符串类型。
*/
inline void sample3()
{
	WFSPTRSTATUS ptrStatus = {0,};
	ptrStatus.lpszExtra = "key1= value1\0key2=中文\0key3=value3\0";

	// 使用模型库将结构体转换成json字符串
	const char* json =
		cxObjectToJson(&ptrStatus, "WFSPTRSTATUS");

	// 打印出来看看效果
	std::cout << "这是双'\\0'字符串结构体转换成的json字符串：";
	std::cout << std::endl << json << std::endl << std::endl;

	// 再使用模型库将json转成结构体
	WFSPTRSTATUS* object = 
		(WFSPTRSTATUS*)cxJsonToObject(json, "WFSPTRSTATUS");

	// 打印机出来看看结构体中字符串的值
	std::string lpszstr(object->lpszExtra,
		object->lpszExtra + lengthOfBytes(object->lpszExtra, 2));
	std::cout << "这里是json转换成结构体后的值：" << std::endl;
	std::cout <<"WFSPTRSTATUS.lpszExtra: " << lpszstr << std::endl;

	// 记得释放内存
	cxFreeObjOrJson(object);
	cxFreeObjOrJson(json);
}

#define sample sample3

#endif