class Solution {
public:
    bool isPalindrome(int n) {
        long original = n;
        long reverse = 0;

        while(n>0){
            int digit = n%10;
            reverse = reverse *10 + digit;
            n=n/10;
        }
        if(original == reverse) {
            return true;
        } else {
            return false;
        }
    }
};