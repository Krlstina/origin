cmake_minimum_required (VERSION 3.8)

project (CMakeCoursework_2)

include_directories(${JC_PROJECT_DIR}/VehicleLib)
add_subdirectory(VehicleLib)

set(MAIN_PROJECT_SRC_LIST CMakeCoursework_2.cpp)
add_executable(CMakeCoursework_2 ${MAIN_PROJECT_SRC_LIST})
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
target_include_directories(CMakeCoursework_2 PUBLIC ./VehicleLib)

target_link_libraries(CMakeCoursework_2 Vehicle)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeCoursework_2 PROPERTY CXX_STANDARD 20)
endif()