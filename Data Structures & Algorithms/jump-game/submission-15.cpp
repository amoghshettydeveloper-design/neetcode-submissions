class Solution {
   public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        int i = 0,n = nums.size();
        while (i < n ) {
            cout<<i+1<<endl;
            if (nums[i] != 0 && i != n-1) {
                int mx = 0 ,mxIndex = i + 1;
                for (int j = i + 1; j < n && j  <= (nums[i] + i); j++) {
                    if(j==n-1)
                        return true;
                    if(nums[j] >= mx || (mx+mxIndex)<=j){
                        mxIndex = j;
                        mx = nums[j];
                    }
                }
                i = mxIndex;
            } else
                return false;
        }
        return true;
    }
};
