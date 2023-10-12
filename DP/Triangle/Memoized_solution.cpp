// TC : O(N*N) => For each possible state only one call will be made
// SC : O(N) + O(N*N) => Stack Space plus DP table space
class Solution {
public:
    int fun(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp)
    {
        if(i == triangle.size()-1)
            return triangle[i][j];

        if(dp[i][j] != -1) return dp[i][j];
        
        int down = triangle[i][j] + fun(i+1,j,triangle,dp);
        int diag = triangle[i][j] + fun(i+1,j+1,triangle,dp);

        return dp[i][j] = min(down,diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return fun(0,0,triangle,dp);
    }
};