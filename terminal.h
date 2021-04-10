#ifndef __TERMINAL_H__
#define __TERMINAL_H__

enum
{
	FG_BLACK      = 30,
	FG_RED        = 31,
	FG_GREEN      = 32,
	FG_YELLOW     = 33,
	FG_BLUE       = 34,
	FG_MAGENTA    = 35,
	FG_CYAN       = 36,
	FG_WHITE      = 37
};

enum
{
	BG_BLACK      = 40,
	BG_RED        = 41,
	BG_GREEN      = 42,
	BG_YELLOW     = 43,
	BG_BLUE       = 44,
	BG_MAGENTA    = 45,
	BG_CYAN       = 46,
	BG_WHITE      = 47
};

enum
{
	TS_NORMAL     = 0,
	TS_BOLD       = 1,
	TS_UNDERSCORE = 4,
	TS_BLINK      = 5,
	TS_REVERSE    = 7
};

void terminal_clear(void);
void terminal_set_color_bg(int bg_color);
void terminal_set_color_fg(int fg_color);
void terminal_set_cursor_xy(int x, int y);
void terminal_set_text_style(int attr);
void terminal_get_size(int *w, int *h);
int kbhit(void);
char getch(int echo);

#endif /* __TERMINAL_H__ */
