class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int numLength = nums.size();
        vector<int> prefix(numLength,1);
        vector<int> suffix(numLength,1);

        for(int i = 1; i < numLength; i++)
            prefix[i] = nums[i-1] * prefix[i-1];

        for(int i = numLength - 2; i >= 0; i--)
            suffix[i] = nums[i+1] * suffix[i+1];
        
        vector<int> res(numLength,1);
        for(int i = 0; i < numLength; i++)
            res[i] = prefix[i] * suffix[i];
        return res;

    }
};
