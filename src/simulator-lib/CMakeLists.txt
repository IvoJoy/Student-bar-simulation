# Target for the expression processing library
add_library(simulator-lib STATIC)

target_sources(
	simulator-lib
	PRIVATE
		"bar-simulator.cpp"
		"bar-simulator.h"
 "Bar33.h" "Student.h" "Student.cpp" "Bar33.cpp" "Group.h" "Group.cpp")
