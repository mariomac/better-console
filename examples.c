/* 
 * File:   examples.c
 * Author: mmacias
 *
 * Created on 13 de noviembre de 2014, 20:09
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "betterconsole.h"

void coloured_printf() {
    set_foreground(BLUE); printf("Blue\n");
    set_foreground(RED); printf("Red\n");
    set_foreground(GREEN); printf("Green\n");
    set_foreground(BROWN); printf("Brown\n");
    set_foreground(MAGENTA); printf("Magenta\n");
    set_foreground(CYAN); printf("Cyan\n");
    set_foreground(WHITE); printf("White\n");
    set_foreground(RED); set_background(CYAN); printf("Red over cyan");
    set_background(BLACK); set_foreground(WHITE);
    printf("\n");
}

void positioned_text() {
    int i, rows, cols, r,c;
    clear_screen();
    set_position(1,1);
    rows = get_max_rows();
    cols = get_max_cols();
    printf("Press INTRO 10 times");
    r = rows/2; c = cols/2;
    for(i = 1 ; i <= 10 ; i++) {
            scanf("%*c");
            set_position(r,c);
            printf("%d",i);
            r = (r * r)%rows + 1;
            c = (c*c)%cols + 1;
    }
    set_position(1,1);
}

void draw_bitmap() {
    int posR = 5, posC = 5;
    char desc[] =
            "              \n"
            "    VVVVV     \n"
            "   VVVVVVVVVV \n"
            "   RRRMMRM    \n"
            "  RMRMMMRMMM  \n"
            "  RMRRMMMRMMM \n"
            "  RRMMMMRRRR  \n"
            "    MMMMMMM   \n"
            "   RRVRRR     \n"
            "  RRRVRRVRRR  \n"
            " RRRRVVVVRRRR \n"
            " MMRVMVVMVRMM \n"
            " MMMVVVVVVMMM \n"
            " MMVVVVVVVVMM \n"
            "   VVV  VVV   \n"
            "  RRR    RRR  \n"
            " RRRR    RRRR \n"
            "              ";

    int r = posR, c = posC;
    int i = 0;
    clear_screen();
    while (desc[i] != '\0') {
        if (desc[i] == '\n') {
            r++;
            c = posC;
        } else {
            if (desc[i] == ' ') set_background(BLACK);
            else if (desc[i] == 'R') set_background(RED);
            else if (desc[i] == 'V') set_background(GREEN);
            else if (desc[i] == 'M') set_background(BROWN);
            else if (desc[i] == 'C') set_background(CYAN);
            else if (desc[i] == 'A') set_background(BLUE);
            else if (desc[i] == 'G') set_background(MAGENTA);
            else if (desc[i] == 'B') set_background(WHITE);
            set_position(r, c);
            printf(" ");
            c++;
        }
        i++;
    }
    set_background(BLACK);   
}

void retrieving_window_size() {
    int r, c, ra = 0, ca = 0;
    int rr, cc;
    char dw = '*';
    int tdw = '*';
    
    clear_screen();
    empty_keyboard_buffer();
    echo_off();
    cursor_off();
    
    while (get_key_pressed() != KEY_ESC) {
        r = get_max_rows();
        c = get_max_cols();
        if (ra != r || ca != c) {
            set_background(BLACK);
            clear_screen();
            set_foreground(BLUE);
            set_background(WHITE);
            for (rr = 1; rr <= r; rr++) {
                set_position(rr, 1);
                putchar(dw);
                set_position(rr, c);
                printf("*");
            }
            for (cc = 1; cc <= c; cc++) {
                set_position(1, cc);
                printf("*");
                set_position(r, cc);
                printf("*");
            }
            set_position(1, c / 2 - 11);
            set_foreground(BLACK);
            printf(" Retrieving Window Size");
            set_foreground(MAGENTA);
            set_background(BLACK);
            set_position(r / 2 - 2, c / 2 - 4);
            printf("Try to resize");
            set_position(r / 2 - 1, c / 2 - 5);
            printf("this window");
            set_position(r / 2, c / 2 - 4);
            printf("(Press ESC");
            set_position(r / 2 + 1, c / 2 - 6);
            printf("to exit)");
            set_foreground(GREEN);
            set_position(r - 1, 2);
            printf("Window Size: %d x %d\n", r, c);
        }
        ra = r;
        ca = c;
    }
    
    echo_on();
    cursor_on();

}

void test_echo_on_off() {
    char user[100], password[100];
    char c; int i = 0;
    empty_keyboard_buffer();
    printf("Username: ");
    scanf("%[^\n]%*c",user);
    echo_off();
    printf("Password: ");
    scanf("%c",&c);
    printf("*");
    while(c != '\n') {
        password[i++] = c;
        scanf("%c",&c);
        printf("*");
    }
    password[i] = '\0';
    echo_on();
    printf("\n\n%s, your password is \"%s\"!!\n\n",user,password);
}

void show_palette() {
    echo_off();
    int x, y, t;
    clear_screen();
    for (t = 0; t < 6; t++) {
        for (x = 1; x <= get_max_cols(); x++) {
            for (y = 1; y <= get_max_rows(); y++) {
                set_background(rgb((double) t / (double) 6,
                        (double) x / (double) get_max_cols(),
                        (double) y / (double) get_max_rows()
                        ));
                set_position(y, x);
                printf(" ");
            }
        }
        scanf("%*c");
    }
    echo_on();
}

#define GRAVITY 1.5
#define BOUNCE_FORCE_CONSERVATION 0.9
#define HIT_FORCE 8

#define BALLSIZE 4

void non_blocking_keyboard_access() {
    cursor_off();
    echo_off();
    set_foreground(WHITE);
    set_background(BLACK);
    char ball[] = " XX "
                  "XXXX"
                  "XXXX"
                  " XX ";
    int ws = 10;
    int key = 0;
    int ww, wh;
    double px = get_max_cols() / 2.0, py = get_max_rows() / 2.0 ;
    double sx=0, sy=0;
    int i,j;
    int lastkey;
    while(key != KEY_ESC) {
        clear_screen();
        set_position(1,1);
        printf("Use arrow keys to hit the ball in any direction.\n");
        printf("Press ESC to exit");
        ww = get_max_cols();
        wh = get_max_rows();
        
        set_background(WHITE);
        for(i = 0 ; i < BALLSIZE * BALLSIZE ; i++) {
            if(ball[i] == 'X') {
                set_position(py+i/BALLSIZE, px+i%BALLSIZE);
                printf(" ");
            }
        }
        set_background(BLACK);
        
        px += sx;
        sy += GRAVITY;
        py += sy;
        
        if(px < 1) {
            sx = -(sx * BOUNCE_FORCE_CONSERVATION);
            px = 1;
        } else if(px + BALLSIZE > ww) {
            sx = -(sx * BOUNCE_FORCE_CONSERVATION);
            px = ww - BALLSIZE;
        }
        if(py < 1) {
            sy = -(sy * BOUNCE_FORCE_CONSERVATION);
            sx *= BOUNCE_FORCE_CONSERVATION;
            py = 1;
        } else if(py + BALLSIZE > wh) {
            sy = -(sy * BOUNCE_FORCE_CONSERVATION);
            py = wh - BALLSIZE;
            sx *= BOUNCE_FORCE_CONSERVATION;
        }
        
        fflush(stdout);
        usleep(100000);
        key = get_key_pressed();
        switch(key) {
            case KEY_UP:
                sy -= HIT_FORCE;
                break;
            case KEY_DOWN:
                sy += HIT_FORCE;
                break;
            case KEY_LEFT:
                sx -= HIT_FORCE;
                break;
            case KEY_RIGHT:
                sx += HIT_FORCE;
                break;
        }
    }
    
    cursor_on();
    echo_on();
}

int main() {
    char option = 0, press_intro;   
        
    while(option != 'e' && option != 'E') {
        press_intro = 1;
        clear_screen();
        set_position(1,1);
        printf("List of examples\n");
        printf("================\n\n");
                
        printf("\t1 - Coloured printf\n");
        printf("\t2 - Positioned text\n");
        printf("\t3 - Draw bitmap\n");
        printf("\t4 - Retrieving window size\n");
        printf("\t5 - Test console echo on/off\n");
        printf("\t6 - Show a complete color palette\n");
        printf("\t7 - Non-blocking keyboard access\n");
        printf("\tE - Exit\n\n");

        printf("Select an option: ");
        
        empty_keyboard_buffer();        
        scanf("%c",&option);        
        switch(option) {
            case '1':
                coloured_printf();
                break;
            case '2':
                positioned_text();
                break;
            case '3':
                draw_bitmap();
                break;
            case '4':
                retrieving_window_size();
                break;
            case '5':
                test_echo_on_off();
                break;
            case '6':
                show_palette();
                break;
            case '7':
                non_blocking_keyboard_access();
                break;

            case 'e':
            case 'E':
                press_intro = 0;
                break;
            default:
                printf("Option not valid!\n");
                break;
        }
        
        if(press_intro) {
            empty_keyboard_buffer();
            printf("Press INTRO to continue...");
            scanf("%*c");
        }
        
    }
    
    printf("Bye!\n");
    
    
    return 0;
}

