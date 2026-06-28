class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, mx = 0;
        vector<bool> hashMap(256,false);
        while(s[r]){
            if(!hashMap[s[r]]){
                mx = max(r - l + 1,mx);
                hashMap[s[r]] = true;
                r++;
            }
            else{
                hashMap[s[l]] = false;
                l++;
            }         
        }
        return mx;
    }
};
