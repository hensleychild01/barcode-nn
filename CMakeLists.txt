cmake_minimum_required(VERSION 4.0)

project(nnue)

set(EIGEN_DIR "C:\\Users\\hensl\\Desktop\\Coding\\cpp libraries\\eigen")

include_directories(${EIGEN_DIR})

add_executable(nnue
        src/main.cpp
        src/NeuralNetwork.cpp
        src/NeuralNetwork.h
)