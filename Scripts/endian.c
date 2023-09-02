#include <stdio.h>

void show_mem_rep(char * start, int n) {
    for(int i = 0; i < n; ++i) printf(" %.2x", start[i]);
    printf("\n");
}

int main() {
    int i = 0x12345678;
    show_mem_rep((char *)&i, sizeof(i));
    return 0;
}