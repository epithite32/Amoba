#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include "FieldButton.hpp"
#include "texteditor.hpp"
#include "graphics.hpp"
#include "JatekMester.hpp"
using namespace genv;

JatekMester::JatekMester(int _meret){
    meret=_meret;
    kor=0;
    egyezes.push_back(0);
    TextEditor* tx=new TextEditor(900,100,80,50,"test");
    w.push_back(tx);

}
void JatekMester::letrehoz(){

    for(int j=0; j<meret; j++){
        for(int i=0; i<meret; i++){
        FieldButton* fbp=new FieldButton(i*20,j*20);
        fb.push_back(fbp);
        w.push_back(fbp);
        sor.push_back(-1);
        }
        palya.push_back(sor);
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
    palya[id/meret][id%meret]=fb[id]->get_userid();
}
bool JatekMester::nyertel(){
    //int mag = i / meret;
    //int szel = i % meret;
    int nyert=-1;
    for(int i=0; i<meret;i++){
            for(int j=0; j<meret-4; j++){
                if(palya[i][j]!=-1&&palya[i][j]==palya[i][j+1] && palya[i][j+1]==palya[i][j+2] && palya[i][j+2]==palya[i][j+3] && palya[i][j+3]==palya[i][j+4]){
                    nyert=palya[i][j];
                }
                if(i<meret-4){
                if(palya[i][j+4]!=-1&&palya[i][j+4]==palya[i+1][j+4] && palya[i+1][j+4]==palya[i+2][j+4] && palya[i+2][j+4]==palya[i+3][j+4] && palya[i+3][j+4]==palya[i+4][j+4]){
                    nyert=palya[i][j+4];
                }
                }
                if(i<meret-4 && j<meret-4 ){
                if(palya[i][j]!=-1&&palya[i][j]==palya[i+1][j+1] && palya[i+1][j+1]==palya[i+2][j+2] && palya[i+2][j+2]==palya[i+3][j+3] && palya[i+3][j+3]==palya[i+4][j+4]){
                    nyert=palya[i][j];
                }
                }
                if(i>=4 && j<meret-4 ){
                if(palya[i][j]!=-1&&palya[i][j]==palya[i-1][j+1] && palya[i-1][j+1]==palya[i-2][j+2] && palya[i-2][j+2]==palya[i-3][j+3] && palya[i-3][j+3]==palya[i-4][j+4]){
                    nyert=palya[i][j];
                }
                }
            }
    }

        if(nyert==0){
            gout<<move_to(800,100)<<text("Piros jatekos nyert")<<refresh;
            return true;
        }else if(nyert==1){
            gout<<move_to(800,100)<<text("Zold jatekos nyert")<<refresh;
            return true;
        }else{
            return false;
        };

    /*
    for(int j=1;j<5;j++){
            cout<<"Iedik" <<fb[i]->get_userid()<<endl;
            cout<<"I+J-edik"<<fb[i+j]->get_userid()<<endl;
        if( ( szel+j<meret ) && (fb[i]->get_userid() == fb[i+j]->get_userid()) && fb[i]->get_userid()!=-1){
            egyezes[fb[i]->get_userid()]++;
        }
        if(egyezes[fb[i]->get_userid()]==4){
            cout<<"nyertel"<<endl;
            return true;

            }else{
            return false;
            }
        }
        egyezes[fb[i]->get_userid()]=0;*/
    /*if(egyezes[1]==5 || egyezes[0]==5){
        cout<<"nyertel"<<endl;
        return true;
    }*/
}
bool JatekMester::donetlen(){
    if(kor==meret*meret-1){
        cout<<"dontetlen";
        return true;
    }

}
void JatekMester::game_log(){
    gout.open(1000,800);
    letrehoz();
    kirajzol();

    event ev;
    while(gin >> ev) {
        w[0]->draw(ev);
        if(w[0]->is_clicked(ev)){
        w[0]->handle(ev);
        }


        for(int i=0; i<fb.size(); i++){
            //cout<<"2"<<endl;
        if(fb[i]->is_clicked(ev) && fb[i]->get_userid()==-1 &&!nyertel()){
            //fb[i]->handle(ev);
            kor++;
            fb[i]->set_userid(kor);
            //nyertel();
            frissit(i);
            donetlen();

        }
        }

        //gout<<move_to(30,30)<<text("test");
    }
}
