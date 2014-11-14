#define BLACK 0
#define RED 1
#define GREEN 2
#define BROWN 3
#define BLUE 4
#define MAGENTA 5
#define CYAN 6
#define WHITE 7

#define BRIGHT 8

#define GRAYS 24
#define RGBTONES 6

// http://man7.org/linux/man-pages/man4/console_codes.4.html
void clear_screen();

void set_position(int row, int col);

void set_foreground(int color);

void set_background(int color);

int get_max_rows();

int get_max_cols();

int rgb(double red, double green, double blue);

int gray(double bright);

void empty_keyboard_buffer();

void echo_on();
void echo_off();