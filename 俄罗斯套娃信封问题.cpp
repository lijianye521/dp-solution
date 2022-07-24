#include<iostream>
#include<vector>
#include<algorithm>
//先把信封按照宽度进行升序排序，然后按照高度进行降序排序，
//问题变成了在新的排好序的数组里寻找最长上升子序列
using namespace std;
class Solution {
public:
 

 int maxEnvelopes_plus(vector<vector<int>>& envelopes)
    {sort(envelopes.begin(),envelopes.end(),[](const auto s1,const auto s2){
        if(s1[0]!=s2[0])
        return s1[0]<s2[0];
        else return s1[1]>s2[1];
    });
    int n=envelopes.size();
    
    for(int i=0;i<envelopes.size();i++)
    {
        for(int j=0;j<envelopes[i].size();j++)
        {
            
            cout<<envelopes[i][j]<<" ";
            
        }cout<<endl;
        
    }
    cout<<"---------------------------------------------------"<<endl;
    vector<int>dp = {envelopes[0][1]};;
    int answer=1;
    for(int i=1;i<n;++i)
    {
        cout<<"the"<<i<<endl;
    for(int i=0;i<dp.size();i++)
    {
        cout<<dp[i]<<" ";
    }
    cout<<endl;
        int nums=envelopes[i][1];
    if(nums>dp.back())
    {
        dp.push_back(nums);
    }
    else
    {
        auto it=lower_bound(dp.begin(),dp.end(),nums);
        /*
        lower_bound()返回值是一个迭代器,返回指向大于等于nums的第一个值的位置
        */
       cout<<"the location of the iteration is"<<*it<<endl;
       *it=nums;

    }
       
    }
    return dp.size();
    }


};
int main()
{
    int shuzu[9][2]={{5,4},{6,4},{6,7},{2,3},{3,1},{5,3},{6,5},{7,2},{8,2}};

    vector<vector<int>>envelopes(9,vector<int>(2,1));

    for(int i=0;i<envelopes.size();i++)
    {
        for(int j=0;j<envelopes[i].size();j++)
        {
            envelopes[i][j]=shuzu[i][j];
            cout<<envelopes[i][j]<<" ";
            
        }cout<<endl;
        
    }
        cout<<"---------------------------------------------------"<<endl;
Solution s;
cout<<s.maxEnvelopes_plus(envelopes)<<endl;


    system("pause");
    return 0;
}