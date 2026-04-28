//
// Created by polar on 28.04.26.
//

#include "SCAR5.h"

SCAR5::SCAR5(){
 magazine_ = 0; // Magazine is always empty on new weapon
}

bool SCAR5::isEmpty() const{
  return magazine_ == 0;
}

bool SCAR5::fire(){
        if (isEmpty()) {
        return false; // Cannot fire if empty
        }
        magazine_--; // Eine Patrone abfeuern
        return true;
}

bool SCAR5::reload(){
        magazine_ = magazine_capacity_; // Fill magazine to its full capacity
        return true; // always true for now
}

unsigned int SCAR5::magazine_state() const{
  return magazine_;
}

