#pragma once

#include <cstdint>
#include <string>

class G36 {
public:
  // CTOR
  G36();

  // Weapon Status
  [[nodiscard]] std::string status() const;
  [[nodiscard]] uint8_t current_ammo() const noexcept;
  [[nodiscard]] bool can_fire() const noexcept;
  [[nodiscard]] bool is_jammed() const noexcept;

  // Actions
  uint8_t fire(uint8_t rounds);
  void reload();

private:
  uint8_t magazine_ = 30;
  bool    jammed_   = false;
  std::string last_status_message_;   // just for better status message
};