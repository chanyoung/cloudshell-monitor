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
	struct block main, cpu_usage, mem_usage, disk_usage, cpu_heat;

/*
	if (display_init (mainwin)) {
		exit (EXIT_FAILURE);
	}
*/

	initscr ();

	main.window = newwin (15,40,0,0);
	box (main.window, 0, 0);
	touchwin (main.window);
	wrefresh (main.window);

	cpu_usage.window = newwin (12,7,1,7);
	mem_usage.window = newwin (12,7,1,15);
	disk_usage.window = newwin (12,7,1,23);
	cpu_heat.window = newwin (12,7,1,31);

	box (cpu_usage.window, 0, 0);
	wrefresh (cpu_usage.window);
	
	box (mem_usage.window, 0, 0);
	wrefresh (mem_usage.window);

	box (disk_usage.window, 0, 0);
	wrefresh (disk_usage.window);

	box (cpu_heat.window, 0, 0);
	wrefresh (cpu_heat.window);

	getchar ();

	/**
	 * Main routine of the program.
	 * Update display continuously.
	 */
/*
	while (1) {
		display_update ();
		refresh ();
	}
*/
	endwin ();

//	display_free (mainwin);

	return EXIT_SUCCESS;
}
