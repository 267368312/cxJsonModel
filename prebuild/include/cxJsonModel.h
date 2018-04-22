#ifndef __XFSMODULE_H__
#define __XFSMODULE_H__

#if defined(_MSC_VER)
	#define STDCALL	__stdcall
	#ifdef CXJSONMODEL_EXPORT
		#define CXJSONMODEL_API __declspec(dllexport)
	#else
		#define CXJSONMODEL_API __declspec(dllimport)
	#endif
#elif defined(__GNUC__)
	#define STDCALL
	#define CXJSONMODEL_API  __attribute__ ((visibility("default")))
#endif

#ifdef __cplusplus
extern "C" {
#endif

	/**
	* @defgroup cxJsonModelAPI	cxJsonModel�ӿں��� 
	* @{
	*/

	/** �������ͣ�����cxJsonToObjectEx/cxObjectToJsonEx���� */
	enum cxCommand {
		WFS_INF_REQUEST, 	/**< INFO���������INFO���������Ӧ */
		WFS_INF_RESPONSE,	/**< INFO��Ӧ�����INFO���������Ӧ */
		WFS_CMD_REQUEST,	/**< CMD���������CMD���������Ӧ */
		WFS_CMD_RESPONSE,	/**< CMD��Ӧ�����CMD���������Ӧ */
		WFS_EVENTS			/**< �¼������¼�������Ӧ */
	};

	/**
	* @brief ��ȡָ���ṹ��������ģ�Ϳ��еĴ�С
	* @param[in] objname �ṹ������
	* @return �ṹ���С��ģ�Ϳ��в����ڶ�Ӧ�ṹ��ʱ����-1
	*/
	CXJSONMODEL_API int STDCALL cxGetObjectSize(const char* objname);

	/**
	* @brief ����֧���б�����
	* @param cmd ����
	* @param cmdType ��������
	* @param ��Ӧ������ַ���ʽ����cmd�����ӦWFS_INF_IDC_STATUS��ֵ����ôcmstr��Ϊ
	* "WFS_INF_IDC_STATUS"
	*/
	typedef void(STDCALL *cxTraverHandler)(int cmd, cxCommand cmdType, const char* cmdstr);

	/**
	* @brief ��ȡģ��֧�ֵ������б��Լ������Ӧ��ϵ
	* @param[in] handler ������������ÿ���������һ�κ���
	* @note ����(����)/��Ӧ(���)��Ϊ�ǲ�ͬ��������Ի����������͵�����
	*/
	CXJSONMODEL_API void STDCALL cxTraverseSupportList(cxTraverHandler handler);

	/**
	* @brief ����������json�ַ���
	* @param[in] obj ����ָ��
	* @param[in] objname ��������
	* @return json�ַ���ָ���NULL
	*/
	CXJSONMODEL_API const char* STDCALL cxObjectToJson(void* obj, const char* objname);

	/**
	* @brief ��json�ַ������ɶ���ָ��
	* @param[in] json json�ַ���
	* @param[in] objname ��������
	* @return ����ָ���NULL
	*/
	CXJSONMODEL_API void* STDCALL cxJsonToObject(const char* json, const char* objname);

	/**
	* @brief ����������json�ַ���
	* @param[in] obj ����ָ��������Ӧ���͵�ָ��,��������Ӧ�������ͣ���Ӧ������������ָ�룬����
	* Ӧ�ַ�������Ӧ�����ַ���ָ��
	* @param[in] cmd ����ֵ
	* @param[in] cmdType ��������
	* @return �ַ�������һ����json�����ص�ָ�����Ӧ���������ƥ�䣬�������Ӧ�ṹ���򷵻�json��
	* ��Ӧ��ͨ�����򷵻��ַ����������ַ������ͺ���������Ҳ�Ƿ������Ӧ�ַ���ָ�룬���Ƕ�Ӧ����ָ��
	* @note �˺�������wosa/xfs�������Ӧ�����ݵĴ������޶�Ӧ���������ģ��ʱ���򷵻ؿ�ָ��
	*/
	CXJSONMODEL_API const char* STDCALL cxObjectToJsonEx(void* obj, int cmd, cxCommand cmdType);

	/**
	* @brief ��json���ɶ�Ӧ����Ӧ��Ӧ������ָ��
	* @param[in] json json�ַ����������Ӧ���͵��ַ���ָ�룬�������ӦWORD���ͣ�����WRODֵת����
	* �ַ�������ַ���ָ��
	* @param[in] cmd ����ֵ
	* @param[in] cmdType ��������
	* @return �ṹ��ָ��������Ӧ��������ָ�룬�������ӦWORD���ͣ��򷵻�WORD����ָ�룬��Ӧ�ַ���
	* �򷵻��ַ���ָ��
	* @note �˺�������wosa/xfs�������Ӧ�����ݵĴ������޶�Ӧ���������ģ��ʱ���򷵻ؿ�ָ��
	*/
	CXJSONMODEL_API void* STDCALL cxJsonToObjectEx(const char* json, int cmd, cxCommand cmdType);

	/**
	* @brief �ͷ��ڴ�
	* @param[in] p ��objectToJson��jsonToObject���ص�ָ��
	* @note �������������ص�ָ������ɴ˺����ͷţ�����ᵼ���ڴ�й©
	*/
	CXJSONMODEL_API void STDCALL cxFreeObjOrJson(const void* p);

	/** @} */

#ifdef __cplusplus
}
#endif

#endif //__XFSMODULE_H__