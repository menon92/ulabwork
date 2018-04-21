#include <iostream>
#include <cstdio>
using namespace std;

const int MAX = 400 + 7;
int matrix[MAX][MAX];

int main()
{
    // freopen("input.txt", "r+", stdin);

    printf("%4d\n", 10);
    printf("%4d\n", 1000);
    printf("%4d\n", 100);


    int tc, n;
    int q, u, v;

    cin >> tc;
    for(int t = 0; t < tc; t++)
    {
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> matrix[i][j];
            }
        }

        cout << "Matrix original:" << endl;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }

        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    matrix[i][j] = matrix[i][j] | (matrix[i][k] & matrix[k][j]);
                }
            }
        }

        cout << "Matrix new:" << endl;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }

        cin >> q;
        for(int i = 0; i < q; i++)
        {
            cin >> u >> v;
            if(matrix[u - 1][v - 1] == 1) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}
