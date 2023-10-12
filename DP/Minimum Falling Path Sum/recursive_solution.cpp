// TC : O(3^(N*M)) => Three decisions at every step can be made
// SC : O(N) => Additional space is of recursion stack only
class Solution {
public:
    int fun(int i, int j, vector<vector<int>> &matrix)
    {
        if(j<0||j>matrix[0].size()-1)
            return 1e9;
        
        if(i==0)
            return matrix[i][j];
    
        int ld = matrix[i][j] + fun(i-1,j-1,matrix);
        int up = matrix[i][j] + fun(i-1,j,matrix);
        int rd = matrix[i][j] + fun(i-1,j+1,matrix);

        return min(up,min(ld,rd));

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int mini = 1e9;
        for(int j=0;j<m;j++)
        {
            mini = min(mini,fun(n-1,j,matrix));
        }

        return mini;
    }
};