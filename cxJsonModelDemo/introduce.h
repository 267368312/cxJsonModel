/**
 * @mainpage cxJsonModel简介 
 * 
 * @section introduce 概述 
 * 
 * cxJsonModel是为WOSA/XFS深度定制的JSON模型库，由C++语言编写，对外提供C
 * 访问接口，除支持对应版本的结构体模型映射外，还为对应版本的五种类型的命令
 * 提供映射功能：
 * <blockquote>
 * <ul>
 * 	<li>Info Commands</li>
 * 		<ol>
 * 			<li>Input Param</li>
 * 			<li>Output Param</li>
 * 		</ol>
 * 	<li>Info Commands</li>
 * 		<ol>
 * 			<li>Input Param</li>
 * 			<li>Output Param</li>
 * 		</ol>
 * 	<li>Events</li>
 * </ul>
 * </blockquote>
 * 利用cxJsonModel提供的命令映射功能，能极大程度的简化您跨语言调用调用的应
 * 用架构。cxJsonModel提供夸平台平台模块，支持主流金融设备所使用的操作系统。
 * 
 * @section depends 依赖 
 * 
 * cxJsonModel模型库依赖两个外部库
 * <ul>
 * 	<li><em>iconv</em> 为cxJsonModel提供编码转换功能</li>
 * 	<li><em>xfs_supp</em> 为cxJsonModel提供内存分配功能</li>
 * </ul>
 * 
 * @section check 使用前检查 
 * cxJsonModel完全依赖<a href="https://www.cen.eu">官方</a>SDK开发，无任
 * 何修改（包括错名）。如果您是无修改的使用官网SDK则可以忽略此节。在
 * cxJsonModel文件夹中有一个CUSTOM文件夹，存放了三个版本头文件，将您使用的头
 * 文件放入对应版本的文件夹，编译对应工程，将prebuild/win32中的iconv.dll和
 * offical目录下的xfs_supp.dll拷贝到工程的输出目录cxJsonModel/bin。运行
 * detectionXXX.exe，detectionXXX.exe会检查您的所有类型与模型库中的类型是否
 * 匹配。若您需要运行demo还需要将json目录拷贝至输出目录。
 * 
 * @section usage 使用cxJsonModle 
 * 
 * cxJsonModel提供的头文件和win32动态库放在prebuild目录下，在vc工程中添加依
 * 赖即可。win32中的动态库采用vs2015编译，如果您的编译器版本过低，可能无法在
 * debug模式下使用，您可以切换到release模式，并在release模式下开开启调试功能。
 * 
 * @section demousage Demo的使用 
 * 
 * 如果您使用过cmake，可以忽略此章节。在cxJsonModel目录下新建一个VS2015
 * 文件夹，进入VS2015文件夹，调出命令行窗口（shift+鼠标右键）,输入“cmake ..”。
 * 更多关于cmake用法请前往<a href="https://cmake.org/cmake-tutorial/">cmake官方教程</a>
 * 
 * @section contact 联系方式 
 * <strong>Email: </strong><a href="mailto:267368312@qq.com">267368312@qq.com</a>
 */