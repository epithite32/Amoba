#ifndef COUNTER_HPP_INCLUDED
#define COUNTER_HPP_INCLUDED
#include "Widget.hpp"
#include "Button.hpp"
#include "graphics.hpp"
//using namespace genv;
//using namespace std;

class Counter: public Widget {
private:
    int akt;
    int mini,maxi;
    Button* b1;
    Button* b2;

public:
    Counter(int _x, int _y,int akt0, int _mini, int _maxi);
    virtual void draw(event ev);
    virtual void handle(event ev);
    virtual bool is_clicked(event ev);
    virtual bool is_on(int m_x, int m_y);
    virtual string get_status() const;
    virtual void set_akt(int _akt);
    virtual int get_akt();
    virtual void reposition(int new_x, int new_y);
    virtual void update();
    virtual void write_status();
    virtual ~Counter();

};

#endif // COUNTER_HPP_INCLUDED





