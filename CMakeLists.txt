
cmake_minimum_required (VERSION 3.8)

project ("My_Graph")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_executable (My_Graph "ListGraph.cpp" "ListGraph.h" "Interface.h" "MatrixGraph.cpp" "MatrixGraph.h" "main.cpp")

