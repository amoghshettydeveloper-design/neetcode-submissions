class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.size()<=k) return s.size();
        int l = 0,r = 0;
        int cnt = 0,mx = 0;
        vector<int> hashMap(26,0);
        while(r<s.size()){
            hashMap[s[r]-'A']++;
            cnt = 0;
            for(int i = 0;i<26;i++){
                cnt = max(cnt,hashMap[i]);
            }
            while(((r-l+1) - cnt)>k){
                hashMap[s[l++]-'A']--;
                cnt = 0;
                for(int i = 0;i<26;i++){
                    cnt = max(cnt,hashMap[i]);
                }
            }
            mx = max(r-l+1,mx);
            r++;
        }
        return mx;
    }
};
