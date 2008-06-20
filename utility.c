/*

  ----------------------------------------------------
  httpry - HTTP logging and information retrieval tool
  ----------------------------------------------------

  Copyright (c) 2005-2008 Jason Bittel <jason.bittel@gmail.com>

*/

#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "error.h"

/* Strip leading and trailing spaces from parameter string, modifying
   the string in place and returning a pointer to the (potentially)
   new starting point */
char *strip_whitespace(char *str) {
        int len;

#ifdef DEBUG
        ASSERT(str);
        ASSERT(strlen(str) > 0);
#endif

        while (isspace(*str)) str++;
        len = strlen(str);
        while (len && isspace(*(str + len - 1)))
                *(str + (len--) - 1) = '\0';

        return str;
}

/* Function originated as strcasecmp() from the GNU C library; modified
   from its original format since s2 will always be lowercase

   Compare s1 and s2, ignoring case of s1, returning less than, equal
   to or greater than zero if s1 is lexiographically less than, equal
   to or greater than s2.  */
int strcmp_name(const char *s1, const char *s2) {
        unsigned char c1, c2;

#ifdef DEBUG
        ASSERT(s1 != s2);
#endif

        do {
                c1 = tolower(*s1++);
                c2 = *s2++;
                if (c2 == '\0') break;
        } while (c1 == c2);

        return c1 - c2;
}
