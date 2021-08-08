#include<iostream>
#include<fstream>
using namespace std;
void printArray(int* arr,int n)
{
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
}
int Insertionsort(int a[],int n)
{
    int i,j,temp,comp=0,shift=0;
    for(i=1;i<n;i++)
    {
        shift++;
        temp=a[i];
        j=i-1;
        while((temp<a[j])&&(j>=0))
        {
            a[j+1]=a[j];
            j--;
            comp++;
            shift++;
        }
        a[j+1]=temp;
    }
    printArray(a,n);
    cout<<"\nNumber of comparisons are:"<<comp;
    cout<<"\nNumber of shifts are:"<<shift;
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
        Insertionsort(arr,n);
    }
    file.close();
    return 0;
}