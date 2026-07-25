class Solution {
public: 
    vector<int> getRow(int rowIndex) {
        vector<int> v;
        long long cur = 1;

        v.push_back(1);

        for (int i = 1; i <= rowIndex; i++) {
            cur = cur * (rowIndex - i + 1) / i;
            v.push_back(cur);
        }

        return v;
    }
};