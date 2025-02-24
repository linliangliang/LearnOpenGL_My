cmake_minimum_required(VERSION 3.10.0)

project(LearnOpenGL_My VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_DEBUG_POSTFIX "_d")

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
ENDIF(NOT CMAKE_BUILD_TYPE)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

if(WIN32)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
endif(WIN32)


#开启调试信息
ADD_COMPILE_OPTIONS(
	/Zi
	/Od
)
ADD_LINK_OPTIONS(/DEBUG)

add_compile_definitions(NANOVG_GLEW)
#add_compile_definitions(GLEW_STATIC) 改用GLAD

file(GLOB LearnOpenGL_My_INC "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h"  "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")
file(GLOB LearnOpenGL_My_SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c" "${CMAKE_CURRENT_SOURCE_DIR}/src/LearnOpenGL_My/*.cpp")

file(GLOB GLAD_SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/glad/*.c")

#三角形demo
file(GLOB TRIANDLE_INC "${CMAKE_CURRENT_SOURCE_DIR}/include/triangle/*.h")
file(GLOB TRIANDLE_SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/triangle/*.cpp")

#纹理demo
file(GLOB TEXTURE_DEMO_INC "${CMAKE_CURRENT_SOURCE_DIR}/include/texture/*.h")
file(GLOB TEXTURE_DEMO_SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/texture/*.cpp")

list(APPEND LearnOpenGL_My_INC_List  ${LearnOpenGL_My_INC} 
    ${TRIANDLE_INC}
    ${TEXTURE_DEMO_INC}
)

list(APPEND LearnOpenGL_My_SRC_List ${LearnOpenGL_My_SRC} 
    ${GLAD_SRC}
    ${TRIANDLE_SRC}
    ${TEXTURE_DEMO_SRC}
)

source_group("src/LearnOpenGL_My" FILES ${LearnOpenGL_My_SRC})
source_group("src/glad/" FILES ${GLAD_SRC})
source_group("src/triangle/" FILES ${TRIANDLE_SRC})
source_group("src/texture/" FILES ${TEXTURE_DEMO_SRC})
source_group("include" FILES ${LearnOpenGL_My_INC_List})

add_executable(LearnOpenGL_My ${LearnOpenGL_My_SRC_List} ${LearnOpenGL_My_INC_List})

target_compile_definitions(LearnOpenGL_My PRIVATE GLEW_STATIC)
if (MSVC)
    # 设置运行时库为动态链接（/MD 或 /MDd）
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
endif()


# 引用头文件路径
set(LearnOpenGL_My_include_path 
    "${CMAKE_CURRENT_SOURCE_DIR}/include/LearnOpenGL_My"
    "${CMAKE_CURRENT_SOURCE_DIR}/dep/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
foreach(__path ${LearnOpenGL_My_include_path})
    target_include_directories(LearnOpenGL_My PRIVATE ${__path})
endforeach()

# 引用lib 所在路径
target_link_directories(LearnOpenGL_My PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/dep/lib")
# 引用lib
target_link_libraries(LearnOpenGL_My PRIVATE 
    glfw3
    tess2
    opengl32
)

