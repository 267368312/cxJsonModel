#ifndef __CXJSONMODEL_TUTORIAL_11_H__
#define __CXJSONMODEL_TUTORIAL_11_H__

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
* @brief 结构体指针的指针类型转换成json 
*
* 指定长度的结构体指针的指针转换
*/
void sample11()
{
	WFSCIMCASHINFO cimCashInfo = { 0, };
	WFSCIMCASHIN* cimCashIn[] = 
		{new WFSCIMCASHIN(), new WFSCIMCASHIN()};
	memset(cimCashIn[0], 0x00, sizeof(WFSCIMCASHIN));
	memset(cimCashIn[1], 0x00, sizeof(WFSCIMCASHIN));
	cimCashInfo.lppCashIn = cimCashIn;
	cimCashInfo.usCount = 2;

	// 使用模型库将结构体转换成json字符串
	const char* json =
		cxObjectToJson(&cimCashInfo, "WFSCIMCASHINFO");

	// 打印出来看看效果
	std::cout << "这是结构体指针的指针转换成的JSON字符串：";
	std::cout << std::endl << json << std::endl << std::endl;

	// 这里没有将json转换成结构体，可以亲自动手转换看看结果

	for (int i = 0; i < 2; ++i) delete cimCashIn[i];

	cxFreeObjOrJson(json);
}

#define sample sample11

#endif