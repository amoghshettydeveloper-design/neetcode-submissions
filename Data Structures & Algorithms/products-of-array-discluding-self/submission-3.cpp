class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int arrSize = nums.size();
        vector<int> prefix(arrSize,1),suffix(arrSize,1);
        vector<int> res;

        for(int i = 1;i<arrSize;i++)
            prefix[i] = prefix[i-1]*nums[i-1];

        for(int i = arrSize-2; i>=0;i--)
            suffix[i] = suffix[i+1]*nums[i+1];

        for(int i = 0 ;i<arrSize;i++)
            res.push_back(prefix[i]*suffix[i]);
        return res;

    }
};
