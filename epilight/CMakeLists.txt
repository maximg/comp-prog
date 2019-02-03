cmake_minimum_required(VERSION 3.12)

project (epilight)

add_subdirectory(../3rdparty ${CMAKE_CURRENT_BINARY_DIR}/3rdparty)

add_executable(epilight
	src/1-bit-ops.cpp
	src/main.cpp
)
target_compile_features(epilight PRIVATE cxx_std_17)

target_link_libraries(epilight PRIVATE
	Catch2::Catch2
)

add_custom_command(TARGET epilight POST_BUILD
	COMMAND epilight
)
