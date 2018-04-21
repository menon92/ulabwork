#include <iostream>
#include <map>
#include <cstdio>
using namespace std;


int main()
{
    // freopen("input.txt", "r+", stdin);
    // freopen("out.txt", "r+", stdout);

    map <string, string> m;

    m[""] = "";

    m[".-"] = "A";
    m["-..."] = "B";
    m["-.-."] = "C";
    m["-.."] = "D";
    m["."] = "E";
    m["..-."] = "F";
    m["--."] = "G";
    m["...."] = "H";
    m[".."] = "I";

    m[".---"] = "J";
    m["-.-"] = "K";
    m[".-.."] = "L";
    m["--"] = "M";
    m["-."] = "N";
    m["---"] = "O";
    m[".--."] = "P";
    m["--.-"] = "Q";
    m[".-."] = "R";

    m["..."] = "S";
    m["-"] = "T";
    m["..-"] = "U";
    m["...-"] = "V";
    m[".--"] = "W";
    m["-..-"] = "X";
    m["-.--"] = "Y";
    m["--.."] = "Z";

    m["-----"] = "0";
    m[".----"] = "1";
    m["..---"] = "2";
    m["...--"] = "3";
    m["....-"] = "4";
    m["....."] = "5";
    m["-...."] = "6";
    m["--..."] = "7";
    m["---.."] = "8";
    m["----."] = "9";

    m[".-.-.-"] = ".";
    m["--..--"] = ",";
    m["..--.."] = "?";
    m[".----."] = "\'";
    m["-.-.--"] = "!";
    m["-..-."] = "/";
    m["-.--."] = "(";
    m["-.--.-"] = ")";
    m[".-..."] = "&";
    m["---..."] = ":";
    m["-.-.-."] = ";";
    m["-...-"] = "=";
    m[".-.-."] = "+";
    m["-....-"] = "-";
    m["..--.-"] = "_";
    m[".-..-."] = "\"";
    m[".--.-."] = "@";

    int tc;

    cin >> tc;
    cin.ignore();
    for(int t = 1; t <= tc; t++)
    {
        string ans = "";
        string line;
        getline(cin, line);
        int len = line.length();

        for(int i = 0; i < len; )
        {
            string tmp = "";
            while(line[i] != ' ' && i < len) {
                tmp += line[i];
                i += 1;
            }
            ans += m[tmp];
            i = i + 1;
            if(line[i] == ' ') {
                // cout << "in" << endl;
                ans += " ";
                i = i + 1;
            }
        }

        if(t > 1) {
            cout << endl;
        }
        cout << "Message #" << t << endl;
        cout << ans << endl;

    }

    return 0;
}
