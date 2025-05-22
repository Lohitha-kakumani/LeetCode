#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();

        sort(queries.begin(), queries.end());

        priority_queue<int> available;
        priority_queue<int, vector<int>, greater<int>> used;

        int j = 0; 
        int usedCount = 0;

        for (int i = 0; i < n; i++) {
            while (j < q && queries[j][0] == i) {
                available.push(queries[j][1]);
                j++;
            }
            while (!used.empty() && used.top() < i) {
                used.pop();
            }

            int active = used.size();
            while (nums[i] > active) {
                if (available.empty() || available.top() < i)
                    return -1;

                int end = available.top();
                available.pop();
                used.push(end);
                usedCount++;
                active++;
            }

            while (!used.empty() && used.top() == i) {
                used.pop();
            }
        }

        return q - usedCount; 
    }
};
