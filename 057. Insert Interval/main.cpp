#include"solution.h"
int main()
{
	Solution sol;
	Interval a(1, 2), b(3, 5), c(6, 7), d(8, 10), e(12, 16);
	vector<Interval>intervals = { a,b,c,d,e };
	vector<Interval>res = sol.insert(intervals, Interval(4, 9));
	for (int i = 0; i < res.size(); i++) {
		cout << '[' << res[i].start << ',' << res[i].end << ']' << ',';
	}
	cout << "\b " << endl;
	return 0;
}
