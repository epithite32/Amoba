#ifndef FIELDBUTTON_HPP_INCLUDED
#define FIELDBUTTON_HPP_INCLUDED
#include "Button.hpp"
#include "Widget.hpp"
#include "graphics.hpp"

using namespace std;
using namespace genv;

class FieldButton : public Widget{
private:
    int x, y;
    Button* b;
    int user_id;
    int round;
    bool kattinthato=false;
    //string title;
    bool selected = false;
public:

    FieldButton(int _x, int _y);
    virtual void set_selected(event ev);
    virtual void draw();
    virtual void handle(event ev);
    virtual bool is_on(int x, int y);
    virtual bool is_clicked(event ev);
    virtual int get_userid();
    virtual void set_userid(int userid);
    ~FieldButton();
    //virtual void set_selected(event ev);

} ;


#endif // FIELDBUTTON_HPP_INCLUDED
