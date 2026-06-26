class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 1 || s.size() == 0) return s.size();
        int i = 0,j=0;
        int mx = 0;
        vector<bool> hashMap(256,false);
        while(s[i]){
            while(s[j]){
                if(hashMap[s[j]])
                    break;
                mx = max(j-i+1,mx);
                hashMap[s[j++]] = true;
            }
            hashMap[s[i]] = false;
            i++;
        }
        return mx;
    }
};
