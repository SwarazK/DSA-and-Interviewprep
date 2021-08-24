class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> row;
        unordered_set<int> column;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    row.insert(i);
                    column.insert(j);
                }
            }
        }
        for(int i = 0; i < matrix.size(); i++){
            if(row.find(i) != row.end()){
                for(int j = 0; j < matrix[0].size(); j++) matrix[i][j] = 0;
                row.erase(i);
            }
        }
        
        for(int j = 0; j < matrix[0].size(); j++){
            if(column.find(j) != column.end()){
                for(int i = 0; i < matrix.size(); i++) matrix[i][j] = 0;
                column.erase(j);
            }
        }
    }
};

//Theres a better version that uses the first row and column as the additional arrays
