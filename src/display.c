#include <stdio.h>
#include <ncurses.h> 
#include "stat.h"
#include "display.h"

int block_init (struct block *block, struct block *next, int x_length, int y_length, int x_offset, int y_offset)
{
	if (block == NULL)
		return -1;
	block->window = newwin (x_length, y_length, x_offset, y_offset);
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

	while (block != NULL) {
		/*
		if (block->value > 75) { color = RED; }
		else if (block->value > 50) { color = YELLOW; }
		else { color = GREEN; }
		*/
		color++;
		mvwprintw (block->window, block->y_offset + (block->y_length /2), block->x_offset, "%s", block->next->x_offset);

		attron (A_BOLD);
		//mvwprintw (block->window, block->y_offset + (block->y_length / 2), 
		//block->x_offset, "%5d", block->value);
		attroff (A_BOLD);

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
