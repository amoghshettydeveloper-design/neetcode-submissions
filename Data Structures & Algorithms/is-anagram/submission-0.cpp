class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!= t.length())
            return false;
        int sArr[26]={0},tArr[26]={0};
        for(int i = 0; i <s.length(); i++){
            sArr[s[i]-'a']++;
            tArr[t[i]-'a']++;
        }

        for(int i = 0; i < 26; i++){
            if(sArr[i] != tArr[i])
                return false;
        }
        return true;
    }
};
