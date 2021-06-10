#include<iostream>
#include<vector>
using namespace std;

int bs(vector<int> &arr, int elem)
{
    int start = 0, end=arr.size()-1;
    int mid;
    while(start<=end)
    {
        mid = (start+end)/2;
        
        if(arr[mid]==elem)
            return mid;
        else if(arr[mid]>elem)
            end = mid-1;
        else
            start = mid+1;
    }
    return -1;
}

int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(4);
    arr.push_back(7);
    arr.push_back(8);
    arr.push_back(10);
    arr.push_back(12);
    arr.push_back(15);
    arr.push_back(15);
    arr.push_back(17);
    for(auto& i:arr)
        cout<<bs(arr,i)<<" ";
    cout<<endl<<bs(arr,0);
    
    return 0;
}