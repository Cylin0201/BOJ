#include <iostream>
#include <algorithm>

void binary_search(int arr[], int arr_size, int key)
{
    int start = 0, end = arr_size - 1;
    while (end >= start)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            std::cout<<mid<<"\n";
            return;
        }
        else if (arr[mid] < key)
            start = mid + 1;
        else
            end = mid - 1;
    }
    std::cout<<"key가 존재하지 않습니다!"<<"\n";
}

/*          test_code for binary_search
int main()
{
    int arr[10] = {7, 0, 1, 6, 2, 9, 8, 3, 4, 5};
    std::sort(arr, arr + 10);
    binary_search(arr, 10, 100);
}
*/