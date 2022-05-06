// 字符串区间哈希
// 时间复杂度: O(n)~O(1)
int base1=1337;
int base2=914846374;
using ui=unsigned int;
vector<ui>Hash1(n+1);
vector<ui>Hash2(n+1);
vector<ui>Base1(n+1);Base1[0]=1;
vector<ui>Base2(n+1);Base2[0]=1;
for(int i=1;i<=n;++i)
Hash1[i]=(Hash1[i-1]*base1+a[i]),
Base1[i]=(Base1[i-1]*base1),
Hash2[i]=(Hash2[i-1]*base2+a[i]),
Base2[i]=(Base2[i-1]*base2);
function<pii(int,int)>get=[&](int l,int r){// return Hash[l,r]
	return mp(Hash1[r]-Hash1[l-1]*Base1[r-l+1],
	Hash2[r]-Hash2[l-1]*Base2[r-l+1]);
};
//use get to solve Long Common Prefix/Suffix in O(log(n))
