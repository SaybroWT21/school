#include <stdio.h>
#include <math.h>

int main(void) {
    char cmd;
    float curr_re = 0.0;
    float curr_im = 0.0;

    printf("** Complex Calculator **\n");

    do {
        float new_re = 0.0;
        float new_im = 0.0;
        int power = 0;

        printf("Operation [0+-*crpq]? ");
        scanf(" %c", &cmd);
        
        if (cmd == '+' || cmd == '-' || cmd == '*') {
            printf("Complex operand? ");
            scanf(" %f %f", &new_re, &new_im);
        } else if (cmd == 'r') {
            printf("Natural operand? ");
            scanf(" %d", &power);
        }
        
        if (cmd == '+') {
            curr_re = curr_re + new_re;
            curr_im = curr_im + new_im;
        } else if (cmd == '-') {
            curr_re = curr_re - new_re;
            curr_im = curr_im - new_im;
        } else if (cmd == '0') {
            curr_re = 0.0;
            curr_im = 0.0;
        } else if (cmd == 'c') {
            curr_im = -1 * curr_im;
        } else if (cmd == '*') {
            float tmp_re = curr_re * new_re - curr_im * new_im;
            float tmp_im = curr_re * new_im + curr_im * new_re;
            curr_re = tmp_re;
            curr_im = tmp_im;
        } else if (cmd == 'r') {
            float tmp_re = curr_re;
            float tmp_im = curr_im;
            if (power == 0) {
                curr_re = 1.0;
                curr_im = 0.0;
            } else {
                for (int i = 1; i < power; i++) {
                    float stg_re = curr_re * tmp_re - curr_im * tmp_im;
                    float stg_im = curr_re * tmp_im + curr_im * tmp_re;
                    curr_re = stg_re;
                    curr_im = stg_im;
                }
            }
        } else if (cmd == 'p') {
            for (int i = 10; i >= -10; i--) {
                for (int j = -10; j <= 10; j++) {
                    if ((curr_re >= j && curr_re < j + 1) && (curr_im >= i && curr_im < i +1)) {
                        printf("*");
                    } else {
                        if (j == 0 && i == 0) {
                            printf("+");
                        } else {
                            if (j == 0) {
                                printf("|");
                            } else if (i == 0) {
                                printf("-");
                            } else {
                                printf(".");
                            }
                        }
                    }
                }
                printf("\n");
            }
        } else if (cmd != 'q') {
            printf("Invalid command \'%c\'\n", cmd);
        }

        if (curr_im < 0.0) {
            printf("Current value is %f%fi\n", curr_re, curr_im);
        } else {
            printf("Current value is %f+%fi\n", curr_re, curr_im);
        }
    } while (cmd != 'q');
    
    printf("Bye!\n");
    return 0;
}