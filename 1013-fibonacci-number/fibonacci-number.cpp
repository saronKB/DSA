class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        int num1=0;
        int num2=1;
        int newNum=0;
        for(int i=2; i<n;i++){
                return fib(n-2)+ fib(n-1);
                newNum=num1+num2;
                num1=num2;
                num2=newNum;
                
            }
            return num2;     
    }
        
    
};