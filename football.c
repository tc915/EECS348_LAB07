#include <stdio.h>

void find_combinations(int score)
{
    // print header
    printf("Possible combinations of scoring plays for %d:\n\n", score);

    // iterate through all combinations of plays
    // loop through possible 8 points plays
    for (int td2pt = 0; td2pt * 8 <= score; td2pt++)
    {
        // loop through possible 7 point plays
        for (int tdfg = 0; tdfg * 7 <= score; tdfg++)
        {
            // loop through possible 6 point plays
            for (int td = 0; td * 6 <= score; td++)
            {
                // loop through possible 3 point plays
                for (int fg = 0; fg * 3 <= score; fg++)
                {
                    // find remaining points after accounting for current combination
                    int remaining = score - (td2pt * 8 + tdfg * 7 + td * 6 + fg * 3);
                    // check if remaining points can be made up with safeties
                    if (remaining >= 0 && remaining % 2 == 0)
                    {
                        // find number of safeties needed
                        int safety = remaining / 2;
                        // print combination
                        printf("%d TD + 2pt, %d TD + FG, %d TD, %d FG, %d Safety\n", td2pt, tdfg, td, fg, safety);
                    }
                }
            }
        }
    }
}

int main()
{
    int score; // score variable

    while (1) // loop until the user enters 0 or 1
    {
        // get user input
        printf("\nEnter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        // read user input
        scanf("%d", &score);
        // if the user enters a negative number, end program
        if (score < 0)
        {
            printf("Invalid score. Score must be 2 or higher\n");
            break;
        }
        // exit condition for when the user enters 0 or 1
        if (score <= 1)
        {
            break;
        }

        if (score < 2)
        {
            printf("Invalid score. Score must be 2 or higher\n");
            continue;
        }
        // find valid score combinations
        find_combinations(score);
    }
    return 0;
}