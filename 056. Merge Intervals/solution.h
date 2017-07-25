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
	static bool cmp(const Interval &a, const Interval &b) {
		return a.start < b.start;
	}
	vector<Interval> merge(vector<Interval>& intervals) {
		sort(intervals.begin(), intervals.end(), cmp);
		vector<Interval>res;
		Interval temp = intervals[0];
		for (int i = 1; i<intervals.size(); i++) {
			if (temp.end < intervals[i].start) {
				res.push_back(temp);
				temp = intervals[i];
			}
			else {
				temp.end = max(temp.end, intervals[i].end);	
			}
		}
		res.push_back(temp);
		return res;
	}
};
