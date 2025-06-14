
class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int a=0; a<=haystack.length()-needle.length()&&needle.length()<=haystack.length();a++){
            if(haystack[a]==needle[0]){
                int index=a;
                for(int b=0;b<needle.length();b++,index++){
                    if(haystack[index]!=needle[b]) break;
                    else if (b==needle.length()-1) return a;
                }
            }
        }
        return -1;
        
    }
};