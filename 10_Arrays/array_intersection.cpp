// QUES: https://www.naukri.com/code360/problems/intersection-of-2-arrays_1082149?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1

#include <iostream>
#include <vector>
using namespace std;


// TWO POINTER APPROACH (TIME COMPLEXITY: O(N+M))
vector<int> arrayInterection(vector<int> &arr1, vector<int> &arr2)
{
    vector<int> ans;
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] == arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return ans;
}

int main()
{

    vector<int> arr1 = {1, 2, 2, 1, 1, 3};
    vector<int> arr2 = {2, 2, 1};

    vector<int> ans = arrayInterection(arr1, arr2);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}