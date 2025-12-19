#include <stdio.h>
#include <string.h>

int main() {
    char text[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";
    int len = strlen(text);
    int end = len;
    char out[1000];
    int k = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (text[i] == ' ' || i == 0) {
            int start = i;
            if (i == 0) 
            start = -1;
            for (int j = start + 1; j < end; j++) {
                out[k] = text[j];
                k++;
            }
            if (i > 0) {
            out[k] = ' ';
            k++;
            }
            end = i;
        }
    }

    printf("%s\n", out);
    return 0;
}
