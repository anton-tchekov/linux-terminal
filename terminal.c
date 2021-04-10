#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>
#include "terminal.h"

void terminal_clear(void)
{
	fputs("\x1B[2]", stdout);
}

void terminal_set_color_bg(int bg_color)
{
	printf("\x1B[%dm", bg_color);
}

void terminal_set_color_fg(int fg_color)
{
	printf("\x1B[%dm", fg_color);
}

void terminal_set_cursor_xy(int x, int y)
{
	printf("\x1B[%d;%dH", x, y);
}

void terminal_set_text_style(int attr)
{
	printf("\x1B[%dm", attr);
}

void console_get_size(int *w, int *h)
{
	struct winsize wsize;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &wsize);
	*w = wsize.ws_row;
	*h = wsize.ws_col;
}

int kbhit(void)
{
	int byteswaiting;
	static struct termios term, term2;
	tcgetattr(0, &term);
	term2 = term;
	term2.c_lflag &= ~ICANON;
	tcsetattr(0, TCSANOW, &term2);
	ioctl(0, FIONREAD, &byteswaiting);
	tcsetattr(0, TCSANOW, &term);
	return byteswaiting > 0;
}

char getch(int echo)
{
	static struct termios kbd_old, kbd_new;
	char ch;
	tcgetattr(0, &kbd_old);
	new = old;
	new.c_lflag &= ~ICANON;
	if(echo)
	{
		new.c_lflag |= ECHO;
	}
	else
	{
		new.c_lflag &= ~ECHO;
	}

	tcsetattr(0, TCSANOW, &kbd_new);
	ch = getchar();
	tcsetattr(0, TCSANOW, &kbd_old);
	return ch;
}
