#ifndef __CXJSONMODEL_TUTORIAL_2_SAMPLE_1_H__
#define __CXJSONMODEL_TUTORIAL_2_SAMPLE_1_H__

#include <iostream>
#include <XFSIDC.H>
#include <cxJsonModel.h>

#include "../common/common.h"

/**
* @defgroup �������ʹ�÷�ʽ WOSA/XFS���������JSONת�� 
* ��ʾ�����������������������ͣ����ַ����Ͳ���ת����WOSA/XFS�������
* ���͡���������������ַ������͵�ָ�룬����ǿ��ΪJSON�ַ������������
* Ӧ���������������ƥ�䡣��Ӧ��ϵ���£�<br/>
* <blockquote>
* <ol style="list-style-type:upper-roman">
*	<li><strong>LPWORD(LPUSHORT LPDWORD)</strong>	���ݶ�����������������</li>
*		<ol>
*			<li><strong>��ʾ����ֵ</strong>	�ַ���ָ�룬���ֵ�ʮ���ƻ�ʮ��������ʽ</li>
*			<li><strong>NULL����</strong>	JSON���� </li>
*		</ol>
*	<li><strong>LPSTR</strong>	�����ַ������͵Ķ��壬�ɷ�Ϊ�������������</li>
*		<ol>
*			<li><strong>�����ַ���</strong>		�ַ���ָ��</li>
*			<li><strong>˫'\0'������</strong>	JSON����</li>
*			<li><strong>˫'\0'������</strong>	JSON����</li>
*			<li><strong>��'\0'�ַ���</strong>	Ƕ�׵�JSON����</li>
*		</ol>
*	<li><strong>�ṹ��ָ��</strong>	JSON����</li>
*	<li><strong>�ṹ��ָ���ָ��</strong>	JSON����</li>
* </ol>
* </blockquote>
*/

/**
* @defgroup �ַ�������������� �ַ������͵��������ת��
* @ingroup �������ʹ�÷�ʽ
*/

/**
* @ingroup �ַ��������������
* @brief �������Ϊ��ͨ�ַ������� 
*
* �������Ϊ��ͨ�ַ������͵�����������Ϊ�ַ���ָ�뼴��
* @note �˺�������ȥû���κ����飬ʵ��������WOSA���ڴ���������·�
* �����ڴ棬Ҳ����ͨ��cxJsonToObjectEx����ת�����ָ�룬����ֱ�Ӵ���
* SP��������ͬʱ����������ģ�����ִ���˱���ת����
*/
inline void sample1()
{
	const char* lpstrFormName = "readIdForm";

	// ʹ��ģ�Ϳ⽫�ṹ��ת����json�ַ���
	const char* object = 
		(const char*)cxJsonToObjectEx(lpstrFormName, 
		WFS_CMD_IDC_READ_TRACK, cxCommand::WFS_CMD_REQUEST);

	// ��ӡ��������Ч��
	std::cout << "�����������ת��ΪWOSA������" << std::endl;
	std::cout << object << std::endl;

	// �ٽ��ṹ������ת��Ϊjson���ݣ�ʵ��ʹ����Ӧ�ò����������ת����
	const char* json =
		(const char*)cxObjectToJsonEx(const_cast<char*>(object),
		WFS_CMD_IDC_READ_TRACK, cxCommand::WFS_CMD_REQUEST);

	// ��ӡ��������Ч��
	std::cout << "����WOSA����ת��Ϊ���������" << std::endl;
	std::cout << json << std::endl;

	// �ǵ��ͷ��ڴ�
	cxFreeObjOrJson(object);
	cxFreeObjOrJson(json);
}

#define sample sample1

#endif //__CXJSONMODEL_TUTORIAL_2_SAMPLE_1_H__