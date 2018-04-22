#ifndef __CXJSONMODEL_TUTORIAL_3_H__
#define __CXJSONMODEL_TUTORIAL_3_H__

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
* @brief ˫'\0'�������ַ���ָ��ת�� 
*
* ˫'\0'�������ַ���ͬ��Ҳ�ᾭ������ת����������������ض���ʽʱ��ת
* ����JSON��������飬���������ʾת����JSON�������������������ַ���
* ת��JSON���������㣺"key1=value1\0...keyN=valueN\0\0",'='�����
* �����пո���<key>��������ĸ�����ֻ��»��߻�����ϣ�<value>��������
* �η�'\0'ֵ��
* @note '='���ұ�����еȺţ��ᱻ��Ϊ���ݱ�����ת����json��<value>
* ��Ϊ�ַ������͡�
*/
inline void sample3()
{
	WFSPTRSTATUS ptrStatus = {0,};
	ptrStatus.lpszExtra = "key1= value1\0key2=����\0key3=value3\0";

	// ʹ��ģ�Ϳ⽫�ṹ��ת����json�ַ���
	const char* json =
		cxObjectToJson(&ptrStatus, "WFSPTRSTATUS");

	// ��ӡ��������Ч��
	std::cout << "����˫'\\0'�ַ����ṹ��ת���ɵ�json�ַ�����";
	std::cout << std::endl << json << std::endl << std::endl;

	// ��ʹ��ģ�Ϳ⽫jsonת�ɽṹ��
	WFSPTRSTATUS* object = 
		(WFSPTRSTATUS*)cxJsonToObject(json, "WFSPTRSTATUS");

	// ��ӡ�����������ṹ�����ַ�����ֵ
	std::string lpszstr(object->lpszExtra,
		object->lpszExtra + lengthOfBytes(object->lpszExtra, 2));
	std::cout << "������jsonת���ɽṹ����ֵ��" << std::endl;
	std::cout <<"WFSPTRSTATUS.lpszExtra: " << lpszstr << std::endl;

	// �ǵ��ͷ��ڴ�
	cxFreeObjOrJson(object);
	cxFreeObjOrJson(json);
}

#define sample sample3

#endif