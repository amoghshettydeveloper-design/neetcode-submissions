// Claude Solution
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for (int n : nums) freq[n]++;

        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& [num, count] : freq)
            buckets[count].push_back(num);

        vector<int> result;
        for (int i = buckets.size()-1; i > 0; i--) {
            for (int n : buckets[i]) {
                result.push_back(n);
                if (result.size() == k) return result;
            }
        }
        return result;

    }
};
