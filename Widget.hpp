#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED
#include "string"
#include "iostream"
#include "graphics.hpp"

using namespace genv;

class Widget {
protected:
    event ev;
    int x,y;
    int w,h;
    bool active=false;
public:
    Widget(int _x, int _y, int _w, int _h);
    virtual void draw(event ev) const;
    virtual void handle(event ev);
    virtual bool is_clicked(event ev);
    virtual void set_active(int mouse_x, int mouse_y);
    virtual bool get_active();
    virtual std::string get_status() const;
    event getEv();
};


#endif // WIDGET_HPP_INCLUDED
