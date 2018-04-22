#ifndef __CXJSONMODEL_TUTORIAL_4_H__
#define __CXJSONMODEL_TUTORIAL_4_H__

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
* @brief ˫'\0'�����Ҵ��±���ַ���ָ��ת�� 
*
* �����ַ�������Ҫ����˫'\0'�������ַ�����ͬ������֮�⣬��Ҫ�����±���
* 0��ʼ���ұ����ԡ�1��Ϊ����������������ʽ���£�
* key1[0]=value0\0...key1[N]=valueN\0\0��ģ�Ϳ�Ὣ��ת��Ϊ���ݣ���
* Ԫ���ǰ�����ֵ��������������JSON����
* @note '='���ұ�����еȺţ��ᱻ��Ϊ���ݱ�����
*/
void sample4()
{
	WFSPTRPRINTFORM ptrPrintFrome = { 0, };
	ptrPrintFrome.lpszFields = 
		"key1[0]=value01\0key2[0]=value02\0key1[1]=value11\0key2[2]=value22\0";

	// ʹ��ģ�Ϳ⽫�ṹ��ת����json�ַ���
	const char* json =
		cxObjectToJson(&ptrPrintFrome, "WFSPTRPRINTFORM");

	// ��ӡ��������Ч��
	std::cout << "����˫'\\0'�ַ����ṹ��ת���ɵ�json�ַ�����";
	std::cout << std::endl << json << std::endl << std::endl;

	// ��ʹ��ģ�Ϳ⽫jsonת�ɽṹ��
	WFSPTRPRINTFORM* object = (WFSPTRPRINTFORM*)
				cxJsonToObject(json, "WFSPTRPRINTFORM");

	// ��ӡ�����������ṹ�����ַ�����ֵ
	std::string lpszFields(object->lpszFields,
		object->lpszFields + lengthOfBytes(object->lpszFields, 2));
	std::cout << "������jsonת���ɽṹ����ֵ��" << std::endl;
	std::cout << "WFSPTRPRINTFORM.lpszFields: " 
			  << lpszFields << std::endl;

	// �ǵ��ͷ��ڴ�
	cxFreeObjOrJson(object);
	cxFreeObjOrJson(json);
}

#define sample sample4

#endif