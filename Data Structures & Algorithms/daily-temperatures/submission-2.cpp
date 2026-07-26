class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> incStack;
        int size = temperatures.size();
        vector<int> res(size,0);
        for (int i = 0; i < size; i++) {
            int num = temperatures[i];
            while (!incStack.empty() && temperatures[incStack.top()] < num) {
                res[incStack.top()] = i - incStack.top();
                incStack.pop();
            }
            incStack.push(i);
        }
        return res;
    }
};
