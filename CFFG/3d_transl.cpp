#include <stdio.h>
#include <graphics.h>
#include <math.h>

void trans();


//these are left,top,right,bottom parameters for bar3d function
int maxx,maxy,midx,midy;

int main()

{

            int ch;

            int gd=DETECT,gm;

            detectgraph(&gd,&gm);

            initgraph(&gd,&gm," ");

            trans();
            getch();
return 0;
}

//function for translation of a 3d object
void trans()

{

            int x,y,x1,x2,y1,y2;
//
//            midx=200;
//
//            midy=200;
//
//            //function to draw 3D rectangular box
//            bar3d(midx+50,midy-100,midx+100,midy-50,60,10);

            bar3d(50,50,150,150,20,1);
            //delay(1000);
            printf("Enter translation factor");

            scanf("%d%d",&x,&y);

            printf("After translation:");
            //      left  top  right  bottom   depth    topflag
            bar3d(50+x ,50+y, 150+x,   150+y,    20,     1);

}
