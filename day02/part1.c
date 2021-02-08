#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *f = fopen("input", "r");
    if (NULL == f)
    {
        return 1;
    }

    int valid = 0;
    char *line = NULL;
    size_t len = 0;
    int read = 0;
    while ((read = getline(&line, &len, f)) != -1)
    {
        // Parse password
        char *numbers = strtok(line, " ");
        char c = strtok(NULL, " ")[0];
        char *password = strtok(NULL, " ");
        password[strlen(password) - 1] = '\0';
        uint8_t min = atoi(strtok(numbers, "-"));
        uint8_t max = atoi(strtok(NULL, "-"));

        // Check password
        uint8_t number = 0;
        for (int i = 0; i < strlen(password); i++)
        {
            if (c == password[i])
            {
                number++;
            }
        }
        if (number <= max && number >= min)
        {
            valid++;
        }
    }
    printf("%d passwords are valid\n", valid);
    fclose(f);
}
