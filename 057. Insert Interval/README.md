## [057. Insert Interval](https://leetcode.com/problems/insert-interval/#/description)
### 题目要求：
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:<br>
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:<br>
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
### 我的解法：
分几种情况讨论，过程有点复杂。这题新建一个vector比直接在intervals上面插入删除耗时更短。。
```c
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval>res;
		if (intervals.empty()) {
			res.push_back(newInterval);
		}
		else if (newInterval.end<intervals.begin()->start) {
			res.push_back(newInterval);
			res.insert(res.end(), intervals.begin(), intervals.end());
		}
		else if (newInterval.start>(intervals.end() - 1)->end) {
			res = intervals;
			res.push_back(newInterval);
		}
		else {
			auto iter1 = intervals.begin();
			for (; iter1<intervals.end(); iter1++) {
				if (newInterval.start>iter1->end) res.push_back(*iter1);
				else break;
			}
			auto iter2 = iter1;
			for (; iter2<intervals.end(); iter2++) {
				if (newInterval.end<iter2->start) break;
			}
			res.push_back(Interval(min(newInterval.start, iter1->start), max(newInterval.end, (iter2 - 1)->end)));
			res.insert(res.end(), iter2, intervals.end());
		}
		return res;
	}
```
### 推荐解法：
避免了分情况讨论，第二个while循环中更新了newInterval
```c
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
```
