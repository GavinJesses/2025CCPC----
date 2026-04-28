#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pii pair<int,int>
#define fi first
#define se second
const int N=2e5+10;
int a[N];
void slove(){
	string s;cin>>s;
	if(count(s.begin(),s.end(),'0')!=count(s.begin(),s.end(),'1')){
		cout<<-1<<endl; // 01数量不同不可操作
		return ;
	}
	int c0=0,c1=0; // 统计可用01的个数
	int t=1; // 记录所处S的位置
	cout<<s.size()/2<<endl; // 每次多两个数，所以操作次数一定是长度除2
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			if(c0==0){ // 如果没有可用0，说明需要新增一个，输出
				cout<<t<<' '<<1<<endl;
				c1++; // 可用1增加
			}
			else{ // 有可用的0就和前面的1配对
				c0--; 
				t++; // 位置移动，前面会多一个S
			}
		}
		else{ // 1的情况与0类似
			if(c1==0){
				cout<<t<<' '<<2<<endl;
				c0++;
			}
			else{
				c1--;
				t++;
			}
		}
	}
} 
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _=1;
	//cin>>_;
	while(_--)
	slove();
	return 0;
}
