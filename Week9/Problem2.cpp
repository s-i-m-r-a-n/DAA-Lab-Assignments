#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void Knapsack(int n,float* weights, float* value, int w){
    float VbyW[n];
    for(int i=0;i<n;i++) 
        VbyW[i] = (float)(value[i]/weights[i]);
    for(int i=0;i<n;i++){
        int pos=i;
        for(int j=i+1;j<n;j++)
            if(VbyW[j]>VbyW[pos])
                pos=j;
        swap(VbyW[i],VbyW[pos]);
        swap(weights[i],weights[pos]);
        swap(value[i],value[pos]);
    }
    int currWeight = 0;
    float finalValue = 0.0;
    for(int i=0;i<n;i++){
        if(currWeight + weights[i] <= w){
            currWeight += weights[i];
            finalValue += value[i];
        }
        else{
            int rem=w-currWeight;
            finalValue += value[i]*((float)rem/weights[i]);
            break;
        }
    }
    cout<<"Maximum value: "<<finalValue<<endl;
}

int main()
{
    ifstream file;
    file.open("Input2.txt");
    if(!file){
        cout<<"File not found";
        return 0;
    }
    int n;
    file>>n;
    float Weights[n],value[n];
    for(int i=0;i< n; i++)
        file>>Weights[i];
    for(int i=0;i< n;i++)   
        file>>value[i];
    int w;
    file>>w;
    Knapsack(n,Weights,value,w);
    return 0;
}