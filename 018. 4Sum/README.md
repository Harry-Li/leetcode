## [018. 4Sum](https://leetcode.com/problems/4sum/#/description)
对比[3Sum](https://github.com/Harry-Li/leetcode/tree/master/013.%20Roman%20to%20Integer)
### 题目要求：
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
### 我的思路：
```c
		vector<vector<int>> fourSum(vector<int>& nums, int target) {
			vector<vector<int>>ret;
			if (nums.size()<4) return ret;
			sort(nums.begin(), nums.end());
			for (int i = 0; i<nums.size() - 3; i++) {
				for (int j = i + 1; j<nums.size() - 2; j++) {
					int k = j + 1, m = nums.size() - 1;
					while (k<m) {
						int sum = nums[i] + nums[j] + nums[k] + nums[m];
						if (sum<target) ++k;
						else if (sum>target) --m;
						else {
							ret.push_back(vector<int>{nums[i], nums[j], nums[k], nums[m]});
							while (k<m&&nums[k] == nums[k + 1]) ++k;
							while (k<m&&nums[m] == nums[m - 1]) --m;
							++k; --m;
						}
					}
					while (j<nums.size() - 2 && nums[j] == nums[j + 1]) ++j;
				}
				while (i<nums.size() - 3 && nums[i] == nums[i + 1]) ++i;
			}
			return ret;
		}

```
### 推荐思路与解法：
下面的解法跳过了不必要的情况
```c
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> total;
        int n = nums.size();
        if(n<4)  return total;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++)
        {
            if(i>0&&nums[i]==nums[i-1]) continue;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;
            for(int j=i+1;j<n-2;j++)
            {
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;
                int left=j+1,right=n-1;
                while(left<right){
                    int sum=nums[left]+nums[right]+nums[i]+nums[j];
                    if(sum<target) left++;
                    else if(sum>target) right--;
                    else{
                        total.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        do{left++;}while(nums[left]==nums[left-1]&&left<right);
                        do{right--;}while(nums[right]==nums[right+1]&&left<right);
                    }
                }
            }
        }
        return total;
    }
```
