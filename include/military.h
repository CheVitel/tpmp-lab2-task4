#ifndef MILITARY_H
#define MILITARY_H

typedef struct {
        char lastname[50];
        char firstname[50];
        char middlename[50];
        char nationality[50];
        char position[50];
        char rank[50];
        int birth_year;
        int birth_month;
        int birth_day;
} Military;

void write_file(const char *filename);
void read_and_filter(const char *filename, const char *outfile);
void print_record(Military *m);
void view_file(const char *filename);

#endif
