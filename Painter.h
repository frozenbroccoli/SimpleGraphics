#ifndef PAINTER_H
#define PAINTER_H

class Painter {
	unsigned char* screen;

public:
	Painter(unsigned char* sc);

	void set_pixel(
		int bytes_per_row,
		int num_rows,
		int x,
		int y,
		bool light_up
	);
};

#endif
