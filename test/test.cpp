#include "graphics.h"
#include <iostream>
#include <string>
#include <math.h>
#include <ctime>
#include <stdio.h>
int i, j = 0, gd = DETECT, gm;
int rect,rect2,score=0;
const int Width = 800;
const int Height = 600;
int g_offSet = 170;
int g_offSet2 = 170;
typedef int Radius;

struct Point
{
    double x;
    double y;
    Point() {}
    Point(double a, double b)
    {
        x = a;
        y = b;
    }
};

template <typename A>
Point convertPixel(A &x, A &y)
{
     x = -x;
    x += Width - g_offSet2;
    //    x+=Width/2;
    y = -y;
    y += Height - g_offSet;
    return {x, y};
}
void drawPixel(double x, double y, int color)
{
    convertPixel(x, y);
    putpixel(x, y, color);
}

void fill(double x, double y, int color)
{
    convertPixel(x, y);
    floodfill(x,y,color);
}
void draw_line_DDA(Point a, Point b, int color)
{
    double x0 = a.x, y0 = a.y, x1 = b.x, y1 = b.y;
    double dx = x1 - x0;
    double dy = y1 - y0;

    double steps = std::max(abs(dx), abs(dy));

    double Xinc = dx / steps;
    double Yinc = dy / steps;
   
     
    for (int i = 0; i < steps; i++)
    {
        drawPixel(x0, y0, color);
        x0 += Xinc;
        y0 += Yinc;
    }
}
void triangle()
{
    draw_line_DDA({1 , 20}, {150 , 300}, WHITE);
    draw_line_DDA({150 , 300}, {300 , 20}, WHITE);
    draw_line_DDA({1 , 20}, {300 , 20}, WHITE);
    fill(50,50,WHITE);
}
void square()
{
    draw_line_DDA({1 , 1}, {1 , 300}, WHITE);
    draw_line_DDA({1 , 1}, {300 , 1}, WHITE);
    draw_line_DDA({300 , 1}, {300 , 300}, WHITE);
    draw_line_DDA({1 , 300}, {300 , 300}, WHITE);
   fill(50,50,WHITE);
}
void Rectangle(int rectHeight,int rectwidth)
{
    draw_line_DDA({1 , 1}, {1 , rectHeight}, WHITE);
    draw_line_DDA({1 , 1}, {rectwidth , 1}, WHITE);
    draw_line_DDA({rectwidth , 1}, {rectwidth , rectHeight}, WHITE);
    draw_line_DDA({1 , rectHeight}, {rectwidth , rectHeight}, WHITE);
       fill((rectwidth-5),(rectHeight -5),WHITE);
}

void testhelp(int *hell,int runs)
{
    
      std::string output = "the points are : ";
      output.append("{ ");
    for (int r = 0; r < runs; r++)
    {
        std::string Imp = std::to_string(hell[r]); 
        output.append(Imp);
        output.append(", ");
    }
    output.append("} ");
    std::string Str7 = output;
    char *Fixer = new char[Str7.length()+1];
    strcpy(Fixer,Str7.c_str());
    outtext(Fixer);

}
void Other()
{
     int shape = rand()%4+1;
    
    int dotnum;
    int random = rand()%15+5;
    if (random %2 !=0){random++;}
    dotnum = random*2;
    int dots[dotnum];
    for (int d = 0; d < dotnum; d++)
    {   
      int  randpoint = rand() %300+25;
      randpoint = -randpoint;
      if (d %2 != 0){ randpoint+= Width - g_offSet2;}
      else{ randpoint+= Height - g_offSet;}
       dots[d]= randpoint;
       if (d == dotnum-1)
       {dots[d] = dots[0];}
        if (d == dotnum)
       {dots[d] = dots[1];}
    }
    std::string scoreImp = std::to_string(random); 
    std::string output = "the random is : ";
     output.append(scoreImp);
    std::string Str7 = output;
    char *Fixer = new char[Str7.length()+1];
    strcpy(Fixer,Str7.c_str());
    outtextxy(20,120,Fixer);
    int dotsets = dotnum/2;
    testhelp(dots,dotnum);
    drawpoly(dotsets,dots);
    
}
void Othertest()
{
    for (int l = 0; l < 10; l++)
    { 
        Other();
         delay(100000);
      clearviewport( );
    }
}
int MainMenu()
{
    void FinalScore();
    int main();
   triangle();
    char MenuImp;
    do
    {
        outtextxy(20, 170, "Press {A} For Play");
        outtextxy(20, 190, "Press {B} For Final Score");
        outtextxy(20, 210, "Press {C} To Exit");
       MenuImp = (char) getch( );
        
        switch (MenuImp)
        {
            case 'a':
            {
              return 0;
            }
            break;
            case 'b':
            {
                FinalScore();
            }
            break;
            case 'c':
            {
                exit(0);
            }
            break;
        
        default:
            break;
        }


    } while ( true);
    
  
}
void CalculateScore()
{
 score += 10;

 clearviewport( );
 std::string output = "the score is : ";
 std::string scoreImp = std::to_string(score); 
 output.append(scoreImp);
 std::string Str17 = output;
 char *Fixer = new char[Str17.length()+1];
  strcpy(Fixer,Str17.c_str());
    outtextxy(20, 70,Fixer);
     delay(1000);
    delete [] Fixer;
     clearviewport( );
   MainMenu();
  
}
void FinalScore()
{
    clearviewport( );
 std::string output = "the score is : ";
 std::string scoreImp = std::to_string(score); 
 output.append(scoreImp);
 std::string Str7 = output;
 char *Fixer = new char[Str7.length()+1];
  strcpy(Fixer,Str7.c_str());
    outtextxy(20, 70,Fixer);
    delete [] Fixer;
   MainMenu();
}
int main()
{  
 
    srand(time(nullptr));
    char c,Cs;
    initwindow(Width,Height,"task5");
    Other();
    Othertest();
    rect = rand() %300+25;
    rect2 = rand() %300+25;
    
    int shape = rand()%4+1;
    switch (shape)
    {
        case 1:
            {
                triangle();
                Cs ='b';
            }
            break;
            case 2:
            {
                Rectangle(rect,rect2);
                Cs ='a';
               
            }
            break;
            case 3:
            {
             square();
             Cs ='c';
            }
            break;
            case 4:
            {
                Other();
                Cs ='d';
            }
            break;
            
    
     default:
        break;
    }
    
    outtextxy(20, 130, "Identify the Shapes");
    outtextxy(20, 150, "What Is the Current shape ?");
    outtextxy(20, 170, "Press {A} if it is a Rectangle");
    outtextxy(20, 190, "Press {B} if it is a Triangle");
    outtextxy(20, 210, "Press {C} if it is a Square");
    outtextxy(20, 230, "Press {D} if it is None of the above");
    do
    {
        c = (char) getch( );
        if (c == Cs )
        {

            std::cout << "vitory " << (int) c << std::endl;
            c=0,Cs=0;
            CalculateScore();
        } 
            else
            {   clearviewport( );
            outtextxy(20, 130, "Identify the Shapes");
            outtextxy(20, 150, "INCORECT SHAPE try again");
            main();
            }
    }   while ((c != 'x') && (c != 'X'));
    getchar();
    
    return 0;
}

