#include <bits/stdc++.h>
using namespace std;

// ======== EXTRA DEFINITION ========
// ==================================

struct _custom_hash {
    static uint64_t process(uint64_t x) {
        x+=0x9e3779b97f4a7c15;
        x=(x^(x>>30))*0xbf58476d1ce4e5b9;
        x=(x^(x>>27))*0x94d049bb133111eb;
        return x^(x>>31);
    }

    size_t operator () (uint64_t x) const {
        static const uint64_t rnd=chrono::steady_clock::now().time_since_epoch().count();
        return process(x+rnd);
    }

    template<typename A,typename B>
    size_t operator () (const pair<A,B>& p) const {
        auto h1=operator()(p.first);
        auto h2=operator()(p.second);
        return h1^(h2<<1);
    }
};

#ifdef PBDS

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/trie_policy.hpp>

template<typename T> using _set=__gnu_pbds::tree<T,__gnu_pbds::null_type,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
template<typename T> using _multiset=__gnu_pbds::tree<T,__gnu_pbds::null_type,less_equal<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
template<typename Key,typename Value> using _map=__gnu_pbds::tree<Key,Value,less<Value>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
template<typename Key,typename Value> using _multimap=__gnu_pbds::tree<Key,Value,less_equal<Value>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
template<typename Key,typename Val> using _unordered_map=__gnu_pbds::gp_hash_table<Key,Val>;
template<typename Key,typename Val> using _hash=__gnu_pbds::gp_hash_table<Key,Val,_custom_hash>;

#endif

// ======== EXTRA DEFINITION ========
#define int long long
// ==================================

const int N=2000005;
const int M=2;
const int K=log2((long double)N)+2;
const int mod=998244353;
const int inf=2e9;
const double pi=acos(-1);
const double eps=1e-9;

#ifdef OPTIMIZE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#endif

#define endl '\n'

#define FRR(file) freopen(file,"r",stdin)
#define FRW(file) freopen(file,"w",stdout)
#define FRE(file) freopen(file,"w",stderr)

#define TIMESTAMP cerr<<fixed<<setprecision(3)<<clock()*1.0/CLOCKS_PER_SEC<<"s"<<endl;

#define _rep(i,a,b) for (int i=(a);i<=(b);++i)
#define _reps(i,a,b,c) for (int i=(a);i<=(b);c)
#define _rrep(i,a,b) for (int i=(a);i>=(b);--i)
#define _rreps(i,a,b,c) for (int i=(a);i>=(b);c)
#define _iter(i,a) for (auto i=a.begin();i!=a.end();++i)
#define _riter(i,a) for (auto i=a.rbegin();i!=a.rend();++i)
#define _graph(i,u) for (int i=h[u];~i;i=ne[i])
#define _dinic(i,u) for (int i=cur[u];~i && k<limit;i=ne[i])
#define _for(i,a) for (auto& i:a)
#define _all(x) (x).begin(),(x).end()
#define _rall(x) (x).rbegin(),(x).rend()
#define _per(x) next_permutation(_all(x))
#define _rper(x) prev_permutation(_all(x))
#define _sort(x) sort(_all(x))
#define _rsort(x) sort(_rall(x))
#define _unique(x) (x).erase(unique(_all(x)),x.end())

#define rint register int
#define i8 int8_t
#define i16 int16_t
#define i32 int32_t
#define i64 int64_t
#define i128 __int128
#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t
#define u64 uint64_t
#define u128 unsigned __int128
#define f128 __float128

#define _sqrt(x) __builtin_sqrt(x)

template<typename T> T lowbit(T x) { return x&-x; }
template<typename T> T popc(T x) { return __builtin_popcountll(x); }
template<typename T,typename S> T kthbit(T x,S k) { return (x>>k)&1; }
template<typename T,typename S> T setbit(T x,S k) { return (x|(((T)1)<<k)); }
template<typename T,typename S> T clrbit(T x,S k) { return (x&~(((T)1)<<k)); }
template<typename T,typename S> T flpbit(T x,S k) { return (x^(((T)1)<<k)); }

template<typename A,typename B> inline size_t LB(const A& a,const B& b) { return lower_bound((a).begin(),(a).end(),(b))-(a).begin(); }
template<typename A,typename B> inline size_t UB(const A& a,const B& b) { return upper_bound((a).begin(),(a).end(),(b))-(a).begin(); }
template<typename A,typename B> inline auto LB2(const A& a,const B& b) { return (a).lower_bound(b); }
template<typename A,typename B> inline auto UB2(const A& a,const B& b) { return (a).upper_bound(b); }

template<typename A,typename B> inline void chmin(A& a,const B& b) { (a>b)?(a=b):a; }
template<typename A,typename B> inline void chmax(A& a,const B& b) { (a<b)?(a=b):a; }
template<typename T> inline T min3(const T& a,const T& b,const T& c) { return min(a,min(b,c)); }
template<typename T> inline T max3(const T& a,const T& b,const T& c) { return max(a,max(b,c)); }
template<typename T> inline T min4(const T& a,const T& b,const T& c,const T& d) { return min(a,min(b,min(c,d))); }
template<typename T> inline T max4(const T& a,const T& b,const T& c,const T& d) { return max(a,max(b,max(c,d))); }
template<typename T> inline T min5(const T& a,const T& b,const T& c,const T& d,const T& e) { return min(a,min(b,min(c,min(d,e)))); }
template<typename T> inline T max5(const T& a,const T& b,const T& c,const T& d,const T& e) { return max(a,max(b,max(c,max(d,e)))); }
template<typename T> inline T min6(const T& a,const T& b,const T& c,const T& d,const T& e,const T& f) { return min(a,min(b,min(c,min(d,min(e,f))))); }
template<typename T> inline T max6(const T& a,const T& b,const T& c,const T& d,const T& e,const T& f) { return max(a,max(b,max(c,max(d,max(e,f))))); }

template<typename T> inline bool check_bound(const T& x,const T& y,const T& n,const T& m) { return x>=1 && x<=n && y>=1 && y<=m; }
template<typename T> inline T _get(const T& i,const T& j,const T& m) { return i*m+j; }
const int dx4[4]={0,1,0,-1};
const int dy4[4]={-1,0,1,0};
const int dx8[8]={-1,-1,-1,0,0,1,1,1};
const int dy8[8]={-1,0,1,-1,1,-1,0,1};

template<typename T1,typename T2> struct vec2 {
    T1 a; T2 b;
    friend bool operator < (const vec2& a,const vec2& b) {
        if (a.a!=b.a) return a.a<b.a;
        else return a.b<b.b;
    }
    friend vec2 operator + (const vec2& a,const vec2& b) { return vec2{a.a+b.a,a.b+b.b}; }
    friend vec2 operator - (const vec2& a,const vec2& b) { return vec2{a.a-b.a,a.b-b.b}; }
};

template<typename T1,typename T2,typename T3> struct vec3 {
    T1 a; T2 b; T3 c;
    friend bool operator < (const vec3& a,const vec3& b) {
        if (a.a!=b.a) return a.a<b.a;
        else if (a.b!=b.b) return a.b<b.b;
        else return a.c<b.c;
    }
    friend vec3 operator + (const vec3& a,const vec3& b) { return vec3{a.a+b.a,a.b+b.b,a.c+b.c}; }
    friend vec3 operator - (const vec3& a,const vec3& b) { return vec3{a.a-b.a,a.b-b.b,a.c-b.c}; }
};

template<typename T1,typename T2,typename T3,typename T4> struct vec4 {
    T1 a; T2 b; T3 c; T4 d;
    friend bool operator < (const vec4& a,const vec4& b) {
        if (a.a!=b.a) return a.a<b.a;
        else if (a.b!=b.b) return a.b<b.b;
        else if (a.c!=b.c) return a.c<b.c;
        else return a.d<b.d;
    }
    friend vec4 operator + (const vec4& a,const vec4& b) { return vec4{a.a+b.a,a.b+b.b,a.c+b.c,a.d+b.d}; }
    friend vec4 operator - (const vec4& a,const vec4& b) { return vec4{a.a-b.a,a.b-b.b,a.c-b.c,a.d-b.d}; }
};

template<typename T1,typename T2,typename T3,typename T4,typename T5> struct vec5 {
    T1 a; T2 b; T3 c; T4 d; T5 e;
    friend bool operator < (const vec5& a,const vec5& b) {
        if (a.a!=b.a) return a.a<b.a;
        else if (a.b!=b.b) return a.b<b.b;
        else if (a.c!=b.c) return a.c<b.c;
        else if (a.d!=b.d) return a.d<b.d;
        else return a.e<b.e;
    }
    friend vec5 operator + (const vec5& a,const vec5& b) { return vec5{a.a+b.a,a.b+b.b,a.c+b.c,a.d+b.d,a.e+b.e}; }
    friend vec5 operator - (const vec5& a,const vec5& b) { return vec5{a.a-b.a,a.b-b.b,a.c-b.c,a.d-b.d,a.e-b.e}; }
};

template<typename T1,typename T2,typename T3,typename T4,typename T5,typename T6> struct vec6 {
    T1 a; T2 b; T3 c; T4 d; T5 e; T6 f;
    friend bool operator < (const vec6& a,const vec6& b) {
        if (a.a!=b.a) return a.a<b.a;
        else if (a.b!=b.b) return a.b<b.b;
        else if (a.c!=b.c) return a.c<b.c;
        else if (a.d!=b.d) return a.d<b.d;
        else if (a.e!=b.e) return a.e<b.e;
        else return a.f<b.f;
    }
    friend vec6 operator + (const vec6& a,const vec6& b) { return vec6{a.a+b.a,a.b+b.b,a.c+b.c,a.d+b.d,a.e+b.e,a.f+b.f}; }
    friend vec6 operator - (const vec6& a,const vec6& b) { return vec6{a.a-b.a,a.b-b.b,a.c-b.c,a.d-b.d,a.e-b.e,a.f-b.f}; }
};

template<typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7> struct vec7 {
    T1 a; T2 b; T3 c; T4 d; T5 e; T6 f; T7 g;
    friend bool operator < (const vec7& a,const vec7& b) {
        if (a.a!=b.a) return a.a<b.a;
        else if (a.b!=b.b) return a.b<b.b;
        else if (a.c!=b.c) return a.c<b.c;
        else if (a.d!=b.d) return a.d<b.d;
        else if (a.e!=b.e) return a.e<b.e;
        else if (a.f!=b.f) return a.f<b.f;
        else return a.g<b.g;
    }
    friend vec7 operator + (const vec7& a,const vec7& b) { return vec7{a.a+b.a,a.b+b.b,a.c+b.c,a.d+b.d,a.e+b.e,a.f+b.f,a.g+b.g}; }
    friend vec7 operator - (const vec7& a,const vec7& b) { return vec7{a.a-b.a,a.b-b.b,a.c-b.c,a.d-b.d,a.e-b.e,a.f-b.f,a.g-b.g}; }
};

using pii=pair<int,int>;
using pdd=pair<double,double>;
using vii=vec2<int,int>;
using viii=vec3<int,int,int>;
using viiii=vec4<int,int,int,int>;
using viiiii=vec5<int,int,int,int,int>;
using viiiiii=vec6<int,int,int,int,int,int>;
using viiiiiii=vec7<int,int,int,int,int,int,int>;
using vi2=vii;
using vi3=viii;
using vi4=viiii;
using vi5=viiiii;
using vi6=viiiiii;
using vi7=viiiiiii;

i64 pw10[]={
    1LL,
    10LL,
    100LL,
    1000LL,
    10000LL,
    100000LL,
    1000000LL,
    10000000LL,
    100000000LL,
    1000000000LL,
    10000000000LL,
    100000000000LL,
    1000000000000LL,
    10000000000000LL,
    100000000000000LL,
    1000000000000000LL,
    10000000000000000LL,
    100000000000000000LL,
    1000000000000000000LL
};

class NullStream {
public:
    template<typename T> NullStream& operator << (const T&) { return *this; }
    inline NullStream& operator << (ostream& (*)(ostream&)) { return *this; }
    inline NullStream& operator << (ios_base& (*)(ios_base&)) { return *this; }
};

static NullStream null_stream;

#ifndef DEBUG
#define cerr null_stream
#define _debug(...) 42
#define __assert(c) 42
#else
inline void _debug_out() { cerr<<endl; }
template<typename A,typename... B> inline void _debug_out(A a,B... b) { cerr<<a<<" "; _debug_out(b...); }
#define _debug(...) cerr<<"["<<#__VA_ARGS__<<"]: ", _debug_out(__VA_ARGS__)
#define __assert(c) \
    do { \
        if (!(c)) { \
            cerr<<"Assertion failed: " #c<<" at "<<__FILE__<<":"<<__LINE__<<endl; \
            abort(); \
        } \
    } while (0)
#endif

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
i64 randint(i64 a,i64 b) {
    uniform_int_distribution<i64> dist(a,b);
    return dist(rnd);
}

namespace IO {
    template<typename T> inline void read(T& x) { int s=1; char c=getchar(); x=0; while (!isdigit(c)) { if (c=='-') s=-1; c=getchar(); } while (isdigit(c) && c!=EOF) x=x*10+(c-'0'),c=getchar(); x*=s; }
    inline void readstr(string& x) { x.clear(); char c=getchar(); while (isspace(c)) c=getchar(); while (!isspace(c) && c!=EOF) x.push_back(c),c=getchar(); }
    inline void readstr(char* x) { int idx=0; char c=getchar(); while (isspace(c)) c=getchar(); while (!isspace(c) && c!=EOF) x[idx++]=c,c=getchar(); x[idx]='\0'; }
    template<typename T> inline void write(T x) { if (x<0) putchar('-'),x=-x; if (x/10) write(x/10); putchar('0'+(x%10)); }
    template<typename T> inline void writesp(T x) { write(x); putchar(' '); }
    template<typename T> inline void writeln(T x) { write(x); putchar(10); }
    inline void writestr(const string& x) { _iter(it,x) putchar(*it); }
    inline void writestr(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); }
    inline void writestrsp(const string& x) { _iter(it,x) putchar(*it); putchar(' '); }
    inline void writestrsp(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); putchar(' '); }
    inline void writestrln(const string& x) { _iter(it,x) putchar(*it); putchar(10); }
    inline void writestrln(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); putchar(10); }
    template<typename T,typename... Args> inline void read(T& arg,Args&... args) { read(arg),read(args...); }
    template<typename T,typename... Args> inline void writesp(const T& arg,const Args&... args) { writesp(arg),writesp(args...); }
    template<typename T,typename... Args> inline void writeln(const T& arg,const Args&... args) { writeln(arg),writeln(args...); }
    template<typename T,typename... Args> inline void writespln(const T& arg,const Args&... args) { writesp(arg),writesp(args...),putchar(10); }
}

namespace IO2 {
    static const int buf_sz=1<<20;
    char *inbuf,*outbuf;
    char *inptr,*inend,*outptr;
    FILE *infile=stdin,*outfile=stdout;

    inline void flush_in() { size_t len=fread(inbuf,1,buf_sz,infile); inptr=inbuf; inend=inbuf+len; if (len<buf_sz) *inend='\0'; }
    inline void flush_out() { if (outptr==outbuf) return; fwrite(outbuf,1,outptr-outbuf,outfile); outptr=outbuf; }
    inline char get_char() { if (inptr>=inend) flush_in(); return *inptr++; }
    inline void put_char(char c) { if (outptr-outbuf>=buf_sz-1) flush_out(); *outptr++=c; }

    inline void init() { inbuf=new char[buf_sz]; outbuf=new char[buf_sz]; memset(inbuf,0,sizeof(char)*buf_sz); memset(outbuf,0,sizeof(char)*buf_sz); inbuf[0]=outbuf[0]='\0'; inptr=inend=inbuf; outptr=outbuf; }
    template<typename T> inline void read(T& x) { int s=1; char c=get_char(); x=0; while (!isdigit(c)) { if (c=='-') s=-1; c=get_char(); } while (isdigit(c) && c!=EOF) x=x*10+(c-'0'),c=get_char(); x*=s; }
    inline void readstr(string& x) { x.clear(); char c=get_char(); while (isspace(c)) c=get_char(); while (!isspace(c) && c!=EOF) x.push_back(c),c=get_char(); }
    inline void readstr(char* x) { int idx=0; char c=get_char(); while (isspace(c)) c=get_char(); while (!isspace(c) && c!=EOF) x[idx++]=c,c=get_char(); x[idx]='\0'; }
    template<typename T> inline void write(T x) { if (x<0) put_char('-'),x=-x; if (x/10) write(x/10); put_char('0'+(x%10)); }
    template<typename T> inline void writesp(T x) { write(x); put_char(' '); }
    template<typename T> inline void writeln(T x) { write(x); put_char(10); }
    inline void writestr(const string& x) { _iter(it,x) put_char(*it); }
    inline void writestr(char* x) { _rep(i,0,strlen(x)-1) put_char(x[i]); }
    inline void writestrsp(const string& x) { _iter(it,x) put_char(*it); put_char(' '); }
    inline void writestrsp(char* x) { _rep(i,0,strlen(x)-1) put_char(x[i]); put_char(' '); }
    inline void writestrln(const string& x) { _iter(it,x) put_char(*it); put_char(10); }
    inline void writestrln(char* x) { _rep(i,0,strlen(x)-1) put_char(x[i]); put_char(10); }
    template<typename T,typename... Args> inline void read(T& arg,Args&... args) { read(arg),read(args...); }
    template<typename T,typename... Args> inline void writesp(const T& arg,const Args&... args) { writesp(arg),writesp(args...); }
    template<typename T,typename... Args> inline void writeln(const T& arg,const Args&... args) { writeln(arg),writeln(args...); }
    template<typename T,typename... Args> inline void writespln(const T& arg,const Args&... args) { writesp(arg),writesp(args...),put_char(10); }
}

namespace Math {
    inline int gcd(int a,int b) { return (!b)?a:gcd(b,a%b); }
    inline int lcm(int a,int b) { return a/gcd(a,b)*b; }
    inline int exgcd(int a,int b,int& x,int& y) { if (!b) { x=1,y=0; return a; } int d=exgcd(b,a%b,y,x); y-=a/b*x; return d; }
    inline int inverse(int a) { int x,y; exgcd(a,mod,x,y); x=(x%mod+mod)%mod; return x; }
    inline int inverse(int a,int p) { int x,y; exgcd(a,p,x,y); x=(x%p+p)%p; return x; }
    inline int ksm(int a,int b) { if (!b) return 1; int k=ksm(a,b>>1); if (b&1) return (k*k%mod)*a%mod; else return k*k%mod; }
    inline int ksm(int a,int b,int mod) { if (!b) return 1; int k=ksm(a,b>>1,mod); if (b&1) return (k*k%mod)*a%mod; else return k*k%mod; }

    int idx;
    int* pri=nullptr;
    bool* flag=nullptr;
    int* mu=nullptr;
    int* phi=nullptr;

    inline void init_mul(bool fmu=false,bool fphi=false) {
        if (pri!=nullptr) delete[] pri;
        if (flag!=nullptr) delete[] flag;
        if (mu!=nullptr) delete[] mu;
        if (phi!=nullptr) delete[] phi;
        pri=new int[N];
        flag=new bool[N];
        if (fmu) mu=new int[N],memset(mu,0,sizeof(int)*N);
        if (fphi) phi=new int[N],memset(phi,0,sizeof(int)*N);
        memset(pri,0,sizeof(int)*N);
        memset(flag,0,sizeof(bool)*N);
        idx=0;
        if (fmu) mu[1]=1;
        if (fphi) phi[1]=1;
        _rep(i,2,N-1) {
            if (!flag[i]) {
                pri[++idx]=i;
                if (fmu) mu[i]=-1;
                if (fphi) phi[i]=i-1;
            }
            _rep(j,1,idx) {
                if (i*pri[j]>=N) break;
                flag[i*pri[j]]=true;
                if (i%pri[j]==0) {
                    if (fphi) phi[i*pri[j]]=phi[i]*pri[j];
                    break;
                }
                if (fphi) phi[i*pri[j]]=phi[i]*phi[pri[j]];
                if (fmu) mu[i*pri[j]]=-mu[i];
            }
        }
    }

    int* f=nullptr;
    int* g=nullptr;

    inline void init_fact() {
        if (f!=nullptr) delete[] f;
        if (g!=nullptr) delete[] g;
        f=new int[N];
        g=new int[N];
        f[0]=g[0]=1;
        _rep(i,1,N-1) f[i]=f[i-1]*i%mod;
        g[N-1]=inverse(f[N-1]);
        _rrep(i,N-2,1) g[i]=g[i+1]*(i+1)%mod;
    }

    inline int C(int n,int m) { return (f[n]*g[m]%mod)*g[n-m]%mod; }
    inline int A(int n,int m) { return f[n]*g[n-m]%mod; }

    inline bool millar_rabin(int n) {
        if (n==1) return false;
        else if (n%2==0) return n==2;
        else if (n%3==0) return n==3;
        int u=n-1,s=0;
        while (!(u&1)) u>>=1,s++;
        _rep(g,1,15) {
            int k=randint(2,n-2);
            k=ksm(k,u,n);
            if (k==1) continue;
            int t=0;
            while (t<s) {
                if (k==n-1) break;
                k=k*k%n;
                t++;
            }
            if (t==s) return false;
        }
        return true;
    }

    inline int pollard_rho(int n) {
        if (n%2==0) return 2;
        int x=0,y=0,c=randint(1,n-1);
        int t=1;
        while (true) {
            x=y;
            int prod=1;
            _rep(i,1,t) {
                y=(y*y+c)%n;
                prod=prod*labs(x-y)%n;
                if (i%127==0) {
                    int d=Math::gcd(prod,n);
                    if (d>1) return d;
                }
            }
            int d=Math::gcd(prod,n);
            if (d>1) return d;
            t<<=1;
        }
        return 42;
    }
}

template<typename BasicType,size_t n>
class BigInt {
public:
    BasicType* arr;

    BigInt(): arr(new BasicType[n]()) {}

    BigInt(const BigInt& oth): arr(new BasicType[n]) {
        copy(oth.arr,oth.arr+n,arr);
    }

    BigInt(BigInt&& oth) noexcept: arr(oth.arr) {
        oth.arr=nullptr;
    }

    BigInt& operator = (const BigInt& b) {
        if (this!=&b) copy(b.arr,b.arr+n,arr);
        return *this;
    }

    BigInt& operator = (BigInt&& b) noexcept {
        if (this!=&b) {
            delete[] arr;
            arr=b.arr;
            b.arr=nullptr;
        }
        return *this;
    }

    ~BigInt() {
        delete[] arr;
    }

    inline void swap(BigInt& oth) noexcept {
        swap(arr,oth.arr);
    }

    inline BasicType& operator [] (size_t pos) { return arr[pos]; }
    inline const BasicType& operator [] (size_t pos) const { return arr[pos]; }

    inline void print() const {
        bool st=false;
        _rrep(i,n-1,1) {
            if (!st && !arr[i]) continue;
            putchar('0'+arr[i]),st=true;
        }
        if (!st) putchar('0');
    }

    inline friend BigInt operator + (const BigInt& a,const BigInt& b) { BigInt<BasicType,n> c; int jw=0; _rep(i,1,n-1) c[i]=a[i]+b[i]+jw,jw=c[i]/10,c[i]%=10; return c; }
    inline friend BigInt operator + (const BigInt& a,int b) { BigInt<BasicType,n> c; int jw=b; _rep(i,1,n-1) c[i]=a[i]+jw,jw=c[i]/10,c[i]%=10; return c; }
    inline friend BigInt operator + (int b,const BigInt& a) { return a+b; }
    inline friend BigInt operator - (const BigInt& a,const BigInt& b) { BigInt<BasicType,n> c; int jw=0; _rep(i,1,n-1) { c[i]=a[i]-b[i]-jw; if (c[i]<0) c[i]+=10,jw=1; else jw=0; } return c; }
    inline friend BigInt operator - (const BigInt& a,int b) { BigInt<BasicType,n> c; int jw=b; _rep(i,1,n-1) { c[i]=a[i]-jw; if (c[i]<0) jw=(-c[i]/10+(bool)((-c[i])%10)),c[i]+=jw*10; else jw=0; } return c; }
    inline friend BigInt operator * (const BigInt& a,const BigInt& b) { BigInt<BasicType,n> c; _rep(i,1,n-1) _rep(j,1,n-i) c[i+j-1]+=a[i]*b[j]; int jw=0; _rep(i,1,n-1) c[i]+=jw,jw=c[i]/10,c[i]%=10; return c; }
    inline friend BigInt operator * (const BigInt& a,int b) { BigInt<BasicType,n> c; _rep(i,1,n-1) c[i]=a[i]*b; int jw=0; _rep(i,1,n-1) c[i]+=jw,jw=c[i]/10,c[i]%=10; return c; }
    inline friend BigInt operator * (int b,const BigInt& a) { return a*b; }
    inline friend BigInt operator / (const BigInt& a,int b) { BigInt<BasicType,n> c; int cur=0; _rrep(i,n-1,1) cur=cur*10+a[i],c[i]=cur/b,cur%=b; return c; }
    inline friend bool operator == (const BigInt& a,const BigInt& b) { _rrep(i,n-1,1) if (a[i]!=b[i]) return false; return true; }
    inline friend bool operator != (const BigInt& a,const BigInt& b) { return !(a==b); }
    inline friend bool operator < (const BigInt& a,const BigInt& b) { _rrep(i,n-1,1) { if (a[i]<b[i]) return true; else if (a[i]>b[i]) return false; } return false; }
    inline friend bool operator <= (const BigInt& a,const BigInt& b) { _rrep(i,n-1,1) { if (a[i]<b[i]) return true; else if (a[i]>b[i]) return false; } return true; }
    inline friend bool operator > (const BigInt& a,const BigInt& b) { _rrep(i,n-1,1) { if (a[i]<b[i]) return false; else if (a[i]>b[i]) return true; } return false; }
    inline friend bool operator >= (const BigInt& a,const BigInt& b) { _rrep(i,n-1,1) { if (a[i]<b[i]) return false; else if (a[i]>b[i]) return true; } return true; }
};

namespace Graph {
    int *e=nullptr,*ne=nullptr,*h=nullptr,*w=nullptr,*f=nullptr,*c=nullptr;
    int tot;
    
    inline void init_graph(bool flow=false) {
        if (e!=nullptr) delete[] e;
        if (ne!=nullptr) delete[] ne;
        if (h!=nullptr) delete[] h;
        if (w!=nullptr) delete[] w;
        if (f!=nullptr) delete[] f;
        if (c!=nullptr) delete[] c;
        e=new int[M];
        ne=new int[M];
        h=new int[N];
        w=new int[M];
        if (flow) f=new int[M],c=new int[M];
        memset(h,-1,sizeof(int)*N),tot=0;
    }

    inline void restore_graph() { memset(h,-1,sizeof(int)*N),tot=0; }
    inline void restore_graph(size_t n) { _rep(i,0,n) h[i]=-1; tot=0; }

    inline void add(int a,int b) { e[tot]=b,ne[tot]=h[a],h[a]=tot++; };
    inline void add(int a,int b,int c) { e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++; }
    inline void add_flow(int a,int b,int c) { e[tot]=b,f[tot]=c,ne[tot]=h[a],h[a]=tot++; e[tot]=a,f[tot]=0,ne[tot]=h[b],h[b]=tot++; }
    inline void add_flow(int a,int b,int F,int C) { e[tot]=b,f[tot]=F,c[tot]=C,ne[tot]=h[a],h[a]=tot++; e[tot]=a,f[tot]=0,c[tot]=-C,ne[tot]=h[b],h[b]=tot++; }

    namespace LCA {
        int *dep=nullptr,**f=nullptr;

        inline void init() { dep=new int[N]; f=new int*[N]; _rep(i,0,N-1) f[i]=new int[K],memset(f[i],0,sizeof(int)*K); memset(dep,0,sizeof(int)*N); }
        inline void restore() { memset(dep,0,sizeof(int)*N),memset(f,0,sizeof(int)*N); }
        inline void restore(size_t n) { _rep(i,0,n) { dep[i]=0; _rep(j,0,K-1) f[i][j]=0; } }

        inline void dfs(int u,int p,int d) {
            dep[u]=d;
            _graph(i,u) {
                if (e[i]==p) continue;
                f[e[i]][0]=u;
                _rep(j,1,K-1) f[e[i]][j]=f[f[e[i]][j-1]][j-1];
                dfs(e[i],u,d+1);
            }
        }

        inline int lca(int a,int b) {
            if (a==b) return a;
            if (dep[a]<dep[b]) swap(a,b);
            _rrep(i,K-1,0) if (dep[f[a][i]]>=dep[b]) a=f[a][i];
            if (a==b) return a;
            _rrep(i,K-1,0) if (f[a][i]!=f[b][i]) a=f[a][i],b=f[b][i];
            return f[a][0];
        }
    }

    namespace SP {
        int *dis=nullptr;
        bool *flag=nullptr;
        priority_queue<pii,vector<pii>,greater<pii>> q;

        inline void init() { dis=new int[N]; flag=new bool[N]; _rep(i,0,N-1) dis[i]=inf,flag[i]=false; }
        inline void restore() { _rep(i,0,N-1) dis[i]=inf,flag[i]=false; }
        inline void restore(size_t n) { _rep(i,0,n) dis[i]=inf,flag[i]=false; }

        inline void dijkstra(int s) {
            q.emplace(pii{dis[s]=0,s});
            while (!q.empty()) {
                auto tp=q.top(); q.pop();
                int u=tp.second;
                if (flag[u]) continue;
                flag[u]=true;
                _graph(i,u) if (dis[e[i]]>dis[u]+w[i]) q.emplace(pii{dis[e[i]]=dis[u]+w[i],e[i]});
            }
        }
    }

    namespace DINIC {
        int S,T;
        int *cur=nullptr,*dep=nullptr;

        inline void init() { S=T=0; cur=new int[N]; dep=new int[N]; memset(cur,0,sizeof(int)*N); memset(dep,0,sizeof(int)*N); }

        inline bool bfs() {
            queue<int> q;
            memset(dep,0,sizeof(int)*N);
            q.emplace(S),cur[S]=h[S],dep[S]=1;
            while (!q.empty()) {
                int u=q.front(); q.pop();
                _graph(i,u) {
                    if (!dep[e[i]] && f[i]) {
                        dep[e[i]]=dep[u]+1;
                        cur[e[i]]=h[e[i]];
                        if (e[i]==T) return true;
                        q.emplace(e[i]);
                    }
                }
            }
            return false;
        }

        inline int dfs(int u,int limit) {
            if (u==T) return limit;
            int k=0;
            _dinic(i,u) {
                cur[u]=i;
                if (dep[e[i]]==dep[u]+1 && f[i]) {
                    int ret=dfs(e[i],min(f[i],limit-k));
                    f[i]-=ret,f[i^1]+=ret,k+=ret;
                    if (!ret) dep[e[i]]=0;
                }
            }
            return k;
        }

        inline int dinic() {
            int ans=0,k;
            while (bfs()) while (k=dfs(S,inf)) ans+=k;
            return ans; 
        }
    }

    namespace MCMF {
        int S,T;
        int *dis=nullptr,*flow=nullptr,*bk=nullptr;
        bool *flag=nullptr;

        inline void init() { S=T=0; dis=new int[N]; flow=new int[N]; bk=new int[N]; flag=new bool[N]; _rep(i,0,N-1) dis[i]=flow[i]=inf; memset(bk,0,sizeof(int)*N); memset(flag,0,sizeof(bool)*N); }
        inline void restore() { S=T=0; _rep(i,0,N-1) dis[i]=inf,flow[i]=inf,bk[i]=flag[i]=0; }
        inline void restore(size_t n) { S=T=0; _rep(i,0,n) dis[i]=inf,flow[i]=inf,bk[i]=flag[i]=0; }
    
        inline bool spfa() {
            _rep(i,0,N-1) dis[i]=inf,flow[i]=inf,bk[i]=flag[i]=0;
            queue<int> q;
            q.emplace(S),dis[S]=0,flag[S]=true;
            while (!q.empty()) {
                int u=q.front(); q.pop(),flag[u]=false;
                _graph(i,u) {
                    if (dis[e[i]]>dis[u]+c[i] && f[i]) {
                        dis[e[i]]=dis[u]+c[i];
                        flow[e[i]]=min(flow[u],f[i]);
                        bk[e[i]]=i;
                        if (!flag[e[i]]) q.emplace(e[i]),flag[e[i]]=true;
                    }
                }
            }
            return dis[T]!=inf;
        }

        inline pii solve() {
            int F=0,C=0;
            while (spfa()) {
                F+=flow[T];
                int u=T;
                while (u!=S) {
                    int i=bk[u];
                    f[i]-=flow[T],f[i^1]+=flow[T];
                    C+=c[i]*flow[T];
                    u=e[i^1];
                }
            }
            return pii{F,C};
        }
    }
}

template<
    class ValueType,
    void (*UP) (ValueType&,ValueType&,ValueType&),
    void (*DOWN) (ValueType&,ValueType&,ValueType&),
    class ModifyType,
    void (*MODIFY) (ValueType&,const ModifyType&),
    int base=1
>
class SEG {
public:
    ValueType *tr=nullptr; // must contain member 'l' and 'r'

    SEG() {}
    SEG(size_t N) { tr=new ValueType[N<<2](); build(1,base,N); }
    ~SEG() { delete[] tr; }
    SEG(const SEG&)=delete;
    SEG& operator=(const SEG&)=delete;

    inline void reserve(size_t N) {
        if (tr!=nullptr) delete[] tr;
        tr=new ValueType[N<<2]();
        build(1,base,N);
    }

    inline void pushup(int u) { if (UP!=nullptr) UP(tr[u],tr[u<<1],tr[u<<1|1]); }
    inline void pushdown(int u) { auto& root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1]; if (DOWN!=nullptr) DOWN(root,left,right); }

    inline void build(int u,int l,int r) {
        tr[u].l=l,tr[u].r=r;
        if (l==r) return;
        int mid=l+r>>1;
        build(u<<1,l,mid); build(u<<1|1,mid+1,r);
        pushup(u);
    }

    inline void modify(int u,int l,int r,const ModifyType& k) {
        if (tr[u].l>=l && tr[u].r<=r) {
            if (MODIFY!=nullptr) MODIFY(tr[u],k);
        } else {
            pushdown(u);
            int mid=tr[u].l+tr[u].r>>1;
            if (l<=mid) modify(u<<1,l,r,k);
            if (r>mid) modify(u<<1|1,l,r,k);
            pushup(u);
        }
    }

    inline ValueType query(int u,int l,int r) {
        if (tr[u].l>=l && tr[u].r<=r) return tr[u];
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        ValueType ans,L,R;
        if (l<=mid) L=query(u<<1,l,r);
        if (r>mid) R=query(u<<1|1,l,r);
        if (UP!=nullptr) UP(ans,L,R);
        return ans;
    }
};

template<
    class ValueType,
    void (*UP) (ValueType&,ValueType&,ValueType&),
    void (*DOWN) (ValueType&,ValueType&,ValueType&),
    class ModifyType,
    void (*MODIFY) (ValueType&,const ModifyType&),
    bool (*CHECK_DELETE) (ValueType&)
>
class DSEG {
public:
    ValueType *tr=nullptr; // must contain member 'l' and 'r'
    int *memPool=nullptr;
    size_t idx=0;

    DSEG() {}
    DSEG(size_t N) { tr=new ValueType[N](); memPool=new int[N]; idx=0; _rrep(i,N-1,1) memPool[++idx]=i; }
    ~DSEG() { delete[] tr; }
    DSEG(const DSEG&)=delete;
    DSEG& operator=(const DSEG&)=delete;

    inline void reserve(size_t N) {
        if (tr!=nullptr) delete[] tr;
        if (memPool!=nullptr) delete[] memPool;
        tr=new ValueType[N]();
        memPool=new int[N];
        idx=0;
        _rrep(i,N-1,1) memPool[++idx]=i;
    }

    inline int newNode() { int u=memPool[idx--]; return u; }
    inline void deleteNode(int u) { memset(tr[u],0,sizeof(tr[u])); memPool[++idx]=u; }
    inline void pushup(int u) { if (UP!=nullptr) UP(tr[u],tr[tr[u].l],tr[tr[u].r]); }
    inline void pushdown(int u) { if (DOWN!=nullptr) DOWN(tr[u],tr[tr[u].l],tr[tr[u].r]); }

    inline void modify(int& u,int l,int r,int L,int R,const ModifyType& k) {
        if (!u) u=newNode();
        if (L>=l && R<=r) {
            if (MODIFY!=nullptr) MODIFY(tr[u],k);
        } else {
            pushdown(u);
            int mid=L+R>>1;
            if (L<=mid) modify(tr[u].l,l,r,L,mid,k);
            if (R>mid) modify(tr[u].r,l,r,mid+1,R,k);
            pushup(u);
            if (CHECK_DELETE!=nullptr && CHECK_DELETE(tr[u])) deleteNode(u),u=0;
        }
    }

    inline ValueType query(int u,int l,int r,int L,int R) {
        if (!u) {
            ValueType v{};
            return v;
        }
        if (L>=l && R<=r) return tr[u];
        pushdown(u);
        int mid=L+R>>1;
        ValueType ans,ll,rr;
        if (l<=mid) ll=query(tr[u].l,l,r,L,mid);
        if (r>mid) rr=query(tr[u].r,l,r,mid+1,R);
        if (UP!=nullptr) UP(ans,ll,rr);
        return ans;
    }
};

template<class ValueType>
class BIT {
public:
    size_t n=0;
    ValueType *tr=nullptr;

    BIT() {}
    BIT(size_t n) { tr=new ValueType[n]; memset(tr,0,sizeof(ValueType)*n); this->n=n; }
    ~BIT() { delete[] tr; }
    BIT(const BIT&)=delete;
    BIT& operator=(const BIT&)=delete;

    inline void reserve(size_t n) { if (tr!=nullptr) delete[] tr; tr=new ValueType[n]; memset(tr,0,sizeof(ValueType)*n); this->n=n; }
    inline void modify(int x,ValueType k) { while (x<=n) tr[x]=tr[x]+k,x+=lowbit(x); }
    inline ValueType query(int x) { ValueType ans=0; while (x) ans=ans+tr[x],x-=lowbit(x); return ans; }

    inline void modify_xor(int x,ValueType k) { while (x<=n) tr[x]=(tr[x]^k),x+=lowbit(x); }
    inline ValueType query_xor(int x) { ValueType ans=0; while (x) ans=(ans^tr[x]),x-=lowbit(x); return ans; }
};

class DSU {
public:
    size_t n=0;
    int *p=nullptr;
    void (*MERGE)(int,int)=nullptr; // x <- y

    DSU() {}
    DSU(size_t n) { p=new int[n]; _rep(i,0,n-1) p[i]=i; this->n=n; }
    DSU(void (*fp)(int,int)=nullptr): MERGE(fp) {}
    DSU(size_t n,void (*fp)(int,int)=nullptr): MERGE(fp) { p=new int[n]; _rep(i,0,n-1) p[i]=i; this->n=n; }
    ~DSU() { delete[] p; }
    DSU(const DSU&)=delete;
    DSU& operator=(const DSU&)=delete;

    inline void reserve(size_t n) { if (p!=nullptr) delete[] p; p=new int[n]; _rep(i,0,n-1) p[i]=i; this->n=n; }
    inline int find(int x) { return (p[x]==x)?p[x]:(p[x]=find(p[x])); }
    inline bool connected(int x,int y) { return find(x)==find(y); }
    inline void merge(int x,int y) {
        x=find(x),y=find(y);
        if (MERGE!=nullptr) MERGE(x,y);
        p[find(y)]=find(x);
    }
};

template<
    typename ValueType,
    void (*UP) (ValueType&,ValueType&,ValueType&),
    void (*DOWN) (ValueType&,ValueType&,ValueType&)
>
class Splay {
public:
    size_t n=0;
    ValueType *tr=nullptr; // must contain member 'p','s[2]','sz'
    int root=0,idx=0;

    Splay() {}
    Splay(size_t n) { this->n=n; tr=new ValueType[n](); }
    ~Splay() { delete[] tr; }
    Splay(const Splay&)=delete;
    Splay operator=(const Splay&)=delete;
    
    inline void reserve(size_t n) { if (tr!=nullptr) delete[] tr; tr=new ValueType[n](); this->n=n; root=idx=0; }
    inline void pushup(int u) { if (UP!=nullptr) UP(tr[u],tr[tr[u].l],tr[tr[u].r]); }
    inline void pushdown(int u) { if (DOWN!=nullptr) DOWN(tr[u],tr[tr[u].l],tr[tr[u].r]); }
    
    inline void rotate(int x) {
        int y=tr[x].p;
        int z=tr[y].p;
        int k=tr[y].s[1]==x;
        if (z) tr[z].s[tr[z].s[1]==y]=x;
        tr[x].p=z;
        tr[y].s[k]=tr[x].s[k^1],tr[tr[x].s[k^1]].p=y;
        tr[x].s[k^1]=y,tr[y].p=x;
        pushup(y);
        pushup(x);
    }

    inline void splay(int x,int k) {
        int y=x;
        stack<int> stk;
        while (y) stk.emplace(y),y=tr[y].p;
        while (!stk.empty()) pushdown(stk.top()),stk.pop();
        while (tr[x].p!=k) {
            int y=tr[x].p;
            int z=tr[y].p;
            if (z!=k) {
                if ((tr[z].s[1]==y)^(tr[y].s[1]==x)) rotate(x);
                else rotate(y);
            }
            rotate(x);
        }
        if (!k) root=x;
    }

    inline int getk(int k) {
        int u=root;
        while (u) {
            pushdown(u);
            if (k<=tr[tr[u].s[0]].sz) u=tr[u].s[0];
            else if (k==tr[tr[u].s[0]].sz+1) return u;
            else k-=tr[tr[u].s[0]].sz+1,u=tr[u].s[1];
        }
        return -1;
    }
};

namespace Convolution {
    const int G=3;

    inline void ntt(vector<int>& a,bool inv) {
        int n=a.size();
        int j=0;
        _rep(i,0,n-1) {
            if (i<j) swap(a[i],a[j]);
            int k=n>>1;
            while ((j^=k)<k) k>>=1;
        }
        _reps(len,2,n,len<<=1) {
            int l=Math::ksm(G,(mod-1)/len);
            if (inv) l=Math::inverse(l);
            _reps(i,0,n-1,i+=len) {
                int w=1;
                _rep(j,0,(len>>1)-1) {
                    int L=a[i+j]%mod,R=a[i+j+(len>>1)]*w%mod;
                    a[i+j]=(L+R)%mod;
                    a[i+j+(len>>1)]=(L-R+mod)%mod;
                    w=w*l%mod;
                }
            }
        }
        if (inv) {
            int v=Math::inverse(n);
            _rep(i,0,n-1) a[i]=a[i]*v%mod;
        }
    }

    vector<int> solve(vector<int>& a,vector<int>& b) {
        int sz=a.size()+b.size()-1;
        int n=1;
        while (n<sz) n<<=1;
        a.resize(n);
        b.resize(n);
        ntt(a,false);
        ntt(b,false);
        _rep(i,0,n-1) a[i]=a[i]*b[i]%mod;
        ntt(a,true);
        a.resize(sz);
        return a;
    }
}

template<typename T>
class Deque {
private:
    struct node {
        T value;
        node *prev;
        node *next;
    } *head,*tail;
    int length;

public:
    Deque(): head(nullptr),tail(nullptr),length(0) {}
    ~Deque() { clear(); }

    Deque(const Deque& oth): head(nullptr),tail(nullptr),length(0) {
        node* curr=oth.head;
        while (curr) {
            emplace(curr->value);
            curr=curr->next;
        }
    }

    Deque& operator = (const Deque& oth) {
        if (this!=&oth) {
            clear();
            node* curr=oth.head;
            while (curr) {
                emplace(curr->value);
                curr=curr->next;
            }
        }
        return *this;
    }

    Deque(Deque&& oth) noexcept: head(oth.head),tail(oth.tail),length(oth.length) {
        oth.head=nullptr;
        oth.tail=nullptr;
        oth.length=0;
    }

    Deque& operator = (Deque&& oth) noexcept {
        if (this!=&oth) {
            clear();
            head=oth.head;
            tail=oth.tail;
            length=oth.length;
            oth.head=nullptr;
            oth.tail=nullptr;
            oth.length=0;
        }
        return *this;
    }

    inline void swap(Deque& oth) noexcept {
        swap(head,oth.head);
        swap(tail,oth.tail);
        swap(length,oth.length);
    }

    inline bool empty() const { return head==nullptr; }
    inline void clear() { while (!empty()) { node* tmp=head; head=head->next; delete tmp; } tail=nullptr; length=0; }
    inline size_t size() const { return length; }
    inline T& front() { if (empty()) __assert(false); return head->value; }
    inline T& back() { if (empty()) __assert(false); return tail->value; }

    inline void emplace_front(const T& value) {
        node* u=new node{value,nullptr,head};
        if (empty()) tail=u;
        else head->prev=u;
        head=u;
        ++length;
    }

    inline void emplace_back(const T& value) {
        node* u=new node{value,tail,nullptr};
        if (empty()) head=u;
        else tail->next=u;
        tail=u;
        ++length;
    }

    template<typename... S> inline void emplace_front(const T& v1,const S&... v2) { emplace_front(v1),emplace_front(v2...); }
    template<typename... S> inline void emplace_back(const T& v1,const S&... v2) { emplace_back(v1),emplace_back(v2...); }

    inline T pop_front() {
        if (empty()) __assert(false);
        T value=head->value;
        node* tmp=head;
        head=head->next;
        delete tmp;
        if (head==nullptr) tail=nullptr;
        else head->prev=nullptr;
        --length;
        return value;
    }

    inline T pop_back() {
        if (empty()) __assert(false);
        T value=tail->value;
        node* tmp=tail;
        tail=tail->prev;
        delete tmp;
        if (tail==nullptr) head=nullptr;
        else tail->next=nullptr;
        --length;
        return value;
    }

    class Iterator {
    private:
        node* curr;

    public:
        Iterator(node* u): curr(u) {}

        T& operator * () { return curr->value; }
        Iterator& operator ++ () { if (curr) curr=curr->next; return *this; }
        Iterator operator ++ (signed) { Iterator tmp=*this; ++(*this); return tmp; }
        bool operator == (const Iterator& oth) const { return curr==oth.curr; }
        bool operator != (const Iterator& oth) const { return curr!=oth.curr; }
    };

    class ConstIterator { 
    private:
        const node* curr;

    public:
        ConstIterator(const node* u): curr(u) {}

        const T& operator * () const { return curr->value; }
        ConstIterator& operator ++ () { if (curr) curr=curr->next; return *this; }
        ConstIterator operator ++ (signed) { ConstIterator tmp=*this; ++(*this); return tmp; }
        bool operator == (const ConstIterator& oth) const { return curr==oth.curr; }
        bool operator != (const ConstIterator& oth) const { return curr!=oth.curr; }
    };

    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }
    ConstIterator cbegin() const { return ConstIterator(head); }
    ConstIterator cend() const { return ConstIterator(nullptr); }
};

using namespace IO;

int fac[N],invfac[N];

int ksm(int a,int b) {
    int res=1;
    while (b) {
        if (b&1) res=1ll*res*a%mod;
        a=1ll*a*a%mod;
        b>>=1;
    }
    return res;
}

void init_fac(int n) {
    fac[0]=1;
    _rep(i,1,n) fac[i]=1ll*fac[i-1]*i%mod;
    invfac[n]=ksm(fac[n],mod-2);
    _rrep(i,n-1,0) invfac[i]=1ll*invfac[i+1]*(i+1)%mod;
}

int C(int n,int m) {
    if (m<0 || m>n) return 0;
    return 1ll*fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}

void fwht(vector<int>& a,bool inv) {
    int n=a.size();
    _reps(len,2,n,len<<=1) {
        _reps(i,0,n-1,i+=len) {
            _rep(j,0,(len>>1)-1) {
                int u=a[i+j],v=a[i+j+(len>>1)];
                a[i+j]=(u+v)%mod;
                a[i+j+(len>>1)]=(u-v+mod)%mod;
            }
        }
    }
    if (inv) {
        int inv_n=ksm(n,mod-2);
        _rep(i,0,n-1) a[i]=1ll*a[i]*inv_n%mod;
    }
}

void solve() {
    int n,k;
    read(n,k);
    vector<int> a(n);
    int max_val=0;
    _rep(i,0,n-1) {
        read(a[i]);
        chmax(max_val,a[i]);
    }
    
    vector<int> cnt(max_val+1,0);
    _rep(i,0,n-1) cnt[a[i]]++;
    
    int size=1;
    while (size<=max_val) size<<=1;
    
    // 预处理每个cnt值的二项式系数
    // coeff[c][j] = C(c, j)，c是出现次数
    int max_cnt=n;
    vector<vector<int>> coeff(max_cnt+1,vector<int>(k+1,0));
    _rep(c,0,max_cnt) {
        _rep(j,0,min(k,c)) coeff[c][j]=C(c,j);
    }
    
    // 在时域做DP，但利用不同cnt值可能重复来优化
    // dp[mask][j]：当前异或和为mask，选了j个的方案数
    vector<vector<int>> dp(size,vector<int>(k+1,0));
    dp[0][0]=1;
    
    _rep(v,0,max_val) {
        int c=cnt[v];
        if (!c) continue;
        
        auto ndp=dp;
        _rep(mask,0,size-1) {
            // 优化：如果dp[mask]全为0则跳过
            bool has=false;
            _rep(j,0,k) if (dp[mask][j]) { has=true; break; }
            if (!has) continue;
            
            _rep(old_j,0,k) {
                int val=dp[mask][old_j];
                if (!val) continue;
                _rep(add_j,1,min(k-old_j,c)) {
                    int new_mask=mask;
                    if (add_j&1) new_mask^=v;
                    ndp[new_mask][old_j+add_j]=(ndp[new_mask][old_j+add_j]+
                        1ll*val*coeff[c][add_j])%mod;
                }
            }
        }
        dp=move(ndp);
    }
    
    writeln(dp[0][k]);
}

i32 main() {
    init_fac(1000000);
    int T;
    read(T);
    while (T--) solve();
    return 0;
}