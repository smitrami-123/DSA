// TC : O(2^(N*N)) = Recursion with two choices at every decision
// SC : O(N) = Stack Space 
class Solution {
public:
    int fun(int i, int j, vector<vector<int>>& triangle)
    {
        int n = triangle.size();
        int m = triangle[n-1].size();
        if(i == n-1)
            return triangle[i][j];
        
        int down = triangle[i][j] + fun(i+1,j,triangle);
        int diag = triangle[i][j] + fun(i+1,j+1,triangle);

        return min(down,diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        return fun(0,0,triangle);
    }
};