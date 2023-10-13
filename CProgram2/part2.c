#include <stdio.h>

void generate_combinations(int score) {
    int td, fg, safety;

    for (td = 0; td * 6 <= score; td++) {
        for (fg = 0; fg * 3 <= score - td * 6; fg++) {
            for (safety = 0; safety * 2 <= score - td * 6 - fg * 3; safety++) {
                if ((td * 6 + fg * 3 + safety * 2) == score) {
                    printf("%d TD + %d FG + %d Safety\n", td, fg, safety);
                }
            }
        }
    }
}

int main() {
    int score;

    while (1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        if (score <= 1) {
            break;
        }

        printf("Possible combinations of scoring plays:\n");
        generate_combinations(score);
    }

    return 0;
}
