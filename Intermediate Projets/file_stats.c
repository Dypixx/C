#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void countFileStats(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error: Unable to open file '%s'\n", filename);
        return;
    }

    int characters = 0, words = 0, lines = 0;
    char ch, prevChar = '\0';

    while ((ch = fgetc(file)) != EOF)
    {
        characters++;

        if (ch == '\n')
        {
            lines++;
        }

        if (isspace(ch) && !isspace(prevChar))
        {
            words++;
        }

        prevChar = ch;
    }

    if (characters > 0 && !isspace(prevChar))
    {
        words++;
    }
    lines += (characters > 0) ? 1 : 0;

    fclose(file);

    printf("\nFile Statistics for '%s':\n", filename);
    printf("Characters: %d\n", characters);
    printf("Words: %d\n", words);
    printf("Lines: %d\n", lines);
}

int main()
{
    char filename[100];

    printf("=========================\n");
    printf("   Created By @Dypixx\n");
    printf("=========================\n");
    printf("Enter the file name (with extension): ");
    scanf("%s", filename);

    countFileStats(filename);

    return 0;
}
