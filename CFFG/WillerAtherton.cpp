#include <iostream>
#include<dos.h>
#include<graphics.h>
using namespace std;

int main()
{
    int i,gd=DETECT,gm;
    int x, y, c=4;
    initgraph(&gd,&gm,"C:\\Program Files\\CodeBlocks\\MinGW\\include\\");
    rectangle(100,100, 300,300);
    line(120,250,120,50);
    line(120,50,180,200);
    line(180,200,280,50);
    line(280,50,280,250);
    line(280,250,120,250);
    x=120;
    y=200;
    putpixel(x,y,4);
    y=y-1;
    outtextxy(x,y,"Start");
    while(1)
    {
        putpixel(x,y,c);
        if(getpixel(x-1,y+1)==15)
        {
            x=x-1;
            y=y+1;
        }
        else if(getpixel(x,y+1)==15)
        {
            y=y+1;
        }
        else if(getpixel(x+1,y+1)==15)
        {
            x=x+1;
            y=y+1;
        }
        else if(getpixel(x+1,y)==15)
        {
            x=x+1;
        }
        else if(getpixel(x+1,y-1)==15)
        {
            x=x+1;
            y=y-1;
        }
        else if(getpixel(x,y-1)==15)
        {
            ;
            y=y-1;
        }
        else if(getpixel(x,y-2)==15)
        {
            ;
            y=y-2;
        }
        else if(getpixel(x-1,y-1)==15)
        {
            x=x-1;
            y=y-1;
        }
        else if(getpixel(x-1,y)==15)
        {
            x=x-1;
            y=y;
        }
        else if(getpixel(x-2,y)==15)
        {
            x=x-2;
            y=y;
        }
        else break;
        delay(20);
    }
    outtextxy(x,y+2,"End");

    cin>>i;
    return 0;
}
