#include <stdio.h>
#include <string.h>
#include "military.h"

void write_file(const char *filename)
{
        FILE *f = fopen(filename, "w");
        if (f == NULL) {
                printf("Ошибка открытия файла\n");
                return;
        }

        fprintf(f, "Иванов Иван Иванович русский лейтенант пехота 1990 5 15\n");
        fprintf(f, "Петров Пётр Петрович белорус капитан артиллерия 1985 3 20\n");
        fprintf(f, "Сидоров Олег Сергеевич русский лейтенант танки 1992 7 10\n");
        fprintf(f, "Козлов Дмитрий Игоревич украинец майор связь 1980 1 25\n");
        fprintf(f, "Новиков Алексей Юрьевич русский лейтенант сапёры 1995 9 3\n");

        fclose(f);
        printf("Файл создан.\n");
}

void view_file(const char *filename)
{
        FILE *f = fopen(filename, "r");
        if (f == NULL) {
                printf("Ошибка открытия файла\n");
                return;
        }

        char line[256];
        printf("\nСодержимое файла %s:\n", filename);
        printf("-----------------------------------\n");
        while (fgets(line, sizeof(line), f) != NULL)
                printf("%s", line);
        printf("-----------------------------------\n");

        fclose(f);
}

void print_record(Military *m)
{
        printf("Фамилия: %s\n", m->lastname);
        printf("Имя: %s\n", m->firstname);
        printf("Отчество: %s\n", m->middlename);
        printf("Национальность: %s\n", m->nationality);
        printf("Звание: %s\n", m->rank);
        printf("Должность: %s\n", m->position);
        printf("Дата рождения: %d.%d.%d\n\n",
                m->birth_day, m->birth_month, m->birth_year);
}

void read_and_filter(const char *filename, const char *outfile)
{
        FILE *f = fopen(filename, "r");
        if (f == NULL) {
                printf("Ошибка открытия файла\n");
                return;
        }

        FILE *out = fopen(outfile, "w");
        if (out == NULL) {
                printf("Ошибка создания выходного файла\n");
                fclose(f);
                return;
        }

        Military m;
        int found = 0;

        while (fscanf(f, "%s %s %s %s %s %s %d %d %d",
                m.lastname, m.firstname, m.middlename,
                m.nationality, m.rank, m.position,
                &m.birth_year, &m.birth_month, &m.birth_day) == 9) {
                if (strcmp(m.rank, "лейтенант") == 0) {
                        print_record(&m);
                        fprintf(out, "%s %s %s %s %s %s %d %d %d\n",
                                m.lastname, m.firstname, m.middlename,
                                m.nationality, m.rank, m.position,
                                m.birth_year, m.birth_month, m.birth_day);
                        found = 1;
                }
        }

        if (!found)
                printf("Военнослужащих в звании лейтенант не найдено.\n");

        fclose(f);
        fclose(out);
        printf("Результаты сохранены в %s\n", outfile);
}
