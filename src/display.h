#ifndef _DISPLAY_H_
#define _DISPLAY_H_

/**
 * The period of program. (sec)
 */
#define SLEEP_TIME 1

#define BLACK	0
#define RED	1
#define GREEN	2
#define YELLOW	3
#define BLUE	4
#define MAGENTA	5
#define CYAN	6
#define WHITE	7

struct block {
	WINDOW * window;
	int x_length;
	int y_length;
	int x_offset;
	int y_offset;
	int value;
	struct block *next;
};

int block_init (struct block *, struct block *, int, int, int, int);
int block_free (struct block *);
int block_update (struct block *);

#endif
