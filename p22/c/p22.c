#include "../../common/common.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char buffer[1024*47];
const size_t buffer_size = sizeof(buffer);

size_t list_cap = 10;
size_t list_num = 0;
char ** list = NULL;

static int
cmpstr(const void * a, const void * b)
{
    return strcmp(*(char * const *)a, *(char * const *)b);
}

static int
alpha_value(const char * s)
{
    int sum = 0;
    char c;
    while ((c = *s++) != '\0')
        sum += c - 'A' + 1;
    return sum;
}

static void
make_list()
{
    list_cap = 10;
    list_num = 0;
    list = malloc(sizeof(*list)*list_cap);
    char * tok;
    char * ptr = buffer;
    while ((tok = strtok(ptr, ",\n")) != NULL) {
        size_t l = strlen(tok);
        tok[l-1] = '\0';
        tok++;
        ptr = NULL;
        list[list_num] = tok;
        list_num++;
        if (list_num >= list_cap) {
            list_cap *= 2;
            list = realloc(list, sizeof(*list)*list_cap);
        }
    }
}

static int
calc_answer()
{
    int i;
    int sum = 0;
    for (i = 0; i < (int) list_num; i++) {
        int av = alpha_value(list[i]);
        sum += av*(i+1);
    }
    return sum;
}

/*
    sort names.txt into alphabetical order
    multiply the alphabetical value of each name by its alphabetical position in the list to obtain a name score

    example:
        COLIN is worth 3 + 15 + 12 + 9 + 14 = 53
        when the list is sorted into alphabetical order, COLIN is the 938th name in the list
        so, COLIN would obtain a score of 938 × 53 = 49714

    What is the total of all the name scores in the file?
*/
int main()
{
    read_file("../names.txt", buffer, sizeof(buffer));

    make_list();

    qsort(list, list_num, sizeof(char*), &cmpstr);

    int answer = calc_answer();

    printf("%d\n", answer);

    return 0;
}
