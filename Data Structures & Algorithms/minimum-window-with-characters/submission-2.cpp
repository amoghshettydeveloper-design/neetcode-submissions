class Solution {
   public:
    bool checkStringHash(vector<int> first, vector<int> second) {
        for (int i = 0; i < 256; i++) {
            if(first[i]!=0)
                // cout << first[i] << " " << second[i] << endl;
            if (first[i] != 0 && first[i] > second[i]) {
                return false;
            }
        }
        return true;
    }

    void printHash(vector<int> showHash) {
        for (int i = 0; i < 256; i++) cout << showHash[i] << endl;
    }

    string generateResString(int st, int end, string s) {
        int i = st;
        string res = "";
        while (i <= end) res += s[i++];
        return res;
    }

    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";
        vector<int> firstStringHash(256, 0);
        vector<int> secondStringHash(256, 0);
        int minLen = 1001;
        string resString = "";
        for (char c : t) {
            firstStringHash[c - 'A']++;
        }
        int i = 0, j = 0;
        while (s[j]) {
            secondStringHash[s[j]-'A']++;
            while(checkStringHash(firstStringHash,secondStringHash)){
                if(minLen >= (j-i+1)){
                    minLen = j - i + 1;
                    resString = generateResString(i,j,s);
                }
                secondStringHash[s[i++]-'A']--;
            }            
            cout<<generateResString(i,j,s)<<" ---> "<<minLen<<endl;
            j++;
        }

        return resString;
    }
};
