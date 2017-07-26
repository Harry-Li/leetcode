#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval>res;
		auto iter = intervals.begin();
		while (iter != intervals.end() && newInterval.start>iter->end) {
			res.push_back(*iter++);
		}
		while (iter != intervals.end() && newInterval.end >= iter->start) {
			newInterval.start = min(iter->start, newInterval.start);
			newInterval.end = max(newInterval.end, iter->end);
			iter++;
		}
		res.push_back(newInterval);
		while (iter != intervals.end()) res.push_back(*iter++);
		return res;
	}
};
