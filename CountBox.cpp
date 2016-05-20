#include "graphics.hpp"
#include "CountBox.h"
#include <sstream>
#include <string>
#include <fstream>

using namespace genv;
using namespace std;

CountBox::CountBox(int x, int y, int sx, int sy, int minimum, int maximum, int kezdoertek)
    : Widget(x,y,sx,sy)
{
    _checked = false;
    kapcsolo = false;
    FontSize=sy-10;
    mini = minimum;
    maxi = maximum;
    szam = kezdoertek;
}

void CountBox::draw() const
{
    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
    gout << move_to(_x+_size_x-20, _y) << color(255,255,255) << box(20, _size_y/2);
    gout << move_to(_x+_size_x-20, _y+(_size_y)/2) << color(255,255,255) << box(20, _size_y/2);
    gout << move_to(_x+_size_x-19, _y+(_size_y)/2) << color(0,0,0) << line(18, 0);

    gout << move_to(_x+_size_x-16, _y+(_size_y)/2+(_size_y)/8) << color(0,0,0) << line(7.5,(_size_y)/3.5);
    gout << move_to(_x+_size_x-17, _y+(_size_y)/2+(_size_y)/8) << color(0,0,0) << line(7.5,(_size_y)/3.5);
    gout << move_to(_x+_size_x-4, _y+(_size_y)/2+(_size_y)/8) << color(0,0,0) << line(-7.5,(_size_y)/3.5);
    gout << move_to(_x+_size_x-3, _y+(_size_y)/2+(_size_y)/8) << color(0,0,0) << line(-7.5,(_size_y)/3.5);

    gout << move_to(_x+_size_x-16, _y+(_size_y)/2-(_size_y)/8) << color(0,0,0) << line(7.5,-(_size_y)/3.5);
    gout << move_to(_x+_size_x-17, _y+(_size_y)/2-(_size_y)/8) << color(0,0,0) << line(7.5,-(_size_y)/3.5);
    gout << move_to(_x+_size_x-4, _y+(_size_y)/2-(_size_y)/8) << color(0,0,0) << line(-7.5,-(_size_y)/3.5);
    gout << move_to(_x+_size_x-3, _y+(_size_y)/2-(_size_y)/8) << color(0,0,0) << line(-7.5,-(_size_y)/3.5);

    gout << color(255,255,255);

    gout.load_font("LiberationSans-Regular.ttf",FontSize);

    std::string betu;

    std::stringstream ss;
    ss << szam;
    ss >> betu;

    gout << move_to(_x+_size_x/14, _y+_size_y/14) << text(betu);

}


void CountBox::handle(event ev)
{
   if (ev.keycode == key_enter)
    {
        ofstream fajl;
        fajl.open("adatok.txt");

        fajl << szam << "\n";

        fajl.close();
    }

    if (ev.type == ev_key && (ev.keycode == key_up || ev.keycode == key_pgup) && szam < maxi && kapcsolo == true)
    {
        szam = szam + 1;
    }

    if (ev.type == ev_key && (ev.keycode == key_down || ev.keycode == key_pgdn) && szam > mini && kapcsolo == true)
    {
        szam = szam - 1;
    }

    if (ev.type == ev_mouse && ev.pos_x > _x+_size_x-20 && ev.pos_x < _x+_size_x && ev.pos_y > _y &&
            ev.pos_y < _y+(_size_y)/2 && ev.button == btn_left && szam < maxi && kapcsolo == true)
    {

        szam = szam + 1;
    }

    if (ev.type == ev_mouse && ev.pos_x > _x+_size_x-20 && ev.pos_x < _x+_size_x && ev.pos_y > _y+(_size_y)/2 &&
            ev.pos_y < _y+_size_y && ev.button == btn_left && szam > mini && kapcsolo == true)
    {

        szam = szam - 1;
    }


}
bool CountBox::is_checked() const
{
    return _checked;
}
void CountBox::action(event ev)
{
}
