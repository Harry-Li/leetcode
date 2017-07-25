#include"solution.h"
int main()
{
	Solution sol;
	Interval a(1, 3);
	Interval b(2, 6);
	Interval c(15, 18);
	Interval d(8, 10);
	vector<Interval>intervals = { a,b,c,d };
	vector<Interval>res = sol.merge(intervals);
	for (int i = 0; i < res.size(); i++) {
		cout << '[' << res[i].start << ',' << res[i].end << ']' << ',';
	}
	cout << "\b " << endl;
}
