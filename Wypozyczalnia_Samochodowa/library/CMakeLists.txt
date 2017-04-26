cmake_minimum_required(VERSION 3.4)
project(Library)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
	 src/Klasa_Aplikacji.cpp
	 src/Klient.cpp
	 src/Lista_Klientow.cpp
	 src/Klient_Domyslny.cpp
	 src/Klient_Typu_A.cpp
	 src/Klient_Typu_B.cpp
	 src/Pojazdy.cpp
	 src/Lista_Pojazdow.cpp
	 src/Rower.cpp
	 src/Pojazdy_Silnikowe.cpp
	 src/Motorower.cpp
	 src/Samochod.cpp
	 src/Wypozyczenie.cpp
	 src/Wyjatek_Ujemna)


add_library(Library ${SOURCE_FILES})

#add 'include' directory with header files from 'Library' project to paths
target_include_directories(Library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

#testy
find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_KLIENT_FILES
        test/master.cpp
        test/KlientTest.cpp)

add_executable (TestKlient ${SOURCE_TEST_KLIENT_FILES})

target_link_libraries (TestKlient
        Library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

#test pojazdow
set(SOURCE_TEST_POJAZD_FILES
	test/master.cpp
        test/PojazdTest.cpp)

add_executable (TestPojazd ${SOURCE_TEST_POJAZD_FILES})

target_link_libraries (TestPojazd
        Library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

#test wypozyczen
set(SOURCE_TEST_WYPOZYCZENIE_FILES
	test/master.cpp
        test/WypozyczenieTest.cpp)

add_executable (TestWypozyczenie ${SOURCE_TEST_WYPOZYCZENIE_FILES})

target_link_libraries (TestWypozyczenie
        Library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

enable_testing()

add_test(TestKlienta TestKlient
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )
add_test(TestPojazdu TestPojazd
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )
add_test(TestWypozyczenia TestWypozyczenie
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )


add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
