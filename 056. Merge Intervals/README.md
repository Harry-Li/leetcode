## [056. Merge Intervals](https://leetcode.com/problems/merge-intervals/#/description)
### 题目要求：
Given a collection of intervals, merge all overlapping intervals.

For example,<br>
Given [1,3],[2,6],[8,10],[15,18],<br>
return [1,6],[8,10],[15,18].
### 解法：
先根据start排序，遍历intervals，比较start与temp.end，更新temp，注意最后不要遗漏temp
```c
	bool cmp(const Interval &a, const Interval &b) {
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
```
