class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int r = nums.size()-1;
        bool found = false;
        while(r>0){
            if(nums[r-1]<nums[r]){
                found = true;
                r--;
                int l = r+1;
                while(l<nums.size()-1&&nums[l+1]>nums[r]) l++; //The part where I made a mistake, carefully think about the iterations
                int temp = nums[l];
                nums[l] = nums[r];
                nums[r] = temp;
                cout<<r<<endl<<nums[0];
                sort(nums.begin() + r + 1, nums.end());
                break;
            }
            else r--;
        }
        if(!found) sort(nums.begin(),nums.end());
    }
};

//Better version that is faster due to no sorting

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int r = nums.size()-1;
        bool found = false;
        while(r>0){
            if(nums[r-1]<nums[r]){
                found = true;
                r--;
                int l = r+1;
                while(l<nums.size()-1&&nums[l+1]>nums[r]) l++;//The part where I made a mistake, carefully think about the iterations
                int temp = nums[l];
                nums[l] = nums[r];
                nums[r] = temp;
                //cout<<r<<endl<<nums[0];
                r++;
                l = nums.size()-1;
                while(l>r){
                    temp = nums[l];
                    nums[l] = nums[r];
                    nums[r] = temp;
                    l--;
                    r++;
                }
                break;
            }
            else r--;
        }
        if(!found) sort(nums.begin(),nums.end());
    }
};