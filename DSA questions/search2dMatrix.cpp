class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        vector<int> temp;
        
        for(int i = 0; i < matrix.size(); i++) temp.push_back(matrix[i][0]);
        auto a = lower_bound(temp.begin(), temp.end(), target);
        
        int row;
        //The case the below if statement doesnt handle is when the target is in the last row
        //if(a == temp.end()) return false;
        if(a == temp.end()){
            //Search the last row to ensure the element is not found
            auto b = lower_bound(matrix[matrix.size()-1].begin(),matrix[matrix.size()-1].end(),target);
            if(b == matrix[matrix.size()-1].end()) return false;
            else if(*b == target) return true;
            else return false;
        }
        else if(*a == target) return true;
        else{
            row = (a - temp.begin()) - 1;
        }
        
        if(row < 0) return false;
        
        a = lower_bound(matrix[row].begin(), matrix[row].end(), target);
        if(a == matrix[row].end()) return false;
        else if(*a == target) return true;
        else return false;
    }
};

//A better version that doesnt require additional space ans use virtual indices exists 