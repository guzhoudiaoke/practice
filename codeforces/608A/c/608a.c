#include <stdio.h>
#include <stdlib.h>

struct passenger {
    int floor;
    int time;
};

struct passenger passengers[101];

int cmp_passenger(const void *left, const void *right)
{
    struct passenger *l = (struct passenger *)left;
    struct passenger *r = (struct passenger *)right;
    return l->floor - r->floor;
}

int main()
{
    int n, s;
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &passengers[i].floor, &passengers[i].time);
    }

    qsort(passengers, n, sizeof(struct passenger), cmp_passenger);
    int cur_floor = s, cur_time = 0;
    for (int i = 0; i < n; i++) {
        int delta = cur_floor - passengers[i].floor;
        cur_time += delta;
        cur_floor = passengers[i].floor;
        if (cur_time < passengers[i].time) {
            cur_time = passengers[i].time;
        }
    }
    cur_time += cur_floor;
    printf("%d\n", cur_time);
    return 0;
}
