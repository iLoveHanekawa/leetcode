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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    string processThis(ListNode* x) {
        string s;
        while(x != nullptr) {
            s.push_back(char(x->val + 48));
            x = x->next;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    int add(char x, char y, int& carry) {
        cout << x << ' ' << y << ' ' << carry << endl;
        int a = (int) x - 48, b = (int) y - 48;
        int c = a + b + carry;
        if(c > 9) {
            carry = 1;
            return c - 10;
        }
        carry = 0;
        return c;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        string a = processThis(l1), b = processThis(l2);
        if(a.length() < b.length()) swap(a, b);
        int an = a.length(), bn = b.length();
        vector<int> v;
        v.reserve(100);
        string addMe = string(an - bn, '0');
        b = addMe + b;
        for(int i = an - 1; i > -1; i--) {
            v.push_back(add(a[i], b[i], carry));
        }
        if(carry != 0) v.push_back(carry);
        reverse(v.begin(), v.end());
        auto print = [&] () {
            for(auto i: v) cout << i << ' ';
            cout << endl;
        };

        ListNode* sol = new ListNode(v[0]);
        for(int i = 1; i < (int) v.size(); i++) {
            ListNode *z = new ListNode(v[i], sol);
            sol = z;
        }
        
        return sol;
    }
};

void solve() {
    ListNode* a = new ListNode(9);
    ListNode* b = new ListNode(9, a);
    ListNode* c = new ListNode(9, b);
    ListNode* d = new ListNode(9);
    ListNode* e = new ListNode(9, d);
    ListNode* f = new ListNode(9, e);
    Solution x = Solution();
    x.addTwoNumbers(c, f);
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