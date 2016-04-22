#ifndef _DISPLAY_H_
#define _DISPLAY_H_

struct block {
	WINDOW * window;
	int x_length;
	int y_length;
	int x_offset;
	int y_offset;
	int value;
};

int block_init (struct block *, int, int, int, int);
int block_free (struct block *);
int block_update (struct block *);

#endif
