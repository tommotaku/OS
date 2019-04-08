#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, h;
    cout<<"Enter the number of memory cylinders and head value \n";
    cin>>n >> h;
    int diff,c, index, min = INT_MAX;
    int a1; vector<int> a;
    cout <<"Enter memory values:\n" ;
    for(int i = 0; i < n; i++){
        cin >> a1;
        a.push_back(a1);
    }
    vector<int>v; v.push_back(h);
    for(int i = 0; i < v.size(); i++){
        if(v.size() == n+1)
            break;
        min = INT_MAX;
        for(int j = 0; j < a.size(); j++){
            diff = abs(v[i]-a[j]);
            if(diff < min){
                min = diff;
                index = j;
                c = a[j];
            }
        }
        a.erase(a.begin()+index);
        v.push_back(c);
    }
    int ans = 0;
    for(int i = 0; i < v.size()-1; i++)
        ans+=abs(v[i]-v[i+1]);
    cout << "Total head movement: " << ans << endl;
}