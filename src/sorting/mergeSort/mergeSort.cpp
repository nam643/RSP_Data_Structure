// Divide phase: O(logn)
// Merge phase: O(n)
// Total: O(nlogn)
// Space: O(n) -> temporary array
#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right){
    vector<int> tmp;

    int i = left;
    int j = mid + 1;

    while(i<=mid && j<=right){
        if(arr[i] <= arr[j]){
            tmp.push_back(arr[i++]);
        }
        else{
            tmp.push_back(arr[j++]);
        }
    }

    while(i<=mid){
        tmp.push_back(arr[i++]);
    }

    while(j<=right){
        tmp.push_back(arr[j++]);
    }

    for(int k = 0;k<static_cast<int>(tmp.size());k++){
        arr[left + k] = tmp[k];
    }
}

void mergeSort(vector<int>& arr, int left, int right){
    if(left >= right) return;

    //divide
    int mid = left + (right-left)/2;

    //conquer
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);

    //merge
    merge(arr,left,mid,right);
}

int main(){
    vector<int> arr = {4,10,3,5,1};

    mergeSort(arr,0,arr.size()-1);

    for(int x : arr) cout<<x<<" ";

    return 0;
}