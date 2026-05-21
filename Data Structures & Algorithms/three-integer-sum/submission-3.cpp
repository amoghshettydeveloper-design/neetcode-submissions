// Most Optmized
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> resArr;
        set<vector<int>> checkSet;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i++){
            int j = i + 1,k=nums.size()-1;
            int target = -nums[i];
            
            while(j<k){
                // cout<<target<<endl;
                if(nums[j] + nums[k] > target)
                    k--;
                else if(nums[j] + nums[k] < target)
                    j++;
                else{
                    vector<int> v = {nums[i],nums[j],nums[k]};
                    sort(v.begin(),v.end());
                    if(checkSet.find(v) == checkSet.end()){
                        resArr.push_back(v);
                        checkSet.insert(v);
                    }
                    j++;
                    k--;
                }
            }
        }
        return resArr;
    }
};
