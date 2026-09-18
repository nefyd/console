#pragma once

#include <chrono>
#include <thread>
#include <print>
#include <unistd.h>

namespace console {

inline void clear() noexcept {
    static constexpr char code[] = "\033[2J\033[H";
    write(STDOUT_FILENO, code, sizeof(code) - 1);
}

inline void draw(char glyph, unsigned int x, unsigned int y) noexcept {
    std::print("\033[{};{}H{}", y + 1, x + 1, glyph);
}

inline void to(unsigned int x, unsigned int y) noexcept {
    std::print("\033[{};{}H", y + 1, x + 1);
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

}
