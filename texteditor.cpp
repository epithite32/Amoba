#include "texteditor.hpp"
#include <string>
using namespace std;
using namespace genv;

bool tullepett=false;
TextEditor::TextEditor(int _x, int _y, int _w, int _h, string _akt):Widget(_x,_y,_w,_h)
{
    x = _x;
    y = _y;
    w = _w;
    h = _h;
    akt=_akt;

    //kivalaszt=false;
}
void TextEditor::draw(event ev)
{
    //cout<<"mukodik";
    if (active)
    {
        gout << color(255,255,255);
    }
    else
    {
        gout << color(155,155,155);
    }

    gout << move_to(x, y) << box(w, h);
    gout << color(0,0,0) << move_to(x+1, y+1) << box(w-2, h-2);
    gout << move_to(x+3,y+gout.cascent()+5) << color(255,255,255) << text(akt);
    if (is_clicked(ev)) gout <<text("|");
}
void TextEditor::handle(event ev)
{
    int i=0;
    if (ev.type == ev_key && active)
    {
        if (ev.keycode >= ' ' && ev.keycode < 255)
        {
            akt+=ev.keycode;


            if (w < 10+gout.twidth(akt) )
            {
                akt = akt.substr(1,akt.length()-1);
            }

        }
        //cout<<tullepett;
        if (ev.keycode == key_backspace){
                    akt = akt.substr(0,akt.length()-1);
                    }
        if(w < 10+gout.twidth(akt)&& ev.keycode == key_backspace){

        }
                }
    }
bool TextEditor::is_on(int m_x, int m_y) {
    return m_x>x && m_x<x+w && m_y>y && m_y<y+h;
}
string TextEditor::getStatus(){
    return akt;
}

bool TextEditor::is_clicked(event ev) {
    return(ev.type==ev_mouse && ev.button==btn_left && is_on(ev.pos_x, ev.pos_y));

}
void TextEditor::setFocused(event ev){
    if(is_clicked(ev)){
        focused=true;
    }else{
        focused=false;
    }
}
