#include "prompt.h"


void Prompt()
{
    char hostname[1204] = "";
    gethostname(hostname, sizeof(hostname));
    printf("\x1B[33m" "%s : \x1B[35msau > " "\x1B[0m", getcwd(konum, 1024));
}

