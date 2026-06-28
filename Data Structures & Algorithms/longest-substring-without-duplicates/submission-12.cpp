// My Clean Solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int mx = 0;
        int l = 0,r = 0;
        vector<bool> strHash(256,false);
        while(s[r]){
            if(!strHash[s[r]]){
                mx = max(mx,r-l+1);
                strHash[s[r]] = true ;
                r++;
            }
            else{
                strHash[s[l]] = false;
                l++;
            }
        }
        return mx;
    }
};
