#include <stdio.h>

int main() {
    // the values of each possible point source are set as constants here.
    const int TD_2PC = 8;
    const int TD_1PC = 7;
    const int TD = 6;
    const int FG = 3;
    const int SAFETY = 2;

    // this block of code takes the user input for the possible scores.
    int score;
    printf("Enter 0 or 1 to STOP\n");
    printf("Enter the NFL score: ");
    scanf("%d", &score);
    if (score <= 1) { // since there are no possible points worth less than 2, exit
        return 0;
    }

    int counts[5] = {0, 0, 0, 0, 0}; // TD_2PCs, TD_1PCs, TDs, FGs, SAFETYs
    printf("Possible combinations of scoring plays if a team's score is 25:\n\n");
    /*
     * These nested loops loop through many possible combinations and validates them
     * during the if statement. Each for loop corresponds to a different source of
     * score in the NFL (2pc, 1pc, td, fg, safety). The counts[] variable will keep
     * track of how many of each type of point are currently being assessed, while
     * the increment variables (i, j, k, l, m) are counted up in the if statement to
     * check if they all add up to the user-inputted score. If they are, the counts
     * are printed out in the printf() statement.
     */
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
