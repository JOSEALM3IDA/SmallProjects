#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *cs;
int length, k;
char *pw;
unsigned long long int pwCount = 0;

// Generate all possible combinations (with length k) of given ascii characters
void recursive(int pos) {
    int p;
    if (pos == k - 1)
        for (p = 0; p < length; p++) {
            pw[pos] = cs[p];
            printf("%s\t", pw);
            pwCount++;
        }
    else
        for (p = 0; p < length; p++) {
            pw[pos] = cs[p];
            recursive(pos + 1);
        }
}

int main(int argc, char **argv) {
    int i;
    if (argc != 3) {
        printf("Usage: %s <password length> <ASCII char list (string)>", argv[0]);
        return;
    }

    cs = malloc(sizeof(argv[2]));
    if (cs == NULL)
        return -1;
    strcpy(cs, argv[2]);
    length = strlen(cs);
    k = atoi(argv[1]);
    pw = malloc(sizeof(char) * (k + 1));
    if (pw == NULL)
        return -1;

    for (i = 0; i < k + 1; i++)
        pw[i] = '\0';
    
    recursive(0);
    printf("\nNumber of passwords generated: %llu\n", pwCount);
    return 0;
}