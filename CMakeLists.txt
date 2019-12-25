cmake_minimum_required(VERSION 3.15)
project(treeAndForestExp)

set(CMAKE_CXX_STANDARD 14)

add_executable(treeAndForestExp main.cpp createTree.h TreeForest.h ArrayQueue.h ArrayQueueImpl.c)