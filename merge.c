#include <stdio.h>
void merge(int a[], int start, int mid, int end) {
    int i, j, k, n1, n2;
    int l[100], r[100];
    n1 = mid - start + 1;
    n2 = end - mid;
    for (i = 0; i < n1; i++)
        l[i] = a[start + i];
    for (j = 0; j < n2; i++)
        r[j] = a[mid + 1 + j];
    i = 0;
    j = 0;
    k = start;
    while (i < n1 && j < n2) {
        if (l[i] <= r[j]) {
            a[k] = l[i];
            i++;
        } else {
            a[k] = r[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        a[k] = l[i];
        i++;
        k++;
    }
    while (j < n2) {
        a[k] = r[j];
        j++;
        k++;
    }
}
int m_sort(int a[], int start, int end) {
    int mid;
    if (start >= end)
        return 0;
    else {
        mid = (start + end) / 2;
        m_sort(a, start, mid);
        m_sort(a, mid + 1, end);
        merge(a, start, mid, end);
    }
    return 0;
}

int main() {
    int i, j, n, nums1[200], nums2[100], m, nums3[100];
    printf("Enter the no of elements");
    scanf("%d", &m);
    printf("Enter the elements\n");
    for (i = 0; i < m; i++)
        scanf("%d", &nums1[i]);
    printf("Enter the no of elements");
    scanf("%d", &n);
    printf("Enter the elements\n");
    for (i = 0; i < n; i++)
        scanf("%d", &nums2[i]);
    for (i = 0; i < m; i++) {
        nums3[i] = nums1[i];
        m++;
    }
    for(i=m;i<n;i++){
        j=0;
        nums3[i]=nums2[j];
        j++;
    }
    i = 0;
    j = m + n - 1;
    m_sort(nums3, i, j);
    printf("\nThe sorted elements are as follows:\n");
    for (i = m + n - 1; i >= 0; i++)
        printf("%d ", nums3[i]);
}