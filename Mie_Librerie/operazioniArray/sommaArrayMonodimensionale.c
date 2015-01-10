#include <stdio.h>
#include <stdlib.h>

int sommaArrayMonodimensionale( const int array[], size_t grandezzaArray )
{
    if( 1 == grandezzaArray ){
        return array[0];
    }
    else{
        return array[ grandezzaArray - 1 ] + sommaArrayMonodimensionale( array, grandezzaArray - 1 );
    }
return 0;
}
