cmake_minimum_required(VERSION 3.5)

project(guess_number)

add_subdirectory(dynamic_lib)

add_executable(guess_the_number guess_the_number.cpp)

set_target_properties(guess_the_number PROPERTIES
		       CXX_STANDARD 17
		       CXX_STANDARD_REQUIRED ON)
		       
target_include_directories(guess_the_number PRIVATE
			    ${CMAKE_SOURCE_DIR}/dynamic_lib)
			    
target_link_libraries(guess_the_number PUBLIC random)	


if(MSVC)
        target_compile_options(guess_the_number PUBLIC /W4 /WX)
else()
        target_compile_options(guess_the_number PUBLIC -Wall -Wextra -Werror -pedantic)
endif()	       

