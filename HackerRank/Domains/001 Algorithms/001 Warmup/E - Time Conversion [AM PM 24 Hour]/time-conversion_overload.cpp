#include <iomanip>
#include <iostream>

using namespace std;

struct Time {
    int hh, mm, ss;
    char period;
};

istream &operator >> (istream &is, Time &t) {
    is >> t.hh;
    is.ignore(1, ':');
    is >> t.mm;
    is.ignore(1, ':');
    is >> t.ss;
    is >> t.period;
    is.ignore(1, 'M');

    return is;
}

ostream &operator << (ostream &os, Time &t) {
    os << setfill('0') << setw(2) << t.hh;
    os << ':';
    os << setfill('0') << setw(2) << t.mm;
    os << ':';
    os << setfill('0') << setw(2) << t.ss;

    return os;
}

int main() {
    Time t;

    cin >> t;

    if (t.hh == 12 && t.period == 'A') {
        t.hh = 0;
    }
    if (t.hh != 12 && t.period == 'P') {
        t.hh += 12;
    }

    cout << t << endl;
    return 0;
}