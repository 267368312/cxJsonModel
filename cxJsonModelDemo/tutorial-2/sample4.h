#ifndef __CXJSONMODEL_TUTORIAL_2_SAMPLE_4_H__
#define __CXJSONMODEL_TUTORIAL_2_SAMPLE_4_H__

#include <fstream>
#include <iostream>
#include <XFSIDC.H>
#include <cxJsonModel.h>

#include "../common/common.h"

/**
* @defgroup 其他内建类型指针请求参数 其他内建类型指针请求参数JSON转换
* @ingroup 请求参数使用方式
*/

/**
* @ingroup 其他内建类型指针请求参数
* @brief WORD型指针代表一个值的请求参数 
*
* 此类请求参数使用cxJsonToObjectEx转换时，应传入数字字符串的十进制或者
* 十六进制形式
* @note 传入LPWORD指针会导致不确定的结果
*/
inline void sample4()
{
	const char* lpwReadData = "0x0001"; //WFS_IDC_TRACK1

	// 使用模型库将请求参数转换为WOSA格式的请求参数
	LPWORD object = (LPWORD)cxJsonToObjectEx(lpwReadData,
		WFS_CMD_IDC_READ_RAW_DATA, cxCommand::WFS_CMD_REQUEST);

	// 打印出来看看效果
	std::cout << "这是请求参数转换为WOSA参数：" << std::endl;
	std::cout << *object << std::endl;

	// 再将结构体数据转换为json数据（实际使用中应该不会存在这种转换）
	const char* json = cxObjectToJsonEx(object,
		WFS_CMD_IDC_READ_RAW_DATA, cxCommand::WFS_CMD_REQUEST);

	// 打印出来看看效果
	std::cout << "这是WOSA参数转换为请求参数: " << std::endl;
	std::cout << json << std::endl;

	// 释放内存
	cxFreeObjOrJson(json);
	cxFreeObjOrJson(object);
}

#define sample sample4

#endif