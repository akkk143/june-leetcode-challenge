class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)
        {
            return nums;
        }
        vector<vector<int>> dp(n,vector<int>());
        sort(nums.begin(),nums.end());
        int largestsubsetind=0;
        int largestlen=1;
        for(int i=n-1;i>=0;i--)
        {
           int maxind=i;
           int maxlen=0;
           dp[i].push_back(nums[i]);
           for(int j=i+1;j<n;j++)
            {
                if(nums[j]%nums[i]==0 && dp[j].size()>maxlen)
                {
                    maxind=j;
                    maxlen=dp[j].size();
                }
            }
            if(maxind !=i)
            {
                dp[i].insert(dp[i].end(),dp[maxind].begin(),dp[maxind].end());
                if(largestlen < maxlen+1)
                {
                    largestlen = maxlen+1;
                    largestsubsetind=i;
                    
                }
            }
        }
       
        return dp[largestsubsetind];
    }
};



// Time Complexity -- O(n^2)
// Space Complexity -- O(n^2)