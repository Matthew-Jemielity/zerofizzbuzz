#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

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

static void fizzbuzz( unsigned long int const i )
{
    typedef void ( * fizzbuzz_handler )( unsigned long int const i );

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

    ( actions[ mod15( i - 1 ) ] )( i );
}

static void usage( void )
{
    ( void ) puts( "Usage: fizzbuzz <inclusive positive limit>" );
    exit( EXIT_FAILURE );
}

static void noop( void )
{
    /* do nothing */
}

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

int main( int argc, char * argv[] )
{
    {
        typedef void ( * fn )( void );

        static fn const argc_check[ 2 ] =
        {
            usage,
            noop
        };

        ( argc_check[ 2 == argc ] )();
    }

    {
        typedef void ( * fn )( unsigned long int * const i );
        static fn const main_loop[ 2 ] =
        {
            breakout,
            operation
        };

        unsigned long int const from_user = strtoul( argv[ 1 ], NULL, 10 );
        unsigned long int iterator = 0U;

    MAIN_LOOP:
        ( main_loop[ from_user != iterator ] )( &iterator );
        goto MAIN_LOOP;
    }

    /* never reached */
    return 0;
}

