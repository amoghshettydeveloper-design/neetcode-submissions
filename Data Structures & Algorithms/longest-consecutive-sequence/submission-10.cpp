class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int mx = 0;
        set<int> numSet;
        for(int n:nums)
            numSet.insert(n);
        for(int n:nums){
            int c = 1;
            mx = max(mx,c);
            if(!numSet.count(n - 1)){
                while(numSet.count(n + 1)){
                    mx = max(mx,++c);
                    n++;
                }
            }
        }
        return mx;
    }
};
