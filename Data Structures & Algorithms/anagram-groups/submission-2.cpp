class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<int>> stringCount;
        vector<vector<string>> stringVectors;
        for(int i=0;i<strs.size();i++){
            vector<int> v(27);
            for(char c: strs[i]){
                v[c-'a']++;
            }
            stringCount.push_back(v);
        }
        
        for(int i=0;i<strs.size();i++){
            vector<string> v;
            if(stringCount[i][26] != 1){
                v.push_back(strs[i]);
                for(int k=i+1;k<strs.size();k++){
                    bool flag = true;
                    for(int j = 0; j < 26 ; j++){
                        if(stringCount[i][j] != stringCount[k][j]){
                            flag = false;
                            break;
                        }
                    }
                    if(flag){
                        v.push_back(strs[k]);
                        stringCount[k][26] = 1;
                    }            
                }
                stringVectors.push_back(v);
            }
        }
        return stringVectors;
    }
};
