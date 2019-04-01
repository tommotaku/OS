#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cout << "Enter no of processes\n";
	cin >> n;
	int tat[n], wt[n], bt;
	vector<pair <int, int> > v;
	cout << "Enter burst time process\n";
	for(int i = 0; i < n;i++){
	    cin >> bt;
	    v.push_back(make_pair(bt, i+1));
	}
	sort(v.begin(), v.end());
	wt[0] = 0;
	for(int i = 1; i < n;i++){
	    wt[i] = wt[i-1]+v[i-1].first;
	} 
	float atat = 0, awt= 0;
	cout << "Processes\tBurst Time\tWaiting Time\tTurn around time\n";
	for(int i = 0; i < n;i++){
	    tat[i] = wt[i]+v[i].first;
	    cout << v[i].second <<"\t\t" << v[i].first <<"\t\t" <<wt[i]<<"\t\t" << tat[i] << endl;
	    awt+=wt[i];
	    atat+=tat[i];
	}
	awt/=n;
	atat/=n;
	cout <<"Average waiting time: " << awt << endl;
	cout <<"Average turn around time: " << atat << endl;
}