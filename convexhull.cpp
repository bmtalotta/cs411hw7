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

	int datasize = data.size();
	for (int i = 0; i < datasize; i++) {
		if (data[i].first < data[leftmost].first) {
			leftmost = i;
		}
	}
	int position = leftmost;
	int q;
	do {
		hull.push_back(data[position]);
		q = (position + 1) % datasize;
		for (int i = 0; i < datasize; i++) {
			if (orientation(data[position], data[i], data[q]) == 2) {
				q = i;
			}
		}
		position = q;
	} while (position != leftmost);
	for (auto i : hull) {
		std::cout << '(' << i.first << ", " << i.second << ")\n";
	}
}

int orientation(std::pair<int, int> p, std::pair<int, int> q, std::pair<int, int> r)
{
	int val = (q.second - p.second) * (r.first - q.first) - (q.first - p.first) * (r.second - q.second);
	if (val == 0) {
		return 0;
	}
	else {
		return (val > 0) ? 1 : 2;
	}
}
