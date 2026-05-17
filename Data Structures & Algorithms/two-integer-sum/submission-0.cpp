class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices;
        indices.push_back(0);
        indices.push_back(0);
        map<int,int> mapIndex;
        for(int i=0; i < nums.size(); i++){
            if(mapIndex.contains(target-nums[i])){
                indices[0] = mapIndex.at(target-nums[i]);
                indices[1] = i;
                break;
            }
            mapIndex[nums[i]] =i;
        }
        return indices;    
    }

    
};
