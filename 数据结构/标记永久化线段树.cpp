typedef double db;//类型 
struct node{// min max sum 不需要的直接删去
	db tag,sum;//加标记和差分区间和 表示这个区间以下的区间和 
	db min,max;//差分最小值 最大值 表示这个区间以下的最小值 最大值 
};
int n=1e5;
vector<node>S(4*(n+1));
int x,y;//每次操作的闭区间 l,r 是初始闭区间 
function<void(int,int,int,db)>add=[&](int p,int l,int r,db val){//c++11
    if(x>r||y<l) return ;
    S[p].sum+=val*(min(r,y)-max(l,x)+1);//算区间和的贡献
    if(x<=l&&r<=y){S[p].min+=val;S[p].max+=val;S[p].tag+=val;return;}//标记永久化在区间上
    int mid=(l+r)>>1;//看部分最小 or 最大值是当前节点的永久化标记加上这次更新的 
    add(p<<1,l,mid,val),add((p<<1)|1,mid+1,r,val);
    S[p].min=min(S[p*2].min,S[p*2+1].min)+S[p].tag;
    S[p].max=max(S[p*2].max,S[p*2+1].max)+S[p].tag; 
};
function<db(int,int,int,db)>qmin=[&](int p,int l,int r,db val)->db{
    if(x>r||y<l) return 1e8;//LL LLONG_MAX
    if(x<=l&&r<=y)	return S[p].min+val;//算出完整的最小值 
    int mid=(l+r)>>1;//带标记下传
    return min(qmin(p*2,l,mid,S[p].tag+val),
    qmin(p*2+1,mid+1,r,S[p].tag+val));//左边右边 
};
function<db(int,int,int,db)>qmax=[&](int p,int l,int r,db val)->db{
    if(x>r||y<l) return 0;//LL LLONG_MIN
    if(x<=l&&r<=y)	return S[p].max+val;//算出完整的最大值 
    int mid=(l+r)>>1;//带标记下传
    return max(qmax(p*2,l,mid,S[p].tag+val),
    qmax(p*2+1,mid+1,r,S[p].tag+val));//左边右边 
};
