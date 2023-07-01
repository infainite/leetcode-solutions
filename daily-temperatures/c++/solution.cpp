class Solution {
public:
    void solve(vector<int>& arr, int start, int end, vector<int>& res)
    {
        bool found = false;

        if (start == end) return;

        int atStart = arr.at(start);
        
        for (int i = start + 1; i < end + 1; i++)
        {
            if (arr.at(i) > atStart)
            {
                found = true;
                res.at(start) = i - start;
                solve(arr, start + 1, end, res);
                solve(arr, end, arr.size() - 1, res);
                break;
            }
        }

        if (!found)
            solve(arr, start + 1, end, res);
    }
    
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);

        solve(temperatures, 0, temperatures.size() - 1, res);

        return res;
    }
};
