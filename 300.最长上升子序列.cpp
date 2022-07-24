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