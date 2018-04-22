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
	* @defgroup cxJsonModelAPI	cxJsonModel接口函数 
	* @{
	*/

	/** 命令类型，用于cxJsonToObjectEx/cxObjectToJsonEx函数 */
	enum cxCommand {
		WFS_INF_REQUEST, 	/**< INFO请求命令，与INFO输入参数对应 */
		WFS_INF_RESPONSE,	/**< INFO响应命令，与INFO输出参数对应 */
		WFS_CMD_REQUEST,	/**< CMD请求命令，与CMD输入参数对应 */
		WFS_CMD_RESPONSE,	/**< CMD响应命令，与CMD输出参数对应 */
		WFS_EVENTS			/**< 事件，与事件参数对应 */
	};

	/**
	* @brief 获取指定结构体名称在模型库中的大小
	* @param[in] objname 结构体名称
	* @return 结构体大小，模型库中不存在对应结构体时返回-1
	*/
	CXJSONMODEL_API int STDCALL cxGetObjectSize(const char* objname);

	/**
	* @brief 遍历支持列表处理函数
	* @param cmd 命令
	* @param cmdType 命令类型
	* @param 对应命令的字符形式，如cmd如果对应WFS_INF_IDC_STATUS的值，那么cmstr就为
	* "WFS_INF_IDC_STATUS"
	*/
	typedef void(STDCALL *cxTraverHandler)(int cmd, cxCommand cmdType, const char* cmdstr);

	/**
	* @brief 获取模块支持的命令列表以及命令对应关系
	* @param[in] handler 遍历处理器，每个命令调用一次函数
	* @note 请求(输入)/响应(输出)认为是不同的命令，所以会有五种类型的命令
	*/
	CXJSONMODEL_API void STDCALL cxTraverseSupportList(cxTraverHandler handler);

	/**
	* @brief 将对象生成json字符串
	* @param[in] obj 对象指针
	* @param[in] objname 对象名称
	* @return json字符串指针或NULL
	*/
	CXJSONMODEL_API const char* STDCALL cxObjectToJson(void* obj, const char* objname);

	/**
	* @brief 将json字符串生成对象指针
	* @param[in] json json字符串
	* @param[in] objname 对象名称
	* @return 对象指针或NULL
	*/
	CXJSONMODEL_API void* STDCALL cxJsonToObject(const char* json, const char* objname);

	/**
	* @brief 将对象生成json字符串
	* @param[in] obj 对象指针或命令对应类型的指针,命令若对应数字类型，则应传入数字类型指针，若对
	* 应字符串，则应传入字符串指针
	* @param[in] cmd 命令值
	* @param[in] cmdType 命令类型
	* @return 字符串，不一定是json，返回的指针与对应的命令参数匹配，若命令对应结构体则返回json，
	* 对应普通类型则返回字符串，包括字符串类型和数字类型也是返回其对应字符串指针，而非对应类型指针
	* @note 此函数用于wosa/xfs中请求和应答数据的处理，若无对应命令的数据模型时，则返回空指针
	*/
	CXJSONMODEL_API const char* STDCALL cxObjectToJsonEx(void* obj, int cmd, cxCommand cmdType);

	/**
	* @brief 将json生成对应的响应或应答数据指针
	* @param[in] json json字符串或命令对应类型的字符串指针，若命令对应WORD类型，则是WROD值转换成
	* 字符串后的字符串指针
	* @param[in] cmd 命令值
	* @param[in] cmdType 命令类型
	* @return 结构体指针或命令对应基本类型指针，若命令对应WORD类型，则返回WORD类型指针，对应字符串
	* 则返回字符串指针
	* @note 此函数用于wosa/xfs中请求和应答数据的处理，若无对应命令的数据模型时，则返回空指针
	*/
	CXJSONMODEL_API void* STDCALL cxJsonToObjectEx(const char* json, int cmd, cxCommand cmdType);

	/**
	* @brief 释放内存
	* @param[in] p 由objectToJson和jsonToObject返回的指针
	* @note 由上述函数返回的指针必须由此函数释放，否则会导致内存泄漏
	*/
	CXJSONMODEL_API void STDCALL cxFreeObjOrJson(const void* p);

	/** @} */

#ifdef __cplusplus
}
#endif

#endif //__XFSMODULE_H__