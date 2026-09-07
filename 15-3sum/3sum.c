#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    
    qsort(nums, numsSize, sizeof(int), compare);

    int **answer = malloc(numsSize * numsSize * sizeof(int *));
    *returnColumnSizes = malloc(numsSize * numsSize * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < numsSize - 2; i++) {

        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {

            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {

                answer[*returnSize] = malloc(3 * sizeof(int));

                answer[*returnSize][0] = nums[i];
                answer[*returnSize][1] = nums[left];
                answer[*returnSize][2] = nums[right];

                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                left++;
                right--;

                while (left < right && nums[left] == nums[left - 1]) {
                    left++;
                }

                while (left < right && nums[right] == nums[right + 1]) {
                    right--;
                }

            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    return answer;
}