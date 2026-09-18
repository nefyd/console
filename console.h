#ifndef CONSOLE
#define CONSOLE

#include <unistd.h>
#include <stdio.h>

inline void console_clear() {
    static const char code[] = "\033[2J\033[H";
    write(STDOUT_FILENO, code, sizeof(code) - 1);
}

inline void console_draw(
    const char glyph,
    const unsigned int x,
    const unsigned int y
) {
    printf("\033[%d;%dH%c", y + 1, x + 1, glyph);
}

inline void console_to(const unsigned int x, const unsigned int y) {
    printf("\033[%d;%dH", y + 1, x + 1);
}

#endif
