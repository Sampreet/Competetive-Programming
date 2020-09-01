#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    int hh, mm, ss, i;
    char period;

    cin >> hh;
    cin.ignore();
    cin >> mm;
    cin.ignore();
    cin >> ss >> period;

    if (hh == 12 && period == 'A') {
        hh = 0;
    }
    if (hh != 12 && period == 'P') {
        hh += 12;
    }

    cout << setfill('0') << setw(2) << hh << ':' << setw(2) << mm << ':' << setw(2) << ss << endl;
    return 0;
}