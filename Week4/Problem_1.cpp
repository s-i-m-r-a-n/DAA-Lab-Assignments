#include<iostream>
#include<fstream>
using namespace std;
void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
}
int comparison=0,inversions=0;
void Merge(int arr[], int l, int mid, int r)
{
    int n1=mid-l+1,n2=r-mid;
    int Leftarr[n1],Rightarr[n2],i,j,k;
    for(i=0; i<n1; i++) 
        Leftarr[i]=arr[l+i];
    for(j=0; j<n2; j++) 
        Rightarr[j] = arr[mid+1+j];
    i=0;j=0;k=l;
    while(i<n1 && j<n2)
    {
        if(Leftarr[i]<=Rightarr[j])
        {
            comparison++;
            arr[k] = Leftarr[i];
            i++;
        }
        else
        {
            comparison++;
            arr[k] = Rightarr[j];
            j++;
            inversions += (mid+1) - (l+i);
        }
        k++;
    }
    while(i<n1)
    {
        arr[k++]=Leftarr[i++];
    }
    while(j<n2)
    { 
        arr[k++]=Rightarr[j++];
    }
}
void MergeSort(int arr[], int l, int h)
{
    if(l<h)
    {
        int mid = l+(h-l)/2;
        MergeSort(arr,l,mid);
        MergeSort(arr,mid+1,h);
        Merge(arr,l,mid,h);
    }
}
int main()
{
    int t;
    ifstream file;
    file.open("input1.txt");
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
        comparison=0,inversions=0;
        MergeSort(arr,0,n-1);
        printArray(arr,n);
        cout<<endl<<"comparisons: "<<comparison<<endl;
        cout<<"inversions: "<<inversions<<endl;
    }
    file.close();
    return 0;
}