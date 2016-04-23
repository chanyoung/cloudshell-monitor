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

	if (!initscr ()) {
		fprintf (stderr, "Err: Initializing screen.\n");
		exit (1);
	}
	if (!has_colors ()) {
		fprintf (stderr, "Err: Terminal doesn't support colors.\n");
		exit (1);
	}
	start_color ();
	use_default_colors ();

	block_init (&main, NULL, 15, 40, 0, 0);
	draw_main (&main);

	block_init (&cpu_heat, NULL, 12, 7, 1, 30);
	block_init (&disk_usage, &cpu_heat, 12, 7, 1, 22);
	block_init (&mem_usage, &disk_usage, 12, 7, 1, 14);
	block_init (&cpu_usage, &mem_usage, 12, 7, 1, 6);

	/**
	 * Main routine of the program.
	 * Update display continuously.
	 */
	while (1) {
		cpu_usage.value = get_cpu_usage ();
		mem_usage.value = get_mem_usage ();
		disk_usage.value = 80;
		cpu_heat.value = get_cpu_heat ();
		block_update (&cpu_usage);
		getchar ();
	}

	block_free (&cpu_usage);
	block_free (&mem_usage);
	block_free (&disk_usage);
	block_free (&cpu_heat);
	block_free (&main);
	endwin ();

	return EXIT_SUCCESS;
}
