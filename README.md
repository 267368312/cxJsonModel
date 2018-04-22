# 概述
cxJsonModel是为WOSA/XFS深度定制的JSON模型库，由C++语言编写，对外提供C 访问接口，除支持对应版本的结构体模型映射外，还为对应版本的五种类型的命令 提供映射功能： 

>- Info Commands 
>    1. Input Param 
>    2. Output Param 
>- Info Commands 
>    1. Input Param 
>    2. Output Param 
>- Events 

利用cxJsonModel提供的命令映射功能，能极大程度的简化您跨语言调用调用的应 用架构。cxJsonModel提供夸平台平台模块，支持主流金融设备所使用的操作系统。

# 依赖
cxJsonModel模型库依赖两个外部库 
> - iconv 为cxJsonModel提供编码转换功能
> - xfs_supp 为cxJsonModel提供内存分配功能 

# 检查
cxJsonModel完全依赖[官方](https://www.cen.eu)SDK开发，无任 何修改（包括错名）。如果您是无修改的使用官网SDK则可以忽略此节。如果您不确定使用的是否为原版SDK，只要您确定版本，将SDK中的头文件拷贝致CUSTOM/detectionXXX目录，然后编译detectionXXX工程，运行生成的可执行程序，即可检查您现有的WOSA/XFS结构是否与模型库匹配。

# 用法
使用cxJsonModel将WOSA/XFS的输出参数转换为JSON：
```
    const char* lpBuffer =
    	"TRACK3:MII=59\0COUNTRY=280\0ISSUERID=50050500\0ACCOUNT=\
    	1234567890\0LUHNT3=1\0EXPIRATION=9912\0SECURE=1\0\0";
    
    WFSRESULT result = { 0, };
    result.u.dwCommandCode = WFS_CMD_IDC_READ_TRACK;
    result.lpBuffer = const_cast<char*>(lpBuffer);
    
    // 使用模型库将结构体转换成json字符串
    const char* json =
    	cxObjectToJsonEx(&result,
    		WFS_CMD_IDC_READ_TRACK, cxCommand::WFS_CMD_RESPONSE);
    
    // 打印出来看看
    std::cout << "这是响应参数转换成的json字符串：" << std::endl;
    std::cout << json << std::endl;
    
    cxFreeObjOrJson(json);
```

运行这段代码，输出结果为：
```
    这是响应参数转换成的json字符串：
    {
       "RequestID" : 0,
       "dwCommandCode" : 201,
       "hResult" : 0,
       "hService" : 0,
       "lpBuffer" : {
          "TRACK3" : {
             "ACCOUNT" : "1234567890",
             "COUNTRY" : "280",
             "EXPIRATION" : "9912",
             "ISSUERID" : "50050500",
             "LUHNT3" : "1",
             "MII" : "59",
             "SECURE" : "1"
          }
       },
       "tsTimestamp" : {
          "wDay" : 0,
          "wDayOfWeek" : 0,
          "wHour" : 0,
          "wMilliseconds" : 0,
          "wMinute" : 0,
          "wMonth" : 0,
          "wSecond" : 0,
          "wYear" : 0
       }
    }
```

同样，也可以将请求参数转换为WOSA/XFS结构体。

# 关于DEMO
demo中写了19个示例，分别挑选了不同类型的对象转换，您可以编译并运行其中的示例，查看输出结果。

# 联系方式
如果您在使用中遇到什么困难，请发送问题到我的[邮箱](mailto:267368312@qq.com)。
