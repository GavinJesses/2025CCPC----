#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> PII;
const int mod = 998244353;
const int N = static_cast<const int>(2e6 + 1000);
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;

void solve() {
    string s;
    cin>>s;
    if(s.substr(s.size()-12,12)=="isallyouneed")
    {
        cout<<"Yes"<<endl;
        cout<<s.substr(0,s.size()-12)<<endl;
    }
    else cout<<"No"<<endl;
}
///lslslsllslslslllllllllllsssssssssllll
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) 
        solve();

    return 0;
}