#include <stdio.h>
#include <ncurses.h>

#include "cpustat.h"

/**
 * The period of program. (sec)
 */
#define SLEEP_TIME 1

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
	mvprintw (0, 0, "========================================");
	mvprintw (1, 0, "========================================");
	mvprintw (2, 0, "====== Welcome to the phdpark.com ======");
	mvprintw (3, 0, "========================================");
	mvprintw (4, 0, "Cpu usage:%3d%%", get_cpu_usage());
	sleep (SLEEP_TIME);
}
