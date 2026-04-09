class Solution {
public:
    bool isPalindrome(string s, int low, int high) {
        while (low < high) {
            if (s[low] != s[high]) return false;
            low++;
            high--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int low=0,high=s.size()-1;
        while(low<high)
        {
            if(s[low] != s[high]){
                return isPalindrome(s, low + 1, high) || isPalindrome(s, low, high - 1);
            }
            low++;
            high--;
        }
        return true;
    }
};