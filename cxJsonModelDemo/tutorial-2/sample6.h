#ifndef __CXJSONMODEL_TUTORIAL_2_SAMPLE_6_H__
#define __CXJSONMODEL_TUTORIAL_2_SAMPLE_6_H__

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <XFSIDC.H>
#include <cxJsonModel.h>

#include "../common/common.h"

/**
* @ingroup 结构体指针类型请求参数
* @brief JSON转结构体指针的指针类型请求参数 
*
* 此类请求参数的json格式应该是json数组
* @par 请求参数须是JSON数组，不显式指定的参数使用默认值0或空指针：
* @code
*	[
*		{
*			"wDataSource": 1,
*			"wStatus":2
*		},
*		{
*			"lpbData": "Hello WOSA/XFS"
*		},
*		{
*			"fwWriteMethod": 100
*		}
*	]
* @endcode
*/
inline void sample6()
{
	std::ifstream stream("json/tutorial2-sample6.json");
	if (!stream.is_open()) {
		std::cerr << "没有找到rc目录的资源文件" << std::endl;
		return;
	}
	std::stringstream sstream;
	sstream << stream.rdbuf();
	std::string jsonstr(sstream.str());

	// 使用模型库将请求参数转换为WOSA格式的请求参数
	LPWFSIDCCARDDATA* lppCardData =
		(LPWFSIDCCARDDATA*)cxJsonToObjectEx(jsonstr.data(),
			WFS_CMD_IDC_WRITE_RAW_DATA, cxCommand::WFS_CMD_REQUEST);

	// 打印出来看看效果
	std::cout << "这是请求参数转换为WOSA参数：" << std::endl;
	for (int i = 0; lppCardData[i]; ++i)
	{
		std::cout << "lppCardData[" << i << "]->wDataSource: "
			<< lppCardData[i]->wDataSource << std::endl;

		std::cout << "lppCardData[" << i << "]->wStatus: "
			<< lppCardData[i]->wStatus << std::endl;

		std::cout << "lppCardData[" << i << "]->ulDataLength: "
			<< lppCardData[i]->ulDataLength << std::endl;

		std::cout << "lppCardData[" << i << "]->lpbData: ";
		if (lppCardData[i]->lpbData) {
			std::cout << (char*)lppCardData[i]->lpbData << std::endl;
		}
		else {
			std::cout << "nullptr" << std::endl;
		}
			
		std::cout << "lppCardData[" << i << "]->fwWriteMethod: "
			<< lppCardData[i]->fwWriteMethod << std::endl;
	}

	// 再将WOSA结构体转换成JSON
	const char* json = cxObjectToJsonEx(lppCardData,
		WFS_CMD_IDC_WRITE_RAW_DATA, cxCommand::WFS_CMD_REQUEST);
	
	// 打印出来看看
	std::cout << "这是WOSA请求参数转换成的JSON:" << std::endl;
	std::cout << json << std::endl;

	// 释放内存，可以用WFMFreeBuffer函数释放
	cxFreeObjOrJson(json);
	cxFreeObjOrJson(lppCardData);
}

#define sample sample6

#endif