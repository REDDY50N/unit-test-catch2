#include "G36.h"

// ----------------------------------------------
// CTOR
// ----------------------------------------------
G36::G36() = default;

// ----------------------------------------------
// STATUS
// ----------------------------------------------
std::string G36::status() const
{
  if (jammed_) {
    return "G36 - JAMMED | Munition: " + std::to_string(magazine_) + "/30";
  }
  return "G36 - Ready | Munition: " + std::to_string(magazine_) + "/30";
}

// ----------------------------------------------
// CURRENT AMMO
// ----------------------------------------------
uint8_t G36::current_ammo() const noexcept
{
  return magazine_;
}

// ----------------------------------------------
// CAN FIRE
// ----------------------------------------------
bool G36::can_fire() const noexcept
{
  return magazine_ > 0 && !jammed_;
}

// ----------------------------------------------
// IS JAMMED
// ----------------------------------------------
bool G36::is_jammed() const noexcept
{
  return jammed_;
}

// ----------------------------------------------
// FIRE
// ----------------------------------------------
uint8_t G36::fire(uint8_t rounds)
{
  if (!can_fire()) {
    jammed_ = true;
    return 0;
  }

  uint8_t actual = (rounds > magazine_) ? magazine_ : rounds;
  magazine_ -= actual;

  if (magazine_ == 0) {
    jammed_ = true;
  }

  return actual;
}

// ----------------------------------------------
// RELOAD
// ----------------------------------------------
void G36::reload()
{
  magazine_ = 30;
  jammed_ = false;
}