class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        //First find the pivot point using binary search
        int low = 0, high = nums.size() - 1, mid = (high+low)/2;
        
        //If nums[mid] > nums[low] search in right and vice versa
        int pivot; //Variable to store the pivot
        
        while(low < high - 1){ //When the search converges low  == high - 1 and low will be the pivot point
            if(nums[mid]>nums[low]) low = mid;
            else high = mid - 1;
            mid = (high+low)/2;
        }
        
        if(nums[high] > nums[low]) low = high; //Edge case similar to the one for the pivoted binary search
        pivot = low + 1;
        
        //Have separately handled the edge case of two sized array
        if(nums.size() == 2){
            if(nums[1] > nums[0]) pivot = 2;
            else pivot = 1;
        }
        
        //Now to run a pivoted version of binary search
        
        low = 0;
        high = nums.size()-1;
        mid = (high+low)/2;
        
        // cout<<pivot;
        
        int ans = -1;
        
        // cout<<(nums[(mid + pivot)%nums.size()] == target);
        
        while(low <= high){ //Consider the case of a single element array containing target
            if(nums[(mid + pivot)%nums.size()] == target){ //The actual mid is compared after considering the pivot
                ans = (mid + pivot)%nums.size();
                break;
            }
            else if(nums[(mid + pivot)%nums.size()] > target) high = mid - 1;
            else low = mid + 1;
            mid = (high+low)/2;
        }
        //2 sized array is an edge case, in any other size the final low and high will be from mid but no in 2
        //Or in any config where one of the ends doesnt move and contains the target
        if(nums[(low + pivot)%nums.size()] == target) ans = (low + pivot)%nums.size();
        return ans;
        
    }
};