#include <sstream>
#include <string>
#include <fstream>
#include "Counter.hpp"
#include "Button.hpp"
using namespace genv;

Counter::Counter(int _x, int _y, int akt0, int _mini, int _maxi)
    : Widget(_x,_y,200,50) {
    akt=akt0;
    mini=_mini;
    maxi=_maxi;
    b1=new Button(_x+150,_y,50,25,"+");
    b2=new Button(_x+150,_y+25,50,25,"-");
    update();
}

void Counter::draw(event ev) {
    stringstream ss;
    string str;
    ss<<akt;
    str=ss.str();
    gout<<move_to(x,y)<<color(220,220,220)<<box(w,h)<<move_to(x+10, y+10)<<color(255,255,255)<<box_to(x+w-50, y+h-10)
        << move_to(x + 20, y + 25) << color( 0, 0, 0) << text(str);


    b1->draw(ev);
    b2->draw(ev);

}

void Counter::set_akt(int _akt) {
    akt = _akt;
}

void Counter::handle(event ev) {

    if(b1->is_clicked(ev) || ev.keycode == key_up || ev.keycode == key_pgup) {
        set_akt(akt + 1);
    }
    if(b2->is_clicked(ev) || ev.keycode == key_down || ev.keycode == key_pgdn) {
        set_akt(akt -1);
    }
    write_status();
    if(akt <= mini) set_akt(mini);
    if(akt >= maxi) set_akt(maxi);

}
bool Counter::is_on(int m_x, int m_y) {
    return m_x>x && m_x<x+w && m_y>y && m_y<y+h;
}
bool Counter::is_clicked(event ev) {
    return ev.type==ev_mouse && ev.button==btn_left && is_on(ev.pos_x, ev.pos_y);
}

int Counter::get_akt() {
    return akt;
}
string Counter::get_status() const {
    return "";
}

void Counter::write_status() {
    ofstream ofs("counter.txt");
    if(ofs.good()) {
        ofs<<get_akt();
    }
    ofs.close();
}


void Counter::reposition(int new_x, int new_y) {
    gout<<move_to(x,y)<<color(0,0,0)<<box(200,50)<<refresh;
    x=new_x;
    y=new_y;

    b1->x=x+150;
    b1->y=y;
    b2->x=x+150;
    b2->y=y+25;
}
void Counter::update() {
    draw(ev);

    gout << refresh;

}
Counter::~Counter() {
    delete b1;
    delete b2;
}

