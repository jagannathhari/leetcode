int solve(char* s, int idx, int* new_idx) {
    char op = '+';
    int ans = 0;
    int i = idx;
    int num = 0;
    int is_num = 0;

    while (s[i] != '\0') {
        if (s[i] == ' ') {
            i++;
            continue;
        }

        if (s[i] == '+' || s[i] == '-') {
            op = s[i];
            is_num = 0;
        }

        if (s[i] == ')') {
            *new_idx = i;
            return ans;
        }

        if (s[i] == '(') {
            int a;
            i++;
            a = solve(s, i, &i);
            if (op == '+') {
                ans += a;
            } else {
                ans -= a;
            }
            is_num = 0;
        }

        if (isdigit(s[i])) {
            num = 0;
            is_num = 1;
            while (s[i] != '\0' && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            i--;
            if (op == '+') {
                ans += num;
            } else {
                ans -= num;
            }
        }
        i++;
    }
    *new_idx = i;
    return ans;
}

int calculate(char* s) {
    int idx = 0;
    return solve(s, idx, &idx);
}
