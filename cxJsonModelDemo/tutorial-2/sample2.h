#ifndef __CXJSONMODEL_TUTORIAL_2_SAMPLE_2_H__
#define __CXJSONMODEL_TUTORIAL_2_SAMPLE_2_H__

#include <fstream>
#include <iostream>
#include <XFSIDC.H>
#include <cxJsonModel.h>

#include "../common/common.h"

/**
* @ingroup �ַ��������������
* @brief �������Ϊ˫'\0'�������������ַ��� 
*
* �������������Ҫ����JSON���󣬵�����ֻ֧����һ�ָ�ʽ������Խ�������
* ˫'\0'��������ʽ���ַ���ת����JSON����������������ͬ�����Խ�������
* ת������Ϊ���߲��Ƽ�ʹ�ò�����WOSA�涨�ĸ�ʽ�����Բ���ʹ��DEMO�н���
* ��ʱ�������ʹ�õ�˫'\0'�ַ���ȷʵ������WOSA�涨�������Ը�д
* tutorial-1/sample3.h��lpszExtra����Ϊ��ʵ��ʹ�õĲ�����������ת����
* �����뱣֤������'\0'����������ᵼ�²�ȷ���Ľ��
*/
inline void sample2()
{
	std::ifstream stream("json/tutorial2-sample2.json");
	if (!stream.is_open()) {
		std::cerr << "û���ҵ�rcĿ¼����Դ�ļ�" << std::endl;
		return;
	}

	// ����û���ҵ��Դ���ָ����Ϊ���루���󣩲���ָ�룬����У���ô��Ӧ
	// ����json/tutorial2-sample2.json�ĸ�ʽ

// 	std::string json(std::istreambuf_iterator<char>(stream),
// 		std::istreambuf_iterator<char>());
// 
// 	const char* object = cxJsonToObjectEx(json.data(),)


}

#define sample sample2

#endif