#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, bt, at;
	cin >> n;
	int rembt[n], wt[n], tat[n];
	vector<pair<int, int> > v;
	for(int i = 0; i < n; i++){
	    cin >> bt >> at;
	    v.push_back(make_pair(bt, at));
	    rembt[i] = bt;
	}
	int complete = 0, time = 0, mi = INT_MAX; int shortest = 0, finish;
	bool check = false;
	while(complete != n){
	    for(int i = 0; i < n; i++){
	        if(v[i].second <= time && rembt[i] < mi && rembt[i] > 0){
	            mi = rembt[i];
	            shortest = i;
	            check = true;
	        }
	    }
	    if(check == false){
	        time++;
	        continue;
	    }
	    rembt[shortest]--;
	    mi = rembt[shortest];
	    if(mi == 0)
	        mi = INT_MAX;
	    if(rembt[shortest] == 0){
	        complete++;
	        check = false;
	        finish = time+1;
	        wt[shortest] = finish - v[shortest].first - v[shortest].second;
	        if(wt[shortest] < 0)
	            wt[shortest] = 0;
	    }
	    time++;
	}
	float awt = 0, atat = 0;
    cout << "Process\tBT\tWT\tTAT\n";
	for(int i = 0; i < n; i++){
	    tat[i] = wt[i] + v[i].first;
	    cout << i+1 <<"\t\t" << v[i].first << "\t" <<wt[i]<<"\t"<<tat[i]<<endl;
	    awt+=wt[i];
	    atat+=tat[i];
	}
	awt/=n;
	atat/=n;
	cout << "Average WT " <<awt <<endl <<"Average TAT " << atat << endl;
	
}
