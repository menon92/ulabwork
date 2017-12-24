#include <iostream>
#include <map>
#include <cstdio>
using namespace std;

string const key = "35214";
map <int, int> keyMap;

void permutation_order() {
    for(int i = 0; i < key.length(); i++) {
        keyMap[key[i]] = i;
    }
}

string encript_text(string msg)
{
     int row,col,j;
    string cipher = "";

    /* calculate column of the matrix*/
    col = key.length();

    /* calculate Maximum row of the matrix*/
    row = msg.length()/col;

    if (msg.length() % col)
        row += 1;

    char matrix[row][col];
    cout << "row: " << row << " col: " << col << endl;
    for (int i=0,k=0; i < row; i++)
    {
        for (int j=0; j<col; )
        {
            if( isalpha(msg[k]) || msg[k]==' ')
            {
                /* Adding only space and alphabet into matrix*/
                matrix[i][j] = msg[k];
            }
            else {
                /* Adding the padding character '_' */
                 matrix[i][j] = '_';
            }
            k++;
            j++;
        }
    }

    printf("Matrix\n");
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
    return "";
}


int main()
{
    permutation_order();

    string text = "INTERNET";

    encript_text(text);

    return 0;
}
