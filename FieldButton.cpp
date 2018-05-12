#include "FieldButton.hpp"
#include "iostream"

using namespace std;

FieldButton::FieldButton(int _x, int _y)
    : Widget(_x,_y,50,50) {
        x=_x;
        y=_y;
        //title=_title;
        user_id=-1;
        //round=0;
    }

void FieldButton::draw() {
    gout << move_to(x+10, y+10) << color(150,150,150)<<box(15,15);
    gout << move_to(x + 15, y + 22) << color(220, 220, 220);

    if(user_id==-1){
    gout<<text(" ");
    }else if(user_id==0){
    gout<<color(255,0,0)<<text("X");
    }else if(user_id==1){
    gout<<color(0,255,0)<<text("O");
}
    gout<<refresh;
}

bool FieldButton::is_on(int m_x, int m_y) {
    return m_x>x+10 && m_x<x+25 && m_y>y+10 && m_y<y+25;
}
bool FieldButton::is_clicked(event ev) {

    return ev.type==ev_mouse && ev.button==btn_left && is_on(ev.pos_x, ev.pos_y);


}
void FieldButton::set_selected(event ev) {
    if(is_clicked(ev)) selected = true;
    else selected = false;
}
void FieldButton::handle(event ev){
    if(is_clicked(ev)){
        round++;
    }
    //set_userid(round);
}
void FieldButton::set_userid(int round){
    if(round==0){
        user_id=-1;
    }else if(round%2==0){
        user_id=0;
    }else if(round%2==1){
        user_id=1;
    }
}
int FieldButton::get_userid(){
    return user_id;
}
FieldButton::~FieldButton() {}
