// a^b mod p
// 时间复杂度: O(log n)
inline int fpow(int a,int b,int p){
	int ans=1,base=a%p;
	for(;b;b/=2){
		if(b&1)ans=1ll*ans*base%p;
		base=1ll*base*base%p;
	}
	return ans;
}
