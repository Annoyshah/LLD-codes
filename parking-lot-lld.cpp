/* ॐ श्री गणेशाय नमः || */
/* ॐ नमः पार्वती पतये हर हर महादेव */
/* कर्पूरगौरं करुणावतारं संसारसारं भुजगेन्द्रहारम्। सदा बसन्तं हृदयारविन्दे भवं भवानीसहितं नमामि।। */
/* ॐ नमो भगवते वासुदेवाय */

#include "bits/stdc++.h"
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

#define int long long
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()

template <typename T> istream& operator >> (istream& in, vector<T>& v) { for (auto &it:v) in >> it; return in; }
template <typename T> ostream& operator << (ostream& os, const vector<T>& v) { for (auto &it:v) os << it << " "; return os; }
template <typename T1, typename T2> ostream& operator << (ostream& os, const pair<T1,T2>& p) { cout << p.first << " " << p.second; return os; }

const int mod = 1e9+7;
const int mod2 = 998244353;

class Slot {
public:
    string type;
    bool occupied;

    Slot(string _type) : type(_type), occupied(false) {}
};

class Floor {
public:
    vector<Slot> slots;

    Floor(int no_of_slots_per_floor) {
        slots.pb(Slot("TRUCK"));
        slots.pb(Slot("BIKE"));
        slots.pb(Slot("BIKE"));
        for(int i = 3; i < no_of_slots_per_floor; ++i) {
            slots.pb(Slot("CAR"));
        }
    }

    int getFreeSlotCount(string vehicle_type) {
        int count = 0;
        for (auto &slot : slots) {
            if (slot.type == vehicle_type && !slot.occupied) count++;
        }
        return count;
    }

    vector<int> getFreeSlots(string vehicle_type) {
        vector<int> free_slots;
        for (int i = 0; i < sz(slots); ++i) {
            if (slots[i].type == vehicle_type && !slots[i].occupied) {
                free_slots.pb(i + 1);
            }
        }
        return free_slots;
    }

    vector<int> getOccupiedSlots(string vehicle_type) {
        vector<int> occupied_slots;
        for (int i = 0; i < sz(slots); ++i) {
            if (slots[i].type == vehicle_type && slots[i].occupied) {
                occupied_slots.pb(i + 1);
            }
        }
        return occupied_slots;
    }
};

class ParkingLot {
public:
    string id;
    vector<Floor> floors;

    ParkingLot(string _id, int no_of_floors, int no_of_slots_per_floor) : id(_id) {
        for(int i = 0; i < no_of_floors; ++i) {
            floors.pb(Floor(no_of_slots_per_floor));
        }
    }

    bool parkVehicle(string vehicle_type, string reg_no, string color, string &ticket_id) {
        for (int i = 0; i < sz(floors); ++i) {
            for (int j = 0; j < sz(floors[i].slots); ++j) {
                if (floors[i].slots[j].type == vehicle_type && !floors[i].slots[j].occupied) {
                    floors[i].slots[j].occupied = true;
                    ticket_id = id + "_" + to_string(i + 1) + "_" + to_string(j + 1);
                    return true;
                }
            }
        }
        return false;
    }

    bool unparkVehicle(string ticket_id, string &reg_no, string &color) {
        stringstream ss(ticket_id);
        string lot_id, floor_no_str, slot_no_str;
        getline(ss, lot_id, '_');
        getline(ss, floor_no_str, '_');
        getline(ss, slot_no_str);

        int floor_no = stoi(floor_no_str) - 1;
        int slot_no = stoi(slot_no_str) - 1;

        if (lot_id == id && floor_no < sz(floors) && slot_no < sz(floors[floor_no].slots) && floors[floor_no].slots[slot_no].occupied) {
            floors[floor_no].slots[slot_no].occupied = false;
            return true;
        }
        return false;
    }

    void displayFreeCount(string vehicle_type) {
        for (int i = 0; i < sz(floors); ++i) {
            cout << "No. of free slots for " << vehicle_type << " on Floor " << i + 1 << ": " << floors[i].getFreeSlotCount(vehicle_type) << endl;
        }
    }

    void displayFreeSlots(string vehicle_type) {
        for (int i = 0; i < sz(floors); ++i) {
            vector<int> free_slots = floors[i].getFreeSlots(vehicle_type);
            cout << "Free slots for " << vehicle_type << " on Floor " << i + 1 << ": ";
            if (!free_slots.empty()) {
                cout << free_slots << endl;
            } else {
                cout << "None" << endl;
            }
        }
    }

    void displayOccupiedSlots(string vehicle_type) {
        for (int i = 0; i < sz(floors); ++i) {
            vector<int> occupied_slots = floors[i].getOccupiedSlots(vehicle_type);
            cout << "Occupied slots for " << vehicle_type << " on Floor " << i + 1 << ": ";
            if (!occupied_slots.empty()) {
                cout << occupied_slots << endl;
            } else {
                cout << "None" << endl;
            }
        }
    }
};

void commandLoop() {
    string command;
    ParkingLot *parkingLot = nullptr;

    while (cin >> command) {
        if (command == "create_parking_lot") {
            string lot_id;
            int no_of_floors, no_of_slots_per_floor;
            cin >> lot_id >> no_of_floors >> no_of_slots_per_floor;
            parkingLot = new ParkingLot(lot_id, no_of_floors, no_of_slots_per_floor);
            cout << "Created parking lot with " << no_of_floors << " floors and " << no_of_slots_per_floor << " slots per floor" << endl;
        } else if (command == "park_vehicle") {
            string vehicle_type, reg_no, color;
            cin >> vehicle_type >> reg_no >> color;
            string ticket_id;
            if (parkingLot->parkVehicle(vehicle_type, reg_no, color, ticket_id)) {
                cout << "Parked vehicle. Ticket ID: " << ticket_id << endl;
            } else {
                cout << "Parking Lot Full" << endl;
            }
        } else if (command == "unpark_vehicle") {
            string ticket_id;
            cin >> ticket_id;
            string reg_no, color;
            if (parkingLot->unparkVehicle(ticket_id, reg_no, color)) {
                cout << "Unparked vehicle with Registration Number: " << reg_no << " and Color: " << color << endl;
            } else {
                cout << "Invalid Ticket" << endl;
            }
        } else if (command == "display") {
            string display_type, vehicle_type;
            cin >> display_type >> vehicle_type;
            if (display_type == "free_count") {
                parkingLot->displayFreeCount(vehicle_type);
            } else if (display_type == "free_slots") {
                parkingLot->displayFreeSlots(vehicle_type);
            } else if (display_type == "occupied_slots") {
                parkingLot->displayOccupiedSlots(vehicle_type);
            }
        } else if (command == "exit") {
            break;
        }
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    commandLoop();
    return 0;
}
