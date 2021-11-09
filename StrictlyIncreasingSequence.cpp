#include<bits/stdc++.h>
using namespace std;
 
string solve (int N, vector<int> A) {
	// Write your code here
	int ans=1;
	for(int i=0;i<N;++i)
	{
		if(A[i]<i)
			ans=0;
		assert(A[i]<=100000&&A[i]>=0);
	}
	
	if(ans)
		return "Yes";
	else 
		return "No";
}
 
int main() {
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for(int i_A = 0; i_A < N; i_A++)
        {
        	cin >> A[i_A];
        }
 
        string out_;
        out_ = solve(N, A);
        cout << out_;
        cout << "\n";
    }
}