#include <stdlib.h>
#include <stdio.h>

int mystery2( const char *s )
{
    int x;

    x = 0;
    while( *s != '\0' ){
        ++x;
        ++s;
    }

return x;
}
