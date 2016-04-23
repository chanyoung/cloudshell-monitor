#include <stdio.h>
#include <ncurses.h> 
#include "stat.h"
#include "display.h"

/**
 * The period of program. (sec)
 */
#define SLEEP_TIME 1

int block_init (struct block *block, int x_length, int y_length, int x_offset, int y_offset)
{
	block->window = newwin (x_length, y_length, x_offset, y_offset);
	box (block->window, 0, 0);
	wrefresh (block->window);
	return 0;
}

int block_free (struct block *block)
{
	if (block == NULL)
		return -1;

	delwin (block->window);
	return 0;
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

int draw_main (struct block *block)
{
	int i = 0,j = 0;

	/*
	 * Title.
	 */
	mvwprintw (block->window, 0, 14, "%12s", " phdpark.com ");

	/*
	 * Gradation on a bar graph.
	 */
	for (i = 0; i < 6; i++) {
		mvwprintw (block->window, (i * 2) + 1, 1, "%4d%c", 100 - (20 * i), '-');
		for (j = 0; j < 3; j++) {
			mvwprintw (block->window, (i * 2) + 1, 13 + (j * 8), "-");
		}
	}

	/*
	 * Graph types.
	 */
	mvwprintw (block->window, 13, 6, "%6s", "Cpu %");
	mvwprintw (block->window, 13, 14, "%6s", "Mem %");
	mvwprintw (block->window, 13, 22, "%6s", "I/O %");
	mvwprintw (block->window, 13, 30, "%6s", "Cpu'C");

	wrefresh (block->window);
}
