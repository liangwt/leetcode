#include <stdio.h>

void merge(int *nums1, int m, int *nums2, int n);

int main()
{
    int nums1[] = {4, 5, 6, 0, 0, 0};
    int m = 3;
    int nums2[] = {1, 2, 3};
    int n = 3;

    merge(nums1, m, nums2, n);
    for (int i = 0; i < 6; i++)
    {
        printf("%d\n", nums1[i]);
    }
}

void merge(int *nums1, int m, int *nums2, int n)
{
    int i = m - 1, j = n - 1, t = m + n - 1;

    while (i >= 0 && j >= 0)
    {
        if (nums1[i] < nums2[j])
        {
            nums1[t] = nums2[j];
            j--;
        }
        else
        {
            nums1[t] = nums1[i];
            i--;
        }
        t--;
    }

    while (j >= 0 && t >= 0)
    {
        nums1[t] = nums2[j];
        j--;
        t--;
    }
}