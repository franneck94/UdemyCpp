cmake_minimum_required(VERSION 3.17)

set(PROJECT "AdasGui")
project(${PROJECT} VERSION 0.1.0 LANGUAGES CXX C)

# Global CMake variables are set here
set(CMAKE_CXX_STANDARD              17)
set(CMAKE_CXX_STANDARD_REQUIRED     ON)
set(CMAKE_CXX_EXTENSIONS            OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS   ON)

# Options
option(ENABLE_WARNINGS  "Enable to add warnings to a target." ON)

# Cmake modules
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/)
include(ConfigSafeGuards)
if (ENABLE_WARNINGS)
    include(Warnings)
endif()

# Project/Library Names
set(ADAS_LIB      lib)
set(IMGUI_LIB     imgui)
set(IMPLOT_LIB    implot)
set(GLFW_LIB      glfw)
set(GLAD_LIB      glad)
set(EXE_NAME      AdasGui)

add_subdirectory(external)
add_subdirectory(src)

add_executable(${EXE_NAME}
        app/imgui_impl_glfw.h
        app/imgui_impl_glfw.cpp
        app/imgui_impl_opengl3.h
        app/imgui_impl_opengl3.cpp
        app/main.cpp)
target_set_warnings(TARGET ${EXE_NAME} ENABLE ON AS_ERROR OFF)

target_include_directories(${EXE_NAME} PUBLIC "imgui/")
target_link_libraries(${EXE_NAME} ${IMGUI_LIB} "${CMAKE_DL_LIBS}")
target_include_directories(${EXE_NAME} PUBLIC "glad/include")
target_link_libraries(${EXE_NAME} ${GLAD_LIB} "${CMAKE_DL_LIBS}")
target_link_libraries(${EXE_NAME} ${GLFW_LIB} "${GLFW_LIBRARIES}")
target_include_directories(${EXE_NAME} PUBLIC "glfw/include")
target_compile_definitions(${EXE_NAME} PUBLIC "GLFW_INCLUDE_NONE")
target_include_directories(${EXE_NAME} PUBLIC "implot")
target_link_libraries(${EXE_NAME} ${IMPLOT_LIB} "${CMAKE_DL_LIBS}")
target_link_libraries(${EXE_NAME} ${ADAS_LIB} "${CMAKE_DL_LIBS}")
