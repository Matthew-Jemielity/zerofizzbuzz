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
#include <limits.h> /* ULONG_MAX */
#include <stdio.h> /* puts */

static unsigned long int div15( unsigned long int const i )
{
    /* TODO: get rid of the division somehow */
    return i / 15;
}

static unsigned long int mod15( unsigned long int const i )
{
    unsigned long int const division = div15( i );
    return i - (( division << 4 ) - division );
}

int main( int argc, char * args[] )
{
    ( void ) argc;
    ( void ) args;

    puts( "testing div15" );
    {
        unsigned long int i;

        for( i = 0; i < ULONG_MAX; ++i )
        {
            assert(( i % 15 ) == div15( i ));
        }

        assert(( ULONG_MAX % 15 ) == div15( ULONG_MAX ));
    }
    puts( "ok" );

    puts( "testing mod15" );
    {
        unsigned long int i;

        for( i = 0; i < ULONG_MAX; ++i )
        {
            assert(( i % 15 ) == mod15( i ));
        }

        assert(( ULONG_MAX % 15 ) == mod15( ULONG_MAX ));
    }
    puts( "ok" );

    return 0;
}

