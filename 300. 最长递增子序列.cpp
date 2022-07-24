//乘积最大子组数
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
int Maxelement=nums[0];
vector<int>dpMax(nums.size());
vector<int>dpMin(nums.size());
dpMax[0]=nums[0];
dpMin[0]=nums[0];
for(int i=1;i<nums.size();++i)
{
    dpMax[i]=max(nums[i],max(nums[i]*dpMax[i-1],nums[i]*dpMin[i-1]));
    dpMin[i]=min(nums[i],min(dpMax[i-1]*nums[i],dpMin[i-1]*nums[i]));
     Maxelement=max(Maxelement,dpMax[i]);
     
}
return Maxelement;

}

};
int main()
{
vector<int>nums;
int shuzu[3]={-2,3,-4};
nums.insert(nums.begin(),shuzu,shuzu+4);//初始化数组
Solution s;
cout<<s.maxProduct(nums)<<endl;

    system("pause");
    return 0;
}