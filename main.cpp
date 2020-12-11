//main.cpp
//Ben Talotta
//for use with cs411 hw 7 convex hull

#include<iostream>
#include<cstdlib>
using std::rand;
#include<vector>;
using std::vector;
#include<utility>
using std::pair;
#include "convexhull.hpp"

int main() {
	vector<pair<int, int>> dataset;
	for (int i = 1; i < 10; ++i) {
		dataset.push_back({ rand() % 20,rand() % 20 });	//used rand() because it doesnt matter if the data is truely random, i just needed to fill the points
	}
	for (auto i : dataset) {
		std::cout << '(' << i.first << ", " << i.second << ")\n";
	}
	std::cout << "\n\n";
	convexhull(dataset);
	return 0;
}
