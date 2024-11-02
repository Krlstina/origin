cmake_minimum_required (VERSION 3.8)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("CMakeBye")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (CMakeBye "CMakeBye.cpp")
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(ByeDynamicLib SHARED "ByeDynamic.h" "ByeDynamic.cpp")
target_link_libraries(CMakeBye ByeDynamicLib)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeBye PROPERTY  20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
