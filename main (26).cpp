#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int CountRecursive(char* str, int i) {
    if (str[i] == '\0' || str[i + 1] == '\0' || str[i + 2] == '\0')
        return 0;
    if (str[i] == 'a' && str[i + 1] == 'b' && str[i + 2] == 'c')
        return 1 + CountRecursive(str, i + 3);
    else
        return CountRecursive(str, i + 1);
}

char* ChangeRecursive(char* dest, const char* str, char* t, int i) {
    if (str[i] != '\0' && str[i + 1] != '\0' && str[i + 2] != '\0') {
        if (str[i] == 'a' && str[i + 1] == 'b' && str[i + 2] == 'c') {
            strcat(t, "**");
            return ChangeRecursive(dest, str, t + 2, i + 3);
        } else {
            *t++ = str[i++];
            *t = '\0';
            return ChangeRecursive(dest, str, t, i);
        }
    } else {
        while (str[i] != '\0') {
            *t++ = str[i++];
        }
        *t = '\0';
        return dest;
    }
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    cout << "String contained " << CountRecursive(str, 0) << " groups of 'abc'" << endl;
    char* dest1 = new char[151];
    dest1[0] = '\0';
    char* dest2 = ChangeRecursive(dest1, str, dest1, 0);
    cout << "Modified string (param) : " << dest1 << endl;
    cout << "Modified string (result): " << dest2 << endl;
    return 0;
}
