#include <stdlib.h>
#include <stdio.h>

void append( char *s1, const char *s2 )
{
    while( *s1 != '\0' ){
        ++s1;
    }

    while(*s1 = *s2){
        ++s1, ++s2;
    }

return;
}
