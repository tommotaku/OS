#include <bits/stdc++.h>
using namespace std;

int main() {
	int m, n;
	cin >> m >> n;
	int block[m], process[n];
	for(int i = 0; i < m; i++) cin >> block[i];
	for(int i = 0; i < n; i++) cin >> process[i];
	int alloc[n];
	memset(alloc,-1,sizeof(alloc));
	for(int i = 0; i < n; i++){
	    for(int j = 0; j < m; j++){
	        if(block[j] >= process[i]){
	            alloc[i] = j;
	            block[j]-=process[i];
	            break;
	        }
	    }
	}
	cout << "Process\tSize\tBlock\n";
	for(int i = 0; i < n; i++){
	    cout <<i+1<<"\t" << process[i] << "\t";
	    if(alloc[i]!=-1) cout << alloc[i]+1 << endl;
	    else cout <<"Not allocated\n";
	}
	
}