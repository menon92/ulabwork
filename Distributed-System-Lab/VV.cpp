#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    const char *s;
    string str;

    char ans[80 + 7];

    while(getline(cin, str))
    {
        s = str.c_str();

        int k = 0;
        for(int i = 0; s[i]; i++)
        {
            if(s[i] >= 'a' && s[i] <= 'z')
            {
                ans[k] = s[i] - 4;
                k++;
            }
            else {
                ans[k] = s[i];
                k++;
            }
        }
        ans[k] = '\0';
        puts(ans);
    }

    return 0;
}
