#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, quant; 
    cin >> n >> quant;
    int p[n], bt[n], rembt[n], wt[n], tat[n];
    for(int i = 0; i < n; i++){
        cin >> bt[i];
        rembt[i] = bt[i];
    }
    int t = 0;
    while(1){
        bool done = true;
        for(int i = 0; i < n; i++){
            if(rembt[i] > 0){
                done = false;
                if(rembt[i] > quant){
                    rembt[i]-=quant;
                    t+=quant;
                }
                else{
                     t+=rembt[i];
                    rembt[i] = 0;
                    wt[i] = t-bt[i];
                }
            }
        }
        if(done == true) break;
    }
    float awt = 0, atat = 0;
    for(int i = 0; i < n; i++){
        tat[i] = bt[i]+wt[i];
        awt+=wt[i];
        atat+=tat[i];
    }
    awt/=n; atat/=n;
    	cout << "Processes\tBurst Time\tWaiting Time\tTurn around time\n";
	for(int i = 0; i < n;i++){
	    cout << i+1 <<"\t\t" << bt[i] <<"\t\t" <<wt[i]<<"\t\t" << tat[i] << endl;
	    
	}
	cout <<"Average waiting time: " << awt << endl;
	cout <<"Average turn around time: " << atat << endl;
    
}