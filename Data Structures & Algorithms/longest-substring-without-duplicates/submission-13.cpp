class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hashMap(256,0);
        int i = 0,j=0,mx=0;
        while(j<s.size()){
            if(hashMap[s[j]]){
                hashMap[s[i]]--;
                i++;
            }
            else{
                mx = max(mx,j-i+1);
                hashMap[s[j]]++;
                j++;
            }
        }
        return mx;
    }
};
