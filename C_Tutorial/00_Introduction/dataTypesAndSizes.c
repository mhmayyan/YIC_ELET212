#include <stdio.h>
#include <stdint.h>

int main( void )
{
     printf( "  sizeof( char ): %d and sizeof( int8_t ): %d are equivalent \n",
             sizeof( char ), sizeof( int8_t ));
     printf( "  sizeof( unsigned char ): %d and sizeof( uint8_t ): %d are equivalent \n",
             sizeof( unsigned char ), sizeof( uint8_t ));

     printf( "  sizeof( short int ): %d\n",
             sizeof( short int ) );
     printf( "sizeof( short int * ): %d\n",
             sizeof( short int * ) );

     printf( "  sizeof( int ): %d\n",
             sizeof( int ) );

     printf( "  sizeof( long int ): %d\n",
             sizeof( long int ) );

     printf( "  sizeof( long ): %d\n",
             sizeof( long ) );

     printf( "  sizeof( long long int ): %d\n",
             sizeof( long long int ) );

     printf( "  sizeof( float ): %d\n",
             sizeof( float ) );

     printf( "  sizeof( double ): %d\n",
             sizeof( double ) );

     printf( "  sizeof( long double ): %d\n",
             sizeof( long double ) );

     return 0;
}