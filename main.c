#include <stdio.h>

int main() {
    FILE *infile = fopen("answers.txt", "r");
    FILE *outfile = fopen("result.txt", "w");
    int score = 0, ans, i;

    if (infile == NULL || outfile == NULL) {
        printf("File error.\n");
        return 1;
    }

    for (i = 0; i < 3; i++) {
        fscanf(infile, "%d", &ans);
        score += ans;
    }

    fprintf(outfile, "Your mindfulness score is: %d\n", score);

    if (score <= 4)
        fprintf(outfile, "Tip: Take 10 mins to sit quietly. Breathe. 💆‍♀️\n");
    else if (score <= 7)
        fprintf(outfile, "Tip: You're halfway there! Go for a short walk. 🚶‍♀️\n");
    else
        fprintf(outfile, "Awesome! You're in tune with yourself! 🌟\n");

    fclose(infile);
    fclose(outfile);
    printf("Done! Check result.txt\n");
    return 0;
}