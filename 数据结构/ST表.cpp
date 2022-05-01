// Sparse-Table 解决离线区间最大、最小、最大公约数询问问题
// 时间复杂度: O(nlog n)~O(1)
template<typename T,int N,auto cmp> struct ST {
  static const int LOGN=log2(N)+1;
  T f[N][LOGN],Logn[N];
  ST(){
  Logn[1]=0;Logn[2]=1;
      for(int i=3;i<N;i++)Logn[i]=Logn[i/2]+1;
  }
  void init(T* a,int n) {
      for(int i=1;i<=n;i++)
          f[i][0]=a[i];
      for(int j=1;j<LOGN;j++)for(int i=1;i+(1<<j)-1<=n;i++)
          f[i][j]=cmp(f[i][j-1],f[i+(1<<(j-1))][j-1]);
  }
  T get(int x, int y) {
      T s=Logn[y-x+1];
      return cmp(f[x][s],f[y-(1<<s)+1][s]);
  }
};
ST<int,1000001,[](int a,int b){
	return max(a,b);
}>ma;
ST<int,1000001,[](int a,int b){
	return min(a,b);
}>mi;
ST<int,1000001,[](int a,int b){
	return __gcd(a,b);
}>mgcd;
