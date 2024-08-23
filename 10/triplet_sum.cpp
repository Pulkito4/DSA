#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// BRUTE FORCE APPROACH: 3 nested loops (TIME COMPLEXITY: O(N^3))
vector<vector<int>> tripletSum(vector<int> &arr, int sum)
{
    set<vector<int>> uniqueTriplets;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            for (int k = j + 1; k < arr.size(); k++)
            {
                if (arr[i] + arr[j] + arr[k] == sum)
                {

                    vector<int> triplet = {arr[i], arr[j], arr[k]};
                    sort(triplet.begin(), triplet.end());
                    uniqueTriplets.insert(triplet);
                }
            }
        }
    }

    // converting set to vector
    vector<vector<int>> ans(uniqueTriplets.begin(), uniqueTriplets.end());

    // returning as it is because the question does not demand any specific order of triplets
    return ans;
}




int main()
{

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
    int sum = 18;

    vector<vector<int>> res = tripletSum(arr, sum);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}