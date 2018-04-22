cmake_minimum_required(VERSION 2.8)

PROJECT(detection310)

# 头文件所在目录
INCLUDE_DIRECTORIES(
    ./
    ${PROJECT_SOURCE_DIR}/../../CUSTOM/XFS310 
    ${PROJECT_SOURCE_DIR}/../../prebuild/include
)

# 定义CEN/XFS版本信息
ADD_DEFINITIONS(-DXFS_VERSION_310)

# 链接库所在目录
IF(MSVC)
    IF(CMAKE_CL_64)
        LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/../../prebuild/win64)
    ELSE()
        LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/../../prebuild/win32)
    ENDIF()
ELSE()
    MESSAGE(fatal_error "Haven't compile other platforms")
ENDIF()

# 所有cpp文件
AUX_SOURCE_DIRECTORY(../src SOURCES)

# 链接动态库
LINK_LIBRARIES(iconv cxJsonModel310 gtest)

ADD_EXECUTABLE(${PROJECT_NAME} ${SOURCES})