/*ॐ श्री गणेशाय नमः || */
/* ॐ नमः पार्वती पतये हर हर महादेव */
/* कर्पूरगौरं करुणावतारं संसारसारं भुजगेन्द्रहारम्। सदा बसन्तं हृदयारविन्दे भवं भवानीसहितं नमामि।। */
/* ॐ नमो भगवते वासुदेवाय */

#include "bits/stdc++.h"
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
 
template <typename T> istream& operator >> (istream& in, vector<T>& v) { for (auto &it:v) in >> it; return in; }
template <typename T> ostream& operator << (ostream& os, const vector<T>& v) { for (auto &it:v) os << it << " "; return os; }
template <typename T1, typename T2> istream& operator >> (istream& in, pair<T1,T2>& p) { cin >> p.first >> p.second; return in; }
template <typename T1, typename T2> ostream& operator << (ostream& os, const pair<T1,T2>& p) { cout << p.first << " " << p.second; return os; }
template <typename T1, typename T2> void maxn(T1& a, T2 b) { a = max(a,b); }
template <typename T1, typename T2> void maxx(T1& a, T2 b) { a = max(a,b); }
 
#define int long long int
#define ll int
#define double long double
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define sz(v) (int)v.size()
#define deb(x) cout<<#x<<"="<<x<<endl;
#define pii pair<int,int> 
#define vi vector<int>
#define repL(i, a, b) for(int i = (a); i < (b); i++)
 
const int mod = 1e9+7;
const int mod2 = 998244353;
const double PI = 3.1415926535897932384626433832795;
vector<vector<int>> board;

class Player {
public:
    string name;
    int position;
    Player(string n) {
        this->name = n;
        this->position = 0;
    }
};

class Board {
public:
    int size = 0;
    Board(int sz) {
        this->size = sz;
        board = vector<vector<int>>(sz, vector<int>(sz, 0));
    }
};

void comderoP0612() {
    int numSnake;
    cin >> numSnake;
    vector<pii> snakePos;
    for (int i = 0; i < numSnake; i++) {
        int x, y;
        cin >> x >> y;
        snakePos.pb({x, y});
    }

    int numLadders;
    cin >> numLadders;
    vector<pii> laddPos;
    for (int i = 0; i < numLadders; i++) {
        int x, y;
        cin >> x >> y;
        laddPos.pb({x, y});
    }

    int numPlayers;
    cin >> numPlayers;
    vector<Player> vec;
    for (int i = 0; i < numPlayers; i++) {
        string s;
        cin >> s;
        Player p(s);
        vec.pb(p);
    }

    Board game(100);
    bool won = false;
    int chance = 0;

    srand(static_cast<unsigned int>(std::time(nullptr)));

    while (!won) {
        int random_number = std::rand() % 6 + 1;
        int old_position = vec[chance].position;
        vec[chance].position += random_number;
        
     
        cout << vec[chance].name << " rolled a " << random_number << " and moved from " << old_position << " to " << vec[chance].position << endl;

        if (vec[chance].position >= 99) {
            won = true;
            cout << vec[chance].name << " wins!" << endl;
            break;
        }

        for (auto &it : snakePos) {
            if (vec[chance].position == it.ff) {
                vec[chance].position = it.ss;
                break;
            }
        }

        for (auto &it : laddPos) {
            if (vec[chance].position == it.ff) {
                vec[chance].position = it.ss;
                break;
            }
        }

        chance = (chance + 1) % sz(vec);
    }
}

int32_t main() { 
    cin.tie(0)->sync_with_stdio(0);
    ll t = 1;
    comderoP0612();
    return 0;
}
