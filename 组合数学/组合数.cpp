// 引用: 典/快速幂.cpp
// 计算组合数：排列数与组合数
// 时间复杂度: O(n)~O(1)
const int mod=1e9+7;
template<int _mod>
struct comb{
	static const int mod=_mod;
	vector<int>jc,jcni;
	int C(int n,int m){// C(n,m)=n!/(m!*(n-m)!)
		if(n<m||m<0) return 0;
		if(m==0) return 1;
		return 1ll*jc[n]*jcni[m]%mod*jcni[n-m]%mod;
	}
	int A(int n,int m){ // A(n,m)=n!/(n-m)!
		if(n<m||m<0) return 0;
		if(m==0) return 1;
		return 1ll*jc[n]*jcni[n-m]%mod;
	}
	comb(int N=1e5+7){
		jc.resize(N+1),jcni.resize(N+1);
		jc[0]=1;for(int i=1;i<=N;++i)
			jc[i]=1ll*jc[i-1]*i%mod;
		jcni[N]=fpow(jc[N],mod-2,mod);
		for(int i=N-1;i>=0;i--)
			jcni[i]=1ll*jcni[i+1]*(i+1)%mod;
	}
};
comb<mod> d;
