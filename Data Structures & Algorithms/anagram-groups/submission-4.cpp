class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> stringMap;
        
        for(string st: strs){
            string key(26,0);
            for(char c: st) key[c-'a']++;
            stringMap[key].push_back(st);
        } 
        
        vector<vector<string>> resVector;
        
        for(const auto& [_,values]: stringMap)
            resVector.push_back(values);
        
        return resVector;
    }
};
