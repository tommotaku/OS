#include <bits/stdc++.h>
using namespace std;

int main() {
	int m, n;
	cin >> m >> n;
	int process[n];
	vector<pair<int, int> > block; int b;
	for(int i = 0; i < m; i++) {
	    cin >> b;
	    block.push_back(make_pair(b,i+1));
	}
	for(int i = 0; i < n; i++) cin >> process[i];
	sort(block.begin(),block.end());
	int alloc[n];
	memset(alloc,-1,sizeof(alloc));
	for(int i = 0; i < n; i++){
	    for(int j = 0; j < m; j++){
	        if(block[j].first >= process[i]){
	            alloc[i] = block[j].second;
	            block[j].first-=process[i];
	            break;
	        }
	    }
	}
	cout << "Process\tSize\tBlock\n";
	for(int i = 0; i < n; i++){
	    cout <<i+1<<"\t" << process[i] << "\t";
	    if(alloc[i]!=-1) cout << alloc[i] << endl;
	    else cout <<"Not allocated\n";
	}
	
}