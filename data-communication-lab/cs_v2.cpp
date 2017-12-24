#include <iostream>
#include <cctype>
#include <cstdlib>

using namespace std;

int main()
{
    string s = "abcABC123";
    string c = "";
    int key = 1;

    for(int i = 0; i < s.length(); i++)
    {
        if(isalpha(s[i]))
        {
            if(islower(s[i])) {
                c += (s[i] + key - 'a') % 26 + 'a';
            }
            else {
                 c += (s[i] + key - 'A') % 26 + 'A';
            }
        }
        else if(isdigit(s[i])) {
            c += (s[i] + key - '0') % 26 + '0';
        }
    }
    cout << c << endl;


    return 0;
}
