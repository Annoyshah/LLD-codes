#include "bits/stdc++.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

#define int long long int
#define ll int
#define double long double
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()
#define deb(x) cout << #x << "=" << x << endl;

class User {
public:
    string id;
    map<string, int> owes_to;  

    User() : id("") {}
    User(string i) : id(i) {}
};

class Splitwise {
public:
    map<string, User> users;  

    void addUser(string userId) {
        users[userId] = User(userId);
    }

    void showBalances() {
        bool noBalances = true;
        for (auto &user : users) {
            for (auto &balance : user.ss.owes_to) {
                if (balance.ss != 0) {
                    noBalances = false;
                    if (balance.ss > 0) {
                        cout << user.ff << " owes " << balance.ff << ": " << balance.ss << endl;
                    } else {
                        cout << balance.ff << " owes " << user.ff << ": " << -balance.ss << endl;
                    }
                }
            }
        }
        if (noBalances) {
            cout << "No balances" << endl;
        }
    }

    void showUserBalances(string userId) {
        bool noBalances = true;
        for (auto &balance : users[userId].owes_to) {
            if (balance.ss != 0) {
                noBalances = false;
                if (balance.ss > 0) {
                    cout << userId << " owes " << balance.ff << ": " << balance.ss << endl;
                } else {
                    cout << balance.ff << " owes " << userId << ": " << -balance.ss << endl;
                }
            }
        }
        if (noBalances) {
            cout << "No balances" << endl;
        }
    }

    void addExpense(string payerId, int amount, vector<string> involvedUsers, string splitType, vector<int> values = {}) {
        if (splitType == "EXACT") {
            int totalExact = accumulate(all(values), 0);
            for (int i = 0; i < sz(involvedUsers); i++) {
                if (involvedUsers[i] != payerId) {
                    users[involvedUsers[i]].owes_to[payerId] += values[i];
                    users[payerId].owes_to[involvedUsers[i]] -= values[i];
                }
            }
        } else if (splitType == "PERCENT") {
            int totalPercent = accumulate(all(values), 0);
            for (int i = 0; i < sz(involvedUsers); i++) {
                if (involvedUsers[i] != payerId) {
                    int owesAmt = (amount * values[i]) / 100;
                    users[involvedUsers[i]].owes_to[payerId] += owesAmt;
                    users[payerId].owes_to[involvedUsers[i]] -= owesAmt;
                }
            }
        } else if (splitType == "EQUAL") {
            int splitAmt = amount / sz(involvedUsers);
            int remaining = amount - (splitAmt * sz(involvedUsers));
            for (int i = 0; i < sz(involvedUsers); i++) {
                if (involvedUsers[i] != payerId) {
                    int finalAmount = (i == sz(involvedUsers) - 1) ? splitAmt + remaining : splitAmt;
                    users[involvedUsers[i]].owes_to[payerId] += finalAmount;
                    users[payerId].owes_to[involvedUsers[i]] -= finalAmount;
                }
            }
        }
    }
};

void comderoP0612() {
    Splitwise splitwise;
    for (int i = 1; i <= 4; i++) {
        splitwise.addUser("u" + to_string(i));
    }

    string command;
    while (cin >> command) {
        if (command == "SHOW") {
            string userId;
            if (cin.peek() == '\n' || cin.peek() == EOF) {
                splitwise.showBalances();
            } else {
                cin >> userId;
                splitwise.showUserBalances(userId);
            }
        } else if (command == "EXPENSE") {
            string payerId;
            cin >> payerId;
            int amount;
            cin >> amount;
            int numUsers;
            cin >> numUsers;
            vector<string> involvedUsers(numUsers);
            for (int i = 0; i < numUsers; i++) {
                cin >> involvedUsers[i];
            }
            string splitType;
            cin >> splitType;
            vector<int> values;
            if (splitType != "EQUAL") {
                values.resize(numUsers);
                for (int i = 0; i < numUsers; i++) {
                    cin >> values[i];
                }
            }
            splitwise.addExpense(payerId, amount, involvedUsers, splitType, values);
        }
    }
}

int32_t main() { 
    cin.tie(0)->sync_with_stdio(0);
    ll t = 1;
    comderoP0612();
    return 0;
}
