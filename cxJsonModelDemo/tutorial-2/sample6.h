#ifndef __CXJSONMODEL_TUTORIAL_2_SAMPLE_6_H__
#define __CXJSONMODEL_TUTORIAL_2_SAMPLE_6_H__

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <XFSIDC.H>
#include <cxJsonModel.h>

#include "../common/common.h"

/**
* @ingroup �ṹ��ָ�������������
* @brief JSONת�ṹ��ָ���ָ������������� 
*
* �������������json��ʽӦ����json����
* @par �����������JSON���飬����ʽָ���Ĳ���ʹ��Ĭ��ֵ0���ָ�룺
* @code
*	[
*		{
*			"wDataSource": 1,
*			"wStatus":2
*		},
*		{
*			"lpbData": "Hello WOSA/XFS"
*		},
*		{
*			"fwWriteMethod": 100
*		}
*	]
* @endcode
*/
inline void sample6()
{
	std::ifstream stream("json/tutorial2-sample6.json");
	if (!stream.is_open()) {
		std::cerr << "û���ҵ�rcĿ¼����Դ�ļ�" << std::endl;
		return;
	}
	std::stringstream sstream;
	sstream << stream.rdbuf();
	std::string jsonstr(sstream.str());

	// ʹ��ģ�Ϳ⽫�������ת��ΪWOSA��ʽ���������
	LPWFSIDCCARDDATA* lppCardData =
		(LPWFSIDCCARDDATA*)cxJsonToObjectEx(jsonstr.data(),
			WFS_CMD_IDC_WRITE_RAW_DATA, cxCommand::WFS_CMD_REQUEST);

	// ��ӡ��������Ч��
	std::cout << "�����������ת��ΪWOSA������" << std::endl;
	for (int i = 0; lppCardData[i]; ++i)
	{
		std::cout << "lppCardData[" << i << "]->wDataSource: "
			<< lppCardData[i]->wDataSource << std::endl;

		std::cout << "lppCardData[" << i << "]->wStatus: "
			<< lppCardData[i]->wStatus << std::endl;

		std::cout << "lppCardData[" << i << "]->ulDataLength: "
			<< lppCardData[i]->ulDataLength << std::endl;

		std::cout << "lppCardData[" << i << "]->lpbData: ";
		if (lppCardData[i]->lpbData) {
			std::cout << (char*)lppCardData[i]->lpbData << std::endl;
		}
		else {
			std::cout << "nullptr" << std::endl;
		}
			
		std::cout << "lppCardData[" << i << "]->fwWriteMethod: "
			<< lppCardData[i]->fwWriteMethod << std::endl;
	}

	// �ٽ�WOSA�ṹ��ת����JSON
	const char* json = cxObjectToJsonEx(lppCardData,
		WFS_CMD_IDC_WRITE_RAW_DATA, cxCommand::WFS_CMD_REQUEST);
	
	// ��ӡ��������
	std::cout << "����WOSA�������ת���ɵ�JSON:" << std::endl;
	std::cout << json << std::endl;

	// �ͷ��ڴ棬������WFMFreeBuffer�����ͷ�
	cxFreeObjOrJson(json);
	cxFreeObjOrJson(lppCardData);
}

#define sample sample6

#endif