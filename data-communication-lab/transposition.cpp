// CPP program for illustrating
// Columnar Transposition Cipher
#include<bits/stdc++.h>
using namespace std;

// Key for Columnar Transposition
//string const key = "HACK";
string const key = "35214";
map<int,int> keyMap;

void setPermutationOrder()
{
    // Add the permutation order into map
    for(int i=0; i < key.length(); i++)
    {
        // by default map sort by key
        keyMap[key[i]] = i;
    }
}

// Encryption
string encryptMessage(string msg)
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
            //if( isalpha(msg[k]) || msg[k]==' ')
            if(k < msg.length() && (isalpha(msg[k]) || msg[k]==' '))
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
    printf("\n");
    for (map<int,int>::iterator ii = keyMap.begin(); ii!=keyMap.end(); ++ii)
    {
        j=ii->second;
        printf("J = %d\n", j);

        // getting cipher text from matrix column wise using permuted key
        for (int i=0; i<row; i++)
        {
            if( isalpha(matrix[i][j]) || matrix[i][j]==' ' || matrix[i][j]=='_')
                cipher += matrix[i][j];
                cout << "cipher" << cipher << endl;
        }
    }

    return cipher;
}

// Decryption
string decryptMessage(string cipher)
{
    /* calculate row and column for cipher Matrix */
    int col = key.length();

    int row = cipher.length()/col;
    cout << "row: " << row << " col " << col << endl;
    char cipherMat[row][col];

    /* add character into matrix column wise */
    for (int j=0,k=0; j<col; j++) {
        for (int i=0; i<row; i++) {
            cipherMat[i][j] = cipher[k++];
        }
    }

    printf("chipermax\n");
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            printf("%c ", cipherMat[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    /* update the order of key for decryption */
    int index = 0;
    for( map<int,int>::iterator ii=keyMap.begin(); ii!=keyMap.end(); ++ii)
        ii->second = index++;

    /* Arrange the matrix column wise according
    to permutation order by adding into new matrix */
    char decCipher[row][col];
    //map<int,int>::iterator ii=keyMap.begin();
    int k = 0;
    for (int l=0,j; key[l]!='\0'; k++)
    {
        j = keyMap[key[l++]];
        printf("J = %d\n", j);
        for (int i=0; i < row; i++)
        {
            decCipher[i][k]=cipherMat[i][j];
            printf("%c", decCipher[i][k]);
        }
        printf("\n");
    }


    /* getting Message using matrix */
    string msg = "";
    for (int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(decCipher[i][j] != '_')
                msg += decCipher[i][j];

            printf("%c", decCipher[i][j]);
        }
        printf("\n");
    }
    return msg;
}

// Driver Program
int main(void)
{
    /* message */
    //string msg = "Geeks for Geeks";
    string msg = "INTERNET";

    setPermutationOrder();

    // Calling encryption function
    string cipher = encryptMessage(msg);
    cout << "Encrypted Message: " << cipher << endl;

    // Calling Decryption function
    cout << "Decrypted Message: " << decryptMessage(cipher) << endl;

    return 0;
}
