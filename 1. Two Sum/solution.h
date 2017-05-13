#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
vector<int> twoSum(vector<int> &numbers, int target)
{
    //Key is the number and value is its index in the vector.
	unordered_map<int, int> hash;
	vector<int> result;
	for (int i = 0; i < numbers.size(); i++) {
		int numberToFind = target - numbers[i];

            //if numberToFind is found in map, return them
		if (hash.find(numberToFind) != hash.end()) {
                    //+1 because indices are NOT zero based
                    //感觉不应该加1啊 by Harry
			result.push_back(hash[numberToFind]);
			result.push_back(i);			
			return result;
		}

            //number was not found. Put it in the map.
		hash[numbers[i]] = i;
	}
	return result;
}
}
/*
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int i, j;
		vector<int> vec;
		for (i = 0; i < nums.size(); i++)
			for (j = i + 1; j < nums.size(); j++)
				if (nums[i] + nums[j] == target) {
					vec.push_back(i);
					vec.push_back(j);
					return vec;
				}
		return vec;
	}
};
*/
