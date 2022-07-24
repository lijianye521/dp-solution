//环形子数组的最大和
#include<iostream>
#include<vector>
/*会了最大子序和，这题也就明白了。
对于环形数组，分两种情况。
(1)答案在数组中间，就是最大子序和。例如[1,-2,3,-2]；
(2)答案在数组两边，例如[5,-3,5]最大的子序和就等于数组的总和SUM-最小的子序和。(一种特殊情况是数组全为负数，也就是SUM-最小子序和==0，最大子序和等于数组中最大的那个)。
*/
using namespace std;
class Solution 
{
public:
    int maxSubarraySumCircular(vector<int>& nums)
    {
    int n=nums.size();
    int maxelement=nums[0];
    int pre=nums[0];
    int pre2=nums[0];
    int minelement=nums[0];
    int sum=nums[0];
    int maxE=nums[0];//最大元素
        for(int i=1;i<n;i++)
        {pre=max(pre+nums[i],nums[i]);
        maxelement=max(maxelement,pre);
        pre2=min(pre2+nums[i],nums[i]);
        minelement=min(minelement,pre2);
        sum+=nums[i];
        if(maxE<nums[i])
        maxE=nums[i];//最大元素
        }
        int bijiao=sum-minelement;
        if(sum-minelement==0)
        {
            bijiao=maxE;
        }
    return max(maxelement,bijiao);
    }
    
};
int main()
{
vector<int>nums;
int shuzu[4]={9,-4,-7,9};
nums.insert(nums.begin(),shuzu,shuzu+4);//初始化数组
Solution s;
cout<<s.maxSubarraySumCircular(nums);

    system("pause");
    return 0;
}