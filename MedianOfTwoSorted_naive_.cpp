#include <iostream>
using namespace std;

int main()
{
    int arr1[] = {15, 35, 45};
    int arr2[] = {10, 30, 40};
    int n = 3, m = 3;
    int *arr3 = new int[m + n];
    int j = 0, x = 0;
    int i = 0;
    while (x <= (m + n))
    {
        if (m != 0 && n != 0)
        {

            if (arr1[i] > arr2[j])
            {
                arr3[x] = arr2[j];
                j++;
                x++;
                if (j == m)
                {
                    break;
                }
            }
            else if (arr1[i] < arr2[j])
            {
                arr3[x] = arr1[i];
                i++;
                x++;
                if (i == n)
                {
                    break;
                }
            }
        }
    }
    int eleCount = x;
    if (j == m)
    {
        for (int y = 0; y < (m + n) - eleCount; y++)
        {
            arr3[x] = arr1[i];
            x++;
            i++;
        }
    }
    else if (n == i)
    {
        for (int y = 0; y <= (m + n) - eleCount; y++)
        {
            arr3[x] = arr1[i];
            x++;
            i++;
        }
    }

    for (int i = 0; i < (m + n); i++)
    {
        cout << arr3[i] << " ";
    }
    cout << endl;
    if ((m + n) % 2 == 0)
    {
        int mid = (0 + ((m + n) - 1)) / 2;
        int mid1 = mid + 1;
        cout << (arr3[mid1] + arr3[mid]) / 2 << endl;
    }
    else if ((m + n) % 2 != 0)
    {
        int mid = (0 + ((m + n) - 1)) / 2;
        cout << arr3[mid] << endl;
    }
    return 0;
}