#include "Widget.hpp"
#include "Button.hpp"
#include "Counter.hpp"
#include "texteditor.hpp"
#include "Choice.hpp"
#include "JatekMester.hpp"
#include <vector>
using namespace genv;
int main() {
    ///nem all meg a nyertel-el
    ///utolso ponton kilep
    //gout.open(800,800);
    //Counter* c = new Counter(100, 30, 10, 0, 100);
    JatekMester* jm = new JatekMester(10);
    //event ev;
    jm->game_log();
return 0;
}
