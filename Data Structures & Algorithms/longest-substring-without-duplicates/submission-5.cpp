class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unsigned long long int strHash = 0;
        int mx = 0;
        int l = 0,r = 0;
        vector<bool> boolArr(256,false);
        while(s[r]){
            if(s[r] && !boolArr[s[r]]){
                mx = max(mx,r-l+1);
                boolArr[s[r]] = true ;
                r++;
            }
            else{
                boolArr[s[l]] = false;
                l++;
            }
        }
        return mx;
    }
};
