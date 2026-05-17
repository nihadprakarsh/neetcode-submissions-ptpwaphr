class Solution {
public:
    int mySqrt(int x) {
        if(x < 2) return x;
        long long int low=0,high=x/2,mid;
        while(low <= high){
            mid = low + (high-low)/2;
            if(mid*mid == x){
               return mid; 
            }
            else if(mid*mid > x){
                high = mid - 1;
            }
            else
            low = mid +1;
        }
        return high;
    }
};