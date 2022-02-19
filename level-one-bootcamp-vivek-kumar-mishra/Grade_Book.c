#include <stdio.h>

struct studDetails{
    char name[100];
    int scores[100];
    float average;
    char grade;
};

typedef struct studDetails Student;

struct reportCard {
    char subjectName[100];
    int no_scores, no_students;
    float weights[100];
    Student student[100];
};

typedef struct reportCard gradebook;

Student input_one_student(int no_scores)
{
    Student stud;
    printf("Enter the name of student:\n");
    scanf("%s", &stud.name);
    printf("Enter the scores:\n");
    for (int i = 0; i < no_scores; i++)
        scanf("%d", &stud.scores[i]);
    return stud;
}

gradebook input_one_gradebook()
{
    gradebook g;
    printf("Name of the course:\n");
    scanf("%s", &g.subjectName);
    printf("Number of students and number of weights:\n");
    scanf("%d %d", &g.no_students, &g.no_scores);
    printf("Enter weights: \n");
    for (int i = 0; i < g.no_scores; i++)
        scanf("%f", &g.weights[i]);
    for (int i = 0; i < g.no_students; i++)
        g.student[i] = input_one_student(g.no_scores);
    return g;
}

void input_n_gradebooks(int n, gradebook gb[])
{
    for (int i = 0; i < n; i++)
        gb[i] = input_one_gradebook();
}

char compute_grade(Student stud)
{
    if (stud.average >= 0 && stud.average < 60)
        stud.grade = 'F';

    else if (stud.average >= 60 && stud.average < 70)
        stud.grade = 'D';

    else if (stud.average >= 70 && stud.average < 80)
        stud.grade = 'C';

    else if (stud.average >= 80 && stud.average < 90)
        stud.grade = 'B';

    else
        stud.grade = 'A';

    return stud.grade;

}

void compute_one_gradebook(gradebook *pg)
{
    float sum = 0, weightSum = 0;

    for (int i = 0; i < pg->no_scores; i++)
        weightSum += pg->weights[i];

    for (int i = 0; i < pg->no_students; i++)
    {
        sum = 0;

        for (int j = 0; j < pg->no_scores; j++)
            sum += pg->student[i].scores[j] * pg->weights[j];

        pg->student[i].average = sum / weightSum;
        pg->student[i].grade = compute_grade(pg->student[i]);
    }
}

void compute_n_gradebooks(int n, gradebook gb[n])
{
    for (int i = 0; i < n; i++)
        compute_one_gradebook(&gb[i]);
}

void print_one_student(Student stud)
{
    printf("%s \t %.2f %c\n", stud.name, stud.average, stud.grade);
}


void print_n_student(int n, gradebook gb[n])
{
    for (int i = 0; i < n; i++)
    {
        printf("%s \n", gb[i].subjectName);
        for (int j = 0; j < gb[i].no_students; j++)
            print_one_student(gb[i].student[j]);
    }
}


int main()
{
    int n;
    printf("Enter the number of gradebook: \n");
    scanf("%d", &n);
    gradebook gb[n];
    input_n_gradebooks(n, gb);
    compute_n_gradebooks(n, gb);
    print_n_student(n, gb);
    return 0;
}