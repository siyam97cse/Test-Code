/// input 2 2 2

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

int main()
{
//int x,y,z,o,x1,x2,y1,y2;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
    int midx=100,midy=200;
    int x1,y1,z1;
    x1= 50;
    y1= 100;
    z1=20;
    float x,y,z;

    bar3d(midx+x1,midy-y1,midx+y1,midy-x1,z1,1);
    printf("The scaling factors are (x,y,z): " );
    scanf("%f %f %f",&x,&y,&z);
    midx=300,midy=300;

    bar3d(midx+x1*x,midy-y1*y,midx+y1*x,midy-x1*y,z*z1,1);
    getch();





}

