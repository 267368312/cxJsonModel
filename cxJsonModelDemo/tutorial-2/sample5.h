#ifndef __CXJSONMODEL_TUTORIAL_2_SAMPLE_5_H__
#define __CXJSONMODEL_TUTORIAL_2_SAMPLE_5_H__

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <XFSIDC.H>
#include <cxJsonModel.h>

#include "../common/common.h"

/**
* @defgroup 结构体指针类型请求参数 结构体指针类型请求参数与JSON的转换
* @ingroup 请求参数使用方式
*/

/**
* @ingroup 结构体指针类型请求参数
* @brief JSON转结构体指针类型的请求参数 
*
* 此类请求参数的json格式应该是json对象
* @par 请求参数应是json对象，如下：
* @code
*	{
*		"wChipProtocol": 100,
*		"lpbChipData": "1234567890abcbefg"
*	}
* @endcode
*/
inline void sample5()
{
	std::ifstream stream("json/tutorial2-sample5.json");
	if (!stream.is_open()) {
		std::cerr << "没有找到rc目录的资源文件" << std::endl;
		return;
	}
	std::stringstream sstream;
	sstream << stream.rdbuf();
	std::string jsonstr(sstream.str());

	// 使用模型库将请求参数转换为WOSA格式的请求参数
	LPWFSIDCCHIPIO lpChipIoIn = 
		(LPWFSIDCCHIPIO)cxJsonToObjectEx(jsonstr.data(),
		WFS_CMD_IDC_CHIP_IO, cxCommand::WFS_CMD_REQUEST);

	// 打印出来看看效果
	std::cout << "这是请求参数转换为WOSA参数：" << std::endl;
	std::cout << "WFSIDCCHIPIO.wChipProtocol: " 
		<< lpChipIoIn->wChipProtocol << std::endl;
	std::cout << "WFSIDCCHIPIO.ulChipDataLength: "
		<< lpChipIoIn->ulChipDataLength << std::endl;
	std::cout << "WFSIDCCHIPIO.lpbChipData: "
		<< (char*)lpChipIoIn->lpbChipData << std::endl;

	// 再将WOSA结构体转换成JSON
	const char* json = cxObjectToJsonEx(lpChipIoIn,
		WFS_CMD_IDC_CHIP_IO, cxCommand::WFS_CMD_REQUEST);

	// 打印出来看看
	std::cout << "这是WOSA请求参数转换成的JSON:" << std::endl;
	std::cout << json << std::endl;

	// 释放内存，可以用WFMFreeBuffer函数释放
	cxFreeObjOrJson(json);
	cxFreeObjOrJson(lpChipIoIn);
}

#define sample sample5

#endif 