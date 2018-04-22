cmake_minimum_required(VERSION 2.8)

PROJECT(cxJsonModelDemo)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/../CUSTOM/XFS310)

# 头文件所在目录
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/../prebuild/include)

# 链接库所在目录
IF(MSVC)
    IF(CMAKE_CL_64)
        LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/../prebuild/win64)
    ELSE()
        LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/../prebuild/win32)
    ENDIF()
ELSE()
    MESSAGE(fatal_error "Haven't compile other platforms")
ENDIF()

# 链接动态库
LINK_LIBRARIES(iconv cxJsonModel310)

# 将运行时依赖项拷贝到生成目录
execute_process(
    COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/json ${EXECUTABLE_OUTPUT_PATH}
)


# 生成demo工程
FOREACH(dir RANGE 1 3 1)
    FOREACH(file RANGE 1 12 1)
        SET(SampleHeader tutorial-${dir}/sample${file}.h)
        IF (EXISTS ${PROJECT_SOURCE_DIR}/${SampleHeader})

            configure_file(
                "${PROJECT_SOURCE_DIR}/main.cpp.in"
                "${PROJECT_SOURCE_DIR}/generate/tutorial${dir}-sample${file}.cpp"
            )
            add_executable(
                tutorial${dir}-sample${file} 
                ${PROJECT_SOURCE_DIR}/${SampleHeader}
                ${PROJECT_SOURCE_DIR}/generate/tutorial${dir}-sample${file}.cpp)

            set_target_properties(
                tutorial${dir}-sample${file} 
                PROPERTIES VERSION 1.0.0.0)
        ENDIF()
    ENDFOREACH(file)
ENDFOREACH(dir)