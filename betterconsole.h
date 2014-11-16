#define BLACK 0
#define RED 1
#define GREEN 2
#define BROWN 3
#define BLUE 4
#define MAGENTA 5
#define CYAN 6
#define WHITE 7

#define BRIGHT 8

#define NO_KEY 0
#define KEY_UP 4283163
#define KEY_RIGHT 4414235
#define KEY_DOWN 4348699
#define KEY_LEFT 4479771
#define KEY_ESC 27

/**
 * Clears the console screen
 */
void clear_screen();

/**
 * Sets the position of the cursor (and the position to which the console will
 * do the next write) to the specified row and column
 * 
 * @param row
 * @param col
 */
void set_position(int row, int col);

/**
 * Sets the color of the foreground. It accepts any of the defined color constants,
 * such color constants plus BRIGHT (e.g. BLUE+BRIGHT) or the return value of the
 * function "rgb(r,g,b)" of this library
 * 
 * @param color
 */
void set_foreground(int color);

/**
 * Sets the color of the background. It accepts any of the defined color constants,
 * such color constants plus BRIGHT (e.g. BLUE+BRIGHT) or the return value of the
 * function "rgb(r,g,b)" of this library
 * 
 * @param color
 */
void set_background(int color);

/**
 * Returns the height of the console window, in rows
 * @return 
 */
int get_max_rows();

/**
 * Returns the width of the console window, in columns
 * @return 
 */
int get_max_cols();

/**
 * Returns a color value calculated from the intensities (from 0 to 1) of the
 * red, green and blue parameters.
 * @param red
 * @param green
 * @param blue
 * @return 
 */
int rgb(double red, double green, double blue);

/**
 * Returns a gray color value calculated from the intensity (from 0 to 1) of the
 * bright parameter.
 * @param bright
 * @return 
 */

int gray(double bright);

/**
 * Empties the keyboard buffer, so any of the key codes that were stored in the
 * STDIN buffer will be removed.
 */
void empty_keyboard_buffer();

/**
 * Turns on the console echo
 */
void echo_on();
/**
 * Turns off the console echo
 */
void echo_off();

/**
 * Returns the last key code pressed. It is a non-blocking operation, so if not
 * key pressed it returns NO_KEY constant. It must return multiple-code escape values (e.g. cursor
 * arrows such as ^[[A) but packed in an integer. Cursor keys are defined as constants
 * KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
 * 
 * @return The last key code pressed, or 0 if no key pressed.
 */
int get_key_pressed();

void cursor_off();
void cursor_on();
