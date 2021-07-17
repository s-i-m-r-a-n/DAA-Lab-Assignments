#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin>>arr[i];
        int num;
        cin>>num;
        int comparison=0,flag=0;
        for(int i=0;i<n;i++){
            comparison++;
            if(num == arr[i]){
                flag=1;
                break;
            }
        }     
        if(flag==1){
            cout<<"YES"<<endl;
            cout<<"Comparison: "<<comparison<<endl;
        }
        else{
            cout<<"NO"<<endl;
            cout<<"Comparison: "<<comparison<<endl;
        }
    }
    return 0;
}