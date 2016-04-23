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

	initscr ();

	block_init (&main, 15,40,0,0);
	draw_main (&main);

	block_init (&cpu_usage, 12,7,1,6);
	block_init (&mem_usage, 12,7,1,14);
	block_init (&disk_usage, 12,7,1,22);
	block_init (&cpu_heat, 12,7,1,30);

	/**
	 * Main routine of the program.
	 * Update display continuously.
	 */
	while (1) {
		getchar ();
	}

	block_free (&cpu_heat);
	block_free (&disk_usage);
	block_free (&mem_usage);
	block_free (&cpu_usage);
	block_free (&main);
	endwin ();

	return EXIT_SUCCESS;
}
