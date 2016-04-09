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

	while (1) {
		display_update ();
	}

	display_free (mainwin);

	return EXIT_SUCCESS;
}
