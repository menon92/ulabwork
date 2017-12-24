#include <iostream>
#include <map>
#include <cstdio>
using namespace std;

string key = "35214";
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
            if(k < msg.length() && (isalpha(msg[k]) || msg[k]==' '))
            {
                /* Adding only space and alphabet into matrix*/
                matrix[i][j] = msg[k];
            }
            else{
                /* Adding the padding character '_' */
                 matrix[i][j] = '_';
            }
            printf("k = %d\n", k);
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

    for(map <int, int> :: iterator ii = keyMap.begin(); ii !=keyMap.end(); ++ii) {
        j = ii->second;
        for(int i = 0; i < row; i++) {
            cipher += matrix[i][j];
        }
    }

    return cipher;
}

string decryptMessage(string cipher) {
    /* calculate row and column for cipher Matrix */
    int col = key.length();

    int row = cipher.length()/col;
    cout << "row: " << row << " col " << col << endl;
    char cipherMat[row][col];

    // take value col wise
    for(int j = 0, k = 0; j < col; j++) {
        for(int i = 0; i < row; i++) {
            cipherMat[i][j] = cipher[k];
            k++;
        }
    }

    printf("Matrix\n");
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            printf("%c", cipherMat[i][j]);
        }
        printf("\n");
    }

    // update keyMap
    int index = 0;
    for(map <int, int> :: iterator ii = keyMap.begin(); ii != keyMap.end(); ++ii) {
        ii->second = index++;
    }
    int j = 0;
    int k = 0;
    char decCipher[row][col];

    for(int l = 0; key[l] != '\0'; k++)
    {
        j = keyMap[key[l++]];
        for(int i = 0; i < row; i++)
        {
            decCipher[i][k] = cipherMat[i][j];
        }
    }

    printf("Matrix\n");
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            printf("%c", decCipher[i][j]);
        }
        printf("\n");
    }

    string msg = "";

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++) {
                if(decCipher[i][j] != '_')
                    msg += decCipher[i][j];
        }
    }
    return msg;
}


int main()
{
    permutation_order();

    string text = "INTERNET";
    string cipher = encript_text(text);

    cout << "cipher text: " << cipher << endl;
    cout << "decript text: " << decryptMessage(cipher) << endl;

    return 0;
}

