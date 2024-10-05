int* findAnagrams(char* s, char* p, int* returnSize) {
    int s_len = strlen(s);
    int p_len = strlen(p);
    int* ans = (int*)malloc(sizeof(int) * s_len);
    int ans_idx = 0;
    
    if (s_len < p_len) {
        *returnSize = 0;
        return ans;
    }

    int frq1[26] = {0};
    int frq2[26] = {0};

    for (int i = 0; i < p_len; i++) {
        frq1[p[i] - 'a']++;
        frq2[s[i] - 'a']++;
    }

    
    for (int i = p_len; i < s_len; i++) {
        if (memcmp(frq1, frq2, sizeof(frq1)) == 0) {
            ans[ans_idx++] = i - p_len;
        }
        frq2[s[i] - 'a']++;
        frq2[s[i-p_len] - 'a']--; 
    }

    if (memcmp(frq1, frq2, sizeof(frq1)) == 0) {
        ans[ans_idx++] = s_len - p_len;
    }

    *returnSize = ans_idx;
    return ans;
}
