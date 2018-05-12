#ifndef JATEKMESTER_HPP_INCLUDED
#define JATEKMESTER_HPP_INCLUDED
#include "Widget.hpp"
#include "FieldButton.hpp"
#include "graphics.hpp"

class JatekMester{

private:
    int meret;
    int kor;
    vector<Widget*> w;
    vector<FieldButton*> fb;
public:

    JatekMester(int _meret);
    virtual bool nyertel();
    virtual void letrehoz();
    virtual void kirajzol();
    virtual void frissit(int id);
    virtual void game_log();
};
#endif // JATEKMESTER_HPP_INCLUDED
