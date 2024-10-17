

#include<bits/stdc++.h>
using namespace std;
void solve(int i, string s, string &f) {
	if (i == s.length()) {
		cout << f << "  orig "<<endl;
		return;
	}
	//picking 
	f = f + s[i];
	solve(i + 1, s,  f);
    cout<<i<<"string is"<<f<<endl;
	//poping out while backtracking
	f.pop_back();
   cout<<i<<"string is"<<f<<endl;
	solve(i + 1, s,  f);
}
int main() {
	string s = "abc";
	string f = "";
	cout<<"All possible subsequences are: "<<endl;
	solve(0, s, f);
}