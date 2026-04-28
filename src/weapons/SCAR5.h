#pragma once
#include <cstdint>

class SCAR5 {

public:
  SCAR5();
  bool isEmpty()const;
  bool fire();
  bool reload();
  unsigned int magazine_state()const;

private:
  unsigned int magazine_capacity_{30};   // Max rounds in magazine
  unsigned int magazine_{0};             // Current rounds in magazine
};



