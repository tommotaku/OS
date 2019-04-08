#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,h;
    cout<<"Enter the number of memory cylinders and head value\n";
    cin>>n>>h;
    int a[n];
    cout<<"Enter the addresses of the memory cylinders\n";
    for(int i = 0; i < n; i++) cin>>a[i];
    int ans = abs(h-a[0]);
    for(int i=0;i<n-1;i++){
        ans+=abs(a[i]-a[i+1]);
    }
    printf("The total head movement is of %d cylinders\n",ans);
}