// 单点求欧拉函数 表示的是小于等于n和n互质的数的个数
// 配合 prime.cpp 使用筛出到 根号n 的线性筛素数初始化 primelist 数组
// 时间复杂度: O( sqrt(n)/log n)
// φ(n) = n * \mul (p_k-1)/p_k 证明：算术基本定理 + 积性函数
int euler(int n){
	int ans=n;
	for(int i=0;i<(int)primelist.size();i++){
		int j=primelist[i];
		if(1ll*j*j>n) break;
		if(n%j==0){
		  ans=ans/j*(j-1);
		  while(n%j==0)n/=j;
		}	
	}
	if(n>1) ans=ans/n*(n-1);
	return ans;
}
