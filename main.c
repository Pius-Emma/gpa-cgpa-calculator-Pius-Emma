/* Name:RWOTOMIA PIUS EMMANUEL 
Registration Number: 25/U/BIE/01419/PE
*/



#include <stdio.h>

void printLine() {
    printf("=============================================================\n");
}
void printThinLine() {
    printf("--------------------------------------------------------------\n");
}

float getGradePoint(float score) {
    if (score >= 80) return 5.0;
    else if (score >= 70) return 4.0;
    else if (score >= 60) return 3.0;
    else if (score >= 50) return 2.0;
    else return 0.0;
}

const char* getGrade(float score) {
    if (score >= 80) return "A";
    else if (score >= 70) return "B";
    else if (score >= 60) return "C";
    else if (score >= 50) return "D";
    else return "F";
}

const char* getClassification(float cgpa) {
    if (cgpa >= 4.40) return "First Class";
    else if (cgpa >= 3.60) return "Second Class Upper";
    else if (cgpa >= 2.80) return "Second Class Lower";
    else if (cgpa >= 2.00) return "Pass";
    else return "Fail";
}

int main(void) {
    const char *sem1_codes[] = {
        "TEMB 1101", "TEMB 1102", "TEMB 1103", "TEMB 1104",
        "TEMB 1105", "TEMB 1106", "TEMB 1107", "TEMB 1108"
    };
    const char *sem2_codes[] = {
        "TEMB 1201", "TEMB 1202", "TEMB 1203", "TEMB 1204",
        "TEMB 1205", "TEMB 1206", "TEMB 1207", "TEMB 1208"
    };
    int sem1_credits[] = {4, 3, 3, 3, 3, 3, 2, 3};
    int sem2_credits[] = {4, 3, 3, 3, 3, 3, 3, 3};

    float sem1_scores[8], sem2_scores[8];
    float sem1_gp[8], sem2_gp[8];
    float sem1_weighted[8], sem2_weighted[8];
    int i;

    /* ── Semester I input ── */
    printLine();
    printf("SEMESTER ONE - SCORE ENTRY\n");
    printLine();
    printf("  %-12s  %s\n", "courseCode", "score");
    printThinLine();

    float sem1_weighted_sum = 0;
    int   sem1_total_credits = 0;

    for (i = 0; i < 8; i++) {
        printf("  %-12s : ", sem1_codes[i]);
        scanf("%f", &sem1_scores[i]);
        if (sem1_scores[i] < 0 || sem1_scores[i] > 100) {
            printf("Invalid score! Please enter a score between 0 and 100:\n");
            i--;
            continue;
        }
        sem1_gp[i]       = getGradePoint(sem1_scores[i]);
        sem1_weighted[i] = sem1_gp[i] * sem1_credits[i];
        sem1_weighted_sum   += sem1_weighted[i];
        sem1_total_credits  += sem1_credits[i];
    }
    float sem1_gpa = sem1_weighted_sum / sem1_total_credits;

    /* ── Semester II input ── */
    printf("\n");
    printLine();
    printf("SEMESTER TWO - SCORE ENTRY\n");
    printLine();
    printf("  %-12s  %s\n", "courseCode", "score");
    printThinLine();

    float sem2_weighted_sum = 0;
    int   sem2_total_credits = 0;

    for (i = 0; i < 8; i++) {
        printf("  %-12s : ", sem2_codes[i]);
        scanf("%f", &sem2_scores[i]);
        if (sem2_scores[i] < 0 || sem2_scores[i] > 100) {
            printf("Invalid score! Please enter a score between 0 and 100:\n");
            i--;
            continue;
        }
        sem2_gp[i]       = getGradePoint(sem2_scores[i]);
        sem2_weighted[i] = sem2_gp[i] * sem2_credits[i];
        sem2_weighted_sum   += sem2_weighted[i];
        sem2_total_credits  += sem2_credits[i];
    }
    float sem2_gpa = sem2_weighted_sum / sem2_total_credits;

    /* ── CGPA ── */
    float cgpa = (sem1_weighted_sum + sem2_weighted_sum) /
                 (sem1_total_credits + sem2_total_credits);

    /* ── Report ── */
    printf("\n\n");
    printLine();
    printf("KYAMBOGO UNIVERSITY ACADEMIC REPORT - YEAR 1\n");
    printf("Bachelors of Engineering in Biomedical and Mechatronics\n");
    printLine();

    /* Semester I table */
    printf("\n  SEMESTER ONE RESULTS\n");
    printThinLine();
    printf("  %-12s  %-7s  %-6s  %-11s  %-11s  %-14s\n",
           "courseCode", "score", "grade",
           "gradePoint", "creditUnits", "weightedContribution");
    printThinLine();
    for (i = 0; i < 8; i++) {
        printf("  %-12s  %-7.2f  %-6s  %-11.1f  %-11d  %.2f\n",
               sem1_codes[i], sem1_scores[i], getGrade(sem1_scores[i]),
               sem1_gp[i], sem1_credits[i], sem1_weighted[i]);
    }
    printThinLine();
    printf("  Total Credit Units : %d\n", sem1_total_credits);
    printf("  Total Weighted Contribution : %.2f\n", sem1_weighted_sum);

    /* Semester II table */
    printf("\n  SEMESTER TWO RESULTS\n");
    printThinLine();
    printf("  %-12s  %-7s  %-6s  %-11s  %-11s  %-14s\n",
           "courseCode", "score", "grade",
           "gradePoint", "creditUnits", "weightedContribution");
    printThinLine();
    for (i = 0; i < 8; i++) {
        printf("  %-12s  %-7.2f  %-6s  %-11.1f  %-11d  %.2f\n",
               sem2_codes[i], sem2_scores[i], getGrade(sem2_scores[i]),
               sem2_gp[i], sem2_credits[i], sem2_weighted[i]);
    }
    printThinLine();
    printf("  Total Credit Units : %d\n", sem2_total_credits);
    printf("  Total Weighted Contribution : %.2f\n", sem2_weighted_sum);

    /* Summary */
    printf("\n");
    printLine();
    printf("Semester One GPA: %.2f\n", sem1_gpa);
    printf("Semester Two GPA: %.2f\n", sem2_gpa);
    printf("Cumulative GPA: %.2f\n", cgpa);
    printf("Academic Classification: %s\n", getClassification(cgpa));
    printLine();

    return 0;
}
