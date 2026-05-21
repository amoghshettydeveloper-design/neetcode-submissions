// Hashing Solution
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> resArr;
        set<int> setArr;
        set<vector<int>> s;
        for(int i=0; i < nums.size();i++){
            
            for(int j = i+1; j<nums.size();j++){
                int sum = nums[i] + nums[j];
                if(setArr.count(-sum)){
                    vector<int> vArr = {nums[i],nums[j],-sum};
                    sort(vArr.begin(),vArr.end());
                    if(s.find(vArr) == s.end()){
                        s.insert(vArr);
                        resArr.push_back(vArr);
                    }
                }
            }
            setArr.insert(nums[i]); 
        }
        return resArr;
    }
};
