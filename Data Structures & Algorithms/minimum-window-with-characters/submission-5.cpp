class Solution {
public:
    int getKey(char c){
        if(c>'Z') return c - 6 - 'A';  
        return c - 'A';
    }
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";
        vector<int> sHash(52,0);
        vector<int> tHash(52,0);
        string resString = "";
        int matches = 0;
        int mn = s.size() + 1;
        
        for(int i = 0;i<t.size();i++){
            sHash[getKey(s[i])]++;
            tHash[getKey(t[i])]++;
        }

        for(int i = 0; i < 52;i++){
            if(sHash[i] >= tHash[i]) matches++;
        }
        cout<<matches<<endl;

        if(matches == 52) return s.substr(0,t.size());
        int l = 0, r = t.size();

        while(s[r]){
            // cout<<s[r]<<endl;
            int key = getKey(s[r]);
            sHash[key]++;
            if(sHash[key] == tHash[key]) matches++;
            while(matches == 52){
                if(r-l+1 < mn){
                    mn = r-l+1;
                    resString = s.substr(l,mn);
                }
                sHash[getKey(s[l])]--;
                if(sHash[getKey(s[l])] < tHash[getKey(s[l])])
                    matches--;
                l++;
            }
            r++;
        }
        cout<<resString;
        return resString;
    }
};
