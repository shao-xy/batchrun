#include <termcap.h>

#include "common.h"

void clear_screen()
{
	char buf[1024];
	tgetent(buf, getenv("TERM"));
	fputs(tgetstr("cl", NULL), stdout);
}
