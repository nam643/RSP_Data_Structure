#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& arr, int n,int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < n && arr[left] > arr[largest]) swap(arr[left],arr[largest]);

    if(right < n && arr[right] > arr[largest]) swap(arr[right], arr[largest]);

    if(largest != i){
        swap(arr[i],arr[largest]);

        heapify(arr,n,largest);
    }
}

void heapSort(vector<int>& arr){
    int n = static_cast<int>(arr.size());

    for(int i = n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }

    for(int i = n-1;i>0;i--){
        swap(arr[0],arr[i]);

        heapify(arr,i,0);
    }
}

int main(){
    vector<int> arr = {3,10,5,4,7};

    heapSort(arr);

    for(int i : arr) cout<<i<<" ";

    return 0;
}