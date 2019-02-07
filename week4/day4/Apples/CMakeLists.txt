cmake_minimum_required(VERSION 3.13)
project(Apples)

set(CMAKE_CXX_STANDARD 14)

include_directories(Apples_Lib)

add_executable(Apples
        Apples_Lib/apples.cpp
        Apples_Lib/apples.h
        Apples_Lib/CMakeLists.txt
        Apples_Tests/apples_test.cpp
        Apples_Tests/CMakeLists.txt
        cmake-build-debug/Apples_lib/cmake_install.cmake
        cmake-build-debug/Apples_lib/libApples_lib.a
        cmake-build-debug/Apples_lib/Makefile
        cmake-build-debug/Apples_Tests/googletest/googlemock/gtest/generated/gmock.pc
        cmake-build-debug/Apples_Tests/googletest/googlemock/gtest/generated/gmock_main.pc
        cmake-build-debug/Apples_Tests/googletest/googlemock/gtest/generated/gtest.pc
        cmake-build-debug/Apples_Tests/googletest/googlemock/gtest/generated/gtest_main.pc
        cmake-build-debug/Apples_Tests/googletest/googlemock/gtest/generated/GTestConfig.cmake
        cmake-build-debug/Apples_Tests/googletest/googlemock/gtest/generated/GTestConfigVersion.cmake
        cmake-build-debug/Apples_Tests/googletest/googlemock/gtest/cmake_install.cmake
        cmake-build-debug/Apples_Tests/googletest/googlemock/gtest/CTestTestfile.cmake
        cmake-build-debug/Apples_Tests/googletest/googlemock/gtest/gtest.cbp
        cmake-build-debug/Apples_Tests/googletest/googlemock/gtest/Makefile
        cmake-build-debug/Apples_Tests/googletest/googlemock/cmake_install.cmake
        cmake-build-debug/Apples_Tests/googletest/googlemock/CTestTestfile.cmake
        cmake-build-debug/Apples_Tests/googletest/googlemock/gmock.cbp
        cmake-build-debug/Apples_Tests/googletest/googlemock/Makefile
        cmake-build-debug/Apples_Tests/googletest/cmake_install.cmake
        cmake-build-debug/Apples_Tests/googletest/CTestTestfile.cmake
        cmake-build-debug/Apples_Tests/googletest/googletest-distribution.cbp
        cmake-build-debug/Apples_Tests/googletest/Makefile
        cmake-build-debug/Apples_Tests/Apples_Tests
        cmake-build-debug/Apples_Tests/cmake_install.cmake
        cmake-build-debug/Apples_Tests/Makefile
        cmake-build-debug/lib/libgtest_maind.a
        cmake-build-debug/lib/libgtestd.a
        cmake-build-debug/Apples.cbp
        cmake-build-debug/cmake_install.cmake
        cmake-build-debug/CMakeCache.txt
        cmake-build-debug/Makefile
        cmake-build-debug/MyApp
        cmake-build-debug/MyApp.cbp
        CMakeLists.txt
        main.cpp)
