#include <iostream>
#include <cstdio>
#include <climits>
#include <cctype>
#include <map>
using namespace std;

const int MAX = 100 + 7;
map <int, int> fib_number;

void generate_fibo_sequences()
{
    int a = 1;
    int b = 2;
    int c;
    fib_number[a] = 0;
    fib_number[b] = 1;

    for(int i = 2; i <= 47; i++)
    {
        c = a + b;
        fib_number[c] = i;
        a = b;
        b = c;
    }
}


int main()
{
    // freopen("input.txt", "r+", stdin);

    int tc, n;

    generate_fibo_sequences();

    cin >> tc;
    for(int t = 0; t < tc; t++)
    {
        char cipher_text[100 + 5];
        char ans[50];

        cin >> n;
        int code[n + 1];
        for(int i = 0; i < n; i++) {
            cin >> code[i];
        }
        cin.ignore();
        gets(cipher_text);

        int ii;
        for(ii = 0; ii < 47; ii++) {
            ans[ii] = ' ';
        }
        ans[ii] = '\0';

        int k = 0;
        for(int i = 0; i < n; i++)
        {
            // skip other char
            for( ;!isupper(cipher_text[k]); k++);

            int index = fib_number[code[i]];
            ans[index] = cipher_text[k];

            k += 1;
        }

        // skipe traling space
        for(ii = 46; ii > 0; )
        {
            if(ans[ii] == ' ') {
                ii = ii - 1;
            }
            else {
                break;
            }
        }
        ans[++ii] = '\0';

        printf("%s\n", ans);


    }

    return 0;
}
