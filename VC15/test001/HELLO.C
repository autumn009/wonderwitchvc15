/*#define BIOS_INLINE*/
#include <sys/bios.h>

char *msg = "Hello, World";

void main(int argc, char *argv[])
{
    int x, y;
	char far * d;
	char far * s;

	d=(char far *)&msg;
	s=(char far *)&x;

//    if (argc != 1) {
//	msg = argv[1];
  //  }

    text_screen_init();

    for (y = 0; y < 17; y++) {
	for (x = 0; x < 17; x++) {
	    text_put_string(x, y, msg);
	    text_put_numeric(0, 15, 4, 0, (int)((long)d >> 16));
	    text_put_numeric(5, 15, 4, 0, (int)((long)s >> 16));
	    text_put_numeric(0, 16, 4, 0, (int)msg);
	    text_put_numeric(5, 16, 4, 0, msg[0]);
	    text_put_numeric(0, 17, 4, 0, x);
	    text_put_numeric(5, 17, 4, 0, y);
	    if (key_wait() == KEY_START) {
		return;
	    }
	}
    }

    key_wait();
}
