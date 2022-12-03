#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
    int arr[] = {2, 325, 0, 34, 34, 89, 83, 24};
    int n = 8;
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}