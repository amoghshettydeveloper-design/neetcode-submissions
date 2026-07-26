class Solution {
   public:
    void bubbleSort(vector<int>& arr, vector<int>& timeArr) {
        int n = arr.size();

        for (int i = 0; i < n - 1; i++) {
            bool swapped = false;

            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    swap(timeArr[j], timeArr[j + 1]);
                    swapped = true;
                }
            }

            if (!swapped) break;
        }
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        bubbleSort(position, speed);
        int size = position.size();
        vector<float> time(size, 0);
        for (int i = 0; i < size; i++) {
            time[i] = (float)(target - position[i]) / speed[i];
        }
        stack<int> incStack;
        int fleet = 0;

        for (int i = 0; i < size; i++) {
            float curCar = time[i];
            while (!incStack.empty() && time[incStack.top()] <= curCar) {
                incStack.pop();
            }
            incStack.push(i);
        }
        while (!incStack.empty()) {
            fleet++;
            incStack.pop();
        }
        return fleet;
    }
};
