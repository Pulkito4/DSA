// QUES: https://www.naukri.com/code360/problems/sum-of-two-arrays_893186?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_4

#include <bits/stdc++.h>
using namespace std;

// vector<int>reverse(vector<int>v){
// 	int s=0;
// 	int e= v.size()-1;
// 	while(s<e){
// 		swap(v[s++], v[e--]);
// 	}
// 	return v;

// }

vector<int> findArraySum(vector<int> &a, int n, vector<int> &b, int m)
{

    int i = n - 1, j = m - 1;
    vector<int> ans;
    int carry = 0;
    while (i >= 0 && j >= 0)
    {
        int val1 = a[i];
        int val2 = b[j];

        int sum = val1 + val2 + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
        j--;
    }

    // 1st case : array 1 is longer than array 2
    while (i >= 0)
    {
        int sum = a[i] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
    }

    // 2nd case : array 2 is longer than array 1
    while (j >= 0)
    {
        int sum = b[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        j--;
    }

    // 3rd case : both same length array but 1 digit extra needed for carry
    while (carry != 0)
    {
        int sum = carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
    }
    // return reverse(ans);
    reverse(ans.begin(), ans.end());
    return ans;
}

void printArray(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr1 = {9, 7, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> arr2 = {9, 7, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> sum = findArraySum(arr1, arr1.size(), arr2, arr2.size());
    printArray(sum);

    return 0;
}