# CMakeList.txt : CMake project for NES_Emulator, include source and define
# project specific logic here.
#

# Add source to this project's executable.

find_package(nlohmann_json CONFIG REQUIRED)

add_executable (NES_Emulator "NES_Emulator.cpp"  "Bus.cpp" "Bus.h" "CPU.h" "CPU.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET NES_Emulator PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(NES_Emulator PRIVATE nlohmann_json::nlohmann_json)