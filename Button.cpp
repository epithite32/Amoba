#include "Button.hpp"
#include "iostream"

using namespace std;


Button::Button(int _x, int _y, int _w, int _h, string _title) {
    x = _x;
    y = _y;
    w = _w;
    h = _h;
    title = _title;

}
void Button::draw(event ev) {
    int tmp;
    if(selected){
        tmp=100;
    }else{
        tmp=0;
    }

    gout << move_to(x, y) << color(150 + tmp,150-tmp,150-tmp)<<box(w,h);
    gout << move_to(x + 10, y + 10) << color(220, 220, 220) <<text(title);
}

void Button::draw(int _r, int _g, int _b) const {
    gout << move_to(x, y) << color(_r,_g,_b)<<box(w,h);
    gout << move_to(x+10, y+10) << color(255,255,255)<<box(w-10,h-10);
    gout << move_to(x + 20, y + 20) << color(220, 220, 220) <<text(title);

}
bool Button::is_on(int m_x, int m_y) {
    return m_x>x && m_x<x+w && m_y>y && m_y<y+h;
}
bool Button::is_clicked(event ev) {

    return ev.type==ev_mouse && ev.button==btn_left && is_on(ev.pos_x, ev.pos_y);


}
void Button::set_selected(event ev) {
    if(is_clicked(ev)) selected = true;
    else selected = false;
}
Button::~Button() {}
