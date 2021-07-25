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
    file.open("input_2.txt");
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
        int flag=0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j <n;j++){
                for(int k = j+1; k < n; k++){
                    if(arr[i] + arr[j] == arr[k]){
                        flag=1;
                        cout<<i+1<<","<<j+1<<","<<k+1<<endl;
                        break;
                    }
                }
            }
        }
        if(!flag)
            cout<<"No sequence found!"<<endl;
    }
    file.close();
    return 0;
}