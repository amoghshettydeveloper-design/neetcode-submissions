class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> frequency(2001,0);
        for(int n:nums)
            frequency[n + 1000]++;

        vector<vector<int>> bucketSize(nums.size()+1);  

        for(int i = 0; i <2001; i++){
            if(frequency[i])
                bucketSize[frequency[i]].push_back(i-1000);
        }

        vector<int> res;
        for(int i = nums.size();i>=0;i--){
            if(bucketSize[i].size()){
                for(int n: bucketSize[i]){
                    res.push_back(n);
                    k--;
                    if(k == 0)  return res;  
                }
            }
        }

        return res;
    }
};
