#ifndef __CXJSONMODEL_TUTORIAL_2_SAMPLE_3_H__
#define __CXJSONMODEL_TUTORIAL_2_SAMPLE_3_H__

#include <fstream>
#include <iostream>
#include <XFSIDC.H>
#include <cxJsonModel.h>

#include "../common/common.h"

/**
* @ingroup 字符串类型请求参数
* @brief 请求参数为双'\0'结束有索引的字符串
*
* 作者没有找到以此类字符串作为输入（请求）参数的命令，如果有，那么它的
* 格式应满足json/tutorial2-sample3.json
*/
inline void sample3()
{
	std::ifstream stream("json/tutorial2-sample3.json");
	if (!stream.is_open()) {
		std::cerr << "没有找到rc目录的资源文件" << std::endl;
		return;
	}
}

#define sample sample3

#endif