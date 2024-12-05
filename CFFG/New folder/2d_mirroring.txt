#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void reflection()
{
    int choice;
    int i,t[5][2]= {10,10, 50,50, 10,50, 10,10};
    for(i=0; i<3; i++)
    {
        line(320+t[i][0],240-t[i][1], 320+t[i+1][0],240-t[i+1][1]);
    }
    printf("\n******MAIN MENU*******\n");
    printf("1. About X\n");
    printf("2. About Y\n");
    printf("3. About O\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1 :
        for(i=0; i<5; i++)
        {
            t[i][1]=-t[i][1];
        }
        break;
    case 2 :
        for(i=0; i<5; i++)
        {
            t[i][0]=-t[i][0];
        }
        break;
    case 3 :
        for(i=0; i<5; i++)
        {
            t[i][0]=-t[i][0];
            t[i][1]=-t[i][1];
        }
        break;
    }
    for(i=0; i<3; i++)
    {
        line(320+t[i][0],240-t[i][1], 320+t[i+1][0],240-t[i+1][1]);
    }
}
int main()
{
    int choice,gd=DETECT,gm;
    initgraph(&gd,&gm,"");
    line(0,240,640,240);
    line(320,0,320,480);
    reflection();
    getch();
    closegraph();
    restorecrtmode();
    return 0;
}
