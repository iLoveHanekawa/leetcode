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
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        auto lps = [&] () {
            vector<int> v(n);
            v[0] = nums[0];
            for(int i = 1; i < n; i++) {
                v[i] = v[i - 1] + nums[i];
            }
            return v;
        };

        auto rps = [&] () {
            vector<int> v(n);
            v[n - 1] = nums[n - 1];
            for(int i = n - 2; i > -1; i--) {
                v[i] = v[i + 1] + nums[i];
            }
            return v;
        };

        vector<int> lv = lps(), rv = rps();

        auto lpsm = [&] () {
            vector<pair<int, int>> v(n);
            v[0] = { nums[0], 0 };
            for(int i = 1; i < n; i++) {
                if(v[i - 1].first > lv[i]) {
                    v[i] = {lv[i], i};
                }
                else {
                    auto [x, y] = v[i - 1];
                    v[i] = { x, y };
                }
            }
            return v;
        };
            
        auto rpsm = [&] () {
            vector<pair<int, int>> v(n);
            v[n - 1] = { nums[n - 1], n - 1 };
            for(int i = n - 2; i > -1; i--) {
                if(v[i + 1].first > rv[i]) {
                    v[i] = {rv[i], i};
                }
                else {
                    auto [x, y] = v[i + 1];
                    v[i] = { x, y };
                }
            }
            return v;
        };

        vector<pair<int, int>> lvm = lpsm(), rvm = rpsm();

        int sum = accumulate(nums.begin(), nums.end(), 0);
        int sol = max(sum, *max_element(nums.begin(), nums.end()));
        for(int i = 1; i < n - 1; i++) {
            int add = 0;
            if(lvm[i - 1].second == 0 && lvm[i - 1].first > 0) add += nums[0];
            if(rvm[i + 1].second == n - 1 && rvm[i + 1].first > 0) add += nums[n - 1];

            sol = max(sol, sum + add - (lvm[i - 1].first + rvm[i + 1].first));
        };
        
        return sol;
    }
};

void solve() {
    Solution x = Solution();
    vector<int> v = { 8, -19, 5, -4, 20};
    cout << x.maxSubArray(v);
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