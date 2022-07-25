#include<stdio.h>
#include<time.h>
#include<conio.h>

#define WIDTH 41
#define HEIGHT 31

int FREE;
int x, y;
int dx,dy;
int SPEED;

int delay() {
    usleep(80/SPEED*1000);
    return 0;
}


void line() {
    for(FREE=0; FREE<WIDTH; FREE++)
        printf("_");
    printf("\n");
}


void wall() {
    for(FREE=2; FREE<HEIGHT; FREE++) {
        gotoxy(1,FREE);
        printf("|");
        gotoxy(WIDTH,FREE);
        printf("|");
    }
    printf("\n");
}

int main() {
    x=WIDTH/2;
    y=HEIGHT/2;
    dx=1;
    dy=1;
    SPEED = 10;

    while(1) {
        line();
        wall();
        line();
        gotoxy(x,y);
        printf("O");
        
        x+=dx;
        y+=dy;
        if(x==2 || x==WIDTH-1) dx*=-1;
        if(y==2 || y==HEIGHT) dy*=-1;
        
        gotoxy(0, HEIGHT+5);
        printf("\n");
        delay();
        clrscr();
    }
    return 0;
}