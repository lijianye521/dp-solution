# [面试题 17.24. 最大子矩阵](https://leetcode.cn/problems/max-submatrix-lcci/)

## 问题描述

难度困难154收藏分享切换为英文接收动态反馈

给定一个正整数、负整数和 0 组成的 N × M 矩阵，编写代码找出元素总和最大的子矩阵。

返回一个数组 `[r1, c1, r2, c2]`，其中 `r1`, `c1` 分别代表子矩阵左上角的行号和列号，`r2`, `c2` 分别代表右下角的行号和列号。若有多个满足条件的子矩阵，返回任意一个均可。

**注意：**本题相对书上原题稍作改动

**示例：**

```
输入：
[
   [-1,0],
   [0,-1]
]
输出：[0,1,0,1]
解释：输入中标粗的元素即为输出所表示的矩阵
```

 

**说明：**

- `1 <= matrix.length, matrix[0].length <= 200`

## 思路

我们之前解决过一维数组的最大和问题，回顾一下就是规定长度为i的数组的最大和为dp[i]。则有
$$
dp[i]=nums[i](dp[i-1]<0)
$$

$$
dp[i]=nums[i]+dp[i-1](dp[i-1]>=0)
$$

显然这个题目是一个二维问题，那么我们就把它压缩成一维，然后再用上面的求解一维的方法，我们规定i是压缩的二维数组的起始行，j是压缩二维数组的结束行，那么那么我们需要遍历i和j；

得到一个一维数组，然后寻找最大子序列的和，并记录这个最大子序列和的起始位置和结束位置，然后算出的最大值再去和一个全局最大值比较，如果超过他那么更新r1,r2,c1,c2

## 代码演示：

```c++
class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) 
    {int r1=0,C1=0,r2=0,C2=0;
    int n=matrix.size();
    int column=matrix[0].size();
    //将从第i行到第j行的矩阵压缩到一维
    int sum=matrix[0][0];

    for(int i=0;i<n;i++)//这里的i为起始行
    {  vector<int> line(column,0);
        for(int j=i;j<n;j++)//这里的j为结束行
        {//清空线性数组
         
               
           int he=matrix[0][0];
           int c1=0;//暂存列起始位置
           int c2=0;//暂存列结束位置
           int sum2=matrix[0][0];
            vector<int>dp(column,0);
                int cc1=0;
                vector<int>dp_xiabiao(column,0);
           for(int k=0;k<column;k++)
            {  

                    line[k]+=matrix[j][k];
                 
              
             int temp=he+line[k];
                 if(temp>=line[k])
                 { he=he+line[k];
                    dp[k]=he;
                    dp_xiabiao[k]=cc1;
                 }
                 else
                 {
                    cc1=k;
                  //  cout<<"cc1 is" <<cc1<<endl;
                    dp[k]=line[k];
                    he=line[k];
                    dp_xiabiao[k]=cc1;
                 }
             }   

                  for(int s=0;s<column;s++)
                  {//cout<<dp_xiabiao[s]<<" "<<"dp is"<<dp[s]<<" ";
                    if(dp[s]>sum2)
                    {
                        c1=dp_xiabiao[s];
                        c2=s;
                        sum2=dp[s];
                    }
                  }
                 // cout<<endl;
   
                 if(sum2>sum)
                 {//压缩后的数组的值大于了sum值那么就进行四个值的更新
                      sum=sum2;
                      r1=i;
                      r2=j;
                      C1=c1;
                      C2=c2;
                 }
                 
        }
    }
vector<int>answer;
answer.push_back(r1);
answer.push_back(C1);
answer.push_back(r2);
answer.push_back(C2);
return answer;

    }
};
```

