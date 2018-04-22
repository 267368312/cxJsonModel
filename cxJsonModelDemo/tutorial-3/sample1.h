#ifndef __CXJSONMODEL_TUTORIAL_3_SAMPLE_1_H__
#define __CXJSONMODEL_TUTORIAL_3_SAMPLE_1_H__

#include <iostream>
#include <XFSIDC.H>
#include <cxJsonModel.h>

#include "../common/common.h"

/**
* @defgroup �¼�����ʹ�÷�ʽ WOSA/XFS��Ӧ/�¼�������JSONת��
* ��ʾ���������Ӧ�������Ӧ���ͣ���WOSA/XFS�����������ת�����ַ�����
* ������
* ��Ӧ�������¼�������ʹ�÷�ʽ��ͬ��ֻ����Ӧ������JSON�ж�Ӧ��Ӧ�ṹ��
* �����������͵ĳ�Ա����ΪdwCommandCode�����¼�����������ΪdwEventID,
* ������о���Ӧ�����е�һ���÷���������ʾ
*/

/**
* @ingroup �¼�����ʹ�÷�ʽ
* @brief ����ʹ������'\0'�����������ַ������ͽ�����ʾ 
*
* WOSA/XFS�ĵ���˵�����������Ӧ���������¼���������JSON������lpBuffer
* ��ֵ����Щֵ�����Ƕ���������ַ����ȣ����ĵ��ľ����ʽ���Ӧ
*/
inline void sample1()
{
	const char* lpBuffer =
		"TRACK3:MII=59\0COUNTRY=280\0ISSUERID=50050500\0ACCOUNT=\
		1234567890\0LUHNT3=1\0EXPIRATION=9912\0SECURE=1\0\0";

	WFSRESULT result = { 0, };
	result.u.dwCommandCode = WFS_CMD_IDC_READ_TRACK;
	result.lpBuffer = const_cast<char*>(lpBuffer);

	// ʹ��ģ�Ϳ⽫�ṹ��ת����json�ַ���
	const char* json =
		cxObjectToJsonEx(&result,
			WFS_CMD_IDC_READ_TRACK, cxCommand::WFS_CMD_RESPONSE);

	// ��ӡ��������
	std::cout << "������Ӧ����ת���ɵ�json�ַ�����" << std::endl;
	std::cout << json << std::endl;

	cxFreeObjOrJson(json);
}

#define sample sample1

#endif