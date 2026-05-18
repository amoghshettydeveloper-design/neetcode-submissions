class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> stringVectors;
        unordered_map<string,vector<string>> stringMap;

        for(string s:strs){
            string key(26,0);
            for(char c:s)
                key[c-'a']++;
            stringMap[key].push_back(s);
        }
        
        for(auto& [key,group]:stringMap){
            stringVectors.push_back(group);
        }
        return stringVectors;
    }
};
