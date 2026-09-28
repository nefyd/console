#pragma once

#include <chrono>
#include <cstdio>
#include <optional>
#include <termios.h>
#include <thread>
#include <print>
#include <unistd.h>

namespace console {

inline void clear() noexcept {
    static constexpr char code[] = "\033[2J\033[H";
    write(STDOUT_FILENO, code, sizeof(code) - 1);
}

inline void draw(
    const char glyph,
    const unsigned int x,
    const unsigned int y
) noexcept {
    std::print("\033[{};{}H{}", y + 1, x + 1, glyph);
}

inline void to(const unsigned int x, const unsigned int y) noexcept {
    std::print("\033[{};{}H", y + 1, x + 1);
}

inline void hibernate(const unsigned int hours) noexcept {
    const auto this_long = std::chrono::hours(hours);
    std::this_thread::sleep_for(this_long);
}

inline void slumber(const unsigned int minutes) noexcept {
    const auto this_long = std::chrono::minutes(minutes);
    std::this_thread::sleep_for(this_long);
}

inline void sleep(const unsigned int seconds) noexcept {
    const auto this_long = std::chrono::seconds(seconds);
    std::this_thread::sleep_for(this_long);
}

inline void snooze(const unsigned int milliseconds) noexcept {
    const auto this_long = std::chrono::milliseconds(milliseconds);
    std::this_thread::sleep_for(this_long);
}

inline void doze(const unsigned int microseconds) noexcept {
    const auto this_long = std::chrono::microseconds(microseconds);
    std::this_thread::sleep_for(this_long);
}

inline void wink(const unsigned int nanoseconds) noexcept {
    const auto this_long = std::chrono::nanoseconds(nanoseconds);
    std::this_thread::sleep_for(this_long);
}

inline void type(
    const std::string_view text,
    const char end = '\n',
    const unsigned delay_ms = 40
) noexcept {
    for (const char c : text) {
        std::fputc(c, stdout);
        std::fflush(stdout);
        console::snooze(delay_ms);
    }
    std::fputc(end, stdout);
}

inline void type(
    const std::string_view text,
    const unsigned delay_ms = 40,
    const char end = '\n'
) noexcept {
    for (const char c : text) {
        std::fputc(c, stdout);
        std::fflush(stdout);
        console::snooze(delay_ms);
    }
    std::fputc(end, stdout);
}

inline std::optional<char> key() {
    termios oldt, t;
    tcgetattr(0, &oldt);
    t = oldt;

    t.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(0, TCSANOW, &t);

    timeval tv{0, 0};
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(0, &fds);

    std::optional<char> captured = std::nullopt;

    if (select(1, &fds, nullptr, nullptr, &tv) > 0) {
        captured = getchar();
    }

    tcsetattr(0, TCSANOW, &oldt);
    return captured;
}

}
