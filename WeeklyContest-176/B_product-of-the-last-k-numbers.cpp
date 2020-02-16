#include<bits/stdc++.h>
using namespace std;

class ProductOfNumbers {
public:
    vector<int> ps;
    int lz=0;//不用lz标记遇到零可以重置ps
    ProductOfNumbers() {
        ps.push_back(1);
    }
    
    void add(int num) {
        if(num==0){
            lz=ps.size();
            ps.push_back(1);
        }else ps.push_back(ps.back()*num);
    }
    
    int getProduct(int k) {
        if(k>=ps.size()-lz)
            return 0;
        return ps.back()/ps[ps.size()-k-1];
    }
};
//树状数组版
class ProductOfNumbers1 {
    int n,a[40005],f[40005][20];
public:
    ProductOfNumbers1() {
        n=0;
    }
    
    void add(int num) {
        a[++n]=num;
        f[n][0]=a[n];
        for(int i=1;1<<i<=n;i++)f[n][i]=f[n][i-1]*f[n-(1<<i-1)][i-1];
    }
    
    int getProduct(int k) {
        int i=n,j=15,ans=1;
        for(;~j;j--)if(k>>j&1)
        {
            ans*=f[i][j];
            i-=1<<j;
        }
        return ans;
    }
};
//c语言版
typedef struct {
  int top;
  int data[40010];   
  int ZeroPos;
} ProductOfNumbers;


ProductOfNumbers* productOfNumbersCreate() {
    ProductOfNumbers* obj;
    obj = (ProductOfNumbers *)malloc(sizeof(ProductOfNumbers));
	obj->top = 0;
	obj->ZeroPos = 0;
    obj->data[0] = 1; 
	return obj;
}

void productOfNumbersAdd(ProductOfNumbers* obj, int num) {
	++obj->top;
	if( num == 0 )
	{
		obj->ZeroPos = obj->top;
		obj->data[obj->top] = 1;	
	}
  	else obj->data[obj->top] = obj->data[obj->top-1]*num;
}

int productOfNumbersGetProduct(ProductOfNumbers* obj, int k) {
	
	k = obj->top-k+1;
    if(k <= obj->ZeroPos) return 0;
    else return obj->data[obj->top]/obj->data[k-1];

}

void productOfNumbersFree(ProductOfNumbers* obj) {
    free(obj);
}

//qc的
#define PB push_back
#define LB lower_bound
#define REP(x, l, u) for(ll x = l;x<u;x++)
#define RREP(x, l, u) for(ll x = l;x>=u;x--)
#define complete_unique(a) a.erase(unique(a.begin(),a.end()),a.end())
#define mst(x, a) memset(x,a,sizeof(x))
#define all(a) begin(a),end(a)
#define PLL pair<ll,ll>
#define MP make_pair
#define se second
#define fi first
#define sz(x) ((int)x.size())

typedef long long ll;
typedef double db;
using namespace std;
typedef vector<ll> VLL;
typedef vector<int> VI;

class ProductOfNumbers2 {
public:
    int cnt;
    vector<pair<int,int>>v;
    ProductOfNumbers2() {
        cnt = 0;
    }
    
    void add(int num) {
        if(num != 1){
            v.PB(MP(cnt,num));
        }
        cnt++;
    }
    
    int getProduct(int k) {
        ll ans = 1;
        int s = cnt-k;
        auto ptr = LB(all(v),make_pair(s,0));
        while(ptr != v.end()){
            ans *= ptr->se;
            if(!ans)break;
            ++ptr;
        }
        return ans;
    }
};
/**
 * Your ProductOfNumbers struct will be instantiated and called as such:
 * ProductOfNumbers* obj = productOfNumbersCreate();
 * productOfNumbersAdd(obj, num);
 
 * int param_2 = productOfNumbersGetProduct(obj, k);
 
 * productOfNumbersFree(obj);
*/