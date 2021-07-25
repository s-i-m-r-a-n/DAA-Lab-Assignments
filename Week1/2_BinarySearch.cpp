#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void Binary_search(int* arr, int l, int h,int key){
    int mid,comparison=0,flag=0;
    while(h>=l){
        comparison++;
        mid=(h+l)/2;
        if(arr[mid]==key){
            flag=1;break;
        }else if(arr[mid]>key)
            h=mid-1;
        else if(arr[mid]<key)
            l=mid+1;
    }
    if(flag)
        cout<<"Present "<<comparison<<endl;
    else
        cout<<"Not Present "<<comparison<<endl;
}

int main()
{
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
        int key;
        file>>key;
        Binary_search(arr,0,n-1,key);
    }   
    file.close(); 
    return 0;
}