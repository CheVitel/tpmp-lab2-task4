#include <stdio.h>
#include "military.h"

int main(void)
{
        const char *infile = "data.txt";
        const char *outfile = "result.txt";

        write_file(infile);
        view_file(infile);

        printf("\nВоеннослужащие в звании лейтенант:\n\n");
        read_and_filter(infile, outfile);

        printf("\nСодержимое файла с результатами:\n");
        view_file(outfile);

        return 0;
}
