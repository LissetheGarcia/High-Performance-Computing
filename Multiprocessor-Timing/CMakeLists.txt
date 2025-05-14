cmake_minimum_required(VERSION 3.30.2)
project(TimeIt)

# Enable CTest  functionality in CTest
enable_testing()

# Built-in routine to find all MPI packages
find_package(MPI)

# Add build targets with their source code files
add_executable(TimeIt TimeIt.c)
add_executable(MPITimeIt mpi_time_it.c)

# Include paths oh mpi c header (mpi.h) and MPI libraries
target_include_directories(MPITimeIt PUBLIC ${MPI_INCLUDE_PATH})
target_link_libraries(MPITimeIt ${MPI_LIBRARIES})

# This gets all files with the extension 'ctest' and adds it to the test list for CTest
# The ctest file needs to be executable or explicitly launched with the 'sh' command as below
file(GLOB TESTFILES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "*.ctest")

foreach(TESTFILE ${TESTFILES})
     add_test(NAME ${TESTFILE} WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
              COMMAND sh ${CMAKE_CURRENT_SOURCE_DIR}/${TESTFILE})
endforeach()

# A custom command, distclean, to remove files that are created
add_custom_target(distclean COMMAND rm -rf CMakeCache.txt CMakeFiles
                  CTestTestfile.cmake Makefile Testing cmake_install.cmake)
