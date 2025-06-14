class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>values={
            {'I',1}, {'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
        };
        int  num =0;
        int n=s.length();
        for (int i=0;i<n;i++){
            if (i+1<n && values[s[i]]<values[s[i+1]]){
                num+=values[s[i+1]]-values[s[i]];
                i++;
            }
            else {
                num+=values[s[i]];
            }
        }
            return num;
        }
        
    };
