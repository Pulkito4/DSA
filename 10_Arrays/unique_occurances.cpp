// QUES: https://leetcode.com/problems/unique-number-of-occurrences/
// Given an array of integers arr, write a function that returns true if and only if the number of occurrences of each value in the array is unique.
#include <bits/stdc++.h>
using namespace std;


// BRUTE FORCE APPROACH (TIME COMPLEXITY: O(N^2))
class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        int i = 0;
        sort(arr.begin(), arr.end());
        vector<int> ans;
        while (i < arr.size())
        {
            int count = 1;
            for (int j = i + 1; j < arr.size(); j++)
            {
                if (arr[i] == arr[j])
                {
                    count++;
                }
            }
            ans.push_back(count);
            i = i + count;
        }
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size() - 1; i++)
        {
            if (ans[i] == ans[i + 1])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{

    vector<int> arr = {1, 2, 2, 1, 1, 3};
    Solution obj;
    cout << obj.uniqueOccurrences(arr);
    return 0;
}