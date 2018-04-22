#ifndef __CXJSONMODEL_TUTORIAL_6_H__
#define __CXJSONMODEL_TUTORIAL_6_H__

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
* @brief ��NULL������ָ������ת�� 
*
* ��NULL�����ķ�charָ��ᱻת��ΪJSON�����ʽ
*/
inline void sample6()
{
	WORD testData[] = {1,2,3,4,5,6,7,8,9,0 };
	WFSPINCAPS pinCaps = { 0, };
	pinCaps.lpwEMVImportSchemes = testData;

	// ʹ��ģ�Ϳ⽫�ṹ��ת����json�ַ���
	const char* json =
		cxObjectToJson(&pinCaps, "WFSPINCAPS");

	// ��ӡ��������Ч��
	std::cout << "������NULL������WORDָ��ת���ɵ�JSON�ַ�����";
	std::cout << std::endl << json << std::endl << std::endl;

	// ��ʹ��ģ�Ϳ⽫jsonת�ɽṹ��
	WFSPINCAPS* object = 
		(WFSPINCAPS*)cxJsonToObject(json, "WFSPINCAPS");
	std::string data;
	for (int i = 0; object->lpwEMVImportSchemes &&
		object->lpwEMVImportSchemes[i]; ++i) {
		char buffer[32] = { 0, };
		sprintf(buffer, "%d ", object->lpwEMVImportSchemes[i]);
		data += buffer;
	}
	std::cout << "������jsonת���ɽṹ����ֵ��" << std::endl;
	std::cout << "WFSPINCAPS.lpwEMVImportSchemes: "
		<< data << std::endl;

	// �ǵ��ͷ��ڴ�
	cxFreeObjOrJson(object);
	cxFreeObjOrJson(json);
}

#define sample sample6

#endif