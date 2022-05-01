// 线性筛素数 时间复杂度: O(n)
vector<int>primelist;// 素数表
vector<int>v;// 最小素因子
void init_prime(int m){//
	v.resize(m+1);
	for(int i=2;i<=m;++i){
		if(v[i]==0)
			v[i]=i,primelist.push_back(i);
		for(auto j:primelist){
			if(j>v[i]||1ll*i*j>m) break;
			v[i*j]=j;
		}
	} 
}	
