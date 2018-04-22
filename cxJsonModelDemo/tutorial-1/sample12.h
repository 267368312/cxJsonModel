#ifndef __CXJSONMODEL_TUTORIAL_12_H__
#define __CXJSONMODEL_TUTORIAL_12_H__

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
* @ingroup ָ�����ͳ�Ա
* @brief ���ַ�ָ��Ľṹ��ת����JSON 
*
* ���ַ�ͬ��֧����ͨ���ַ���˫'\0'���ַ�������'\0'�����Ŀ��ַ���������
* ��ͨ���ַ�����ʾ�����ַ�ִ��UTF-16LE��UTF-8�ı���ת�����ὫJSON�е�
* Unicode�����ֶ���Ϊ��UTF-8���룬ת����UTF-16LE��ӽṹ�����������
* �ṹ���е�Unicode�ֶ���Ϊ��UTF-16LE��ת����UTF-8���JSON�����
*/
inline void sample12()
{
	WFSCIMITEMINFO cimItemInfo = { 0, };
	cimItemInfo.lpszSerialNumber = L"SN1234567890";

	// ʹ��ģ�Ϳ⽫�ṹ��ת����json�ַ���
	const char* json =
		cxObjectToJson(&cimItemInfo, "WFSCIMITEMINFO");

	// ��ӡ��������Ч��
	std::cout << "���ǽṹ��ָ���ָ��ת���ɵ�JSON�ַ�����";
	std::cout << std::endl << json << std::endl << std::endl;

	// ��ʹ��ģ�Ϳ⽫jsonת�ɽṹ��
	WFSCIMITEMINFO* object = (WFSCIMITEMINFO*)
		cxJsonToObject(json, "WFSCIMITEMINFO");

	std::wcout << object->lpszSerialNumber << std::endl;

	cxFreeObjOrJson(object);
	cxFreeObjOrJson(json);
}

#define sample sample12

#endif