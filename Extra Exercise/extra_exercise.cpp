#include <iostream>
#include <string>

using namespace std;

string name(int n) {
    switch (n) {
    case 0:
        return "";
    case 3:
        return "Kilo";
    case 6:
        return "Mega";
    case 9:
        return "Giga";
    case 12:
        return "Tera";
    case 15:
        return "Peta";
    case 18:
        return "Exa";
    case 21:
        return "Zeta";
    case 24:
        return "Yota";
    case 27:
        return "Bronto";
    case 30:
        return "Geop";
    default:
        return "No match!";
    }
}

string suffixWithUnit(double number) {
    string suff = to_string(number);
    int check = 0;
    while (suff[check] != '.') check++;
    suff.erase(suff.begin() + check);
    check--;
    int nameofsuff = 0;
    while (number >= 1000) {
        number /= 1000;
        nameofsuff+=3;
    }
    suff.insert(suff.begin() + check - nameofsuff + 1, '.');
    while (suff[suff.length() - 1] == '0'
        || suff[suff.length() - 1] == '.') suff.erase(suff.length() - 1);
    return suff + " " + name(nameofsuff);
}
int main()
{
    cout << suffixWithUnit(123) << endl;
    cout << suffixWithUnit(1234) << endl;
    cout << suffixWithUnit(12345) << endl;
    cout << suffixWithUnit(123456) << endl;
    cout << suffixWithUnit(1234567) << endl;
    cout << suffixWithUnit(12345678) << endl;
    cout << suffixWithUnit(123456789) << endl;
    cout << suffixWithUnit(12345.54321) << endl;
    cout << suffixWithUnit(12367623.36768) << endl;
    return 0;
}