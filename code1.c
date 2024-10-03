#include <stdio.h>

int main() {
    const int TD_2PC = 8;
    const int TD_1PC = 7;
    const int TD = 6;
    const int FG = 3;
    const int SAFETY = 2;
    int score;
    printf("Enter 0 or 1 to STOP\n");
    printf("Enter the NFL score: ");
    scanf("%d", &score);
    if (score <= 1) {
        return 0;
    }

    int counts[5] = {0, 0, 0, 0, 0}; // TD_2PCs, TD_1PCs, TDs, FGs, SAFETYs
    printf("Possible combinations of scoring plays if a team's score is 25:\n\n");
    for (int i = 0; i <= score; i += TD_2PC) { // TD_2PC
        counts[1] = 0;
        for (int j = 0; j <= score; j += TD_1PC) { // TD_1PC
            counts[2] = 0;
            for (int k = 0; k <= score; k += TD) { // TD
                counts[3] = 0;
                for (int l = 0; l <= score; l += FG) { // FG
                    counts[4] = 0;
                    for (int m = 0; m <= score; m += SAFETY) { // SAFETY
                        if ((i + j + k + l + m) == score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", counts[0], counts[1], counts[2], counts[3], counts[4]);
                        }
                        counts[4]++;
                    }
                counts[3]++;
                }
            counts[2]++;
            }
        counts[1]++;
        }
    counts[0]++;
    }
    return 0;
}
