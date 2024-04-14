int romanToInt(char * restrict s) {
    int rom_int[7] = {1, 5, 10, 50, 100, 500, 1000};
    int n = strlen(s);
    int final_val = 0;
    int prev_val = 0;

    for (int i = n - 1; i >= 0; i--) {
        int curr_val;
        switch (s[i]) {
            case 'I':
                curr_val = rom_int[0];
                break;
            case 'V':
                curr_val = rom_int[1];
                break;
            case 'X':
                curr_val = rom_int[2];
                break;
            case 'L':
                curr_val = rom_int[3];
                break;
            case 'C':
                curr_val = rom_int[4];
                break;
            case 'D':
                curr_val = rom_int[5];
                break;
            case 'M':
                curr_val = rom_int[6];
                break;
            default:
                return -1;  
        }

        if (curr_val >= prev_val) {
            final_val += curr_val;
        } else {
            final_val -= curr_val;
        }

        prev_val = curr_val;
    }

    return final_val;
}
