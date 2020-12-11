//convexhull.hpp
// Ben Talotta
// For CS 411 Fall 2020 HW 7

#ifndef FILE_CONVEXHULL_H_INCLUDED
#define FILE_CONVEXHULL_H_INCLUDED
#include<iostream>
#include<vector>;
#include<utility>

void convexhull(std::vector<std::pair<int, int>> data);
int orientation(std::pair<int, int> p, std::pair<int, int> q, std::pair<int, int> r);

#endif //#ifndef FILE_CONVEXHULL_H_INCLUDED

