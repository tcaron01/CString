#include <stdio.h>
#include "string.h"

int main() {
    String *s = create("ezaezaeazeza");
    printf("%s\n", data(s));
    free_string(&s);
    return 0;
}