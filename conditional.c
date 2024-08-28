#include <stdio.h>

int main() {
    printf("What temperature is it?");
    
    // read in temperature
    int temp;
    scanf("%d", &temp);

    if (temp > 70) {
        printf("It's hot");
    } else if (temp >= 30) {
        printf("It's mild");
    } else {
        printf("It's cold");
    }

    return 0;
}