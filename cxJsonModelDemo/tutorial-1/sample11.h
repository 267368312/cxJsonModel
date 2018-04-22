#ifndef __CXJSONMODEL_TUTORIAL_11_H__
#define __CXJSONMODEL_TUTORIAL_11_H__

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
* @brief �ṹ��ָ���ָ������ת����json 
*
* ָ�����ȵĽṹ��ָ���ָ��ת��
*/
void sample11()
{
	WFSCIMCASHINFO cimCashInfo = { 0, };
	WFSCIMCASHIN* cimCashIn[] = 
		{new WFSCIMCASHIN(), new WFSCIMCASHIN()};
	memset(cimCashIn[0], 0x00, sizeof(WFSCIMCASHIN));
	memset(cimCashIn[1], 0x00, sizeof(WFSCIMCASHIN));
	cimCashInfo.lppCashIn = cimCashIn;
	cimCashInfo.usCount = 2;

	// ʹ��ģ�Ϳ⽫�ṹ��ת����json�ַ���
	const char* json =
		cxObjectToJson(&cimCashInfo, "WFSCIMCASHINFO");

	// ��ӡ��������Ч��
	std::cout << "���ǽṹ��ָ���ָ��ת���ɵ�JSON�ַ�����";
	std::cout << std::endl << json << std::endl << std::endl;

	// ����û�н�jsonת���ɽṹ�壬�������Զ���ת���������

	for (int i = 0; i < 2; ++i) delete cimCashIn[i];

	cxFreeObjOrJson(json);
}

#define sample sample11

#endif