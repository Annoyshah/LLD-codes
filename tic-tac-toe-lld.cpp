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

class Board {
public:
    vector<vector<int>> board;
    Board() {
        board = vector<vector<int>>(3, vector<int>(3, -1));
    }
};

class Game {
private:
    Board board;
public:
    int makeaMove(int x, int y, int mark) {
        if (board.board[x][y] != -1) {
            cout << "Invalid Move" << endl;
            return 1;
        }
        board.board[x][y] = mark;
        return 0;
    }

    bool checkifWin(int ele) {
   
        for (int i = 0; i < 3; i++) {
            bool found = true;
            for (int j = 0; j < 3; j++) {
                if (board.board[i][j] != ele) {
                    found = false;
                    break;
                }
            }
            if (found) return true;
        }

       
        for (int i = 0; i < 3; i++) {
            bool found = true;
            for (int j = 0; j < 3; j++) {
                if (board.board[j][i] != ele) {
                    found = false;
                    break;
                }
            }
            if (found) return true;
        }

        
        bool found = true;
        for (int i = 0; i < 3; i++) {
            if (board.board[i][i] != ele) {
                found = false;
                break;
            }
        }
        if (found) return true;

        found = true;
        for (int i = 0; i < 3; i++) {
            if (board.board[i][2 - i] != ele) {
                found = false;
                break;
            }
        }
        return found;
    }

    void displayBoard() {
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board.board[i][j] == -1) cout << " _ ";
                else if(board.board[i][j] == 1) cout << " X ";
                else cout << " O ";
            }
            cout << endl;
        }
        cout<<endl;
    }
};

void comderoP0612() {
    string x, o, player1, player2;
    cin >> x >> player1 >> o >> player2;
    Game g;
    bool chance = 1; 
    while (true) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        int p = g.makeaMove(x, y, chance);
        if(p==0){
        g.displayBoard();
        if (g.checkifWin(chance)) {
            if (chance == 1) {
                cout << player1 << " wins" << endl;
            } else {
                cout << player2 << " wins" << endl;
            }
            return;
        }
        chance = !chance;
        }
        else{
            continue;
        }
    }
}

int32_t main() { 
    cin.tie(0)->sync_with_stdio(0);
    ll t = 1;
    comderoP0612();
    return 0;
}
