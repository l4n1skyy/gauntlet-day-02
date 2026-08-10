#include "Owned.hpp"
Owned::Owned() : m_enemy(new Enemy()) {}

Owned::~Owned() { delete m_enemy; }

Owned::Owned(const Owned &other) { m_enemy = new Enemy(*other.m_enemy); }

Owned &Owned::operator=(const Owned &other) {
  if (this != &other) {
    delete m_enemy;
    m_enemy = new Enemy(*other.m_enemy);
  }
  return *this;
}

Enemy *Owned::operator->() const { return m_enemy; }
