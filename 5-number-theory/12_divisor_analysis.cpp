#include<bits/stdc++.h>

using namespace std;

#define ll long long
const ll mod = 1e9 + 7;
const ll mod2= 1e9+6;


ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m

void solve() {
    ll n;
    cin >> n;
    vector<ll>prime(n), power(n);
    for (int i = 0; i < n; i++) {
        cin >> prime[i] >> power[i];
    }

    //number of divisors
    ll ans1 = 1;
    for (int i = 0; i < n; i++) {
        ans1 *= (power[i] + 1);
        ans1 %= mod;
    }
    cout << ans1 << " ";

    //sum of divisors
    ll ans2 = 1;
    for (int i = 0; i < n; i++) {
        ll num = expo(prime[i], power[i] + 1, mod);
        num = (num - 1 + mod) % mod;
        ll deno = prime[i] - 1;
        ans2 *= mod_div(num, deno, mod);
        ans2 %= mod;
    }
    cout << ans2 << " ";

    //product of divisors
    
    ll num = 1; ll pro = 1;
    for(int i=0;i<n;i++){
        pro = expo(pro,(power[i]+1),mod);
        ll temp = (power[i]*(power[i]+1))/2;
        ll base = expo(prime[i],temp,mod);
        ll val = expo(base,num,mod);
        pro*=val;
        pro%=mod;
        num*=(power[i]+1);
        num%=mod2;
    }
    cout<<pro<<" ";


}

int main()
{

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}