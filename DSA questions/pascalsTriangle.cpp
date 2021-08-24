class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        int i = 1;
        
        while(i <= numRows){
            vector<int> temp;
            temp.push_back(1);
            int j = 1;
            while( j < i){
                if(j == i-1) temp.push_back(1);
                else temp.push_back(ans[i-2][j-1]+ans[i-2][j]);
                j++;
            }
            ans.push_back(temp);
            i++;
        }
        
        return ans;
    }
};