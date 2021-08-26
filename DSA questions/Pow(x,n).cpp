class Solution {
public:
    double myPow(double x, int n) {
        if(abs(x) == 1){
            if(n%2 == 0 || x == 1) return 1;
            else return -1;
        }
        double ans = binExp(x,abs(n));
        if(n<0) ans = 1/ans;
        return ans;
    }
    
    double binExp(double x,long int n){ // Long int is required to prevent overflow when taking abs(-2147483648)
        if(n == 0){
            return 1.0;
        }
        else if(n%2 == 0){
            return binExp(x*x,n/2);
        }
        else return x*binExp(x,n-1);
    }
};