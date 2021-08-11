#include <iostream>
#include<fstream>
using namespace std;
void merge(int arr[], int l,int m,int r)
{
    int n1=m-l+1,n2=r-m;
    int L[n1],R[n2],i,j,k;
    for(i=0;i<n1;i++)L[i]=arr[l+i];
    for(j=0;j<n2;j++)R[j]=arr[m+1+j];
    i=0;j=0;k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]= L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]= R[j];
        j++;
        k++;
    }
}

void Sort(int arr[], int l, int h)
{
    if(l<h)
    {
        int mid = l+(h-l)/2;
        Sort(arr,l,mid);
        Sort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}
int BinarySearch(int arr[], int l, int h)
{
    int mid,flag=1;
    while(h>=l)
    {
        mid=(h+l)/2;
        if(arr[mid]==arr[mid+1])
        {
            flag=0;break;
        }
        else if(arr[mid]>arr[mid+1])
            h=mid-1;
        else if(arr[mid]<arr[mid+1])
            l=mid+1;
    }
    return flag;
}
int main()
{
    int t;
    ifstream file;
    file.open("input_3.txt");
    if(!file)
    {
        cout<<"File not found";
        return 0;
    }
    file>>t;
    while(t--)
    {
        int n;
        file>>n;
        int arr[n];
        for (int i = 0; i < n; i++)
            file>>arr[i];
        Sort(arr,0,n-1);
        int flag=BinarySearch(arr,0,n-1);
        if(flag)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    file.close();
    return 0;
}