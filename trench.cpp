#include "stdio.h"
#include "TXLib.h"
#include "trenches.h"

//это прототип


int main()
{
    int firstscene();
    int secondscene();
    int thirdscene();

    txCreateWindow(1200,800);

    txSetFillColor(TX_WHITE);
    txClear();


    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        firstscene();
        secondscene();
        thirdscene();
        printf("Спасибо, шо играли");
        HDC adam = txLoadImage("finalsprite.bmp");
        sprite first={50,520,5,0,0,1,0,2,adam};
         map field={0};
         field.four();
         int i;
         while(first.x1<1200)
         {
            txSetFillColor(TX_WHITE);
            txClear();
            field.draw1();
            field.draw2();
            txSetColor(TX_WHITE,1);
            for(i=0;i<=800;i+=40)
                    txLine(0,i-1,1200,i-1);
            first.draw();
            first.moving();
            Sleep(300);
            if(first.x1<=0)
                first.x1=0;
         }
         txSetFillColor(TX_WHITE);
         txClear();
        return 0;


    }


}
int firstscene()
{

    HDC adam = txLoadImage("finalsprite.bmp");
    HDC blowup = txLoadImage("shooting.bmp");
    sprite first={50,520,5,0,0,1,0,2,adam};
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
    int reload1=0;
    int reload2=0;
    int reload3=0;
    int reload4=0;
    int reload5=0;
    int i;
    int timingblind=0;
    while(first.x1<1200)
    {

        txSetFillColor(TX_WHITE);
        txClear();
        field.draw1();                                                                //no u
        first.color=field.A[first.y1/40][(first.x1+10)/40];
        if((timing1==25)&&(firstshot.state==0))
        {
            firstshot.state=3;
            timing1=0;
            reload1=1;
        }
        if((timing1==3)&&(firstshot.state==3)&&(reload1==1))
        {
            firstshot.state=1;
            timing1=0;
        }
        if((timing1==10)&&(firstshot.state==1))
        {
            firstshot.state=3;
            timing1=0;
            reload1=0;
        }
        if((timing1==3)&&(firstshot.state==3)&&(reload1==0))
        {
            firstshot.state=0;
            timing1=0;
        }

        if((timing2==15)&&(secondshot.state==0))
        {
            secondshot.state=3;
            timing2=0;
            reload2=1;
        }
        if((timing2==3)&&(secondshot.state==3)&&(reload2==1))
        {
            secondshot.state=1;
            timing2=0;
        }
        if((timing2==7)&&(secondshot.state==1))
        {
            secondshot.state=3;
            timing2=0;
            reload2=0;
        }
        if((timing2==3)&&(secondshot.state==3)&&(reload2==0))
        {
            secondshot.state=0;
            timing2=0;
        }

        if((timing3==30)&&(thirdshot.state==0))
        {
            thirdshot.state=3;
            timing3=0;
            reload3=1;
        }
        if((timing3==3)&&(thirdshot.state==3)&&(reload3==1))
        {
            thirdshot.state=1;
            timing3=0;
        }
        if((timing3==10)&&(thirdshot.state==1))
        {
            thirdshot.state=3;
            timing3=0;
            reload3=0;
        }
        if((timing3==3)&&(thirdshot.state==3)&&(reload3==0))
        {
            thirdshot.state=0;
            timing3=0;
        }

        if((timing4==20)&&(fourthshot.state==0))
        {
            fourthshot.state=3;
            timing4=0;
            reload4=1;
        }
        if((timing4==3)&&(fourthshot.state==3)&&(reload4==1))
        {
            fourthshot.state=1;
            timing4=0;
        }
        if((timing4==10)&&(fourthshot.state==1))
        {
            fourthshot.state=3;
            timing4=0;
            reload4=0;
        }
        if((timing4==3)&&(fourthshot.state==3)&&(reload4==0))
        {
            fourthshot.state=0;
            timing4=0;
        }

        if((timing5==19)&&(fifthshot.state==0))
        {
            fifthshot.state=3;
            timing5=0;
            reload5=1;
        }
        if((timing5==3)&&(fifthshot.state==3)&&(reload5==1))
        {
            fifthshot.state=1;
            timing5=0;
        }
        if((timing5==7)&&(fifthshot.state==1))
        {
            fifthshot.state=3;
            timing5=0;
            reload5=0;
        }
        if((timing5==3)&&(fifthshot.state==3)&&(reload5==0))
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
        txSetColor(TX_WHITE,1);
        for(i=0;i<=800;i+=40)
                txLine(0,i-1,1200,i-1);
        first.draw();
        first.moving();
        if(first.x1<=0)
            first.x1=0;

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
        if(timingblind==1)
            {
                txSelectFont("terminal",30,6);
                txSetColor(TX_WHITE);
                txDrawText(699,199,1099, 399, "Твоя задача дойти до конца\n (Используй стрелки вправо и влево чтобы ходить)");
                txSelectFont("terminal",30,6);
                txSetColor(RGB(0,153,102));
                txDrawText(700,200,1100, 400, "Твоя задача дойти до конца\n (Используй стрелки вправо и влево чтобы ходить)");
                timingblind=0;
            }
            else
            {
                txSelectFont("terminal",30,6);
                txSetColor(TX_WHITE);
                txDrawText(699,199,1099, 399, "Твоя задача дойти до конца\n (Используй стрелки вправо и влево чтобы ходить)");
                timingblind=1;
            }

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
    sprite first={50,520,5,0,0,1,0,2,adam};
    rifle mar={180,510,0,adam};
    shooting firstshot={120,500,1,3,blowup};
    shooting secondshot={280,450,0,5,blowup};
    shooting thirdshot={480,500,1,4,blowup};
    shooting fourthshot={680,510,1,3,blowup};
    shooting fifthshot={880,400,1,7,blowup};
    map field={0};
    field.two();
    field.draw1();
    field.draw2();
    int timing1=0;
    int timing2=0;
    int timing3=0;
    int timing4=0;
    int timing5=0;
    int reload1=0;
    int reload2=0;
    int reload3=0;
    int reload4=0;
    int reload5=0;
    int timingblind=0;
    int timingshoot=0;
    int i;
    while(first.x1<1200)
    {

        txSetFillColor(TX_WHITE);
        txClear();
        field.draw1();                                                                //no u
        first.color=field.A[first.y1/40][(first.x1+15)/40];

        if((timing1==7)&&(firstshot.state==0))
        {
            firstshot.state=3;
            timing1=0;
            reload1=1;
        }
        if((timing1==3)&&(firstshot.state==3)&&(reload1==1))
        {
            firstshot.state=1;
            timing1=0;
        }
        if((timing1==5)&&(firstshot.state==1))
        {
            firstshot.state=3;
            timing1=0;
            reload1=0;
        }
        if((timing1==3)&&(firstshot.state==3)&&(reload1==0))
        {
            firstshot.state=0;
            timing1=0;
        }

        if((timing2==17)&&(secondshot.state==0))
        {
            secondshot.state=3;
            timing2=0;
            reload2=1;
        }
        if((timing2==3)&&(secondshot.state==3)&&(reload2==1))
        {
            secondshot.state=1;
            timing2=0;
        }
        if((timing2==7)&&(secondshot.state==1))
        {
            secondshot.state=3;
            timing2=0;
            reload2=0;
        }
        if((timing2==3)&&(secondshot.state==3)&&(reload2==0))
        {
            secondshot.state=0;
            timing2=0;
        }

        if((timing3==10)&&(thirdshot.state==0))
        {
            thirdshot.state=3;
            timing3=0;
            reload3=1;
        }
        if((timing3==3)&&(thirdshot.state==3)&&(reload3==1))
        {
            thirdshot.state=1;
            timing3=0;
        }
        if((timing3==10)&&(thirdshot.state==1))
        {
            thirdshot.state=3;
            timing3=0;
            reload3=0;
        }
        if((timing3==3)&&(thirdshot.state==3)&&(reload3==0))
        {
            thirdshot.state=0;
            timing3=0;
        }

        if((timing4==15)&&(fourthshot.state==0))
        {
            fourthshot.state=3;
            timing4=0;
            reload4=1;
        }
        if((timing4==3)&&(fourthshot.state==3)&&(reload4==1))
        {
            fourthshot.state=1;
            timing4=0;
        }
        if((timing4==10)&&(fourthshot.state==1))
        {
            fourthshot.state=3;
            timing4=0;
            reload4=0;
        }
        if((timing4==3)&&(fourthshot.state==3)&&(reload4==0))
        {
            fourthshot.state=0;
            timing4=0;
        }

        if((timing5==19)&&(fifthshot.state==0))
        {
            fifthshot.state=3;
            timing5=0;
            reload5=1;
        }
        if((timing5==3)&&(fifthshot.state==3)&&(reload5==1))
        {
            fifthshot.state=1;
            timing5=0;
        }
        if((timing5==7)&&(fifthshot.state==1))
        {
            fifthshot.state=3;
            timing5=0;
            reload5=0;
        }
        if((timing5==3)&&(fifthshot.state==3)&&(reload5==0))
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
        txSetColor(TX_WHITE,1);
        for(i=0;i<=800;i+=40)
                txLine(0,i-1,1200,i-1);
        mar.draw();
        first.draw();
        if(timingshoot==0)
            first.moving();
        if(first.x1<=0)
            first.x1=0;

        if((first.x1>120)&&(first.x1<200)&&(firstshot.state==1)&&(first.color==1))
        {
            first.death();
            mar.state=0;
            firstshot.state=0;
            secondshot.state=0;
            thirdshot.state=0;
            fourthshot.state=0;
            fifthshot.state=0;
        }
        if((first.x1>280)&&(first.x1<480)&&(secondshot.state==1)&&(first.color==1))
        {
            first.death();
            mar.state=0;
            firstshot.state=0;
            secondshot.state=0;
            thirdshot.state=0;
            fourthshot.state=0;
            fifthshot.state=0;
        }
        if((first.x1>480)&&(first.x1<680)&&(thirdshot.state==1)&&(first.color==1))
        {
            first.death();
            mar.state=0;
            firstshot.state=0;
            secondshot.state=0;
            thirdshot.state=0;
            fourthshot.state=0;
            fifthshot.state=0;
        }
        if((first.x1>680)&&(first.x1<800)&&(fourthshot.state==1)&&(first.color==1))
        {
            first.death();
            mar.state=0;
            firstshot.state=0;
            secondshot.state=0;
            thirdshot.state=0;
            fourthshot.state=0;
            fifthshot.state=0;
        }
        if((first.x1>880)&&(first.x1<1160)&&(fifthshot.state==1)&&(first.color==1))
        {
            first.death();
            mar.state=0;
            firstshot.state=0;
            secondshot.state=0;
            thirdshot.state=0;
            fourthshot.state=0;
            fifthshot.state=0;

        }
        if((first.x1>160)&&(first.x1<240)&&(GetAsyncKeyState(0x45)))
        {
            mar.state=1;
            first.rifle=1;

        }
        if(first.rifle==0)
        {
            if(timingblind==1)
            {
                txSelectFont("terminal",30,6);
                txSetColor(TX_WHITE);
                txDrawText(699,299,1099, 399, "Подойди и забери винтовку (Нажми E)");
                txSelectFont("terminal",30,6);
                txSetColor(RGB(0,153,102));
                txDrawText(700,300,1100, 400, "Подойди и забери винтовку (Нажми E)");
                timingblind=0;
            }
            else
            {
                txSelectFont("terminal",30,6);
                txSetColor(TX_WHITE);
                txDrawText(699,299,1099, 399, "Подойди и забери винтовку (Нажми E)");
                timingblind=1;
            }
        }
        else
        {
            if(timingblind==1)
            {
                txSelectFont("terminal",30,6);
                txSetColor(TX_WHITE);
                txDrawText(699,299,1099, 399, "Теперь ты можешь уничтожать эту ересь на фоне \n (Нажми Пробел, выйдя из-за укрытия, пока она отключена)");
                txSelectFont("terminal",30,6);
                txSetColor(RGB(0,153,102));
                txDrawText(700,300,1100, 400, "Теперь ты можешь уничтожать эту ересь на фоне \n (Нажми Пробел, выйдя из-за укрытия, пока она отключена)");
                timingblind=0;
            }
            else
            {
                txSelectFont("terminal",30,6);
                txSetColor(TX_WHITE);
                txDrawText(699,299,1099, 399, "Теперь ты можешь уничтожать эту ересь на фоне \n (Нажми Пробел, выйдя из-за укрытия, пока она отключена)");
                timingblind=1;
            }

            if(timingshoot==1)
            {
                timingshoot++;
                first.state=13;
            }
            else if(timingshoot==2)
            {
                timingshoot++;
                first.state=14;
            }
            else if(timingshoot==3)
            {
                if((first.x1>120)&&(first.x1<240)&&(firstshot.state==0)&&(first.color==1))
                    firstshot.state=2;
                if((first.x1>280)&&(first.x1<480)&&(secondshot.state==0)&&(first.color==1))
                    secondshot.state=2;
                if((first.x1>480)&&(first.x1<680)&&(thirdshot.state==0)&&(first.color==1))
                    thirdshot.state=2;
                if((first.x1>680)&&(first.x1<800)&&(fourthshot.state==0)&&(first.color==1))
                    fourthshot.state=2;
                if((first.x1>880)&&(first.x1<1160)&&(fifthshot.state==0)&&(first.color==1))
                    fifthshot.state=2;
                timingshoot=0;
                first.state=6;
                first.ammo--;
            }
            if((GetAsyncKeyState(VK_SPACE))&&(first.ammo>0))
                if(timingshoot==0)
                {
                    timingshoot++;
                    first.state=12;
                }

        }
        if(first.rifle==1)
        {
            if(first.ammo==2)
            {
                txSelectFont("terminal",40,8);
                txSetColor(TX_WHITE);
                txDrawText(0,0,100, 50, "Патроны: 2");
            }
            if(first.ammo==1)
            {
                txSelectFont("terminal",40,8);
                txSetColor(TX_WHITE);
                txDrawText(0,0,100, 50, "Патроны: 1");
            }
            if(first.ammo==0)
            {
                txSelectFont("terminal",40,8);
                txSetColor(TX_WHITE);
                txDrawText(0,0,100, 50, "Патроны: 1");
            }
        }
        if(first.x1>=1000)
            first.ammo=2;

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

int thirdscene()
{
    HDC adam = txLoadImage("finalsprite.bmp");
    HDC pic = txLoadImage("comm.bmp");
    sprite first={50,520,5,0,6,1,1,2,adam};
    comm zero={800,515,0,pic};
    map field={0};
    field.three();
    int timing1=0;
    int timingcomm=0;
    int i;
    int timingshoot=0;
    int timingblind1=0;
    int timingblind2=0;
    int timingblind3=0;
    while(first.x1!=1200)
    {
        if(first.x1<=0)
        {
            txSetFillColor(TX_BLACK);
            txClear();
            Sleep(3000);
            txSelectFont("Terminal",50,10);
            txSetColor(TX_WHITE);
            txTextOut(400,400, "Вы вернулись назад. Вскоре вы были убиты на поле боя.");
            Sleep(3000);
            return 0;
        }
        txSetFillColor(TX_WHITE);
        txClear();
        field.draw1();                                                                //no u
        first.color=field.A[first.y1/40][(first.x1+15)/40];
        if(zero.state==1)
        {
            txSelectFont("Terminal",5,2);
            txSetColor(TX_WHITE);
            txDrawText(700,500,900, 520, "Назад!");
        }
        field.draw2();
        txSetColor(TX_WHITE,1);
        for(i=0;i<=800;i+=40)
                txLine(0,i-1,1200,i-1);
        first.draw();
        zero.draw();
        if(timingshoot==0)
            first.moving();
        if((timing1==5)&&(field.A[1][1]==1))
        {
            timing1=0;
            field.four();
        }
        if((timing1==1)&&(field.A[1][1]==7))
        {
            timing1=0;
            field.three();
        }
        if(first.x1>=300)
        {
            if((timingcomm>=5)&&(zero.state==0))
            {
                timingcomm=0;
                zero.state=1;

            }
            if((timingcomm>=3)&&(zero.state==1))
            {
                timingcomm=0;
                zero.state=0;

            }
            if(GetAsyncKeyState(VK_SPACE))
            {
                first.state=12;
                field.four();
                field.draw1();
                field.draw2();
                zero.draw();
                first.draw();
                Sleep(500);
                field.four();
                field.draw1();
                field.draw2();
                first.state=15;
                zero.draw();
                first.draw();
                Sleep(500);
                txSetFillColor(TX_BLACK);
                txClear();
                Sleep(5000);
                txSelectFont("Terminal",50,10);
                txSetColor(TX_WHITE);
                txTextOut(400,400, "Вы были приговорены к расстрелу за убийство командира и дезертирство.");
                Sleep(3000);

                break;
            }

        }
        else
            zero.state=0;

        if(first.x1>=350)
        {
            if(timingblind1==1)
            {
                txSelectFont("terminal",40,8);
                txSetColor(TX_WHITE);
                txDrawText(699,299,1099, 399, "Убей его");
                txSelectFont("terminal",40,8);
                txSetColor(RGB(0,153,102));
                txDrawText(700,300,1100, 400, "Убей его");
                timingblind1=0;
            }
            else if(timingblind1==0)
            {
                txSelectFont("terminal",40,8);
                txSetColor(TX_WHITE);
                txDrawText(699,299,1099, 399, "Убей его");
                timingblind1=1;
            }
        }
        if(first.x1>=400)
        {
            if(timingblind2==1)
            {
                txSelectFont("terminal",60,12);
                txSetColor(TX_WHITE);
                txDrawText(299,499,499, 399, "Убей его");
                txSelectFont("terminal",60,12);
                txSetColor(RGB(0,153,102));
                txDrawText(300,500,500, 400, "Убей его");
                timingblind2=0;
            }
            else
            {
                txSelectFont("terminal",60,12);
                txSetColor(TX_WHITE);
                txDrawText(299,499,499, 399, "Убей его");
                timingblind2=1;
            }
        }
        if(first.x1>=425)
        {
            if(timingblind3==1)
            {
                txSelectFont("terminal",30,6);
                txSetColor(TX_WHITE);
                txDrawText(599,499,799, 399, "Убей его");
                txSelectFont("terminal",30,6);
                txSetColor(RGB(0,153,102));
                txDrawText(600,500,800, 400, "Убей его");
                timingblind3=0;
            }
            else
            {
                txSelectFont("terminal",30,6);
                txSetColor(TX_WHITE);
                txDrawText(599,499,799, 399, "Убей его");
                timingblind3=1;
            }
        }
        if(first.x1>=500)
            first.x1=500;


        if(first.x1<=400)
            Sleep(500);
        else
            Sleep(300);

        timing1++;
        timingcomm++;
    }
}
