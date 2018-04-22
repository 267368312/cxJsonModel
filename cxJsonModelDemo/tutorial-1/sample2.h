#ifndef __CXJSONMODEL_TUTORIAL_2_H__
#define __CXJSONMODEL_TUTORIAL_2_H__

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
* @defgroup ָ�����ͳ�Ա WOSA/XFS�ṹ���а���ָ��Ľṹ�� 
* @ingroup ����ʹ�÷�ʽ
* ������ʾ�������͵�ָ��ת��
*/

/**
* @ingroup ָ�����ͳ�Ա
* @brief �����ַ���ָ��Ľṹ�� 
*
* ָ����������ͨխ�ַ�����ת����cxJsonModel���ַ������͵������Զ�����
* ����ת������Ϊjson�ַ�����UTF-8���룬���ṹ���е��ַ���ΪGB18030��
* �롣�������յ���JSON�ַ�����ֵ��ṹ���еĳ�Ա������ͬ�������ַ�����
* �͵����ݴ�UTF-8ת��ΪGB18030�����Է��صĽṹ�����ַ�����GB18030���룻
* �����ṹ��ת��ΪJSON�ַ���ʱ������ԱΪ�ַ������͵����ݴ�GB18030����
* ת����UTF-8��֧����Ƨ�֡������в�����ʾ��
*/
inline void sample2()
{
	WFSPTRQUERYFIELD ptrQueryField;
	ptrQueryField.lpszFieldName = "PtrField";
	ptrQueryField.lpszFormName = "PtrForm";

	// ʹ��ģ�Ϳ⽫�ṹ��ת����json�ַ���
	const char* json = 
		cxObjectToJson(&ptrQueryField, "WFSPTRQUERYFIELD");

	// ��ӡ��������Ч��
	std::cout << "���Ǽ��ַ����ṹ��ת���ɵ�json�ַ�����" << std::endl;
	std::cout << json << std::endl << std::endl;

	// ��ʹ��ģ�Ϳ⽫jsonת�ɽṹ��
	WFSPTRQUERYFIELD* object = (WFSPTRQUERYFIELD*)
				cxJsonToObject(json, "WFSPTRQUERYFIELD");

	// ��ӡ�����������ṹ���ֵ
	std::cout << "������json�ַ���ת���ɽṹ����ֵ��" << std::endl;
	std::cout << "WFSPTRQUERYFIELD.lpszFormName: "
		<< object->lpszFormName << std::endl;
	std::cout << "WFSPTRQUERYFIELD.lpszFieldName: "
		<< object->lpszFieldName << std::endl << std::endl;

	// �ǵ��ͷ��ڴ�
	cxFreeObjOrJson(object);
	cxFreeObjOrJson(json);
}

#define sample sample2

#endif