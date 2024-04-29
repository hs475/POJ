#include <stdio.h>
#include <cstring>
#include <queue>

int pro[10005], r[10005], p;

void manager(int n) {
    int tmp, min = 10000, max = 0, flag, step = 0;
    char t;
    //小
    std::priority_queue <int, std::vector<int>, std::greater<int>> q1;
    std::priority_queue <int> q2;
    while (scanf("%c", &t)) {
        if (t == 'e') break;
        if (t == 'a') {
            scanf("%d", &tmp);
            pro[tmp]++;
            if (tmp < min) min = tmp;
            if (tmp > max) max = tmp;
            continue;
        }
        if (t == 'p') {
            scanf("%d", &tmp);
            p = tmp;
            continue;
        }
        if (t == 'r'){
            step++;
            //printf("ok\n");
            if (p == 1) {
                flag = 0;
                for (int i = min; i <= max; ++i) {
                    if (pro[i] > 0) {
                        pro[i]--;
                        flag = 1;
                        min = i;
                        //printf("%d\n", i);
                        //printf("%d %d\n", step, r[step]);
                        if (r[step]) printf("%d\n", i);
                        break;
                    }
                }
                //printf("%d\n", flag);
                if (!flag) {
                    printf("-1\n");
                    continue;
                }
            }
            if (p == 2) {
                flag = 0;
                for (int i = max; i >= min; --i) {
                    if (pro[i] > 0) {
                        pro[i]--;
                        flag = 1;
                        max = i;
                        if (r[step]) printf("%d\n", i);
                        break;
                    }
                }
                if (!flag) {
                    printf("-1\n");
                    continue;
                }
            }
        }
    }
}

int main() {
    int n, removal, tmp;
    while (scanf("%d", &n) != EOF) {
        p = 1;
        memset(pro, 0, sizeof(pro));
        memset(r, 0, sizeof(r));
        scanf("%d", &removal);
        for (int i = 0; i < removal; ++i) {
            scanf("%d", &tmp);
            r[tmp] = 1;
        }
        manager(n);
    }
}