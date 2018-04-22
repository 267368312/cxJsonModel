#ifndef __CXJSONMODEL_TUTORIAL_6_H__
#define __CXJSONMODEL_TUTORIAL_6_H__

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
* @brief 以NULL结束的指针类型转换 
*
* 以NULL结束的非char指针会被转换为JSON数组格式
*/
inline void sample6()
{
	WORD testData[] = {1,2,3,4,5,6,7,8,9,0 };
	WFSPINCAPS pinCaps = { 0, };
	pinCaps.lpwEMVImportSchemes = testData;

	// 使用模型库将结构体转换成json字符串
	const char* json =
		cxObjectToJson(&pinCaps, "WFSPINCAPS");

	// 打印出来看看效果
	std::cout << "这是以NULL结束的WORD指针转换成的JSON字符串：";
	std::cout << std::endl << json << std::endl << std::endl;

	// 再使用模型库将json转成结构体
	WFSPINCAPS* object = 
		(WFSPINCAPS*)cxJsonToObject(json, "WFSPINCAPS");
	std::string data;
	for (int i = 0; object->lpwEMVImportSchemes &&
		object->lpwEMVImportSchemes[i]; ++i) {
		char buffer[32] = { 0, };
		sprintf(buffer, "%d ", object->lpwEMVImportSchemes[i]);
		data += buffer;
	}
	std::cout << "这里是json转换成结构体后的值：" << std::endl;
	std::cout << "WFSPINCAPS.lpwEMVImportSchemes: "
		<< data << std::endl;

	// 记得释放内存
	cxFreeObjOrJson(object);
	cxFreeObjOrJson(json);
}

#define sample sample6

#endif