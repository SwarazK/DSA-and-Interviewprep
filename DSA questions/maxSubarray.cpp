    int maxSubArray(vector<int>& nums) {
        long long int sum = nums[0], max_sum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(sum+nums[i] < nums[i]) sum = nums[i];
            else sum += nums[i];
            if(sum > max_sum) max_sum = sum;
        }
        return max_sum;
    }

    //Another version
    int maxSubArray(vector<int>& nums) {
        long long int sum = 0, max_sum = nums[0];
        for(auto i : nums){
            sum += i;
            if(sum > max_sum) max_sum = sum;
            if(sum < 0) sum = 0;
        }
        return max_sum;
    }
