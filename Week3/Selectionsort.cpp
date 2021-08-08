#include<iostream>
#include<fstream>
using namespace std;
void printArray(int* arr,int n)
{
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
}
int Selectionsort(int a[],int n)
{
    int i,j,s,pos,temp,comp=0,swap=0;
    for(i=0;i<n-1;i++)
    {
        swap++;
        s=a[i];
        pos=i;
        for(j=i+1;j<n;j++)
        {
            comp++;
            if(a[j]<s)
            {
                s=a[j];
                pos=j;
            }
        }
        temp=a[i];
        a[i]=a[pos];
        a[pos]=temp;
    }
    printArray(a,n);
    cout<<"\nNumber of comparisons are:"<<comp;
    cout<<"\nNumber of swaps are:"<<swap;
    cout<<"\n";
    return 0;
}
int main()
{
    int t;
    ifstream file;
    file.open("input_1.txt");
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
        Selectionsort(arr,n);
    }
    file.close();
    return 0;
}