// starter.cpp: leaks on the early-return path, and never frees on the normal
// one
#include <iostream>
struct Enemy {
  int hp = 100;
};

int fight(bool flee) {
  Enemy *e = new Enemy();
  if (flee) {
    delete e;
    return -1; // BUG: leaks e
  }
  int result = e->hp;
  delete e;
  // BUG: no `delete e;` here either
  return result;
}
int main() { std::cout << fight(false) << ' ' << fight(true) << '\n'; }
