# CMake generated Testfile for 
# Source directory: /home/lissethe/github/High-Performance-Computing/Multiprocessor-Timing
# Build directory: /home/lissethe/github/High-Performance-Computing/Multiprocessor-Timing/timerBuild
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[my_mpi_app.ctest]=] "sh" "/home/lissethe/github/High-Performance-Computing/Multiprocessor-Timing/my_mpi_app.ctest")
set_tests_properties([=[my_mpi_app.ctest]=] PROPERTIES  WORKING_DIRECTORY "/home/lissethe/github/High-Performance-Computing/Multiprocessor-Timing/timerBuild" _BACKTRACE_TRIPLES "/home/lissethe/github/High-Performance-Computing/Multiprocessor-Timing/CMakeLists.txt;27;add_test;/home/lissethe/github/High-Performance-Computing/Multiprocessor-Timing/CMakeLists.txt;0;")
