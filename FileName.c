#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PI 3.14 // ����� ��
#define n 10 // ������ �������
#define SCREENW 120 // ������ �������
#define SCREENH 30 // ������ �������


double F1(double x);  // ����������� ������� F1
double F2(double x);  // ����������� ������� F2

double integrand(double t, double d);

struct znachenia {
    double x; //�������� � 
    double* values;
    int count;// ���������� � 
    double* array;
    double xmin;
    double xmax;
    double dx;
};

struct znachenia* A(double xmin, double dx, double* values);  // ���������� ������ �������� x
struct znachenia* B(double* array, int N, double xmin, double xmax);  // ���������� ���������� ��������� ��������
void result(FILE* outputFile, double x, int func_num, double (*func)(double));  // ������� ��������� � ����
double find_min(double (*func)(double), double* values, int N);  // ������� ����������� ��������
double find_max(double (*func)(double), double* values, int N);  // ������� ������������ ��������
double differentiate(double (*func)(double), double x, double epsilon);  // ������������ �����������������
typedef double (*TFunc)(double);
void plot(double x0, double x1, TFunc f);
// �������� ������� ��� ��������� ������� �� �������� ���������
void tabulate(double (*func)(double), double xn, double xk, double h);



void menu(FILE* outputFile);  // ���� ��� ������ ��������


struct znachenia* mode1(const char* filename, struct znachenia* data);


int main() {

    setlocale(LC_CTYPE, "RUS");  // ��������� ������ ��� �������� �����
    FILE* outputFile = fopen("output.txt", "w");  // �������� ����� ��� ������
    menu(outputFile);  // ����� ����
    fclose(outputFile);  // �������� �����
    return 0;

}


void menu(FILE* outputFile) {
    int choice;
    struct znachenia x_for_formuls; // ��������� ������������ ��� ������������� ����� � 
    double  xn, xk, h, d, t;
    double values[n], xmin, xmax, dx, epsilon = 1e-5;
    int func_choice;
    double* array;

    while (1) {
        printf("������� ����:\n");
        printf("1. ���������� �������\n");
        printf("2. ��������� �������\n");
        printf("3. ��������� ���������� ��������� ��������\n");
        printf("4. ����������� ������������ � ������������� ��������\n");
        printf("5. ����������������� ������� � �������� �����\n");
        printf("6. ������ �������� f1\n");
        printf("7. ������ ������� f2\n");
        printf("8. �����\n");
        scanf("%d", &choice);  // ����� ������ ����

        switch (choice) {
        case 1:
            printf("�������� �������:\n1 - F1\n2 - F2\n3 - integrand\n");
            scanf("%d", &func_choice);  // ����� �������
            printf("������� �������� x, t, d:\n");
            scanf("%lf", &x_for_formuls.x);  // ���� �������� x
            scanf("%lf", &d);
            scanf("%lf", &t);
            fprintf(outputFile, "|x\t\t|F%d(x)\t\t|\n", func_choice);  // ����� � ����
            fprintf(outputFile, "-----------------------\n");
            switch (func_choice) {
            case 4: result(outputFile, x_for_formuls.x, 1, F1); break;  // ���������� � ����� ���������� ��� F1
            case 5: result(outputFile, x_for_formuls.x, 1, F2); break;  // ���������� � ����� ���������� ��� F2
            case 1:
                printf("%d\n", F1(x_for_formuls.x));
                mode1("FILE.txt", &x_for_formuls);
                break;  // ���������� � ����� ���������� ��� F1
            case 2:
                printf("%d\n", F2(x_for_formuls.x));
                mode1("FILE.txt", &x_for_formuls);
                break;  // ���������� � ����� ���������� ��� F2printf("%d", F2);  
            case 3:
                printf("%d\n", integrand);
                mode1("FILE.txt", &x_for_formuls);
                break; //���������� � ����� ���-�� ��� ������������� ��������� 

            default: printf("������������ ����� �������.\n");
            }
            break;
        case 2:
            printf("�������� �������:\n1 - F1\n2 - F2\n");
            scanf("%d", &func_choice);  // ����� �������
            printf("������� ��������� �������� (xmin):\n");
            scanf("%lf", &xmin);  // ���� xmin
            printf("������� ��� (dx):\n");
            scanf("%lf", &dx);  // ���� dx
            A(xmin, dx, values);  // ����� ������� A ��� ��������� ��������
            fprintf(outputFile, "|x\t\t|F%d(x)\t\t|\n", func_choice);  // ����� � ����
            fprintf(outputFile, "_________________________\n");
            for (int i = 0; i < n; i++) {  // ������� �������� � ���������� �������
                switch (func_choice) {
                case 1: fprintf(outputFile, "|%.5lf\t|%lf\t|\n", values[i], F1(values[i])); break;
                case 2: fprintf(outputFile, "|%.5lf\t|%lf\t|\n", values[i], F2(values[i])); break;



                default: printf("������������ ����� �������.\n"); break;
                }
            }
            break;
        case 3:
            printf("������� ��������� �������� (xmin):\n");
            scanf("%lf", &xmin);  // ���� xmin
            printf("������� �������� �������� (xmax):\n");
            scanf("%lf", &xmax);  // ���� xmax
            printf("������� ���������� �������� N:\n");
            scanf("%d", &x_for_formuls.count);  // ���� N
            array = (double*)malloc(x_for_formuls.count * sizeof(double));  // ��������� ������ ��� �������
            B(array, x_for_formuls.count, xmin, xmax);  // ����� ������� B ��� ��������� ���������� ��������� ��������
            fprintf(outputFile, "��������������� ���������� ��������:\n");
            for (int i = 0; i < x_for_formuls.count; i++) {
                fprintf(outputFile, "%lf\n", array[i]);  // ����� �������� � ����
            }
            free(array);  // ������������ ������
            break;
        case 4:
            printf("�������� �������:\n1 - F1\n2 - F2\n");
            scanf("%d", &func_choice);  // ����� �������
            printf("������� ��������� �������� (xmin):\n");
            scanf("%lf", &xmin);  // ���� xmin
            printf("������� �������� �������� (xmax):\n");
            scanf("%lf", &xmax);  // ���� xmax
            printf("������� ���������� �������� N:\n");
            scanf("%d", &x_for_formuls.count);  // ���� N

            array = (double*)malloc(x_for_formuls.count * sizeof(double));  // ��������� ������ ��� �������
            B(array, x_for_formuls.count, xmin, xmax);  // ��������� ���������� ��������

            double (*selected_func)(double) = NULL;  // ��������� �� ��������� �������
            switch (func_choice) {
            case 1: selected_func = F1; break;  // ����� F1
            case 2: selected_func = F2; break;  // ����� F2

            default:
                printf("������������ ����� �������.\n");
                free(array);
                return;
            }

            double* func_values = (double*)malloc(x_for_formuls.count * sizeof(double));  // ��������� ������ ��� �������� �������
            if (!func_values) {
                printf("������ ��������� ������ ��� ������� �������� �������.\n");
                free(array);
                return;
            }

            for (int i = 0; i < x_for_formuls.count; i++) {  // ���������� �������� ������� ��� ������� ���������
                func_values[i] = selected_func(array[i]);
            }

            double min_value = find_min(selected_func, func_values, x_for_formuls.count);  // ���������� ������������ ��������
            double max_value = find_max(selected_func, func_values, x_for_formuls.count);  // ���������� ������������� ��������

            printf("����������� ��������: %.5lf\n", min_value);  // ����� ������������ ��������
            printf("������������ ��������: %.5lf\n", max_value);  // ����� ������������� ��������

            free(func_values);  // ������������ ������
            free(array);  // ������������ ������
            break;


        case 5:
            printf("������� ����� ��� �����������������:\n");
            scanf("%lf", &x_for_formuls.x);  // ���� �����
            printf("����������� ������� F1 � ����� %.5lf: %.5lf\n", x_for_formuls.x, differentiate(F1, x_for_formuls.x, epsilon));  // ���������� �����������
            break;
        case 8:
            printf("����� �� ���������.\n");
            return;


        case 7:
            printf("������� ��������� �������� �������: \n");
            scanf("%lf", &xn);
            printf("������� �������� �������� �������: \n");
            scanf("%lf", &xk);
            plot(xn, xk, F1);
            break;


        case 6:
            printf("������� ��������� �������� �������: \n");
            scanf("%lf", &xn);
            printf("������� �������� �������� �������: \n");
            scanf("%lf", &xk);
            plot(xn, xk, F2);
            break;
        default:
            printf("������������ �����. ���������� �����.\n");
            break;
        }
    }
}

// ������� F1
double F1(double x) {
    if (x == 0 || x == PI) {
        return NAN;
    }
    return (-log(x / PI)) * cos(0.7 * x);
}

// ������� F2
double F2(double x) {
    if (x > -1) {
        return x + 1;
    }
    else if (-2 <= x && x <= -1) {
        return 1 - pow(x, 5);
    }
    else {
        return x + log(fabs(cos(x)));
    }
}
double integrand(double t, double d) {
    return (d * t) / log(t);
}


// ������� ���������� �������
void plot(double x0, double x1, TFunc f) {
    char screen[SCREENH][SCREENW];
    double x, y[SCREENW];
    double ymin = 0, ymax = 0;
    double hx, hy;
    int i, j;
    int xz, yz;

    hx = (x1 - x0) / (SCREENW - 1);

    // ������ �������� ��� ������ �����
    for (i = 0, x = x0; i < SCREENW; ++i, x += hx) {
        y[i] = f(x);
        if (y[i] < ymin) {
            ymin = y[i];
        }
        if (y[i] > ymax) {
            ymax = y[i];
        }
    }

    hy = (ymax - ymin) / (SCREENH - 1);
    yz = (int)floor((0.0 - ymin) / hy + 0.5);
    xz = (int)floor((0.0 - x0) / hx + 0.5);

    // ������������� ������� ���������
    for (j = 0; j < SCREENH; ++j) {
        for (i = 0; i < SCREENW; ++i) {
            screen[j][i] = ' ';
        }
    }

    // ����������� ����
    for (j = 0; j < SCREENH; ++j) {
        for (i = 0; i < SCREENW; ++i) {
            if (j == yz && i == xz) screen[j][i] = '+';
            else if (j == yz) screen[j][i] = '-';
            else if (i == xz) screen[j][i] = '|';
        }
    }

    // ����������� ��������� �������� 
    for (i = 0; i < SCREENW; ++i) {
        j = (int)floor((ymax - y[i]) / hy + 0.5);
        if (j >= 0 && j < SCREENH) screen[j][i] = '*';
    }

    // ������ ������� ��������
    for (j = 0; j < SCREENH; ++j) {
        for (i = 0; i < SCREENW; ++i) {
            putchar(screen[j][i]);
        }
        putchar('\n');
    }
}






struct znachenia* A(double xmin, double dx, double* values) {
    struct znachenia data;

    data.x = xmin;
    data.dx = dx;
    data.values = values;

    for (int i = 0; i < n; i++)
    {
        values[i] = xmin + i * dx;  // ��������� ������� �������� � ����� dx

    }

    return &data;
}
struct znachenia* B(double* array, int N, double xmin, double xmax) {
    struct znachenia data;
    int count = 0;
    while (count < N) {
        double num = xmin + (double)rand() / RAND_MAX * (xmax - xmin);  // ��������� ���������� �����
        int unique = 1;
        for (int i = 0; i < count; i++) {
            if (fabs(array[i] - num) < 1e-6) {  // �������� ������������ ��������
                unique = 0;
                break;
            }
        }
        if (unique) array[count++] = num;  // ���������� ����������� �������� � ������
    }
    data.xmax = xmax;
    data.array = array;
    //data.count = count;
    data.xmin = xmin;
    data.count = count;
    return &data;

}
void result(FILE* outputFile, double x, int func_num, double (*func)(double)) {
    fprintf(outputFile, "|%.3lf\t|%lf\t|\n", x, func(x));  // ����� ���������� � ����
}
double find_min(double (*func)(double), double* values, int N) {
    double min = values[0];
    for (int i = 1; i < N; i++)
        if (values[i] < min)  // ����� ������������ ��������
            min = values[i];
    return min;
}
double find_max(double (*func)(double), double* values, int N) {
    double max = values[0];
    for (int i = 1; i < N; i++)
        if (values[i] > max)  // ����� ������������� ��������
            max = values[i];
    return max;
}
double differentiate(double (*func)(double), double x, double epsilon) {
    return (func(x + epsilon) - func(x)) / epsilon;  // ������������ �����������������
}

struct znachenia* mode1(const char* filename, struct znachenia* data) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("������ �������� �����");
        return NULL;
    }
    //for (int i = 0; i < size; i++) {
    fprintf(file, "%lf %lf\n", data->x, data->count);

    fclose(file);
    printf("������ �������� � ���� %s\n", filename);
    return &data;
}