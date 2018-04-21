#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    string s;

    while(cin >> s)
    {
        int len = s.length();
        int i = 0;

        while(i < len)
        {
            if(s[i] == s[i + 1])
            {
                // s = s.erase(i, i + 2);
                s.erase(s.begin() + i);
                s.erase(s.begin() + i);
                // cout << "i: " << i << ", " << i + 2 << endl;
                // cout << "s: " << s << endl;
                len = s.length();
                i = 0;
            }
            else {
                i += 1;
            }
        }

        if(s.length() != 0) {
            cout << s << endl;
        }
        else {
            cout << "Empty String" << endl;
        }
    }

    return 0;
}
