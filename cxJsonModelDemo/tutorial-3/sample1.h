#ifndef __CXJSONMODEL_TUTORIAL_3_SAMPLE_1_H__
#define __CXJSONMODEL_TUTORIAL_3_SAMPLE_1_H__

#include <iostream>
#include <XFSIDC.H>
#include <cxJsonModel.h>

#include "../common/common.h"

/**
* @defgroup 事件参数使用方式 WOSA/XFS响应/事件参数的JSON转换
* 演示如何利用响应命令和响应类型，将WOSA/XFS所定义的类型转换成字符类型
* 参数。
* 响应参数和事件参数的使用方式相同，只是响应参数的JSON中对应响应结构体
* 中联合体类型的成员名称为dwCommandCode，而事件参数的名称为dwEventID,
* 这里仅列举响应参数中的一种用法来进行演示
*/

/**
* @ingroup 事件参数使用方式
* @brief 这里使用三个'\0'结束的特殊字符串类型进行演示 
*
* WOSA/XFS文档中说明的输出（响应）参数和事件参数都是JSON对象中lpBuffer
* 的值，这些值可能是对象、数组和字符串等，跟文档的具体格式相对应
*/
inline void sample1()
{
	const char* lpBuffer =
		"TRACK3:MII=59\0COUNTRY=280\0ISSUERID=50050500\0ACCOUNT=\
		1234567890\0LUHNT3=1\0EXPIRATION=9912\0SECURE=1\0\0";

	WFSRESULT result = { 0, };
	result.u.dwCommandCode = WFS_CMD_IDC_READ_TRACK;
	result.lpBuffer = const_cast<char*>(lpBuffer);

	// 使用模型库将结构体转换成json字符串
	const char* json =
		cxObjectToJsonEx(&result,
			WFS_CMD_IDC_READ_TRACK, cxCommand::WFS_CMD_RESPONSE);

	// 打印出来看看
	std::cout << "这是响应参数转换成的json字符串：" << std::endl;
	std::cout << json << std::endl;

	cxFreeObjOrJson(json);
}

#define sample sample1

#endif