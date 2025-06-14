class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end()); 
        vector<int> distinct(s.begin(), s.end()); 
        sort(distinct.begin(), distinct.end(), greater<int>()); 
    
        if (distinct.size() >= 3) 
            return distinct[2];   
        else
            return distinct[0];   


        
    }
};