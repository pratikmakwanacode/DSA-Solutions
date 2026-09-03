#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int count[128] = {0};
    int left = 0, maxLength = 0;

    for (int right = 0; s[right] != '\0'; right++) {
        count[s[right]]++;

        while (count[s[right]] > 1) {
            count[s[left]]--;
            left++;
        }

        int currentLength = right - left + 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }

    return maxLength;
}