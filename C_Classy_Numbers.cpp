/* :) */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define cin(v) for(auto &i:v){cin>>i;}
#define cout(v) for(auto i:v){cout<<i<<" ";}cout<<endl;
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define endl "\n"
#define pb push_back
#define tolower(s1) transform(s1.begin(), s1.end(), s1.begin(),::tolower)
#define toupper(s1) transform(s1.begin(), s1.end(), s1.begin(), ::toupper)
#define upperbound(v1, k) upper_bound(v1.begin(), v1.end(), k)-v1.begin()
#define lowerbound(v1, k) lower_bound(v1.begin(), v1.end(), k)-v1.begin()
#define lcm(a,b) ((a)/(__gcd(a,b))*(b))
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

const int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};
const int MOD = 1e9 + 7, MX = 1e18, MN = -1e18, N = 5e5 + 10;
vector<long long> fact(N), invfact(N);

//-------------------Some imp funtion ---------------------------------------------------------

int binexp(int a, int b) { int r = 1; while (b) r *= (b & 1) ? a : 1, a *= a, b >>= 1; return r; }
int binpow(int a, int b, int m) { int r = 1; for (a %= m; b; b >>= 1, a = 1LL * a * a % m) if (b & 1) r = 1LL * r * a % m; return r; }
int modinv(int a, int m) { return binpow(a, m - 2, m); }
void precompute_factorials() { fact[0] = invfact[0] = 1; for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * i % MOD, invfact[i] = binpow(fact[i], MOD - 2, MOD); }
long long nCr(int n, int r) { return (r < 0 || r > n) ? 0 : fact[n] * invfact[r] % MOD * invfact[n - r] % MOD; }
vector<int> sieve(int n) { vector<int> p, is(n + 1, 1); is[0] = is[1] = 0; for (int i = 2; i <= n; i++) if (is[i]) { p.push_back(i); for (int j = i * i; j <= n; j += i) is[j] = 0; } return p; }
vector<int> prime_factors(int n) { vector<int> f; for (int i = 2; i * i <= n; i++) while (n % i == 0) f.push_back(i), n /= i; if (n > 1) f.push_back(n); return f; }
// ---------------------------------------------------------------------------------------------
//Problem Classy Number Codeforces 1036C
//-------------------less gooo-----------------------------------------------------------------
int dp[20][20][2];

int solve(string &s,int idx,int tight,int cnt){
    if(cnt>3) return 0; // as we need atmost 3 non zero digits in the number
    if(idx == s.size()) return 1; // base case that we got one number finally
    if(dp[idx][cnt][tight]!=-1) return dp[idx][cnt][tight]; // if already has this dp state just return that
    int limit = tight? s[idx]-'0' : 9; // setting up limit for the loop
    int ans = 0;
    for(int i=0;i<=limit;i++){
        int updateCnt = cnt + (i!=0); // if we are picking up a non zero digit increate the count..
        ans += solve(s,idx+1,tight&(i==limit),updateCnt);
    }
    return dp[idx][cnt][tight] = ans;
}

void solve() {
    int l,r;
    cin>>l>>r;
    memset(dp,-1,sizeof(dp));
    string right = to_string(r);
    int rans= solve(right,0,1,0);
    memset(dp,-1,sizeof(dp));
    string left = to_string(l-1);
    int lans = solve(left,0,1,0);
    cout<<rans-lans<<endl;
}

signed main(){
    auto begin = std::chrono::high_resolution_clock::now();
    fast
    int tc=1;
    cin>>tc;
    while(tc--){solve();}
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}