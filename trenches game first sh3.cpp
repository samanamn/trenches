#include "stdio.h"
#include "TXLib.h"
#include "trenches.h"

//это прототип


int main()
{
    int firstscene();
    int secondscene();

    txCreateWindow(1200,800);

    txSetFillColor(TX_WHITE);
    txClear();


    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        firstscene();
        secondscene();
    }

    return 0;
}
int firstscene()
{

    HDC adam = txLoadImage("finalsprite.bmp");
    HDC blowup = txLoadImage("shooting.bmp");
    sprite first={50,520,5,0,1,5,adam};
    shooting firstshot={120,500,1,3,blowup};
    shooting secondshot={300,450,1,4,blowup};
    shooting thirdshot={480,500,0,4,blowup};
    shooting fourthshot={740,450,1,5,blowup};
    shooting fifthshot={1100,520,1,2,blowup};
    map field={0};
    field.one();
    field.draw1();
    field.draw2();
    int timing1=0;
    int timing2=0;
    int timing3=0;
    int timing4=0;
    int timing5=0;
    while(first.x1!=1200)
    {

        txSetFillColor(TX_WHITE);
        txClear();
        field.draw1();                                                                //no u
        first.color=field.A[first.y1/40][(first.x1+10)/40];
        if((timing1==25)&&(firstshot.state==0))
        {
            firstshot.state=1;
            timing1=0;
        }
        if((timing1==10)&&(firstshot.state==1))
        {
            firstshot.state=0;
            timing1=0;
        }
        if((timing2==15)&&(secondshot.state==0))
        {
            secondshot.state=1;
            timing2=0;
        }
        if((timing2==7)&&(secondshot.state==1))
        {
            secondshot.state=0;
            timing2=0;
        }
        if((timing3==30)&&(thirdshot.state==0))
        {
            thirdshot.state=1;
            timing3=0;
        }
        if((timing3==10)&&(thirdshot.state==1))
        {
            thirdshot.state=0;
            timing3=0;
        }
        if((timing4==20)&&(fourthshot.state==0))
        {
            fourthshot.state=1;
            timing4=0;
        }
        if((timing4==10)&&(fourthshot.state==1))
        {
            fourthshot.state=0;
            timing4=0;
        }
        if((timing5==19)&&(fifthshot.state==0))
        {
            fifthshot.state=1;
            timing5=0;
        }
        if((timing5==7)&&(fifthshot.state==1))
        {
            fifthshot.state=0;
            timing5=0;
        }
        firstshot.draw();
        secondshot.draw();
        thirdshot.draw();
        fourthshot.draw();
        fifthshot.draw();
        field.draw2();
        first.draw();
        first.moving();
        if((first.x1>120)&&(first.x1<200)&&(firstshot.state==1)&&(first.color==1))
            first.death();
        if((first.x1>280)&&(first.x1<480)&&(secondshot.state==1)&&(first.color==1))
            first.death();
        if((first.x1>480)&&(first.x1<600)&&(thirdshot.state==1)&&(first.color==1))
            first.death();
        if((first.x1>720)&&(first.x1<920)&&(fourthshot.state==1)&&(first.color==1))
            first.death();
        if((first.x1>1080)&&(first.x1<1160)&&(fifthshot.state==1)&&(first.color==1))
            first.death();

        txSleep(300);
        timing1++;
        timing2++;
        timing3++;
        timing4++;
        timing5++;
    }
    txDeleteDC(adam);
    txDeleteDC(blowup);

}

int secondscene()
{
    HDC adam = txLoadImage("finalsprite.bmp");
    HDC blowup = txLoadImage("shooting.bmp");
    sprite first={50,520,5,0,1,5,adam};
    shooting firstshot={120,500,1,3,blowup};
    shooting secondshot={280,450,0,5,blowup};
    shooting thirdshot={480,500,1,4,blowup};
    shooting fourthshot={680,510,1,3,blowup};
    shooting fifthshot={1100,520,1,2,blowup};
    map field={0};
    field.two();
    field.draw1();
    field.draw2();
    int timing1=0;
    int timing2=0;
    int timing3=0;
    int timing4=0;
    int timing5=0;
    while(first.x1!=1200)
    {

        txSetFillColor(TX_WHITE);
        txClear();
        field.draw1();                                                                //no u
        first.color=field.A[first.y1/40][(first.x1+10)/40];
        if((timing1==10)&&(firstshot.state==0))
        {
            firstshot.state=1;
            timing1=0;
        }
        if((timing1==5)&&(firstshot.state==1))
        {
            firstshot.state=0;
            timing1=0;
        }
        if((timing2==20)&&(secondshot.state==0))
        {
            secondshot.state=1;
            timing2=0;
        }
        if((timing2==10)&&(secondshot.state==1))
        {
            secondshot.state=0;
            timing2=0;
        }
        if((timing3==30)&&(thirdshot.state==0))
        {
            thirdshot.state=1;
            timing3=0;
        }
        if((timing3==10)&&(thirdshot.state==1))
        {
            thirdshot.state=0;
            timing3=0;
        }
        if((timing4==20)&&(fourthshot.state==0))
        {
            fourthshot.state=1;
            timing4=0;
        }
        if((timing4==10)&&(fourthshot.state==1))
        {
            fourthshot.state=0;
            timing4=0;
        }
        if((timing5==19)&&(fifthshot.state==0))
        {
            fifthshot.state=1;
            timing5=0;
        }
        if((timing5==7)&&(fifthshot.state==1))
        {
            fifthshot.state=0;
            timing5=0;
        }
        firstshot.draw();
        secondshot.draw();
        thirdshot.draw();
        fourthshot.draw();
        fifthshot.draw();
        field.draw2();
        first.draw();
        first.moving();
        if((first.x1>120)&&(first.x1<200)&&(firstshot.state==1)&&(first.color==1))
            first.death();
        if((first.x1>300)&&(first.x1<480)&&(secondshot.state==1)&&(first.color==1))
            first.death();
        if((first.x1>480)&&(first.x1<680)&&(thirdshot.state==1)&&(first.color==1))
            first.death();
        if((first.x1>680)&&(first.x1<800)&&(fourthshot.state==1)&&(first.color==1))
            first.death();
        if((first.x1>1080)&&(first.x1<1160)&&(fifthshot.state==1)&&(first.color==1))
            first.death();

        txSleep(300);
        timing1++;
        timing2++;
        timing3++;
        timing4++;
        timing5++;
    }
    txDeleteDC(adam);
    txDeleteDC(blowup);

}

