
#include <stdio.h>
#include <stdlib.h>

char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    char** result = malloc(numsSize * sizeof(char*));
    int count = 0;
    int i = 0;

    while (i < numsSize) {
        int start = nums[i];

        while (i + 1 < numsSize &&
               (long long)nums[i + 1] == (long long)nums[i] + 1) {
            i++;
        }

        result[count] = malloc(25 * sizeof(char));

        if (start == nums[i]) {
            sprintf(result[count], "%d", start);
        } else {
            sprintf(result[count], "%d->%d", start, nums[i]);
        }

        count++;
        i++;
    }

    *returnSize = count;
    return result;
}
