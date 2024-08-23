// QUES: https://www.naukri.com/code360/problems/pair-sum_697295?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// BRUTE FORCE APPROACH (TIME COMPLEXITY: O(N^2))
// even other approaches mentioned on code studio are of O(N^2) time complexity
vector<vector<int>> pairSum(vector<int> &arr, int sum)
{
    vector<vector<int>> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] + arr[j] == sum)
            {
                ans.push_back({min(arr[i], arr[j]), max(arr[i], arr[j])});
                /* above line can be simplified as
                vector<int> temp;
                temp.push_back(min(arr[j], arr[j]));
                temp.push_back(max(arr[j], arr[j]));
                ans.push_back(temp);
                */
            }
        }
    }
    sort(ans.begin(), ans.end()); // sorting the pairs because question demands it
    return ans;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = 10;

    vector<vector<int>> res = pairSum(arr, sum);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i][0] << " " << res[i][1] << endl;
    }

    return 0;
}