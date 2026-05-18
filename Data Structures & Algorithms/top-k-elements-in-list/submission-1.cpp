class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> numHash(2001,0);
        
        for(int i: nums){
                numHash[i+1000]++;
        } 
        vector<vector<int>> res(nums.size()+1);
        for(int i=0;i<numHash.size();i++){
            if(numHash[i]!=0)
                res[numHash[i]].push_back(i);
        }
        vector<int> finRes;
        for(int i=res.size()-1;i>0;i--){
            for(int n:res[i]){
                finRes.push_back(n-1000);

                if(finRes.size() == k)
                    return finRes;
            }
        }
        return finRes;
    }
};
