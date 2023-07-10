#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#define PR(x) cout << #x": " << x << "\t";
#define vPR(v) for(auto i: v) {cout << i << " ";} cout << endl;
#define vvPR(v) for(auto i: v){ for(auto j: i) cout << j << " "; cout << endl;}
inline void cflag(string s){cout << s << endl;}
#define en cout << endl;		
#define ll long long
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define defMethod(i) (i*i)

//---------------------------------------

class Solution {
public:

    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> prefix(n, 0);
        for(int i = 1; i < n; i++) {
            prefix[i] = nums[n - 1] -  nums[n - i - 1] + prefix[i - 1];
        }
        int sol = 0;
        reverse(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            long long diff = i - 1 >= 0? diff = prefix[i] - prefix[i - 1]: 0;
            auto comp = [&](const long long& a, const long long& b) {
                int index = &a - &prefix[0];
                return a - prefix[i] - (diff * (index - i)) <= b;
            };
            int maxI = lower_bound(prefix.begin() + i + 1, prefix.end(), k, comp) - prefix.begin() - i;
            sol = max(sol, maxI);
        }
        return sol;
    }
};

void solve() {
    
}

int main() {
    sync;
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}

//---------------------------------------

/*
NOTE TO SELF/READER:	
••••••••••••••••••••••••••••••••
•be careful with bounds.
•be careful with special/edge cases (n=1, n=0).
•watch out for leaking(%M).
•watch out for declaration of memory in excess
•declare large arrays in heap
•be careful using arrays with n>1 dimensions (wrt memory limit)
•in large arrays, maybe ll could suffice where youre using long long(for runtime error)
•think while afk during practice: stay productive afk. 
•its better if you always have a problem to think about when youre taking breaks.
•write down new things right as you learn about them.

NOTE TO ANANYA:
••••••••••••••••••••••••••••
I really adore you, and I know you really like hearing it from me. 
Oh jaan how terribly I've missed you.
Just know that im always thinking of you, no matter what I do..
*/

/*
*/