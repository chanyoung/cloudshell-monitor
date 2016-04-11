#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curses.h>

#include "display.h"

/**
 * Main function 
 */
int
main (void) {
	WINDOW * mainwin;

	if (display_init (mainwin)) {
		exit (EXIT_FAILURE);
	}

	/**
	 * Main routine of the program.
	 * Update display continuously.
	 */
	while (1) {
		display_update ();
		refresh ();
	}

	display_free (mainwin);

	return EXIT_SUCCESS;
}
