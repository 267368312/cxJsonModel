#ifndef __CXJSONMODEL_TUTORIAL_8_H__
#define __CXJSONMODEL_TUTORIAL_8_H__

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
* @brief �г������Ƶ�ָ������ת�����ַ��� 
*
* ת����json�󣬱�ʾ�������Ƶ��ֶβ��������json�ַ���
*/
inline void sample8()
{
	const char* testData = "123\1\3\0\181232439843\254\255\0\0\0234adaswe~123\0\0\0\0";
	WFSIPMMEDIASTATUS ipmMediaStatus = { 0, };
	ipmMediaStatus.lpbCodelineData = (LPBYTE)testData;
	ipmMediaStatus.ulCodelineDataLength = lengthOfBytes(testData, 5);

	// ʹ��ģ�Ϳ⽫�ṹ��ת����json�ַ���
	const char* json =
		cxObjectToJson(&ipmMediaStatus, "WFSIPMMEDIASTATUS");

	// ��ӡ��������Ч��
	std::cout << "�����г������Ƶ�BYTEָ��ת���ɵ�JSON�ַ�����";
	std::cout << std::endl << json << std::endl << std::endl;

	// ��ʹ��ģ�Ϳ⽫jsonת�ɽṹ��
	WFSIPMMEDIASTATUS* object =
		(WFSIPMMEDIASTATUS*)cxJsonToObject(json, "WFSIPMMEDIASTATUS");

	// ��ӡ�����������ṹ�����ַ�����ֵ
	std::string lpbCodelineData(object->lpbCodelineData,
		object->lpbCodelineData + object->ulCodelineDataLength);
	std::cout << "������jsonת���ɽṹ����ֵ��" << std::endl;
	std::cout << "WFSIPMMEDIASTATUS.lpbCodelineData: " 
			  << lpbCodelineData << std::endl;

	// �ǵ��ͷ��ڴ�
	cxFreeObjOrJson(object);
	cxFreeObjOrJson(json);
}

#define sample sample8

#endif