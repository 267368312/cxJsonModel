#ifndef __CXJSONMODEL_TUTORIAL_2_SAMPLE_5_H__
#define __CXJSONMODEL_TUTORIAL_2_SAMPLE_5_H__

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <XFSIDC.H>
#include <cxJsonModel.h>

#include "../common/common.h"

/**
* @defgroup �ṹ��ָ������������� �ṹ��ָ���������������JSON��ת��
* @ingroup �������ʹ�÷�ʽ
*/

/**
* @ingroup �ṹ��ָ�������������
* @brief JSONת�ṹ��ָ�����͵�������� 
*
* �������������json��ʽӦ����json����
* @par �������Ӧ��json�������£�
* @code
*	{
*		"wChipProtocol": 100,
*		"lpbChipData": "1234567890abcbefg"
*	}
* @endcode
*/
inline void sample5()
{
	std::ifstream stream("json/tutorial2-sample5.json");
	if (!stream.is_open()) {
		std::cerr << "û���ҵ�rcĿ¼����Դ�ļ�" << std::endl;
		return;
	}
	std::stringstream sstream;
	sstream << stream.rdbuf();
	std::string jsonstr(sstream.str());

	// ʹ��ģ�Ϳ⽫�������ת��ΪWOSA��ʽ���������
	LPWFSIDCCHIPIO lpChipIoIn = 
		(LPWFSIDCCHIPIO)cxJsonToObjectEx(jsonstr.data(),
		WFS_CMD_IDC_CHIP_IO, cxCommand::WFS_CMD_REQUEST);

	// ��ӡ��������Ч��
	std::cout << "�����������ת��ΪWOSA������" << std::endl;
	std::cout << "WFSIDCCHIPIO.wChipProtocol: " 
		<< lpChipIoIn->wChipProtocol << std::endl;
	std::cout << "WFSIDCCHIPIO.ulChipDataLength: "
		<< lpChipIoIn->ulChipDataLength << std::endl;
	std::cout << "WFSIDCCHIPIO.lpbChipData: "
		<< (char*)lpChipIoIn->lpbChipData << std::endl;

	// �ٽ�WOSA�ṹ��ת����JSON
	const char* json = cxObjectToJsonEx(lpChipIoIn,
		WFS_CMD_IDC_CHIP_IO, cxCommand::WFS_CMD_REQUEST);

	// ��ӡ��������
	std::cout << "����WOSA�������ת���ɵ�JSON:" << std::endl;
	std::cout << json << std::endl;

	// �ͷ��ڴ棬������WFMFreeBuffer�����ͷ�
	cxFreeObjOrJson(json);
	cxFreeObjOrJson(lpChipIoIn);
}

#define sample sample5

#endif 