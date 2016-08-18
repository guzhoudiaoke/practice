#include <stdio.h>
#include <stdlib.h>

int cmp_price(const void *left, const void *right)
{
    return *(int *)left - *(int *)right;
}

int binary_search(int a[], int low, int high, int key) 
{
    while (low <= high) {
        int mid = (low + high)/2;
        if (a[mid] == key) {
            return mid;
        } else if (a[mid] > key) {
            high = mid - 1;
        } else { //a[mid] < key
            low = mid + 1;
        }
    }
 
    return -1;
}
 
int binary_up_bound(int a[], int low, int high, int key) {
    while (low < high) {
        int mid = (low + high + 1)/2;
        if (a[mid] > key) {
            high = mid - 1;
        } else { //a[mid] <= key
            low = mid;
        }
    }
 
    if (a[low] <= key) {
        return low;
    } else {
        return -1;
    }
}
 
int binary_low_bound(int a[], int low, int high, int key) {
    while (low < high) {
        int mid = (low + high)/2;
        if (a[mid] < key) {
            low = mid + 1;
        } else { //a[mid] >= key
            high = mid;
        }
    }
 
    if (a[high] >= key) {
        return high;
    } else {
        return -1;
    }
}

int solve(int *an, int n, int x)
{
    int index = binary_up_bound(an, 0, n-1, x);
    if (index == -1) {
        return 0;
    }
    return index + 1;
}

int main()
{
    int n = 0, q = 0, i = 0, x = 0;
    int *an = NULL;

    scanf("%d", &n);
    an = (int *) malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        scanf("%d", &an[i]);
    }
    qsort(an, n, sizeof(int), cmp_price);

    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        scanf("%d", &x);
        printf("%d\n", solve(an, n, x));
    }

    return 0;
}
