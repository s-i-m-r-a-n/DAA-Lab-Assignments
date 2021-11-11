#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void ComputeMinCost(int* arr,int n){
    sort(arr,arr+n);
    vector<int> sum;
    int cost=0;
    int curCost=0;
    for(int i=0;i<n-1;i++){
        if(i==0)
            curCost = arr[i] + arr[i+1];
        else
            curCost += arr[i+1];
        sum.push_back(curCost);
    }
    for(int i=0;i<sum.size();i++)
        cost += sum[i];
    cout<<cost<<endl;
}

int main()
{
    ifstream file;
    file.open("Input3.txt");
    if(!file){
        cout<<"File not found";
        return 0;
    }
    int n;
    file>>n;
    int arr[n];
    for(int i=0;i<n;i++)    
        file>>arr[i];
    ComputeMinCost(arr,n);
    return 0;
}