
// TC : O(N*M) : Single call for each state so there are n*m states
// SC : O(N) + O(N*M) : Recursion Stack plus DP Table
class Solution {
public:
    int fun(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        if(j<0||j>matrix[0].size()-1)
            return 1e9;
        
        if(dp[i][j] != 1e9)
            return dp[i][j];

        if(i==0)
            return dp[i][j]=matrix[i][j];
    
        int ld = matrix[i][j] + fun(i-1,j-1,matrix,dp);
        int up = matrix[i][j] + fun(i-1,j,matrix,dp);
        int rd = matrix[i][j] + fun(i-1,j+1,matrix,dp);

        return dp[i][j] = min(up,min(ld,rd));

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,1e9));
        int mini = 1e9;
        for(int j=0;j<m;j++)
        {
            mini = min(mini,fun(n-1,j,matrix,dp));
        }

        return mini;
    }
};
