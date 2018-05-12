#ifndef CHOICE_HPP_INCLUDED
#define CHOICE_HPP_INCLUDED
#include "Widget.hpp"
#include "Button.hpp"
#include "graphics.hpp"
#include <vector>


class Choice: public Widget {
private:
    int h;
    int mozog;
    string valasztott;
    Button* b1;
    Button* b2;
    vector<string> elemek;


public:

    int kezdomeret;
    Choice(int _x, int _y,string _valasztott, int _h, int kezdomeret);
    vector<Button*> options;
    virtual int get_h();
    virtual void draw(event ev);
    virtual void StringFeltolt(vector<string> str);
    virtual void SetHeight();
    virtual void addOption(string op);
    virtual void ButtonFeltolt();
    virtual void handle(event ev);
    virtual bool is_clicked(event ev);
    virtual bool is_on(int m_x, int m_y);
    virtual string get_status() const;
    virtual void set_valasztott(string _valasztott);
    virtual string get_valasztott();
    virtual void update();
    virtual void write_status();
    virtual ~Choice();

};

#endif // CHOICE_HPP_INCLUDED
