#ifndef TEXTEDITOR_HPP_INCLUDED
#define TEXTEDITOR_HPP_INCLUDED
#include <string>
#include <vector>
#include "Widget.hpp"
#include "graphics.hpp"

using namespace std;
class TextEditor : public Widget
{
    int x, y, w, h;

    string str;
    bool focused=false;
public:
    string akt;
    TextEditor(int _x, int _y, int _w, int _h,string akt);
    virtual void draw(event ev);
    string getStatus();
    virtual void handle(event ev) ;
    virtual bool is_on(int m_x, int m_y);
    virtual bool is_clicked(event ev);
    virtual void setFocused(event ev);
    inline string value()
    {
        return akt;
    }
};



#endif // TEXTEDITOR_HPP_INCLUDED
