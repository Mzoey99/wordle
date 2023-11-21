#include <string.h>
#include <stdbool.h>

bool char_in_str(char* str, char x) {
    int n = strlen(str);
    for (int i = 0; i < n; i++) {
        if (str[i] == x)
            return true;
    }
    return false;
}

bool est_egal(char* str1, char* str2) {
    int n1 = strlen(str1);
    int n2 = strlen(str2);
    if (n1 != n2) {
        return false;
    }
    for (int i = 0; i < n1; i++) {
        if (str1[i] != str2[i])
            return false;
    }
    return true;
}