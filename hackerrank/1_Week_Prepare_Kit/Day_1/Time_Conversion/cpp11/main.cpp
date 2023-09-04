#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    // hh:mm:ssAM
    string ap = s.substr(8);
    string hs = s.substr(0, 2);
    string ms = s.substr(2, 6);

    int hh = stoi(s.substr(0, 2));
    // cout << ap << endl;
    // cout << hh << endl;
    // cout << "hs=" << hs << endl;
    // cout << "ms=" << ms << endl;
    if (ap == "AM") {
        if (hh == 12) {
            hs = "00";
        }
    }
    else { // ap == "PM"
        if (hh < 12) {
            hs = to_string(hh + 12);
        }
    }
    return hs + ms;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
