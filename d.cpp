/* 

    ॐ हौं जूं सः ॐ भूर्भुवः स्वः 
    ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् उर्वारुकमिव बन्धनान्मृत्योर्मुक्षीय मामृतात् 
    ॐ स्वः भुवः भूः ॐ सः जूं हौं ॐ

   @Author  : Akshat Madhavan
   @Country : INDIA 
   
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()

#ifdef AKSHAT
#include "debug.h"
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif


template<class T>void output (vector<T> &a) {for (auto &x : a) {cout << x << ' ';}cout << '\n';}
template<typename T> void chmin (T &a, T b) {if (a > b) swap(a, b);}
template<typename T> void chmax (T &a, T b) {if (a < b) swap(a, b);}



int brute(int n, int k, string s) {
    auto k_proper = [&] (string t) ->bool {
        int l, r ;
        for (l = 0, r = 0; r + 1 < n; ++r) {
            if (t[r] != t[r + 1]) {
                if ((r - l + 1) != k) {
                    return 0;
                } else {
                    l = r + 1;
                }
            }
        }
        return (r - l + 1) == k;
    };

    auto can = [&] (int p) ->bool {
        string new_s;
        for (int i = p + 1; i < n; ++i)
            new_s += s[i];
        for (int i = p; i >= 0; --i) {
            new_s += s[i];
        }
        return k_proper(new_s);
    };

    for (int i = 0; i < n; ++i) {
        if (can(i)) {
            return i + 1;
        }
    }

    return -1;
}
void solve() {
    int n, k;
    cin >> n >> k;


    string s;
    cin >> s;


    auto k_proper = [&] (string t) ->bool {
        int l, r;
        for (l = 0, r = 0; r + 1 < n; ++r) {
            if (t[r] != t[r + 1]) {
                if ((r - l + 1) != k) {
                    return 0;
                } else {
                    l = r + 1;
                }
            }
        }
        return (r - l + 1) == k;
    };

    auto can = [&] (int p) ->bool {
        string new_s;
        for (int i = p + 1; i < n; ++i)
            new_s += s[i];
        for (int i = p; i >= 0; --i) {
            new_s += s[i];
        }
        return k_proper(new_s);
    };

    if (k_proper(s)) {
        cout << n << "\n";
        return;
    }

    int need = k, r = n - 1;

    while (r > 0 && need > 0 && s[r] == s[n - 1])
        r--, need--;

    int lst = -1, lk = -1;
    for (int l = 0, r = 0; r + 1 < n; ++r) {
        if (s[r] != s[r + 1]) {
            if ((r - l + 1) == need) {
                lk = (lk == -1 ? r : lk);
            }
            if ((r - l + 1) > k) {
                lst = r;
                break;
            } else {
                l = r + 1;
            }
        }
    }


    if (lst != -1) {
        cout << (can(lst - k) ? lst - k + 1 : -1) << "\n";
        return;
    }

    cout << (lk != -1 && can(lk) ? lk + 1 : -1) << "\n";
} 


int32_t main() {
    
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    #ifdef AKSHAT   
        freopen("error.txt", "w", stderr);  
    #endif  

    int tc = 1;
    cin >> tc;
    for (int cases = 1; cases <= tc; ++cases) {
        solve();
        // cout << (solve() ? "YES\n" : "NO\n");
        // cout << "Case # " << cases;
    } 

    #ifdef AKSHAT
        double timeTaken = 1000.0 * clock() / CLOCKS_PER_SEC;
        cout << "\n[Finished in " << timeTaken << "ms]";
        cerr << "\n[Finished in " << timeTaken << "ms]";
    #endif

    return 0;
}

//JAI SHREE RAM !!!!
