class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = INT_MIN,sum = 0;

        for(int n:nums){
            sum += n;
            mx = max(mx,sum);
            if(sum<0)
                sum = 0;
        }
        return mx;
    }
};
