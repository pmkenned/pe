#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char buffer[1024*20];

static void
read_file()
{
    FILE * fp = fopen("../words.txt", "r");
    if (fp == NULL) {
        perror("error");
        exit(1);
    }

    size_t n = fread(buffer, 1, sizeof(buffer), fp);
    if (n < sizeof(buffer)) {
        if (ferror(fp)) {
            perror("error");
            exit(1);
        }
    }
    if (!feof(fp)) {
        fprintf(stderr, "buffer size insufficient\n");
        exit(1);
    }
    fclose(fp);
}

size_t num_tokens = 0;
size_t tokens_cap = 10;
char ** tokens = NULL;

static void
get_tokens()
{
    tokens = malloc(sizeof(*tokens)*tokens_cap);
    char * tok;
    char * ptr = buffer;
    while ((tok = strtok(ptr, ",\n")) != NULL) {
        ptr = NULL;
        size_t l = strlen(tok);
        tok[l-1] = '\0';
        tok++;
        tokens[num_tokens++] = tok;
        if (num_tokens >= tokens_cap) {
            tokens_cap *= 2;
            tokens = realloc(tokens, sizeof(*tokens)*tokens_cap);
        }
    }
}

static int
tri_value(const char * s)
{
    int sum = 0;
    while (*s)
        sum += *s++ - 'A' + 1;
    return sum;
}

int main()
{
    size_t i;
    read_file();
    get_tokens();

    int count = 0;
    for (i = 0; i < num_tokens; i++) {
        int t = tri_value(tokens[i]);
        int r = sqrt(2*t);
        if (r*(r+1) == 2*t)
            count++;
    }
    printf("%d\n", count);

    return 0;
}
