#ifndef __CXJSONMODEL_TUTORIAL_10_H__
#define __CXJSONMODEL_TUTORIAL_10_H__

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
* ������NULL�����Ľṹ��ָ���ָ��ת��
*/
inline void sample10()
{
	WFSIPMIMAGEDATA* ipmImageDatas[3] = 
	{ 
		new WFSIPMIMAGEDATA(), 
		new WFSIPMIMAGEDATA(),
		nullptr
	};
	const char* imageFiles[] = 
	{
		"c:\\Program Files\\Commond Files\\XFS\\SDK\\imageFile1",
		"c:\\Program Files\\Commond Files\\XFS\\SDK\\imageFile2"
	};

	for (int i = 0; i < 2; ++i) {
		ipmImageDatas[i]->wImageSource = (i + 1) * 10 + 1;
		ipmImageDatas[i]->wImageType = (i + 1) * 10 + 2;
		ipmImageDatas[i]->wImageColorFormat = (i + 1) * 10 + 3;
		ipmImageDatas[i]->wImageScanColor = (i + 1) * 10 + 4;
		ipmImageDatas[i]->wImageStatus = (i + 1) * 10 + 5;
		ipmImageDatas[i]->lpszImageFile = const_cast<char*>(imageFiles[i]);
	}

	WFSIPMMEDIASIZE ipmMediaSize = {100, 200};

	WFSIPMMEDIASTATUS ipmMediaStatus = { 0, };
	ipmMediaStatus.lppImage = ipmImageDatas;
	ipmMediaStatus.lpMediaSize = &ipmMediaSize;

	// ʹ��ģ�Ϳ⽫�ṹ��ת����json�ַ���
	const char* json =
		cxObjectToJson(&ipmMediaStatus, "WFSIPMMEDIASTATUS");

	// ��ӡ��������Ч��
	std::cout << "���ǽṹ��ָ���ָ��ת���ɵ�JSON�ַ�����";
	std::cout << std::endl << json << std::endl << std::endl;

	// ��ʹ��ģ�Ϳ⽫jsonת�ɽṹ��
	WFSIPMMEDIASTATUS* object =
		(WFSIPMMEDIASTATUS*)cxJsonToObject(json, "WFSIPMMEDIASTATUS");

	for (int i = 0; object->lppImage[i]; ++i) {
		std::cout
			<< "WFSIPMMEDIASTATUS.lppImage[" << i << "]->wImageSource: " 
			<< object->lppImage[i]->wImageSource << std::endl;

		std::cout
			<< "WFSIPMMEDIASTATUS.lppImage[" << i << "]->wImageType: "
			<< object->lppImage[i]->wImageType << std::endl;

		std::cout
			<< "WFSIPMMEDIASTATUS.lppImage[" << i << "]->wImageColorFormat: "
			<< object->lppImage[i]->wImageColorFormat << std::endl;

		std::cout
			<< "WFSIPMMEDIASTATUS.lppImage[" << i << "]->wImageScanColor: "
			<< object->lppImage[i]->wImageScanColor << std::endl;

		std::cout
			<< "WFSIPMMEDIASTATUS.lppImage[" << i << "]->wImageStatus: "
			<< object->lppImage[i]->wImageStatus << std::endl;

		std::cout
			<< "WFSIPMMEDIASTATUS.lppImage[" << i << "]->lpszImageFile: "
			<< object->lppImage[i]->lpszImageFile << std::endl;
	}

	for (int i = 0; i < 2; ++i)
		delete ipmImageDatas[i];

	// �ǵ��ͷ��ڴ�
	cxFreeObjOrJson(object);
	cxFreeObjOrJson(json);
}

#define sample sample10

#endif