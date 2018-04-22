#ifndef __CXJSONMODEL_TUTORIAL_2_SAMPLE_1_H__
#define __CXJSONMODEL_TUTORIAL_2_SAMPLE_1_H__

#include <iostream>
#include <XFSIDC.H>
#include <cxJsonModel.h>

#include "../common/common.h"

/**
* @defgroup 请求参数使用方式 WOSA/XFS请求参数的JSON转换 
* 演示如何利用请求命令和请求类型，将字符类型参数转换成WOSA/XFS所定义的
* 类型。请求参数必须是字符串类型的指针，但不强制为JSON字符串，而是与对
* 应命令所定义的类型匹配。对应关系如下：<br/>
* <blockquote>
* <ol style="list-style-type:upper-roman">
*	<li><strong>LPWORD(LPUSHORT LPDWORD)</strong>	根据定义存在以下两种情况</li>
*		<ol>
*			<li><strong>表示单个值</strong>	字符串指针，数字的十进制或十六进制形式</li>
*			<li><strong>NULL结束</strong>	JSON数组 </li>
*		</ol>
*	<li><strong>LPSTR</strong>	根据字符串类型的定义，可分为以下四种情况：</li>
*		<ol>
*			<li><strong>常规字符串</strong>		字符串指针</li>
*			<li><strong>双'\0'无索引</strong>	JSON对象</li>
*			<li><strong>双'\0'有索引</strong>	JSON数组</li>
*			<li><strong>三'\0'字符串</strong>	嵌套的JSON对象</li>
*		</ol>
*	<li><strong>结构体指针</strong>	JSON对象</li>
*	<li><strong>结构体指针的指针</strong>	JSON数组</li>
* </ol>
* </blockquote>
*/

/**
* @defgroup 字符串类型请求参数 字符串类型的请求参数转换
* @ingroup 请求参数使用方式
*/

/**
* @ingroup 字符串类型请求参数
* @brief 请求参数为普通字符串类型 
*
* 请求参数为普通字符串类型的命令，传入参数为字符串指针即可
* @note 此函数看上去没做任何事情，实际上它用WOSA的内存分配器重新分
* 配了内存，也就是通过cxJsonToObjectEx函数转换后的指针，可以直接传给
* SP做参数，同时如果存在中文，它将执行了编码转换。
*/
inline void sample1()
{
	const char* lpstrFormName = "readIdForm";

	// 使用模型库将结构体转换成json字符串
	const char* object = 
		(const char*)cxJsonToObjectEx(lpstrFormName, 
		WFS_CMD_IDC_READ_TRACK, cxCommand::WFS_CMD_REQUEST);

	// 打印出来看看效果
	std::cout << "这是请求参数转换为WOSA参数：" << std::endl;
	std::cout << object << std::endl;

	// 再将结构体数据转换为json数据（实际使用中应该不会存在这种转换）
	const char* json =
		(const char*)cxObjectToJsonEx(const_cast<char*>(object),
		WFS_CMD_IDC_READ_TRACK, cxCommand::WFS_CMD_REQUEST);

	// 打印出来看看效果
	std::cout << "这是WOSA参数转换为请求参数：" << std::endl;
	std::cout << json << std::endl;

	// 记得释放内存
	cxFreeObjOrJson(object);
	cxFreeObjOrJson(json);
}

#define sample sample1

#endif //__CXJSONMODEL_TUTORIAL_2_SAMPLE_1_H__