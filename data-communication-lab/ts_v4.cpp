#include <iostream>
#include <cstdio>
#include <cctype>
#include <map>
using namespace std;

//string key = "35214";
string key = "HACK";
map <int, int> mapKey;

void doMapKey() {
    for(int i = 0; i < key.length(); i++) {
        mapKey[key[i]] = i;
    }
}
string encript(string msg)
{
    int col = key.length();
    int row = msg.length() / col;
    if(msg.length() % col) {
        row++;
    }
    char matrix[row][col];
    for(int i = 0, k = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(k < msg.length() && (isalpha(msg[i]) || msg[k] == ' ')) {
                matrix[i][j] = msg[k];
            }
            else {
                matrix[i][j] = '_';
            }
            k++;
        }
    }
    int j = 0;
    string encript_text = "";
    for(map <int, int> :: iterator ii = mapKey.begin(); ii != mapKey.end(); ++ii) {
        j = ii->second;
        for(int i = 0; i < row; i++) {
            if(isalpha(matrix[i][j]) || matrix[i][j] == ' ' || matrix[i][j] == '_') {
                encript_text += matrix[i][j];
            }
        }
    }
    return encript_text;
}

string decript(string msg)
{
    int col = key.length();
    int row = msg.length() / col;
    char d_matrix[row][col];

    int k = 0;
    for(map <int, int> :: iterator ii = mapKey.begin(); ii != mapKey.end(); ++ii) {
        //ii->second = index++;
        int j = ii->second;
        for(int i = 0; i < row; i++) {
            d_matrix[i][j] = msg[k++];
        }
    }
    string str = "";
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(d_matrix[i][j] != '_') {
                str += d_matrix[i][j];
            }
        }
    }
    return str;
}
int main()
{
    doMapKey();
//    string str;
//    getline(cin, str);
//    cout << str << endl;

    string msg = "INTERNET";
    //string msg = "Geeks for Geek";
    string cipher = encript(msg);
    cout << "cipher :" << cipher << endl;
    cout << "decript:" << decript(cipher) << endl;

    return 0;
}
