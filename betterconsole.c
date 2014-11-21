#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>

#include "betterconsole.h"

#define GRAYS 24
#define RGBTONES 6

// http://man7.org/linux/man-pages/man4/console_codes.4.html
void clear_screen() {
	printf("\033[2J");
}

void set_position(int row, int col) {
	printf("\033[%d;%dH",row,col);
}

void set_foreground(int color) {
	printf("\033[38;5;%dm",color);
}

void set_background(int color) {
	printf("\033[48;5;%dm",color);
}

int get_max_rows() {
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    return w.ws_row;
}

int get_max_cols() {
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    return w.ws_col;
}

int rgb(double red, double green, double blue) {
    int r = (int)(red * (RGBTONES));
    if(r >= RGBTONES) r = RGBTONES-1;
    int g = (int)(green * (RGBTONES));
    if(g >= RGBTONES) g = RGBTONES-1;
    int b = (int)(blue * (RGBTONES));
    if(b >= RGBTONES) b = RGBTONES-1;
    return 16 + b + g * RGBTONES + r * RGBTONES * RGBTONES ;
}
int gray(double bright) {
    int col = (int) (bright * (GRAYS+2));
    if(col == 0) {
        return 0;
    } else if(col >= GRAYS+1) {
        return 255-GRAYS;
    } else {
        return (col) + (255-GRAYS);
    }
}

void empty_keyboard_buffer() {
    fseek(stdin,0,SEEK_END);
}

void echo_on() {
    struct termios cfg;
    tcgetattr(0, &cfg);                        /* grab old terminal i/o settings */
    cfg.c_lflag |= ICANON; /* enable buffered i/o */
    cfg.c_lflag |= ECHO;        /* set echo mode */
    tcsetattr(0, TCSANOW, &cfg);              /* use these new terminal i/o settings now */          
}

void echo_off() {
    struct termios cfg;
    tcgetattr(0, &cfg);                        /* grab old terminal i/o settings */
    cfg.c_lflag &= ~ICANON; /* disable buffered i/o */
    cfg.c_lflag &= ~ECHO;        /* unset echo mode */
    tcsetattr(0, TCSANOW, &cfg);              /* use these new terminal i/o settings now */       
}

int get_key_pressed() {
    struct termios trm, oldterm;
    
    tcgetattr(STDIN_FILENO, &oldterm);
    trm = oldterm;
    
    trm.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ICRNL); 
    
    trm.c_cc[VMIN] = 0;
    trm.c_cc[VTIME] = 0;
    
    tcsetattr(STDIN_FILENO,TCSANOW, &trm);
    
    int keypressed = 0;
    int cursor = 0;
    
    read(STDIN_FILENO,&keypressed,1);
    if(keypressed == KEY_ESC) {
        read(STDIN_FILENO,&cursor,2);
        keypressed |= cursor<<8;
    }
    
    tcsetattr(STDIN_FILENO,TCSANOW, &oldterm);    
    
    return keypressed;
}

void cursor_off() {
    printf("\033[?25l");
}

void cursor_on() {
    printf("\033[?25h");
}

#undef GRAYS
#undef RGBTONES