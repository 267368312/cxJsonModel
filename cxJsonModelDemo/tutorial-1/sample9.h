#ifndef __CXJSONMODEL_TUTORIAL_9_H__
#define __CXJSONMODEL_TUTORIAL_9_H__

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
* @brief �ṹ��ָ������ת����json���� 
*/
void sample9()
{
	const char* testData = "Hello Sample9";
	WFSPINKEYDETAIL pinKeyDetail = { 0, };
	WFSXDATA xData = { 0, };
	xData.lpbData = (LPBYTE)testData;
	xData.usLength = strlen(testData);
	pinKeyDetail.lpxKeyBlockHeader = &xData;

	// ʹ��ģ�Ϳ⽫�ṹ��ת����json�ַ���
	const char* json =
		cxObjectToJson(&pinKeyDetail, "WFSPINKEYDETAIL");

	// ��ӡ��������Ч��
	std::cout << "���ǽṹ��ָ��ת���ɵ�JSON�ַ�����";
	std::cout << std::endl << json << std::endl << std::endl;

	// ��ʹ��ģ�Ϳ⽫jsonת�ɽṹ��
	WFSPINKEYDETAIL* object =
		(WFSPINKEYDETAIL*)cxJsonToObject(json, "WFSPINKEYDETAIL");

	// ��ӡ�����������ṹ�����ַ�����ֵ
	std::string lpbData(
		(char*)object->lpxKeyBlockHeader->lpbData,
		(char*)object->lpxKeyBlockHeader->lpbData +
		object->lpxKeyBlockHeader->usLength);
	std::cout << "������jsonת���ɽṹ����ֵ��" << std::endl;
	std::cout << "WFSPINKEYDETAIL.lpxKeyBlockHeader.lpbData: "
		<< lpbData << std::endl;

	// �ǵ��ͷ��ڴ�
	cxFreeObjOrJson(object);
	cxFreeObjOrJson(json);
}

#define sample sample9

#endif