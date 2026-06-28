class Solution {
public:
    int getKey(char c){
        return c - 'a';
    }
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> h1(26,0);
        vector<int> h2(26,0);
        int matches = 0;
        for(int i = 0;i<s1.size();i++){
            h1[getKey(s1[i])]++;
            h2[getKey(s2[i])]++;
        }

        for(int i = 0; i < 26;i++){
            if(h1[i] == h2[i]) matches++;
        }

        if(matches == 26) return true;
        for(int i = s1.size(); i < s2.size();i++){
            int add = getKey(s2[i]);
            int rem = getKey(s2[i - s1.size()]);
            
            h2[add]++;
            if(h2[add] == h1[add]) matches++;
            else if(h2[add] - 1 == h1[add] ) matches--;

            h2[rem]--;
            if(h2[rem] == h1[rem]) matches++;
            else if(h2[rem] + 1 == h1[rem]) matches--;

            if(matches == 26) return true;
        }
        return false;
    }
};
