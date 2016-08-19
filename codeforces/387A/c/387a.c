#include <stdio.h>
#include <string.h>

int current_hh;
int current_mm;
int duration_hh;
int duration_mm;
int sleep_hh;
int sleep_mm;
char ans[6];

void solve()
{
    if (current_mm < duration_mm) {
        current_hh--;
        current_mm += 60;
    }
    sleep_mm = current_mm - duration_mm;

    if (current_hh < duration_hh) {
        current_hh += 24;
    }
    sleep_hh = current_hh - duration_hh;
    sprintf(ans, "%02d:%02d", sleep_hh, sleep_mm);
}

int main()
{
    scanf("%d:%d", &current_hh, &current_mm);
    scanf("%d:%d", &duration_hh, &duration_mm);

    solve();
    printf("%s\n", ans);
    return 0;
}
