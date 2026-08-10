#pragma once

#include <chrono>
#include <cstdlib>
#include <iostream>
#include <thread>

namespace console {

inline void clear() noexcept {
  std::system("clear");
}

inline void draw(char glyph, unsigned int x, unsigned int y) noexcept {
  std::cout << "\033[" << y + 1 << ";" << x + 1 << "H" << glyph;
}

inline void to(unsigned int x, unsigned int y) noexcept {
  std::cout << "\033[" << y + 1 << ";" << x + 1 << "H";
}

inline void hibernate(unsigned int hours) noexcept {
  const auto this_long = std::chrono::hours(hours);
  std::this_thread::sleep_for(this_long);
}

inline void slumber(unsigned int minutes) noexcept {
  const auto this_long = std::chrono::minutes(minutes);
  std::this_thread::sleep_for(this_long);
}

inline void sleep(unsigned int seconds) noexcept {
  const auto this_long = std::chrono::seconds(seconds);
  std::this_thread::sleep_for(this_long);
}

inline void snooze(unsigned int milliseconds) noexcept {
  const auto this_long = std::chrono::milliseconds(milliseconds);
  std::this_thread::sleep_for(this_long);
}

inline void doze(unsigned int microseconds) noexcept {
  const auto this_long = std::chrono::microseconds(microseconds);
  std::this_thread::sleep_for(this_long);
}

inline void wink(unsigned int nanoseconds) noexcept {
  const auto this_long = std::chrono::nanoseconds(nanoseconds);
  std::this_thread::sleep_for(this_long);
}

} // namespace console