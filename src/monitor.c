#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curses.h>

#include "display.h"

int
main (void) {
	WINDOW * mainwin;

	if (display_init (mainwin)) {
		exit (EXIT_FAILURE);
	}

	mvaddstr (13, 33, "Hello world!");
	refresh ();
	sleep (3);

	display_free (mainwin);

	return EXIT_SUCCESS;
}
