#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void input(char s[]);
void compute(char s[], int a[], int* b, int* c);
void output(int a[], int b, int c);

int main() {
    char s[200];
    int a[26] = { 0 };
    int b = 0;
    int c = 0;

    input(s);
    compute(s, a, &b, &c);
    output(a, b, c);

    return 0;
}

void input(char s[]) {
    printf("문장을 입력하세요:\n");
    fgets(s, 200, stdin);
}

void compute(char s[], int a[], int* b, int* c) {
    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];

        if (ch >= 'A' && ch <= 'Z') {
            a[ch - 'A']++;
        }
        else if (ch >= 'a' && ch <= 'z') {
            a[ch - 'a']++;
        }
        else if (ch >= '0' && ch <= '9') {
            (*b)++;
        }
        else {
            (*c)++;
        }
    }
}

void output(int a[], int b, int c) {
    printf("\n[알파벳 개수]\n");
    for (int i = 0; i < 26; i++) {
        if (a[i] > 0)
            printf("%c : %d\n", 'A' + i, a[i]);
    }

    printf("\n숫자 : %d\n", b);
    printf("기타 문자 : %d\n", c);
}
