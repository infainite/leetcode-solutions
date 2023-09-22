class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> t;
        vector<int> res(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++)
        {
          if (t.empty())
            t.push(i);
          else if (temperatures[t.top()] < temperatures[i])
          {
            res[t.top()] = i - t.top();
            t.pop();
            i--;
          }
          else
          {
            t.push(i);
          }
        }

        return res;
    }
};
