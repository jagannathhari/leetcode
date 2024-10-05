bool checkInclusion(char* s1, char* s2) {
    int len1 = strlen(s1), len2 = strlen(s2);
    if (len1 > len2) return false;

    int frq1[26] = {0}, frq2[26] = {0};

    for (int i = 0; i < len1; i++) {
        frq1[s1[i] - 'a']++;
        frq2[s2[i] - 'a']++;
    }

    if (memcmp(frq1, frq2, sizeof(frq1)) == 0) {
        return true;
    }

    for (int i = len1; i < len2; i++) {
        frq2[s2[i] - 'a']++;
        frq2[s2[i - len1] - 'a']--;

        if (memcmp(frq1, frq2, sizeof(frq1)) == 0) {
            return true;
        }
    }

    return false;
}
