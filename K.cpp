#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pii pair<int,int>
#define fi first
#define se second
const int N=2e5+10;
vector<int> a(N);
void slove(){
    fill(a.begin(),a.end(),0);
	int n,m;cin>>n>>m;
	deque<pii> q;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		q.push_back({x,i}); // 将数据和下标一起存入
	}
	int ff=1; // 用来记录方向
	while(m--){
		char op;cin>>op;
		if(ff==1){ // 顺时针方向
			pii f=q.front();  // 从队头取元素
			q.pop_front();
			f.fi--;
			if(op=='S'){ // 停止牌
				if(f.fi!=0)
				q.push_back(f); 
				q.push_back(q.front()); // 将下一个也存入队尾
				q.pop_front();
			}
			if(op=='R'){ // 反转牌
				ff=-1;
				if(f.fi!=0) // 改变了方向，下一次就该从队尾取了，所以这个再存回队头
				q.push_front(f);
			}
			if(op=='D'){ // +2牌
				if(f.fi!=0)
				q.push_back(f);
				pii f=q.front();
				q.pop_front();
				q.push_back({f.fi+2,f.se}); // +2后也会被停止，所以直接存到后面
			}
			if(op=='C'){
				if(f.fi!=0)
				q.push_back(f);
			}
		}
		else{ // 逆时针的方向，思路和上面一模一样，只是取得时候从队尾取数据了
			pii f=q.back();
			q.pop_back();
			f.fi--;
			if(op=='S'){
				if(f.fi!=0)
				q.push_front(f);
				q.push_front(q.back());
				q.pop_back();
			}
			if(op=='R'){
				ff=1;
				if(f.fi!=0)
				q.push_back(f);
			}
			if(op=='D'){
				if(f.fi!=0)
				q.push_front(f);
				pii f=q.back();
				q.pop_back();
				q.push_front({f.fi+2,f.se});
			}
			if(op=='C'){
				if(f.fi!=0)
				q.push_front(f);
			}
		}
	}
	while(q.size()){ // 将队列中剩余的手牌数量同步到数组中，便于输出
		pii f=q.front();
		q.pop_front();
		a[f.se]=f.fi;
	}
	for(int i=1;i<=n;i++) // 按序输出即可
	cout<<a[i]<<endl;
    cout<<endl;
} //sdadwadsadwadwwwwwwawww
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _=1;
	//cin>>_;
	while(_--)
	slove();
	return 0;
}


// TLE写法
// #include <bits/stdc++.h>
// #define int long long
// using namespace std;
// typedef pair<int, int> PII;
// const int mod = 998244353;
// const int N = static_cast<const int>(2e6 + 1000);
// const int INF = 0x3f3f3f3f;
// const double eps = 1e-6;

// void solve()
// {
//     int n, m;
//     cin >> n >> m;
//     vector<int> v(n);
//     vector<int> f(n, 1);
//     int sum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> v[i];
//         sum += v[i];
//     }
//     string s;
//     cin >> s;
//     int cur = 0;
//     int rev = 1;
//     for (int i = 0; i < s.size(); i++)
//     {
//         // while (f[cur] == 0)
//         // {
//         //     if (rev == 1)
//         //         cur = (cur + 1) % n;
//         //     else
//         //         cur = (cur - 1 + n) % n;
//         // }
//         if (s[i] == 'C')
//         {
//             v[cur]--;
//             sum--;
//             if (sum == 0)
//                 break;
//             if (v[cur] == 0)
//             {
//                 f[cur] = 0;
//             }
//             if (rev == 1)
//                 cur = (cur + 1) % n;
//             else
//                 cur = (cur - 1 + n) % n;
//             while (f[cur] == 0)
//             {
//                 if (rev == 1)
//                     cur = (cur + 1) % n;
//                 else
//                     cur = (cur - 1 + n) % n;
//             }
//         }
//         else if (s[i] == 'S')
//         {
//             v[cur]--;
//             sum--;
//             if (sum == 0)
//                 break;
//             if (v[cur] == 0)
//             {
//                 f[cur] = 0;
//             }
//             if (rev == 1)
//                 cur = (cur + 1) % n;
//             else
//                 cur = (cur - 1 + n) % n;
//             while (f[cur] == 0)
//             {
//                 if (rev == 1)
//                     cur = (cur + 1) % n;
//                 else
//                     cur = (cur - 1 + n) % n;
//             }
//             if (rev == 1)
//                 cur = (cur + 1) % n;
//             else
//                 cur = (cur - 1 + n) % n;
//             while (f[cur] == 0)
//             {
//                 if (rev == 1)
//                     cur = (cur + 1) % n;
//                 else
//                     cur = (cur - 1 + n) % n;
//             }
//         }
//         else if (s[i] == 'R')
//         {
//             v[cur]--;
//             sum--;
//             if (sum == 0)
//                 break;
//             if (v[cur] == 0)
//             {
//                 f[cur] = 0;
//             }
//             rev = -rev;
//             if (rev == 1)
//                 cur = (cur + 1) % n;
//             else
//                 cur = (cur - 1 + n) % n;
//             while (f[cur] == 0)
//             {
//                 if (rev == 1)
//                     cur = (cur + 1) % n;
//                 else
//                     cur = (cur - 1 + n) % n;
//             }
//         }
//         else if (s[i] == 'D')
//         {
//             v[cur]--;
//             sum--;
//             if (sum == 0)
//                 break;
//             if (v[cur] == 0)
//             {
//                 f[cur] = 0;
//             }
//             if (rev == 1)
//                 cur = (cur + 1) % n;
//             else
//                 cur = (cur - 1 + n) % n;
//             while (f[cur] == 0)
//             {
//                 if (rev == 1)
//                     cur = (cur + 1) % n;
//                 else
//                     cur = (cur - 1 + n) % n;
//             }
//             v[cur] += 2;
//             if (rev == 1)
//                 cur = (cur + 1) % n;
//             else
//                 cur = (cur - 1 + n) % n;
//             while (f[cur] == 0)
//             {
//                 if (rev == 1)
//                     cur = (cur + 1) % n;
//                 else
//                     cur = (cur - 1 + n) % n;
//             }
//         }
//         // for (auto it : v)
//         // {
//         //     cout << it << endl;
//         // }
//         // cout << endl;
//     }
//     for (auto it : v)
//     {
//         cout << it << endl;
//     }
//     cout << endl;
// }

// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     int t = 1;
//     // cin >> t;
//     while (t--)
//         solve();

//     return 0;
// }