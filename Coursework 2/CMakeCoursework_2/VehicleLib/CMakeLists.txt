cmake_minimum_required (VERSION 3.8)

project ("Vehicle")
message("Hello")

set(SOURCES VehicleDynamic.cpp GroundVehicle.cpp AirVehicle.cpp)
set(HEADERS VehicleDynamic.h GroundVehicle.h AirVehicle.h)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(Vehicle SHARED ${SOURCES} ${HEADERS})

target_include_directories(Vehicle PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_custom_command(TARGET Vehicle POST_BUILD   # Adds a post-build event
   COMMAND ${CMAKE_COMMAND} -E copy_if_different       # which executes "cmake - E copy_if_different..."
   "${CMAKE_SOURCE_DIR}/out/build/x64-debug/VehicleLib/Vehicle.dll"       # <--this is in-file
   ${CMAKE_SOURCE_DIR}/out/build/x64-debug/)                          # <--this is out-file path