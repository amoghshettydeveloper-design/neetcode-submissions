class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        map<int,int> freqCount;
        priority_queue<int> pq;
        for(int i = 0;i<k;i++)
        {
            int element = nums[i];
            if(freqCount.count(element))
                freqCount[element] =  freqCount[element] + 1;
            else
                freqCount[element] = 1;
            pq.push(element);
        }
        res.push_back(pq.top());
        for(int i = k; i < nums.size();i++){
            int removeNum = nums[i - k];
            int element = nums[i];
            freqCount[removeNum] = freqCount[removeNum] - 1;
            if(freqCount.count(element))
                freqCount[element] =  freqCount[element] + 1;
            else
                freqCount[element] = 1;
            pq.push(element);
            int mxElement = pq.top();
            while(freqCount[mxElement] == 0){
                pq.pop();
                mxElement = pq.top();
            }
            res.push_back(mxElement);
        }
        return res;
    }
};
