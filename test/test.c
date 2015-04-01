/**
 * \author      Mateusz Jemielity matthew.jemielity@gmail.com
 * \brief       Tests for zerofizzbuzz.
 * \date        03/28/2015 04:33:14 AM
 * \file        test.c
 * \version     2.0
 *
 * Tests basic assumptions about functions core to zerofizzbuzz.
 **/

#include <assert.h> /* assert */
#include <stdio.h> /* puts */

static unsigned long int div15_exit(
    unsigned long int const i,
    unsigned long int const result
)
{
    ( void ) i;
    return result - 1;
}

static unsigned long int div15_loop(
    unsigned long int const i,
    unsigned long int const result
)
{
    typedef unsigned long int (* div_loop_func)(
        unsigned long int const i,
        unsigned long int const result
    );

    static div_loop_func const divider[ 2 ] =
    {
        div15_exit,
        div15_loop
    };

    return divider[ i >= 15 ]( i - 15, result + 1 );
}

static unsigned long int div15( unsigned long int const i )
{

    return div15_loop( i, 0 );
}

static unsigned long int mod15( unsigned long int const i )
{
    unsigned long int const division = div15( i );
    return i - (( division << 4 ) - division );
}

int main( int argc, char * args[] )
{
    unsigned long int const limit = 1000000U;

    ( void ) argc;
    ( void ) args;

    printf( "testing div15: 0 to %lu\n", limit );
    {
        unsigned long int i;

        for( i = 0; i < limit; ++i )
        {
            assert(( i / 15 ) == div15( i ));
        }
    }
    puts( "ok" );

    printf( "testing mod15: 0 to %lu\n", limit );
    {
        unsigned long int i;

        for( i = 0; i < limit; ++i )
        {
            assert(( i % 15 ) == mod15( i ));
        }

    }
    puts( "ok" );

    return 0;
}

