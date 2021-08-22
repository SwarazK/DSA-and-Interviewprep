class Solution {
public:
    //Basic logic is that to iterate over the array and move 0 to first index without 0 and move 2 to last index without 2
    
    void sortColors(vector<int>& nums) {
        
        int lo = 0, hi = nums.size()-1, mid = lo;

        while(mid <= hi){
            if(nums[mid] == 0){ 
                nums[mid] = nums[lo];
                nums[lo] = 0;
                mid++;
                lo++;
            }
            else if(nums[mid] == 2){ 
                nums[mid] = nums[hi];
                nums[hi] = 2;
                hi--;
            }
            else mid++;
        }
    }
};