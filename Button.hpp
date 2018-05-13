#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

#include "graphics.hpp"

using namespace std;
using namespace genv;

class Button {
public:
    int x, y, w, h;
    bool kattinthato=false;
    string title;
    bool selected = false;

    Button(int _x, int _y, int _w, int _h, string _title);
    virtual void set_selected(event ev);
    virtual void draw(event ev);
    virtual void draw(int _r, int _g, int _b) const;
    virtual bool is_on(int m_x, int m_y);
    virtual bool is_clicked(event ev);
    virtual ~Button();

};


#endif // BUTTON_HPP_INCLUDED
