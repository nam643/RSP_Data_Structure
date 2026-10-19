/*
build heap: O(N)
sorting: O(nlogn)
total : O(nlogn)


Space: O(1)
*/
#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& arr, int n, int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < n && arr[left] > arr[largest]) largest = left;

    if(right < n && arr[right] > arr[largest]) largest = right;

    if(largest != i){
        swap(arr[i], arr[largest]);

        heapify(arr,n,largest);
    }
}

void heapSort(vector<int>& arr){
    int n = static_cast<int>(arr.size());

    //Build max heap

    for(int i = n/2-1;i>=0;i--){ // n/2-1 = last non-leaf
        heapify(arr,n,i);
    }

    //extract maximum

    for(int i = n-1;i>0;i--){
        swap(arr[0],arr[i]);

        heapify(arr,i,0);
    }
}

int main()
{
    vector<int> arr = {4, 10, 3, 5};

    heapSort(arr);

    for (int x : arr)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}