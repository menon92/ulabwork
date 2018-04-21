#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 100 + 7;
const int INF = 1000000000 + 7;
int matrix[MAX][MAX];

int main()
{
    int n;
    string s;

    while(cin >> n)
    {
        cin.ignore();
        for(int r = 1; r < n; r++)
        {
            for(int c = 0; c < r; c++)
            {
                cin >> s;
                if(s == "x") {
                    matrix[r][c] = matrix[c][r] = INF;
                }
                else {
                    matrix[r][c] = matrix[c][r] = atoi(s.c_str());
                }

            }
        }

        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }

        int max_cost = 0;
        for(int i = 0; i < n; i++) {
            if(matrix[0][i] > max_cost) {
                max_cost = matrix[0][i];
            }
        }
        cout << max_cost << endl;


    }

    return 0;
}
