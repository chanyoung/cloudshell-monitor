#include <stdio.h>
#include <ncurses.h>

int display_init (WINDOW * mainwin)
{
	if ((mainwin = initscr()) == NULL) {
		fprintf (stderr, "Error initialising ncurses.\n");
		return -1;
	}
	return 0;
}

int display_free (WINDOW * mainwin)
{
	if (mainwin == NULL)
		return -1;

	delwin (mainwin);
	endwin ();
	refresh ();
	return 0;
}

int display_update ()
{
	mvaddstr (13, 33, "Hello world!");
	refresh ();
	sleep (1);
}
