// 普通并查集
// 路径压缩 + 启发式合并
// 时间复杂度: O(α(n)) α(n)为反阿克曼函数
struct DSU{
	vector<int>fa,siz;
	void init(int n){
		fa.resize(n+1);
		siz.resize(n+1);
		iota(all(fa),0);
		fill(all(siz),1);
		return ;
	}
	int find(int x){
		return fa[x]==x?x:fa[x]=find(fa[x]);
	}	
	int merge(int x,int y){
		int f1=find(x),f2=find(y);
		if(f1==f2) return 0;
		if(siz[f1]>siz[f2])swap(f1,f2);// 启发式合并
		fa[f1]=f2;
		siz[f2]+=siz[f1];
		return 1;
	}
}d;
