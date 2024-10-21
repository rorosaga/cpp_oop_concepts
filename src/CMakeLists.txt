
# Look for headers in the include directory
include_directories(${CMAKE_SOURCE_DIR}/include)
# add_library(DynamicArray SHARED DynamicArray.h)

# You can also add any stand alone executables
# add_executable(example main.cpp) # Will make a binary called "example" inside build/bin using main.cpp
add_executable(student_class student_class.cpp)
add_executable(dynamicArray_class dynamicArray_class.cpp)
add_executable(rule_of_zero rule_of_zero.cpp)
