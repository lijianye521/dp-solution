## [300. 最长递增子序列](https://leetcode.cn/problems/longest-increasing-subsequence/)

### 问题描述

难度中等2653收藏分享切换为英文接收动态反馈

给你一个整数数组 `nums` ，找到其中最长严格递增子序列的长度。

**子序列 **是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，`[3,6,2,7]` 是数组 `[0,3,1,6,2,2,7]` 的子序列。

**示例 1：**

```
输入：nums = [10,9,2,5,3,7,101,18]
输出：4
解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。

```

**示例 2：**

```
输入：nums = [0,1,0,3,2,3]
输出：4

```

**示例 3：**

```
输入：nums = [7,7,7,7,7,7,7]
输出：1

```

 

**提示：**

- `1 <= nums.length <= 2500`
- `-104 <= nums[i] <= 104`

 

**进阶：**

- 你能将算法的时间复杂度降低到 `O(n log(n))` 吗?

### 思路

我们使用dp[i]表示第i位数字前的最长上升子序列的长度;

i\<j ,dp[j]是在i之前的最长上升子序列  如果nums[i]\>nums[j]，那么很明显dp[i]=dp[j]+1

我们的任务是找出i之前所有的j，使得dp[i]是一个最大值   那么递推公式就出来了
$$
dp[i]=max(dp[j]+1)(j<i)
$$
那么事情变得简单了起来，再想想初始条件 dp[0]=1

两个for循环 一个遍历i 一个遍历j 时间复杂度O(n^2^)

### 代码演示

```c++
//最长上升子序列
#include<iostream>
//diercishiyan 
#include<vector>
using namespace std;
//xiugai
class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {int n=0;
    vector<int> dp(nums.size(),1);//创造一个长度为数组长度的dp数组；初值全部为1
    for(int i=0;i<nums.size();i++)
    {
        for(int j=0;j<i;j++)
        {if(nums[i]>nums[j])
        dp[i]=max(dp[i],dp[j]+1);
        } 
        if(n<dp[i])
         n=dp[i];
    }
   return n;
    }
};
int main()
{
vector<int>nums;
int shuzu[8]={10,9,2,5,3,7,101,18};
nums.insert(nums.begin(),shuzu,shuzu+8);//初始化数组
Solution s;
cout<<s.lengthOfLIS(nums);

    system("pause");
    return 0;
}
```

