#include <FEHImages.h>
#include <FEHKeyboard.h>
#include <FEHLCD.h>
#include <FEHUtility.h>
#include <FEHFile.h>
#include <FEHRandom.h>
#include <FEHSD.h>
#include <LCDColors.h>

/*draw main menu function*/
void DrawMenu()
{  
    /*set background color*/
    LCD.SetBackgroundColor(PINK);
    LCD.Clear();

    /*make rectangles*/
    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(55,60,100,50);
    LCD.FillRectangle(55,60,100,50);

    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(165,60,100,50);
    LCD.FillRectangle(165,60,100,50);

    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(55,120,100,50);
    LCD.FillRectangle(55,120,100,50);

    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(165,120,100,50);
    LCD.FillRectangle(165,120,100,50);

    /*make the text for each option*/
    LCD.SetFontScale(0.5);
    float currentScale = LCD.GetFontScale();
    LCD.SetFontColor(GRAY);
    LCD.WriteAt("Play Game",75,78);
    LCD.WriteAt("View Statistics",170,78);
    LCD.WriteAt("How to Play",68,138);
    LCD.WriteAt("Credits",195,138);
    LCD.Update();
}

void ReturnHome()
{
    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(10,210,120,20);
    LCD.FillRectangle(10,210,120,20);
    LCD.SetFontScale(0.5);
    float currentScale = LCD.GetFontScale();
    LCD.SetFontColor(GRAY);
    LCD.WriteAt("Return to Homepage",15,213);
}

void PlayGame()
{
    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(10,180,120,20);
    LCD.FillRectangle(10,180,120,20);
    LCD.SetFontScale(0.5);
    float currentScale = LCD.GetFontScale();
    LCD.SetFontColor(GRAY);
    LCD.WriteAt("Continue to Game",20,184);
}

void statistics()
{
    LCD.SetFontColor(GRAY);
    LCD.WriteAt("Level 1 Best Time: 03:15:21",75,80);   
    LCD.WriteAt("Level 2 Best Time: 03:15:21",75,95); 
    LCD.WriteAt("Level 3 Best Time: 03:15:21",75,110); 
}

void HowToPlay()
{
    LCD.SetFontColor(GRAY);
    LCD.WriteAt("Choose from 3 levels and characters.",60,80);
    LCD.WriteAt("Use the up arrow to jump to avoid obstacles.",30,95);
    LCD.WriteAt("Your goal is to stay alive for as long as you can.",10,110);
    LCD.WriteAt("Good luck and have fun!",80,125);
}

void credits()
{
    LCD.WriteAt("Authors: Megan McConnell and Costa Zografos",30,80); 
    LCD.WriteAt("Sources: https://u.osu.edu/sdpsi",55,105); 
    LCD.WriteAt("mulator/programming-syntax",55,120); 
}

void ChooseLevel()
{
    /*write title*/
    LCD.SetFontColor(GRAY);
    LCD.WriteLine("Select Level");

    /*create level options*/
    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(110,50,100,40);
    LCD.FillRectangle(110,50,100,40); 
    LCD.SetFontColor(GRAY);
    LCD.WriteAt("Level 1: Easy",120,65);

    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(110,100,100,40);
    LCD.FillRectangle(110,100,100,40); 
    LCD.SetFontColor(GRAY);
    LCD.WriteAt("Level 2: Medium",115,115);

    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(110,150,100,40);
    LCD.FillRectangle(110,150,100,40); 
    LCD.SetFontColor(GRAY);
    LCD.WriteAt("Level 3: Hard",120,165);
}

void ChooseCharacter()
{
    /*write title*/
    LCD.SetFontColor(GRAY);
    LCD.WriteLine("Select Character");
}

int main()
{    
    /*call draw menu function*/ 
    DrawMenu(); 

    /*define location variables*/
    float x, y;
    
    /*initialize values*/
    bool homescreen = true;
    bool choosingLevel = false;
    int selectedLevel = 0;  // Will store 1, 2, or 3

    while(true){
        /* Wait until the user touches the screen */
        while(!LCD.Touch(&x,&y)) {};

        if (homescreen == true)
        {
            /*play game selected*/
            if(x >= 55 && x <= 155 && y >= 60 && y <= 110)
            {
                /*write selected option*/
                LCD.Clear();
                LCD.WriteLine("Play Game selected");
                homescreen = false;

                /*call return to home function*/
                ReturnHome();
                PlayGame();
            }

            /*statistics selected*/
            if(x >= 165 && x <= 265 && y >= 60 && y <= 110)
            {
                LCD.Clear();
                LCD.WriteLine("Statistics selected");
                homescreen = false;
                statistics();
                /*call return to home function*/
                ReturnHome();
            }

            /*how to play selected*/
            if(x >= 55 && x <= 155 && y >= 120 && y <= 170)
            {
                LCD.Clear();
                LCD.WriteLine("How to Play selected");
                homescreen = false;
                HowToPlay();
                /*call return to home function*/
                ReturnHome();
            }

            /*credits selected*/
            if(x >= 165 && x <= 265 && y >= 120 && y <= 170)
            {
                LCD.Clear();
                LCD.WriteLine("Credits selected");
                homescreen = false;
                credits();
                /*call return to home function*/
                ReturnHome();
            }
        }
        else
        {
            while (!LCD.Touch(&x,&y)){}
             if (x >= 10 && x <= 130 && y >= 210 && y <= 230)
            {
                homescreen = true;
                DrawMenu();
            }

            /*choose level function if the user continues to game*/
            if (x >= 10 && x <= 130 && y >= 180 && y <= 200)
            {
                LCD.Clear();
                ChooseLevel();  
                choosingLevel = true;
            }

            if (choosingLevel == true)
            {
                /*user selects level 1*/
                if (x >= 110 && x <= 210 && y >= 50 && y <= 90)
                {
                    selectedLevel = 1;
                    choosingLevel = false; 
                    LCD.Clear();
                    ChooseCharacter();
                }

                 /*user selects level 2*/
                if (x >= 110 && x <= 210 && y >= 100 && y <= 140)
                {
                    selectedLevel = 2;
                    choosingLevel = false;
                    LCD.Clear();
                    ChooseCharacter();
                }

                 /*user selects level 3*/
                if (x >= 110 && x <= 210 && y >= 150 && y <= 190)
                {
                    selectedLevel = 3;
                    choosingLevel = false;
                    LCD.Clear();
                    ChooseCharacter();
                }
            }

        }
    
        LCD.Update();
        
    }   

        while (1) {
            LCD.Update();
            // Never end
        }
        return 0;

}       





    