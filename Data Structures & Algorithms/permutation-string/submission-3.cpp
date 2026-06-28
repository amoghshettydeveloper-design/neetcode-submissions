class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        vector<int> firstHash(26,0);
        vector<int> secondHash(26,0);
        int flag = true;
        for(int i = 0;i<s1.size();i++){
            firstHash[s1[i]-'a']++;
            secondHash[s2[i]-'a']++;
        }
        for(int i = 0;i<26;i++){
            if(firstHash[i]!=0 || secondHash[i]!=0)
            if(firstHash[i] != secondHash[i])
                flag = false;
        }
        if(flag) return flag;
        for(int i = s1.size(); i < s2.size(); i++){
            secondHash[s2[i-s1.size()]-'a']--;
            secondHash[s2[i]-'a']++;
            if(secondHash[s2[i]-'a'] == firstHash[s2[i]-'a']){
            flag = true;
                for(int j = 0;j<26;j++){
                    if(firstHash[j] != 0 || secondHash[j] != 0)
                    if(firstHash[j] != secondHash[j]){
                        flag = false;
                        break;
                    }
                }
                if(flag) return flag;
            }
        }

        return flag;
    }
};
