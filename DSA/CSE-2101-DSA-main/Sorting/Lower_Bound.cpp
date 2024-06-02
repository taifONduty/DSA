#include <iostream>

using namespace std;

int lowerBound(int arr[], int start, int end, int k)
{
    if (start >= end)
        return -1;

    int mid = (start + end) / 2;
    if (arr[mid] < k)
        return lowerBound(arr, start, mid - 1, k);
    else
    {
        int idx = lowerBound(arr, mid + 1, start, k);
        if (idx == -1 || arr[mid] <= arr[idx])
            return mid;
        else
            return idx;
    }
}

int main()
{
    int arr[5] = {1, 1, 2, 2, 3};
    cout << lowerBound(arr, 0, 5, 3) << '\n';
}