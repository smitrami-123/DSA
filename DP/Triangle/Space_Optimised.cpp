// TC : O(N*N) => Single Call for each state
// SC : O(N) => Only prev state row and curr state row is stored
class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        vector<int> prev(m,0),curr(m,0);
        for(int j=0;j<m;j++)
        {
            prev[j] = triangle[n-1][j];
        }

        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<=i;j++)
            {
                
                int down = triangle[i][j] + prev[j];
                int diag = triangle[i][j] + prev[j+1];
                curr[j] = min(down,diag);
            }

            prev = curr;
            
        }

        return prev[0];
    }
};