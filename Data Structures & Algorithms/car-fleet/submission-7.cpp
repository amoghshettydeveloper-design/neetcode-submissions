// Optimized by Claude
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        // Pair position with speed so std::sort can't desync them
        vector<pair<int,int>> cars(n); // {position, speed}
        for (int i = 0; i < n; i++) {
            cars[i] = {position[i], speed[i]};
        }
        sort(cars.begin(), cars.end()); // ascending by position

        // Stack holds each car's time-to-target as a fraction: num/den
        // num = target - position, den = speed
        stack<pair<int,int>> st;

        for (int i = 0; i < n; i++) {
            int pos = cars[i].first;
            int spd = cars[i].second;
            int num = target - pos;
            int den = spd;

            // Pop while top-of-stack's time <= current car's time
            // topNum/topDen <= num/den  <=>  topNum*den <= num*topDen  (cross multiply)
            while (!st.empty()) {
                long long topNum = st.top().first;
                long long topDen = st.top().second;
                if (topNum * den <= (long long)num * topDen) {
                    st.pop();
                } else {
                    break;
                }
            }
            st.push({num, den});
        }

        return st.size();
    }
};