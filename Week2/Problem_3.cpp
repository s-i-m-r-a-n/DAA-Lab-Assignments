#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
    fastio;
    int t;
    ifstream file;
    file.open("input_3.txt");
    if(!file){
        cout<<"File not found";
        return 0;
    }
    file>>t;
    while(t--){
        int n;
        file>>n;
        int arr[n];
        for (int i = 0; i < n; i++)
            file>>arr[i];
        int k,count=0;
        file>>k;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(abs(arr[i]-arr[j]) == k)
                    count++;
            }
        }
        cout<<count<<endl;
    }
    file.close();
    return 0;
}