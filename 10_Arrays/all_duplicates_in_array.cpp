// QUES: https://leetcode.com/problems/find-all-duplicates-in-an-array/description/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Approach 1 : Using negative indexing/ Index Marking   // MOST OPTIMIZED+
/*
Explanation:
    Index Marking: This approach uses the array itself to mark visited elements by negating the value at the index corresponding to the absolute value of the element (minus one).
    Duplicate Check: If the value at this index is already negative, it means the element has been encountered before, so it is a duplicate.
    Result: Duplicates are collected in the ans vector.

Pros:
    Time Complexity: O(n), where n is the number of elements in the array.
    Space Complexity: O(1) additional space.

Cons:
    Modifies Input: The input array is modified, which might not be desirable in some cases.
*/
vector<int> findDuplicates(vector<int> &nums)
{
    vector<int> arr = nums;
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        int index = abs(arr[i]) - 1;
        if (arr[index] < 0)
        {
            ans.push_back(abs(arr[i]));
        }
        arr[index] = -arr[index];
    }
    return ans;
}

// Approach 2: Using Sorting
/*
Explanation:
    Sorting: The input array is sorted.
    Duplicate Check: The sorted array is then traversed, and consecutive elements are compared.
    Result: If two consecutive elements are the same, they are duplicates and added to the ans vector.

Pros:
    Simplicity: The logic is straightforward and easy to understand.
    No Complex Modification: Does not rely on modifying the array in a complex way.

Cons:
    Time Complexity: O(n log n) due to the sorting step.
    Space Complexity: O(1) additional space, but the sorting step might not be desirable if the array is large.
 */
vector<int> find_duplicates(vector<int> &arr)
{
    vector<int> ans;
    sort(arr.begin(), arr.end());
    int i = 0;
    while (i < arr.size() - 1)
    {
        if (arr[i] == arr[i + 1])
        {
            ans.push_back(arr[i]);
        }
        i++;
    }
    return ans;
}



// Approach 3: Using Sorting and Counting  // a redundant version of approach 2 in this ques
// but this approach can be used in other ques where we need to find the duplicates with their count
/*
Explanation:
    Sorting: The input array is sorted.
    Counting Duplicates: The sorted array is traversed, and for each element, a nested loop counts how many times it appears consecutively.
    Result: If an element appears exactly twice, it is added to the ans vector.

Pros:
    Handles Specific Duplicate Counts: This approach can be modified to handle specific counts of duplicates (e.g., exactly two duplicates).

Cons:
    Time Complexity: O(n^2) in the worst case due to the nested loop.
    Space Complexity: O(1) additional space, but the sorting step might not be desirable if the array is large.
*/

vector<int> find_duplicates_3(vector<int> &nums)
{
    int i = 0;
    sort(nums.begin(), nums.end());
    vector<int> ans;
    while (i < nums.size())
    {
        int count = 1;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] < nums[j])
            {
                break;
            }
            if (nums[i] == nums[j])
            {
                count++;
            }
        }
        if (count == 2)
        {
            ans.push_back(nums[i]);
        }
        i = i + count;
    }
    return ans;
}



int main()
{

    vector<int> arr = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> ans = findDuplicates(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    vector<int> ans2 = find_duplicates(arr);
    for (int i = 0; i < ans2.size(); i++)
    {
        cout << ans2[i] << " ";
    }
    cout << endl;

    vector<int> ans3 = find_duplicates_3(arr);
    for (int i = 0; i < ans3.size(); i++)
    {
        cout << ans3[i] << " ";
    }
    cout << endl;

    return 0;
}

/* CODE ANALYSIS */
/*
In this code snippet, we are given an array of integers. We need to find all the duplicates in the array and return them in a vector.

Approach 1: Efficient in terms of time complexity (O(n)) but modifies the input array.
Approach 2: Simpler and does not modify the array in a complex way but has a higher time complexity (O(n log n)) due to sorting.
Approach 3: Can handle specific counts of duplicates but has the highest time complexity (O(n^2)) due to the nested loop.
*/