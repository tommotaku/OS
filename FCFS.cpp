#include <iostream>
using namespace std;

int main() {
	int n;
	cout << "Enter no of processes\n";
	cin >> n;
	int p[n], bt[n], tat[n], wt[n];
	cout << "Enter burst time process\n";
	for(int i = 0; i < n;i++){
	    cin >> bt[i];
	}
	wt[0] = 0;
	for(int i = 1; i < n;i++){
	    wt[i] = wt[i-1]+bt[i-1];
	} 
	float atat = 0, awt= 0;
	cout << "Processes\tBurst Time\tWaiting Time\tTurn around time\n";
	for(int i = 0; i < n;i++){
	    tat[i] = wt[i]+bt[i];
	    cout << i+1 <<"\t\t" << bt[i] <<"\t\t" <<wt[i]<<"\t\t" << tat[i] << endl;
	    awt+=wt[i];
	    atat+=tat[i];
	}
	awt/=n;
	atat/=n;
	cout <<"Average waiting time: " << awt << endl;
	cout <<"Average turn around time: " << atat << endl;
}