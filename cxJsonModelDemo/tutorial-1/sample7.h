#ifndef __CXJSONMODEL_TUTORIAL_7_H__
#define __CXJSONMODEL_TUTORIAL_7_H__

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
* @brief �г������Ƶ�ָ������ת�������� 
*
* ת����json�󣬱�ʾ�������Ƶ��ֶβ��������json�ַ���
*/
inline void sample7()
{
	USHORT testData[] = { 0,1,2,3,4,5,6,7,8,9 };
	WFSCDMSTARTEX cdmStartEx = { 0, };
	cdmStartEx.lpusCUNumList = testData;
	cdmStartEx.usCount = 5;

	// ʹ��ģ�Ϳ⽫�ṹ��ת����json�ַ���
	const char* json =
		cxObjectToJson(&cdmStartEx, "WFSCDMSTARTEX");

	// ��ӡ��������Ч��
	std::cout << "�����г������Ƶ�USHORTָ��ת���ɵ�JSON�ַ�����";
	std::cout << std::endl << json << std::endl << std::endl;

	// ��ʹ��ģ�Ϳ⽫jsonת�ɽṹ��
	WFSCDMSTARTEX* object =
		(WFSCDMSTARTEX*)cxJsonToObject(json, "WFSCDMSTARTEX");
	std::string data;
	for (int i = 0; i < object->usCount; ++i) {
		char buffer[32] = { 0, };
		sprintf(buffer, "%d ", object->lpusCUNumList[i]);
		data += buffer;
	}
	std::cout << "������jsonת���ɽṹ����ֵ��" << std::endl;
	std::cout << "WFSCDMSTARTEX.lpusCUNumList: "
		<< data << std::endl;

	// �ǵ��ͷ��ڴ�
	cxFreeObjOrJson(object);
	cxFreeObjOrJson(json);
}

#define sample sample7

#endif