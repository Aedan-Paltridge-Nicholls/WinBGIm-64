#include "graphics.h"
#include <iostream>
#include <string>
#include <math.h>
#include <ctime>
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

}
void square()
{
    draw_line_DDA({1 , 1}, {1 , 300}, WHITE);
    draw_line_DDA({1 , 1}, {300 , 1}, WHITE);
    draw_line_DDA({300 , 1}, {300 , 300}, WHITE);
    draw_line_DDA({1 , 300}, {300 , 300}, WHITE);

}
void Rectangle(int rectHeight,int rectwidth)
{
    draw_line_DDA({1 , 1}, {1 , rectHeight}, WHITE);
    draw_line_DDA({1 , 1}, {rectwidth , 1}, WHITE);
    draw_line_DDA({rectwidth , 1}, {rectwidth , rectHeight}, WHITE);
    draw_line_DDA({1 , rectHeight}, {rectwidth , rectHeight}, WHITE);

}
int MainMenu()
{
   //clearviewport( );
    char MenuImp;
    do
    {
       MenuImp = (char) getch( );
        outtextxy(20, 170, "Press {A} For Play");
        outtextxy(20, 190, "Press {B} For Final Score");
        outtextxy(20, 210, "Press {C} To Exit");
        switch (MenuImp)
        {
            case 'a':
            {
              
            }
            break;
            case 'b':
            {
                
            }
            break;
            case 'c':
            {
                
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
 
 std::string output = "the score is : ";
 std::string scoreImp = std::to_string(score); 
 output.append(scoreImp);
 std::string Str17 = output;
 char *Fixer = new char[Str17.length()+1];
  strcpy(Fixer,Str17.c_str());
    outtextxy(20, 70,Fixer);
    delete [] Fixer;
   MainMenu();
   // cleardevice();
}

void FinalScore()
{


}
int main()
{
    srand(time(nullptr));
    char c,Cs;
    initwindow(Width,Height,"task5");
    rect = rand() %300+1;
    rect2 = rand() %300+1;
    
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
            CalculateScore();
        } 
  else
  {   // Process one of the special keys:
    c = (char) getch( );
    switch (c)
    {
        case KEY_HOME:    std::cout << "Home key."   << std::endl; break;
        case KEY_UP: std::cout << "Up key."     << std::endl; break;
        case KEY_PGUP:    std::cout << "PgUp key."   << std::endl; break;
        case KEY_LEFT:    std::cout << "Left key."   << std::endl; break;
        case KEY_CENTER:  std::cout << "Center key." << std::endl; break;
        case KEY_RIGHT:   std::cout << "Right key."  << std::endl; break;
        case KEY_END:     std::cout << "End key."    << std::endl; break;
        case KEY_DOWN:    std::cout << "Down key."   << std::endl; break;
        case KEY_PGDN:    std::cout << "PgDn key."   << std::endl; break;
        case KEY_INSERT:  std::cout << "Insert key." << std::endl; break;
        case KEY_DELETE:  std::cout << "Delete key." << std::endl; break;
        case KEY_F1:std::cout << "F1 key."     << std::endl; break;
        case KEY_F2:std::cout << "F2 key."     << std::endl; break;
        case KEY_F3:std::cout << "F3 key."     << std::endl; break;
        case KEY_F4:std::cout << "F4 key."     << std::endl; break;
        case KEY_F5:std::cout << "F5 key."     << std::endl; break;
        case KEY_F6:std::cout << "F6 key."     << std::endl; break;
        case KEY_F7:std::cout << "F7 key."     << std::endl; break;
        case KEY_F8:std::cout << "F8 key."     << std::endl; break;
        case KEY_F9:std::cout << "F9 key."     << std::endl; break;
        default: std::cout << "Unknown extended key." << std::endl;
    }
    }
        }   while ((c != 'x') && (c != 'X'));



        
    
        

        getchar();
        
        return 0;
    }

