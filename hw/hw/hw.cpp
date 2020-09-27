// hw.cpp : Defines the entry point for the application.
//

#include "hw.h"


int main(int argc, char** argv)
{
	pic_data out;

	decode_png("./pngs/test1.png", &out);

	write_png_file("./pngs/test1_out.png", &out);
	decode_png("./pngs/02.png", &out);

	write_png_file("./pngs/02_out.png", &out);
	free(out.rgba);
	

	return 0;
}
