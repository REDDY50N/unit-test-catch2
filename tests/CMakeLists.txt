add_executable(Test_G36 G36_Test.cpp)
target_link_libraries(Test_G36 PRIVATE WeaponsLib Catch2::Catch2WithMain)
add_test(NAME G36_Tests COMMAND Test_G36)

add_executable(Test_SCAR5 SCAR5_Test.cpp)
target_link_libraries(Test_SCAR5 PRIVATE WeaponsLib Catch2::Catch2WithMain)
add_test(NAME G36_SCAR COMMAND Test_SCAR5)