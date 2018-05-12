#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include "FieldButton.hpp"
#include "graphics.hpp"
#include "JatekMester.hpp"
using namespace genv;

JatekMester::JatekMester(int _meret){
    meret=_meret;
    kor=0;


}
void JatekMester::letrehoz(){
    for(int j=0; j<meret; j++){
        for(int i=0; i<meret; i++){
        FieldButton* fbp=new FieldButton(i*20,j*20);

        fb.push_back(fbp);
        w.push_back(fbp);
        }
    }
}
void JatekMester::kirajzol(){
        for(int i=0; i<meret*meret; i++){
                fb[i]->draw();
                //cout<<"test";
        }
    }
void JatekMester::frissit(int id){
    fb[id]->draw();
}
bool JatekMester::nyertel(){
    for(int i=0; i<fb.size()-5;i++){
    for(int j=0;j<5;j++){
        if(fb[i]->get_userid() == fb[i+j]->get_userid() && fb[i]->get_userid()!=-1){
            return true;
            cout<<"NAGYON JO VAGY";
            }else{
            return false;
        }
        }
    }
}
void JatekMester::game_log(){
    gout.open(800,800);
    letrehoz();
    kirajzol();

    event ev;
    while(gin >> ev) {
            cout<<"1"<<endl;
        for(int i=0; i<fb.size(); i++){
            //cout<<"2"<<endl;
        if(fb[i]->is_clicked(ev) && fb[i]->get_userid()==-1 &&!nyertel()){
            cout<<"belemegy";
            //fb[i]->handle(ev);
            kor++;
            fb[i]->set_userid(kor);
            frissit(i);
            nyertel();
        }
        }

        //gout<<move_to(30,30)<<text("test");
    }
}
