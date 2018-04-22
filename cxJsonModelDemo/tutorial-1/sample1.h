#ifndef __CXJSONMODEL_TUTORIAL_1_H__
#define __CXJSONMODEL_TUTORIAL_1_H__

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
* @defgroup ����ʹ�÷�ʽ WOSA/XFS�ṹ����JSON�໥ת�� 
* ��ʾ�����cxJsonModel�⽫�ṹ����json�����໥ת��
*/

/**
* @defgroup �ڽ��������� ��򵥵Ľṹ���JSON֮���ת�� 
* @ingroup ����ʹ�÷�ʽ
* ��ʾʹ�����ݳ�Ա�Ƿ�ָ���ڽ����͵�ʹ�÷�ʽ
*/

/**
* @ingroup �ڽ���������
* @brief �򵥽ṹ��ת����Json 
*
* �򵥽ṹ����ֻ������C/C++�����ڽ���������
*/
inline void sample1()
{
	WFSPTRRETRACTBINS ptrRetractBins;
	ptrRetractBins.usRetractCount = 4;
	ptrRetractBins.wRetractBin = 10;

	// ʹ��ģ�Ϳ⽫�ṹ��ת����json�ַ���
	const char* json = 
		cxObjectToJson(&ptrRetractBins, "WFSPTRRETRACTBINS");

	// ��ӡ��������Ч��
	std::cout << "���Ǽ򵥽ṹ��ת���ɵ�json�ַ�����" << std::endl;
	std::cout << json << std::endl << std::endl;

	// ��ʹ��ģ�Ϳ⽫jsonת�ɽṹ��
	WFSPTRRETRACTBINS* object = (WFSPTRRETRACTBINS*)
					cxJsonToObject(json, "WFSPTRRETRACTBINS");

	// ��ӡ�����������ṹ���ֵ
	std::cout << "������json�ַ���ת���ɽṹ����ֵ��" << std::endl;
	std::cout << "WFSPTRRETRACTBINS.usRetractCount: "
		<< object->usRetractCount << std::endl;
	std::cout << "WFSPTRRETRACTBINS.wRetractBin: "
		<< object->wRetractBin << std::endl << std::endl;

	// �ǵ��ͷ��ڴ�
	cxFreeObjOrJson(object);
	cxFreeObjOrJson(json);
}

#define sample sample1

#endif