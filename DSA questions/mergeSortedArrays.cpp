class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int l = 0, r = 0, k = n-1;
            while(l<=k && r < m){
                if(arr1[l] <= arr2[r]) l++;
                else{
                    int temp = arr1[k];
                    arr1[k] = arr2[r];
                    arr2[r] = temp;
                    r++;
                    k--;
                }
            }
            sort(arr1, arr1 + n);
            sort(arr2, arr2 + m);
        } 
};