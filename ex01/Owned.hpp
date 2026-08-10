#pragma once

struct Enemy {
  int hp = 100;
};

class Owned {
public:
  Owned();
  Owned(const Owned &other);
  Owned &operator=(const Owned &other);
  ~Owned();

  Enemy *operator->() const;

private:
  Enemy *m_enemy;
};

int fight(bool flee);
