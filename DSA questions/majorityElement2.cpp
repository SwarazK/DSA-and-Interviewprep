class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //We use two sets of counters for the two different majority elements and then we traverse to confirm
        long long int ele1 = 100000000000,ele2 = 100000000000, c1 = 0, c2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == ele1) c1++;
            else if(nums[i] == ele2) c2++;
            else if(c1 == 0){
                ele1 = nums[i];
                c1 = 1;
            }
            else if(c2 == 0){
                ele2 = nums[i];
                c2 = 1;
            }
            else{
                c1--;
                c2--;
            }
        }
        int count1 = 0, count2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == ele1) count1++;
            else if(nums[i] == ele2) count2++;
        }
        
        vector<int> ans;
        if(count1 > nums.size()/3) ans.push_back(ele1);
        if(count2 > nums.size()/3) ans.push_back(ele2);
        return ans;
    }
};