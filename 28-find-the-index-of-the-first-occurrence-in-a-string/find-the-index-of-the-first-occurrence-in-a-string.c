#include <string.h>

int strStr(char* haystack, char* needle) {
    int h_len = strlen(haystack);
    int n_len = strlen(needle);

    // Agar needle haystack se badi hai, toh milna namumkin hai
    if (n_len > h_len) return -1;

    // Sliding window ki tarah har possible starting point check karein
    for (int i = 0; i <= h_len - n_len; i++) {
        int j = 0;
        // Characters match karein
        while (j < n_len && haystack[i + j] == needle[j]) {
            j++;
        }
        // Agar poori needle match ho gayi
        if (j == n_len) {
            return i;
        }
    }

    return -1;
}