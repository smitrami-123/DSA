// TC : O(N*M) : Call for each state
// SC : O(N) : Only previous and current rows are stored additionally
class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> prev(m,INT_MAX),curr(m,INT_MAX);

        for(int j=0;j<m;j++)
        {
            prev[j] = matrix[0][j];
        }

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int ld = 1e9;
                int rd = 1e9;

                if(j-1>=0)ld = matrix[i][j] + prev[j-1];
                
                int up = matrix[i][j] + prev[j];
                
                if(j+1<m)rd = matrix[i][j] + prev[j+1];
                
                curr[j] = min(up,min(ld,rd));
            }

            prev = curr;
        }

        
        int mini = 1e9;
        for(int j=0;j<m;j++)
        {
            mini = min(mini,prev[j]);
        }

        return mini;
    }
};