#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

class DSU{
private:
    std::vector<int> parent;
    std::vector<int> size;

public:
    DSU(int n){
        parent.resize(n);
        size.resize(n,1);

        std::iota(parent.begin(),parent.end(),0);
    }

    int find(int x){
        if(x==parent[x]) return x;

        return parent[x] = find(parent[x]);
    }

    bool unite(int a,int b){
        int rootA = find(a);
        int rootB = find(b);

        if(rootA == rootB) return false;

        if(size[rootA] < size[rootB]) std::swap(rootA,rootB);

        size[rootA] += size[rootB];
        parent[rootB] = rootA;
        return true;
    }
};

int main(){
    std::vector<std::vector<int>> edgeList = {{0,1,3}, {0,2,4}, {0,3,5}, {1,3,4}, {2,3,2} ,{1,2,3}};
    DSU dsu(4);
    std::sort(edgeList.begin(),edgeList.end(), [&](const std::vector<int>& a, const std::vector<int>& b){
        return a[2] <= b[2];
    });

    int minimumWeight = 0;

    for(auto x : edgeList){
        std::cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<"\n";
    }

    for(auto x : edgeList){
        if(dsu.unite(x[0],x[1])) minimumWeight += x[2];
    }

    std::cout<<minimumWeight<<"\n";
    return 0;
}