class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp (105, vector<int> (105,0-1));
        return search(m,n,dp);
    }
    int search(int m, int n, vector<vector<int>>& dp){
        if(m == 1 && n == 1) return 1;
        else if (dp[m][n]!=-1) return dp[m][n];
        else{
            int ans = 0;
            if(m > 1) ans += search(m-1,n,dp);
            if(n > 1) ans += search(m,n-1,dp);
            dp[m][n] = ans;
            dp[n][m] = ans;
            return ans;
        }
    }
};