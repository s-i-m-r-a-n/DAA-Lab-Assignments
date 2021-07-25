#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);\
    cout.tie(NULL)


#define endl "\n"

using namespace std;

int Binary_search(int* arr, int l, int h,int key,int occurrence){
    int mid,index=-1;
    while(h>=l){
        mid=(h+l)/2;
        if(arr[mid]==key){
            index=mid;
            if(occurrence)
                h= mid-1;
            else
                l= mid+1;
        }else if(arr[mid]>key)
            h=mid-1;
        else if(arr[mid]<key)
            l=mid+1;
    }
    return index;
}

int main()
{
    fastio;
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
        int key;
        file>>key;
        int first_occur = Binary_search(arr,0,n-1,key,1);
        int last_occur = Binary_search(arr,0,n-1,key,0);
        if(first_occur!=-1)
            cout<<key<<"->"<<last_occur-first_occur+1<<endl;
        else
            cout<<"Key not present "<<key<<endl;
    }
    file.close();
    return 0;
}