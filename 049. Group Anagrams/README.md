## [049. Group Anagrams](https://leetcode.com/problems/group-anagrams/#/description)
### 题目要求：
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], <br>
Return:

[<br>
	["ate", "eat","tea"],<br>
	["nat","tan"],<br>
	["bat"]<br>
]
### 我的解法：
```c
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>>res;
		unordered_map<string, int>group;
		int count = 0;
		for (int i = 0; i<strs.size(); i++) {
			string temp = strs[i];
			sort(temp.begin(), temp.end());
			auto it = group.find(temp);
			if (it != group.end()) {
				res[it->second].push_back(strs[i]);
			}
			else {
				group[temp] = count;
				res.push_back({strs[i]});
				++count;
			}
		}
		return res;
	}
```
### 解法二：
```c
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string,vector<string>>m;
		for (int i = 0; i<strs.size(); i++) {
			string temp = strs[i];
			sort(temp.begin(), temp.end());
			m[temp].push_back(strs[i]);
		}
		vector<vector<string>>res;
		for (auto &e : m) {
			res.push_back(e.second);
		}
		return res;
	}
```
### 解法三：
General sort takes O(nlogn) time. In this problem, since the string only contains lower-case alphabets, we can write a sorting function using counting sort (O(n) time) to speed up the sorting process.
```c
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, multiset<string>> mp;
        for (string s : strs) {
            string t = strSort(s);
            mp[t].insert(s);
        }
        vector<vector<string>> anagrams;
        for (auto m : mp) { 
            vector<string> anagram(m.second.begin(), m.second.end());
            anagrams.push_back(anagram);
        }
        return anagrams;
    }
    string strSort(string& s) {
        int count[26] = {0}, n = s.length();
        for (int i = 0; i < n; i++)
            count[s[i] - 'a']++;
        int p = 0;
        string t(n, 'a');
        for (int j = 0; j < 26; j++)
            for (int i = 0; i < count[j]; i++)
                t[p++] += j;
        return t;
    } 
```
