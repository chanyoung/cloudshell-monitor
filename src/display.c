#include <stdio.h>
#include <ncurses.h>

#include "stat.h"
#include "display.h"

/**
 * The period of program. (sec)
 */
#define SLEEP_TIME 1

int block_init (struct block *block)
{
/*
	if ((mainwin = initscr()) == NULL) {
		fprintf (stderr, "Error initialising ncurses.\n");
		return -1;
	}
	return 0;
*/
}

int block_free (struct block *block)
{
/*
	if (mainwin == NULL)
		return -1;

	delwin (mainwin);
	endwin ();
	refresh ();
	return 0;
*/
}

int two_column_line (int line_number, char *left, char *right)
{
	mvprintw (line_number, 0, "= %-16s || %-16s =", left, right);
}

int block_update (struct block *block)
{
/*
	mvprintw (0, 0, "========================================");
	mvprintw (1, 0, "============== phdpark.com =============");
	two_column_line (2, "System uptime", "152:32:25");
	two_column_line (3, "Cpu usage: 22%", "temperatur: 56'C");
	two_column_line (4, "Mem usage: 59%", "free: 102M");
	two_column_line (5, "mmcblk busy: 100", "free: 102M");
	two_column_line (6, "sda busy: 100", "free: 324G");
	mvprintw (7, 0, "================= Users ================");
	mvprintw (8, 0, "= root,monitor,cypark,chpark,ftp       =");
	mvprintw (9, 0, "======= Established connections ========");
	two_column_line (10, "192.168.0.1", "7001");
	two_column_line (11, "192.168.0.1", "7001");
	two_column_line (12, "192.168.0.1", "7001");
	two_column_line (13, "192.168.0.1", "7001");
	mvprintw (14, 0, "========================================");
*/
	sleep (SLEEP_TIME);
}
