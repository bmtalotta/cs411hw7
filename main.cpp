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
#include<algorithm>
#include<chrono>
#include "convexhull.hpp"


bool uniq_pair(const pair<int,int> & p1, const pair<int,int> &p2) {
	return ((p1.first==p2.first) && (p1.second==p2.second));
}

int main() {
	int dataSize = 10;
	std::cout << "Enter Size Of Data(defaults to 10): ";
	std::cin >> dataSize;
	vector<pair<int, int>> dataset;
	std::cout << "creating data\n";
	for (int i = 1; i < dataSize; ++i) {
		dataset.push_back({ rand() % 40,rand() % 40 });	//used rand() because it doesnt matter if the data is truely random, i just needed to fill the points
	}
	
	std::sort(dataset.begin(),dataset.end());
	vector<pair<int,int>>::iterator it = std::unique(dataset.begin(), dataset.end(), uniq_pair);
	dataset.resize(std::distance(dataset.begin(),it));
	if (dataSize < 15) {
		std::cout << "all points after making unique:\n";
		printData(dataset);
	}
	std::cout << "\n\nconvex hull points:\n";
	auto start = std::chrono::high_resolution_clock::now();
	vector<pair<int, int>> hull = convexHull(dataset);
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	printData(hull);
	std::cout << "Time to run: " << duration.count() << " microseconds" << std::endl;
	std::cout << "brute force same data\n";
	start = std::chrono::high_resolution_clock::now();
	printData(bruteconvexhull(dataset));
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "Time to run: " << duration.count() << " microseconds"<< std::endl;
	return 0;
}
