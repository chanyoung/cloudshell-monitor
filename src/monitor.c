#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curses.h>

int
main (void) {
	WINDOW * mainwin;

	if ((mainwin = initscr()) == NULL) {
					fprintf (stderr, "Error initialising ncurses.\n");
					exit (EXIT_FAILURE);
	}

	mvaddstr (13, 33, "Hello world!");
	refresh ();
	sleep (3);

	delwin (mainwin);
	endwin ();
	refresh ();

	return EXIT_SUCCESS;
}
