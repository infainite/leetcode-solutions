class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        int current;
        for (int i = temperatures.size() - 1; i >= 1; i--)
        {
            current = temperatures.at(i);
            for (int j = i - 1; j >= 0; j--)
                if (temperatures.at(j) < current)
                    result.at(j) = i - j; 
        }

        return result;
    }
};
