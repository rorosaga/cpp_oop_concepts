include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.2
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

include_directories(${CMAKE_SOURCE_DIR}/src)

link_libraries(GTest::gtest_main)

add_executable(test_dynamicArray test_dynamicArray.cpp) 

target_link_libraries(test_dynamicArray GTest::gtest_main)
  
gtest_discover_tests(test_dynamicArray)