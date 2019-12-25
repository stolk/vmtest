#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

#include "pseudorand.h"

#define NUMITER		40

int main( int argc, char* argv[] )
{
	if ( argc != 3 )
	{
		fprintf( stderr, "Usage: %s numused capacity\n", argv[0] );
		exit( 1 );
	}

	const int numused  = atoi( argv[1] );
	const int capacity = atoi( argv[2] );

	const size_t bufsz = capacity * sizeof( uint64_t );

	for ( int iter=0; iter<NUMITER; ++iter )
	{
		uint64_t* buf = (uint64_t*) malloc( bufsz );

		for ( int i=0; i<numused; ++i )
			buf[ i ] = pseudorand();

		uint64_t result = 0;
		for ( int i=0; i<numused; ++i )
			result = result ^ buf[ i ];

		// Leave the last buffer intact, so we can measure resident size.
		if ( iter != NUMITER-1 )
			free( buf );
	}

	const pid_t p = getpid();
	char cmd[128];
	snprintf( cmd, sizeof(cmd), "cat /proc/%d/status", p );
	system( cmd );
}

