class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> resArr(temperatures.size(),0);
        for(int i = 0; i < temperatures.size();i++){
            int num = temperatures[i];
            while(!st.empty() && temperatures[st.top()]<num){
                int idx = st.top();
                resArr[idx] = i-idx;
                st.pop();
            }
            st.push(i);
        }
        return resArr;
    }
};
