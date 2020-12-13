//convexhull.hpp
// Ben Talotta
// For CS 411 Fall 2020 HW 7

#ifndef FILE_CONVEXHULL_H_INCLUDED
#define FILE_CONVEXHULL_H_INCLUDED
#include<iostream>
#include<vector>
#include<utility>

std::vector<std::pair<int, int>> convexHull(std::vector<std::pair<int, int>> &data);
std::vector<std::pair<int, int>> bruteconvexhull(std::vector<std::pair<int, int>> &data);
std::vector<std::pair<int, int>> merge(std::vector<std::pair<int, int>> &leftHull, std::vector<std::pair<int, int>> &rightHull);
int orientation(std::pair<int, int> pos, std::pair<int, int> newPos, std::pair<int, int> curq);
void printData(std::vector<std::pair<int, int>> data);

#endif //#ifndef FILE_CONVEXHULL_H_INCLUDED

