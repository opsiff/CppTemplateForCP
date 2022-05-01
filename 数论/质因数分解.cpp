// 配合 prime.cpp 使用筛出到 n 的线性筛素数初始化 v 数组
// 时间复杂度: O(log n)
vector<pii> fact(int n){
	vector<pii>res;
	while(n>1){
		int cnt=0;
		int cur=v[n];
		while(n%cur==0)n/=cur,cnt++;
		res.pb({cur,cnt});
	}
	return res;
}
// 配合 prime.cpp 使用筛出到 根号n 的线性筛素数
// 时间复杂度: O(n/log n)
using vpii=vector<pii>;
vpii solve(int x){
	vpii p;
	for(auto i:primelist){
		if(i*i>x) break;
		if(x%i==0){
			int cnt=0;
			while(x%i==0){
				cnt++;
				x/=i;
			}
			p.pb({i,cnt});
		}
	}
	if(x!=1) p.pb({x,1});
	return p;
}
