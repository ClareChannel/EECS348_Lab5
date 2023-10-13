//Elizabeth Channel//
//Lab 5 - Part two//
//NFL Score//

#include <stdio.h>


//generate function//
void generate_combinations(int score) {
    //set up variables for touchodwn, fieldgoal, and saftey//
    int td, fg, safety;

    //touchdown set to zero, touchdowns time 6 is less than equal to score, add touchdown//
    for (td = 0; td * 6 <= score; td++) {
        //fieldgoal set to zero, number of fgs times three is less than score touchdown, add//
        for (fg = 0; fg * 3 <= score - td * 6; fg++) {
            //saftey set to zero, times two less than equal to score minus touchdown minus fieldgoal, add/
            for (safety = 0; safety * 2 <= score - td * 6 - fg * 3; safety++) {
                //if # of td times 6 plus #of fieldgoals times 3 + # of safety times 2 is score//
                if ((td * 6 + fg * 3 + safety * 2) == score) {
                    //print possibilities//
                    printf("%d TD + %d FG + %d Safety\n", td, fg, safety);
                }
            }
        }
    }
}

//main function//
int main() {
    //variable for score//
    int score;

    //loop//
    while (1) {
        //print intructions for user to input//
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        //user input score//
        scanf("%d", &score);

        //if input score is 1 or less//
        if (score <= 1) {
            //end program//
            break;
        }

        //otherwise print the possible combinations//
        printf("Possible combinations of scoring plays:\n");
        generate_combinations(score);
    }

    return 0;
}
