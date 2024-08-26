#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// BRUTE FORCE APPROACH: 3 nested loops (TIME COMPLEXITY: O(N^3))
vector<vector<int>> tripletSum(vector<int> &arr, int sum)
{
    set<vector<int>> uniqueTriplets;
    for (int i = 0; i < arr.size() - 2; i++) // size -2 because we need atleast 3 elements to form a triplet
    {
        for (int j = i + 1; j < arr.size() - 1; j++)
        {
            for (int k = j + 1; k < arr.size(); k++)
            {
                if (arr[i] + arr[j] + arr[k] == sum)
                {

                    vector<int> triplet = {arr[i], arr[j], arr[k]};
                    sort(triplet.begin(), triplet.end());
                    uniqueTriplets.insert(triplet); // using set to avoid duplicates // set will automatically handle the duplicates
                }
            }
        }
    }

    // converting set to vector
    vector<vector<int>> ans(uniqueTriplets.begin(), uniqueTriplets.end());

    // returning as it is because the question does not demand any specific order of triplets
    return ans;
}

// 2 Pointer + sorting approach (TIME COMPLEXITY: O(N^2))

/**
 * One way to avoid duplication of triplets is to use a set to store the triplets.
 * but this will increase the space complexity to O(n)
 */

vector<vector<int>> triplet_sum(vector<int> &arr, int sum)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    set<vector<int>> uniqueTriplets;

    for (int i = 0; i < arr.size(); i++)
    {
        int left = i + 1;
        int right = arr.size() - 1;

        while (left < right)
        {
            int temp_sum = arr[i] + arr[left] + arr[right];

            if (temp_sum == sum)
            {
                vector<int> triplet = {arr[i], arr[left], arr[right]};
                uniqueTriplets.insert(triplet);
                left++;
                right--;
            }
            else if (temp_sum < sum)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    ans = vector<vector<int>>(uniqueTriplets.begin(), uniqueTriplets.end());
    return ans;
}

/**
 * Another way to avoid the duplication of triplets is to simply skip the duplicates while traversing the array.
 * since the array is sorted, we can skip the duplicates by checking the adjacent elements.
 *
 * the following code is an upgradation of the above approach and it also reduces the space complexity to O(1)
 * also it it more optimized in the sense that it will also skip the iteration for same values of i
 */

vector<vector<int>> triplet_sum2(vector<int> &arr, int sum)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        int left = i + 1;
        int right = arr.size() - 1;

        while (left < right)
        {
            int temp_sum = arr[i] + arr[left] + arr[right];

            if (temp_sum == sum)
            {
                vector<int> triplet = {arr[i], arr[left], arr[right]};
                ans.push_back(triplet);

                int x = arr[left];
                int y = arr[right];

                // skipping the duplicates
                // if the next element is same as the current element then keep moving the pointer
                while (arr[left] == x && left < right)
                {
                    left++;
                }
                // if the previous element is same as the current element then keep moving the pointer
                while (arr[right] == y && left < right)
                {
                    right--;
                }
            }
            else if (temp_sum < sum)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        while (i + 1 < arr.size() && arr[i] == arr[i + 1])
        {
            i++;
        }
    }
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