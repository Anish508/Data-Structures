#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int st, int mid, int end)
{
      int i = st;
      int j = mid + 1;

      vector<int> temp;

      while (i <= mid && j <= end)
      {
            if (arr[i] < arr[j])
            {
                  temp.push_back(arr[i]);
                  i++;
            }
            else
            {
                  temp.push_back(arr[j]);
                  j++;
            }
      }

      while (i <= mid)
      {
            temp.push_back(arr[i]);
            i++;
      }

      while (j <= end)
      {
            temp.push_back(arr[j]);
            j++;
      }

      for (int idx = 0; idx < temp.size(); idx++)
      {
            arr[idx + st] = temp[idx];
      }
}
void mergeSort(vector<int> &arr, int st, int end)
{
      if (st < end)
      {
            int mid = st + (end - st) / 2;
            mergeSort(arr, st, mid);
            mergeSort(arr, mid + 1, end);
            merge(arr, st, mid, end);
      }
}
int main()
{
      int n;

      cout << "Enter array size:";
      cin >> n;
      vector<int> arr(n);

      cout << "Enter the elements:";
      for (int i = 0; i < n; i++)
      {
            cin >> arr[i];
      }
      mergeSort(arr, 0, n - 1);

      cout << "sorted array:";
      for (int val : arr)
      {
            cout << val << " ";
      }
      cout << endl;
      return 0;
}
