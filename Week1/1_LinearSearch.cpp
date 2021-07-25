#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    int t;
    ifstream file;
    file.open("input_1.txt");
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
        int num;
        file>>num;
        int comparison=0,flag=0;
        for(int i=0;i<n;i++){
            comparison++;
            if(num == arr[i]){
                flag=1;
                break;
            }
        }     
        if(flag==1)
            cout<<"Present "<<comparison<<endl;
        else
            cout<<"Not Present "<<comparison<<endl;
    }   
    file.close(); 
    return 0;
}