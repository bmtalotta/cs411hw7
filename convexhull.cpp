//convexhull.cpp
// Ben Talotta
// For CS 411 Fall 2020 HW 7

#include "convexhull.hpp"
#include<iostream>
#include<vector>;
#include<utility>
using std::vector;
using std::pair;

void convexhull(std::vector<std::pair<int, int>> data)
{
	vector<pair<int, int>> hull;
	int leftmost = 0;
	int counterClockwise = 2;

	int datasize = data.size();
	for (int i = 0; i < datasize; i++) {
		if (data[i].first < data[leftmost].first) {
			leftmost = i;
		}
	}
	int position = leftmost;
	int q; //last visited counter clockwise pos
	do {
		
		hull.push_back(data[position]);
		q = (position + 1) % datasize;
		for (int i = 0; i < datasize; i++) {
			if (orientation(data[position], data[i], data[q])) {
				q = i;
			}
		}
		position = q;
	} while (position != leftmost);
	printData(hull);
}

bool orientation(std::pair<int, int> pos, std::pair<int, int> newPos, std::pair<int, int> curq)
{
	int val = (newPos.second - pos.second) * (curq.first - newPos.first) - (newPos.first - pos.first) * (curq.second - newPos.second);
	return val < 0;
}

void printData(std::vector<std::pair<int, int>> data)
{
	for (auto i : data) {
		std::cout << '(' << i.first << ", " << i.second << ")\n";
	}
}
