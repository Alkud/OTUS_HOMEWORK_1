#CmakeList.txt for OTUS Homework #1
#Check CMake version
cmake_minimum_required(VERSION 3.2)

#Set project name, set PROJECT_VERSION_MINOR value equal to TRAVIS_BUILD NUMBER
project(helloworld VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

set (BOOST_MIN_VERSION "1.54.0")
#set (BOOST_LIBRARYDIR "/usr/lib/x86_64-linux-gnu")
#set (BOOST_INCLUDEDIR "/usr/include/boost")

#Find Boost UTF component, get BOOST_LIBRARIES and BOOST_INCLUDE_DIR values
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

#Process project_version_minor.h to set OTUS_HW_1_VERSION_MINOR value equal to PROJECT_VERSION_MINOR
configure_file(helper_functions.h.in helper_functions.h)

#Set executable target
add_executable(helloworld main.cpp)

#Set library target
add_library(helper_functions helper_functions.cpp)

#Set test target_link_libraries
add_executable(otus_hw_1_test otus_hw_1_test.cpp)

#Enable tests
enable_testing()
add_test(
NAME test_hw_1
COMMAND otus_hw_1_test)

#Set properties and compile options for executable target
set_target_properties(helloworld
  PROPERTIES CXX_STANDARD 14
             CXX_STANDARD_REQUIRED ON
             COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

#Set properties for test target
set_target_properties(otus_hw_1_test PROPERTIES
  COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
  INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

#Link
target_link_libraries(helloworld helper_functions)
target_link_libraries(otus_hw_1_test
  ${Boost_LIBRARIES}
  helper_functions
)

install(TARGETS helloworld RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT alexandr_kudinov@mail.ru)

include(CPack)
