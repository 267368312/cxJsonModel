#ifndef __CXJSONMODEL_TUTORIAL_9_H__
#define __CXJSONMODEL_TUTORIAL_9_H__

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
* @brief 结构体指针类型转换成json对象 
*/
void sample9()
{
	const char* testData = "Hello Sample9";
	WFSPINKEYDETAIL pinKeyDetail = { 0, };
	WFSXDATA xData = { 0, };
	xData.lpbData = (LPBYTE)testData;
	xData.usLength = strlen(testData);
	pinKeyDetail.lpxKeyBlockHeader = &xData;

	// 使用模型库将结构体转换成json字符串
	const char* json =
		cxObjectToJson(&pinKeyDetail, "WFSPINKEYDETAIL");

	// 打印出来看看效果
	std::cout << "这是结构体指针转换成的JSON字符串：";
	std::cout << std::endl << json << std::endl << std::endl;

	// 再使用模型库将json转成结构体
	WFSPINKEYDETAIL* object =
		(WFSPINKEYDETAIL*)cxJsonToObject(json, "WFSPINKEYDETAIL");

	// 打印机出来看看结构体中字符串的值
	std::string lpbData(
		(char*)object->lpxKeyBlockHeader->lpbData,
		(char*)object->lpxKeyBlockHeader->lpbData +
		object->lpxKeyBlockHeader->usLength);
	std::cout << "这里是json转换成结构体后的值：" << std::endl;
	std::cout << "WFSPINKEYDETAIL.lpxKeyBlockHeader.lpbData: "
		<< lpbData << std::endl;

	// 记得释放内存
	cxFreeObjOrJson(object);
	cxFreeObjOrJson(json);
}

#define sample sample9

#endif