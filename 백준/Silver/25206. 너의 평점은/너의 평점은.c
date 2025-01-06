#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 51

int main() {
    double class_hour = 0.0;
    double sum = 0.0;

    for (int i = 0; i < 20; i++) {
        char subject[MAX_SIZE] = {0};
        double now_class = 0.0;
        char grade[3] = {0};

        if (scanf("%50s %lf %2s", subject, &now_class, grade) != 3) {
            continue;
        }

        if (grade[0] == 'P') {
            continue;
        }

        double score = 0.0;
        if (grade[0] == 'A') {
            score = 4.0;
        } else if (grade[0] == 'B') {
            score = 3.0;
        } else if (grade[0] == 'C') {
            score = 2.0;
        } else if (grade[0] == 'D') {
            score = 1.0;
        } else if (grade[0] == 'F') {
            class_hour += now_class;
            continue;
        }

        if (grade[1] == '+') {
            score += 0.5;
        }

        sum += score * now_class;
        class_hour += now_class;
    }

    if (class_hour == 0) {
        printf("0.000000\n");
    } else {
        printf("%.6f\n", sum / class_hour);
    }

    return 0;
}
