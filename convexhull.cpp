//convexhull.cpp
// Ben Talotta
// For CS 411 Fall 2020 HW 7

#include "convexhull.hpp"
#include<iostream>
using std::cout;
using std::endl;
#include<vector>
#include<utility>
using std::vector;
using std::pair;
#include<algorithm>

std::vector<std::pair<int, int>> convexHull(std::vector<std::pair<int, int>> &data)
{
	if (data.size() <= 5) {
		return bruteconvexhull(data);
	}
	std::vector<std::pair<int, int>> left;
	std::vector<std::pair<int, int>> right;
	for (int i = 0; i < data.size(); i++) {
		//cout << "starter for loop" << endl;
		if (i < data.size() / 2) {
			left.push_back(data[i]);
		}
		else {
			right.push_back(data[i]);
		}
	}
	std::vector<std::pair<int, int>> leftHull = convexHull(left);
	std::vector<std::pair<int, int>> rightHull = convexHull(right);
	return merge(leftHull,rightHull);
}

std::vector<std::pair<int, int>> bruteconvexhull(std::vector<std::pair<int, int>> &data)
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
			if (orientation(data[position], data[i], data[q]) < 0) {
				q = i;
			}
		}
		position = q;
	} while (position != leftmost);
	return hull;
}

std::vector<std::pair<int, int>> merge(std::vector<std::pair<int, int>> &leftHull, std::vector<std::pair<int, int>> &rightHull)
{

	int rightmostLeftHull = 0;
	int leftmostRightHull = 0;
	
	for (int i = 0; i < leftHull.size(); i++) {
		if (leftHull[i].first > leftHull[rightmostLeftHull].first) {
			rightmostLeftHull = i;
		}
	}
	for (auto i = 0; i < rightHull.size(); i++) {
		if (rightHull[i].first < rightHull[leftmostRightHull].first) {
			leftmostRightHull = i;
		}
	}


	bool done = 0;
	int curLeftHullVal = rightmostLeftHull;
	int curRightHullVal = leftmostRightHull;
	while (!done) {
		done = 1;
		while (orientation(rightHull[curRightHullVal], leftHull[curLeftHullVal], leftHull[(curLeftHullVal + 1) % leftHull.size()])>=0) {
			curLeftHullVal = (curLeftHullVal + 1) % leftHull.size();
		}

		while (orientation(leftHull[curLeftHullVal], rightHull[curRightHullVal], rightHull[((rightHull.size() + curRightHullVal - 1) % rightHull.size())])<=0) {
			curRightHullVal = (rightHull.size() + curRightHullVal - 1) % rightHull.size();
			done = 0;
		}
	}

	int upperLeft = curLeftHullVal;
	int upperRight = curRightHullVal;
	curLeftHullVal = rightmostLeftHull;
	curRightHullVal = leftmostRightHull;
	done = 0;
	while (!done) {
		done = 1;
		while (orientation(leftHull[curLeftHullVal], rightHull[curRightHullVal], rightHull[((curRightHullVal + 1) % rightHull.size())])>=0) {
			curRightHullVal = (curRightHullVal + 1) % rightHull.size();
		}
		while (orientation(rightHull[curRightHullVal], leftHull[curLeftHullVal], leftHull[(leftHull.size() + curLeftHullVal - 1) % leftHull.size()])<=0) {
			curLeftHullVal = (leftHull.size() + curLeftHullVal - 1) % leftHull.size();
			done = 0;
		}
	}
	int lowerLeft = curLeftHullVal;
	int lowerRight = curRightHullVal;

	vector<pair<int, int>>mergedHull;
	int pos = upperLeft;
	mergedHull.push_back(leftHull[pos]);
	while (pos != lowerLeft) {
		pos = (pos + 1) % leftHull.size();
		mergedHull.push_back(leftHull[pos]);
	}
	pos = lowerRight;
	mergedHull.push_back(rightHull[pos]);
	while (pos != upperRight) {
		pos = (pos + 1) % rightHull.size();
		mergedHull.push_back(rightHull[pos]);
	}
	return mergedHull;
}

int orientation(std::pair<int, int> pos, std::pair<int, int> newPos, std::pair<int, int> curq)
{
	int val = (newPos.second - pos.second) * (curq.first - newPos.first) - (newPos.first - pos.first) * (curq.second - newPos.second);

	return val;
}

void printData(std::vector<std::pair<int, int>> data)
{
	for (auto i : data) {
		std::cout << '(' << i.first << ", " << i.second << ")\n";
	}
}
