class Solution {
public:
    bool isPalindrome(int x) {
        unsigned int temp;
        unsigned int reverse=0;
        temp=x;
        while (temp>0){
            int last=temp%10;
            reverse= reverse*10 +last;
            temp=temp/10;

        }
        return reverse==x;



        
    }
};