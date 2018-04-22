#ifndef __CXJSONMODEL_TUTORIAL_2_SAMPLE_4_H__
#define __CXJSONMODEL_TUTORIAL_2_SAMPLE_4_H__

#include <fstream>
#include <iostream>
#include <XFSIDC.H>
#include <cxJsonModel.h>

#include "../common/common.h"

/**
* @defgroup �����ڽ�����ָ��������� �����ڽ�����ָ���������JSONת��
* @ingroup �������ʹ�÷�ʽ
*/

/**
* @ingroup �����ڽ�����ָ���������
* @brief WORD��ָ�����һ��ֵ��������� 
*
* �����������ʹ��cxJsonToObjectExת��ʱ��Ӧ���������ַ�����ʮ���ƻ���
* ʮ��������ʽ
* @note ����LPWORDָ��ᵼ�²�ȷ���Ľ��
*/
inline void sample4()
{
	const char* lpwReadData = "0x0001"; //WFS_IDC_TRACK1

	// ʹ��ģ�Ϳ⽫�������ת��ΪWOSA��ʽ���������
	LPWORD object = (LPWORD)cxJsonToObjectEx(lpwReadData,
		WFS_CMD_IDC_READ_RAW_DATA, cxCommand::WFS_CMD_REQUEST);

	// ��ӡ��������Ч��
	std::cout << "�����������ת��ΪWOSA������" << std::endl;
	std::cout << *object << std::endl;

	// �ٽ��ṹ������ת��Ϊjson���ݣ�ʵ��ʹ����Ӧ�ò����������ת����
	const char* json = cxObjectToJsonEx(object,
		WFS_CMD_IDC_READ_RAW_DATA, cxCommand::WFS_CMD_REQUEST);

	// ��ӡ��������Ч��
	std::cout << "����WOSA����ת��Ϊ�������: " << std::endl;
	std::cout << json << std::endl;

	// �ͷ��ڴ�
	cxFreeObjOrJson(json);
	cxFreeObjOrJson(object);
}

#define sample sample4

#endif