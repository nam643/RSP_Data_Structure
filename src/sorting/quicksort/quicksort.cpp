#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

int partition(std::vector<int>& vec, int low, int high){
    int pivot = vec[high]; //set last element as pitvot

    //index of the element smaller than the pivot
    int i = low - 1;

    for(int j = low;j<high;j++){
        if(vec[j] <= pivot){
            i++;
            std::swap(vec[i],vec[j]);
        }
    }

    std::swap(vec[i+1], vec[high]);
    return i+1;
}

void quicksort(std::vector<int>& vec, int low, int high){
    if(low < high){
        int pi = partition(vec, low, high);

        quicksort(vec,low,pi-1);
        quicksort(vec,pi+1,high);
    }
}

int main(){
    std::vector<int> vec = {4, 3, 1, 2, 5, 9, 7, 10, 6};
    std::vector<int> ans = vec;
    std::sort(ans.begin(),ans.end());
    int n = static_cast<int>(vec.size());

    quicksort(vec,0,n-1);
    
    assert(vec==ans);
    std::cout<<"SUCCESS!"<<" ";
    return 0;
}