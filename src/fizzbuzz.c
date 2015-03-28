#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef void ( * fizzbuzz_handler )( unsigned long int const i );

static void handle_fizz( unsigned long int const i )
{
    ( void ) i;
    ( void ) puts( "fizz" );
}

static void handle_buzz( unsigned long int const i )
{
    ( void ) i;
    ( void ) puts( "buzz" );
}

static void handle_fizzbuzz( unsigned long int const i )
{
    ( void ) i;
    ( void ) puts( "fizzbuzz" );
}

static void handle_number( unsigned long int const i )
{
    ( void ) printf( "%lu\n", i );
}

static fizzbuzz_handler const actions[ 15 ] =
{
    handle_number,
    handle_number,
    handle_fizz,
    handle_number,
    handle_buzz,
    handle_fizz,
    handle_number,
    handle_number,
    handle_fizz,
    handle_buzz,
    handle_number,
    handle_fizz,
    handle_number,
    handle_number,
    handle_fizzbuzz
};

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

static void fizzbuzz( unsigned long int const i )
{
    ( actions[ mod15( i - 1 ) ] )( i );
}

typedef void ( * fn )( unsigned long int * const i );

static void usage( unsigned long int * const i )
{
    ( void ) i;
    ( void ) puts( "Usage: fizzbuzz <inclusive limit>" );
    exit( EXIT_FAILURE );
}

static void noop( unsigned long int * const i )
{
    ( void ) i;
}

static fn const argc_check[ 2 ] =
{
    usage,
    noop
};

static void breakout( unsigned long int * const i )
{
    ( void ) i;
    exit( EXIT_SUCCESS );
}

static void operation( unsigned long int * const i )
{
    fizzbuzz( *i + 1 );
    *i = *i + 1;
}

static fn const main_loop[ 2 ] =
{
    breakout,
    operation
};

int main( int argc, char * argv[] )
{
    /* argc is always at least 1 */
    ( argc_check[ !!( argc - 1 ) ] )( NULL );

    {
        unsigned long int const from_user = strtoul( argv[ 1 ], NULL, 10 );
        unsigned long int iterator = 0;

    MAIN_LOOP:
        ( main_loop[ 0 != ( iterator ^ from_user ) ] )( &iterator );
        goto MAIN_LOOP;
    }

    /* never reached */
    return 0;
}

