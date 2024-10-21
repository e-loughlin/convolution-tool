# Find Google Test
find_package(GTest REQUIRED)


add_executable(Test_ImageData Test_ImageData.cpp)

target_link_libraries(Test_ImageData gtest gtest_main)

add_test(NAME Test_ImageData COMMAND Test_ImageData)



add_executable(Test_Kernel Test_Kernel.cpp)  

target_link_libraries(Test_Kernel gtest gtest_main)

add_test(NAME Test_Kernel COMMAND Test_Kernel)
