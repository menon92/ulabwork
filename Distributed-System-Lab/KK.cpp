#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;

    while(cin >> n)
    {
        int a[n + 1];

        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        // lcm(a, b) = (a * b) / gcd(a, b);

        int ans = a[0];
        for(int i = 1; i < n; i++) {
            ans = (ans * a[i]) / (__gcd(ans, a[i]));
        }
        cout << ans << endl;
    }


    return 0;
}
