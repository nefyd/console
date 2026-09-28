c/c++ headers for common command-line program operations such as clearing the terminal, sleeping the program, manipulating the terminal cursor, output with a typewriting effect, and reading terminal input without needing to click enter/return.

# supported platforms

posix operating systems:
- linux
- macos
- windows with posix environment (e.g. wsl)
- some others

# functions

below is a list of every function contained in the headers, along with brief descriptions, organized by type of operation. do note that these are from the c++ header, and that the c header may lag behind in updates.

## output functions

`void clear()` clears the terminal

`void draw(char glyph, unsigned int x, unsigned int y)` writes a character on the specified coords

`void to(unsigned int x, unsigned int y)` simply jumps the cursor to the specified coords

`void type(std::string_view text, char end = '\n', unsigned delay_ms = 40)` output with typewriter effect
> `void type(std::string_view text, unsigned delay_ms = 40, char end = '\n')` is an overload for the above function where the `delay_ms` parameter comes before the `end` parameter. this allows specifying the delay without needing to specify the end character

## input functions

`std::optional<char> key()` gets character input without requiring the user to press enter. designed for command-line games

## sleep functions

these functions halt the program for a specified amount of time, ordered by descending units of time

`void hibernate(unsigned int hours)`

`void slumber(unsigned int minutes)`

`void sleep(unsigned int seconds)`

`void snooze(unsigned int milliseconds)`

`void doze(unsigned int microseconds)`

`void wink(unsigned int nanoseconds)`
