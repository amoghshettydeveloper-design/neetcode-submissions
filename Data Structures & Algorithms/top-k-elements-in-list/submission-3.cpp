class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int numLength = nums.size();
        vector<int> res;
        unordered_map<int,int> freqCounter;
        for(int n: nums) freqCounter[n]++;

        vector<vector<int>> bucketSize(numLength+1);

        for(auto& [num,count]:freqCounter)
            bucketSize[count].push_back(num);
        
        for(int i = numLength;i>=0;i--){
            for(int n:bucketSize[i]){
                res.push_back(n);
                cout<<k<<endl;
                k--;
                cout<<k<<endl;                
                if(k == 0){
                    return res;
                }
            }
        }
        return res;

    }
};
