#ifndef __CXJSONMODEL_TUTORIAL_1_H__
#define __CXJSONMODEL_TUTORIAL_1_H__

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
* @defgroup 基本使用方式 WOSA/XFS结构体与JSON相互转换 
* 演示如何用cxJsonModel库将结构体与json进行相互转换
*/

/**
* @defgroup 内建数据类型 最简单的结构体和JSON之间的转换 
* @ingroup 基本使用方式
* 演示使用数据成员是非指针内建类型的使用方式
*/

/**
* @ingroup 内建数据类型
* @brief 简单结构体转换成Json 
*
* 简单结构体中只包含了C/C++语言内建数据类型
*/
inline void sample1()
{
	WFSPTRRETRACTBINS ptrRetractBins;
	ptrRetractBins.usRetractCount = 4;
	ptrRetractBins.wRetractBin = 10;

	// 使用模型库将结构体转换成json字符串
	const char* json = 
		cxObjectToJson(&ptrRetractBins, "WFSPTRRETRACTBINS");

	// 打印出来看看效果
	std::cout << "这是简单结构体转换成的json字符串：" << std::endl;
	std::cout << json << std::endl << std::endl;

	// 再使用模型库将json转成结构体
	WFSPTRRETRACTBINS* object = (WFSPTRRETRACTBINS*)
					cxJsonToObject(json, "WFSPTRRETRACTBINS");

	// 打印机出来看看结构体的值
	std::cout << "这里是json字符串转换成结构体后的值：" << std::endl;
	std::cout << "WFSPTRRETRACTBINS.usRetractCount: "
		<< object->usRetractCount << std::endl;
	std::cout << "WFSPTRRETRACTBINS.wRetractBin: "
		<< object->wRetractBin << std::endl << std::endl;

	// 记得释放内存
	cxFreeObjOrJson(object);
	cxFreeObjOrJson(json);
}

#define sample sample1

#endif