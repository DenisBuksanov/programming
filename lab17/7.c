#include "8.h"
#include <wchar.h>
#include <wctype.h>

bool pal(const wchar_t* str) {
    if (str == NULL) return false;
    
    int left = 0;
    int right = wcslen(str) - 1;
    
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int glas(const wchar_t* str) {
    if (str == NULL) return 0;
    
    int count = 0;
    const wchar_t* vowels = L"аеёиоуыэюяАЕЁИОУЫЭЮЯ";
    
    for (int i = 0; str[i] != L'\0'; i++) {
        if (wcschr(vowels, str[i]) != NULL) {
            count++;
        }
    }
    return count;
}
