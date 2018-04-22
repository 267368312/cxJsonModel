#ifndef __CXJSONMODEL_TUTORIAL_2_SAMPLE_3_H__
#define __CXJSONMODEL_TUTORIAL_2_SAMPLE_3_H__

#include <fstream>
#include <iostream>
#include <XFSIDC.H>
#include <cxJsonModel.h>

#include "../common/common.h"

/**
* @ingroup �ַ��������������
* @brief �������Ϊ˫'\0'�������������ַ���
*
* ����û���ҵ��Դ����ַ�����Ϊ���루���󣩲������������У���ô����
* ��ʽӦ����json/tutorial2-sample3.json
*/
inline void sample3()
{
	std::ifstream stream("json/tutorial2-sample3.json");
	if (!stream.is_open()) {
		std::cerr << "û���ҵ�rcĿ¼����Դ�ļ�" << std::endl;
		return;
	}
}

#define sample sample3

#endif