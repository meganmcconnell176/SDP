#include <FEHImages.h>
#include <FEHKeyboard.h>
#include <FEHLCD.h>
#include <FEHUtility.h>
#include <FEHFile.h>
#include <FEHRandom.h>
#include <FEHSD.h>
#include <LCDColors.h>


/*4 main buttons - play, stats, instructions, credits*/
int main(void)
{
    while (true)
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

        Sleep(5000);
             
}

    