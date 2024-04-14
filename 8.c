#include <limits.h>
int myAtoi(char *s) {
    long result = 0;
    int sign = 1;
    int idx = 0;

    while (s[idx] == ' ') {
        ++idx;
    }
    
    if (s[idx] == '+') {
        ++idx;
    }
    else if (s[idx] == '-') {
        sign = -1;
        ++idx;
    }

    while (s[idx] >= '0' && s[idx] <= '9') {
        result = result * 10 + (s[idx] - '0');
        if (result > INT_MAX) {
            return sign == -1 ? INT_MIN : INT_MAX;
        }
        ++idx;
    }

    return sign * result;
}
