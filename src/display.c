#include <stdio.h>
#include <ncurses.h> 
#include "stat.h"
#include "display.h"

int block_init (struct block *block, struct block *next, int y_length, int x_length, int y_offset, int x_offset)
{
	if (block == NULL)
		return -1;
	block->window = newwin (y_length, x_length, y_offset, x_offset);
	block->x_length = x_length;
	block->y_length = y_length;
	block->x_offset = x_offset;
	block->y_offset = y_offset;
	block->value = 0;
	block->next = next;
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

int block_update (struct block *block)
{
	int color = 0;
	int height = 0, width = 0;

	while (block != NULL) {
		if (block->value > 75) { color = WHITE_RED; }
		else if (block->value > 50) { color = WHITE_YELLOW; }
		else { color = WHITE_GREEN; }

		// Fill box
		height = block->value / 10;
		width = block->value % 5;
		wattron (block->window, COLOR_PAIR (color));
		while (width > 0) {
			mvwprintw (block->window, block->y_length - height - 2, width, " ");
			width--;
		}
		while (height > 0) {
			mvwprintw (block->window, block->y_length - height - 1, 1, "%5s", "");
			height--;
		}
		wattroff (block->window, COLOR_PAIR (color));

		// Write number
		/*
		wattron (block->window, A_BOLD);
		if (block->value > 9)
			mvwprintw (block->window, (block->y_length / 2) - 1, (block->x_length / 2) - 1, "%3d", block->value);
		else
			mvwprintw (block->window, (block->y_length / 2) - 1, (block->x_length / 2) - 1, "%2d", block->value);
		wattroff (block->window, A_BOLD);
		*/

		wrefresh (block->window);

		block = block->next;
	}
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
		mvwprintw (block->window, (i * 2) + 1, 1, "%4d%c", 100 - (20 * i), '_');
		for (j = 0; j < 3; j++) {
			mvwprintw (block->window, (i * 2) + 1, 13 + (j * 8), "_");
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
