cmake_minimum_required (VERSION 3.8)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Homework_3_9_2_CMakeProject")

add_executable (Homework_3_9_2_CMakeProject "Homework_3_9_2_CMakeProject.cpp" "Figure/triangle.h" "Figure/triangle.cpp" "Figure/quadrilateral.h" "Figure/quadrilateral.cpp"
				"Figure/right_angled_triangle.h" "Figure/right_angled_triangle.cpp" "Figure/isosceles_triangle.h" "Figure/isosceles_triangle.cpp"
				"Figure/equilateral_triangle.h" "Figure/equilateral_triangle.cpp" "Figure/parallelogram.h" "Figure/parallelogram.cpp"
				"Figure/rectangle_figure.h" "Figure/rectangle_figure.cpp" "Figure/square.h" "Figure/square.cpp" "Figure/rhomb.h" "Figure/rhomb.cpp")