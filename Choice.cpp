#include <sstream>
#include <string>
#include <fstream>
#include "Choice.hpp"
#include "Button.hpp"
using namespace genv;

Choice::Choice(int _x, int _y, string _valasztott, int _h,int _kezdomeret): Widget(_x,_y,200,_h) {
    valasztott=_valasztott;
    h=_h;
    kezdomeret=_kezdomeret;
    mozog=0;
    b1=new Button(_x+175,_y,25,25,"^");
    b2=new Button(_x+175,_y+_h-15,25,25,"v");
}

int Choice::get_h() {
    return h;
}
void Choice::addOption(string op){
    elemek.push_back(op);
}
void Choice::draw(event ev) {

    gout<<move_to(x,y)<<color(220,220,220)<<box_to(x+w,y+h-10)<<move_to(x+10, y+10);

    /*for(int i=mozog; i<options.size()+mozog; i++) {

        options[i]->draw(ev);
        options[i]->kattinthato=true;

    }*/
    for(int i = 0; i < options.size(); i ++)
    {
        options[i]->draw(ev);

    }

    b1->draw(ev);
    b2->draw(ev);
}

void Choice::SetHeight() {
    h=((options.size())*30)+10;
}
void Choice::ButtonFeltolt() {
    for(int i=0; i<elemek.size(); i++) {
        Button* tmp=new Button(x,y+10+i*30,175,30,elemek[i]);
        options.push_back(tmp);
    }


}
void Choice::StringFeltolt(vector<string> str) {
    elemek=str;

}

void Choice::set_valasztott(string _valasztott) {
    valasztott = _valasztott;
}

void Choice::handle(event ev) {
    for(int i=0; i<options.size(); i++) {
        options[i]->set_selected(ev);
    }
        //options[i]->kattinthato=false;
        write_status();

    if(b1->is_clicked(ev)&& mozog>0) {
        mozog--;
    } else if(b2->is_clicked(ev)&& mozog<options.size()-3) {
        mozog++;
    }


}
bool Choice::is_on(int m_x, int m_y) {
    return m_x>x && m_x<x+w && m_y>y && m_y<y+h;
}
bool Choice::is_clicked(event ev) {
    return ev.type==ev_mouse && ev.button==btn_left && is_on(ev.pos_x, ev.pos_y);
}

string Choice::get_valasztott() {
    return valasztott;
}


string Choice::get_status() const {
    return "";
}

void Choice::write_status() {
    ofstream ofs("choice.txt");
    if(ofs.good()) {
        ofs<<get_valasztott();
    }
    ofs.close();
}



void Choice::update() {
    draw(ev);

    //gout << refresh;

}
Choice::~Choice() {
    delete b1;
    delete b2;
}
