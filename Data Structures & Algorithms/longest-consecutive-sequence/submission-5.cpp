// Optimized solution
class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==1||nums.size()==0)  return nums.size();
        unordered_set<int> numSet;
        for(int n:nums){
            numSet.insert(n);
        }
        int mx = 1;
        for(int n: nums){
            if(!numSet.count(n-1)){
                int c = 1;
                while(numSet.count(n+1)){
                    c++;
                    n++;
                    mx = max(mx,c);
                }
            }
        }
        return mx;
    }
};
