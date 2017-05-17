## 1.Two Sum
https://leetcode.com/problems/two-sum/#/description
### 题目要求：
在数组中找出两个数，使这两个数的和为一个给定值target。
### 我的思路：
直接用嵌套for循环遍历数组，判断两个数的和是否为target。
### Submission Details：
https://leetcode.com/submissions/detail/102633130/<br>
Runtime: 206 ms<br>
Your runtime beats 11.76 % of cpp submissions.
### 推荐思路与解法：
用unordered_map来存储数组中的数，实现O(n)的时间复杂度。
```cpp
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
			result.push_back(hash[numberToFind] + 1);
			result.push_back(i + 1);			
			return result;
		}

            //number was not found. Put it in the map.
		hash[numbers[i]] = i;
	}
	return result;
}
```
Neater:
```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> imap;
    
    for (int i = 0;; ++i) {
        auto it = imap.find(target - nums[i]);
        //注意map的find函数的使用
        if (it != imap.end()) 
            return vector<int> {i, it->second};
            
        imap[nums[i]] = i;
    }
}
```
