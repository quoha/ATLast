// A T L A S T
//
// Autodesk Threaded Language Application System Toolkit
//
//  ATLast/primdeftest.c
//
//  Created by John Walker in January of 1990.
//  Copyright (c) 1990 John Walkder. All rights reserved.
//  Original at https://www.fourmilab.ch/atlast/atlast.html
//
//  Updated by Michael Henderson on 6/19/14.
//  Changes Copyright (c) 2014 Michael D Henderson. All rights reserved.
//
// Test primitive definition in Atlast
//

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "atldef.h"

prim ptime(void) {
    So(1);
    Push = time(NULL);
}

prim phhmmss(void) {
    struct tm *lt;

    Sl(1);
    So(2);
    lt = localtime(&S0);
    S0 = lt->tm_hour;
    Push = lt->tm_min;
    Push = lt->tm_sec;
}

static struct primfcn timep[] = {
    {"0TIME",   ptime},
    {"0HHMMSS", phhmmss},
    {NULL,      (codeptr) 0}
};

int main(int argc, const char *argv[]) {
    char t[132];
    atl_init();
    atl_primdef(timep);
    while (printf("-> "),
           fgets(t, 132, stdin) != NULL)
        atl_eval(t);
    return 0;
}

#endif