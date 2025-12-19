#include <stdio.h>
int main() {
    char text[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";
    char new_text[1000]; 
    int i = 0; 
    int j = 0; 
    
    new_text[j] = '?';
    j++;
    while (text[i] != '\0') {
        if (text[i] == ' ') {
            new_text[j] = ' ';
            j++;
            new_text[j] = '?';
            j++;
        } else {
            new_text[j] = text[i];
            j++;
        }
        i++; 
    }
    printf("%s\n", new_text);
    return 0;
}
