#ifndef __CXJSONMODEL_TUTORIAL_8_H__
#define __CXJSONMODEL_TUTORIAL_8_H__

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
* @brief 有长度限制的指针类型转换成字符串 
*
* 转换成json后，表示长度限制的字段不会出现在json字符串
*/
inline void sample8()
{
	const char* testData = "123\1\3\0\181232439843\254\255\0\0\0234adaswe~123\0\0\0\0";
	WFSIPMMEDIASTATUS ipmMediaStatus = { 0, };
	ipmMediaStatus.lpbCodelineData = (LPBYTE)testData;
	ipmMediaStatus.ulCodelineDataLength = lengthOfBytes(testData, 5);

	// 使用模型库将结构体转换成json字符串
	const char* json =
		cxObjectToJson(&ipmMediaStatus, "WFSIPMMEDIASTATUS");

	// 打印出来看看效果
	std::cout << "这是有长度限制的BYTE指针转换成的JSON字符串：";
	std::cout << std::endl << json << std::endl << std::endl;

	// 再使用模型库将json转成结构体
	WFSIPMMEDIASTATUS* object =
		(WFSIPMMEDIASTATUS*)cxJsonToObject(json, "WFSIPMMEDIASTATUS");

	// 打印机出来看看结构体中字符串的值
	std::string lpbCodelineData(object->lpbCodelineData,
		object->lpbCodelineData + object->ulCodelineDataLength);
	std::cout << "这里是json转换成结构体后的值：" << std::endl;
	std::cout << "WFSIPMMEDIASTATUS.lpbCodelineData: " 
			  << lpbCodelineData << std::endl;

	// 记得释放内存
	cxFreeObjOrJson(object);
	cxFreeObjOrJson(json);
}

#define sample sample8

#endif