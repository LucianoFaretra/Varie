void invertiArray( const int array[], size_t zero, size_t grandezzaArray )
{
    if( zero < grandezzaArray ){
        someFunction( array, zero + 1, grandezzaArray );
        printf("%d", array[ zero ] );
    }
return;
}
