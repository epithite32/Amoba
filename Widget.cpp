#include "Widget.hpp"
#include "Counter.hpp"
#include "graphics.hpp"

Widget::Widget(int _x, int _y, int _w, int _h) {
    x=_x;
    y=_y;
    w=_w;
    h=_h;
}
void Widget::draw(event ev) const {

}
void Widget::set_active(int mousex, int mousey) {

    active = mousex>x && mousex<x+w && mousey>y && mousey<y+h;

}
bool Widget::is_clicked(event ev) {
    return false;
}
void Widget::handle(event ev) {

}

bool Widget::get_active() {
    return active;
}
event Widget::getEv() {
    return ev;
}
string Widget::get_status() const {
    return "";
}
