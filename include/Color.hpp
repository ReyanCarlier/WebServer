#include <ostream>

namespace Color {
    enum Code {
        FG_DEFAULT = 39,
        FG_BLACK = 30,
        FG_RED = 31,
        FG_GREEN = 32,
        FG_YELLOW = 33,
        FG_BLUE = 34,
        FG_MAGENTA = 35,
        FG_CYAN = 36,
        FG_LIGHT_GRAY = 37,
        FG_DARK_GRAY = 90,
        FG_LIGHT_RED = 91,
        FG_LIGHT_GREEN = 92,
        FG_LIGHT_YELLOW = 93,
        FG_LIGHT_BLUE = 94,
        FG_LIGHT_MAGENTA = 95,
        FG_LIGHT_CYAN = 96,
        FG_WHITE = 97,
        BG_RED = 41,
        BG_GREEN = 42,
        BG_BLUE = 44,
        BG_DEFAULT = 49,
        BOLD = 1,
        UNDERLINE = 4,
        BLINK = 5,
        RESET_BOLD = 21,
        RESET_UNDERLINE = 24,
        RESET_BLINK = 25,
        RESET = 0
    };
    class Modifier {
        Code code;
    public:
        Modifier(Code pCode) : code(pCode) {}
        friend std::ostream&
        operator<<(std::ostream& os, const Modifier& mod) {
            return os << "\033[" << mod.code << "m";
        }
    };
}

Color::Modifier red(Color::FG_RED);
Color::Modifier def(Color::FG_DEFAULT);
Color::Modifier green(Color::FG_GREEN);
Color::Modifier blue(Color::FG_BLUE);
Color::Modifier bg_red(Color::BG_RED);
Color::Modifier bg_green(Color::BG_GREEN);
Color::Modifier bg_blue(Color::BG_BLUE);
Color::Modifier bg_def(Color::BG_DEFAULT);
Color::Modifier yellow(Color::FG_YELLOW);
Color::Modifier magenta(Color::FG_MAGENTA);
Color::Modifier cyan(Color::FG_CYAN);
Color::Modifier light_gray(Color::FG_LIGHT_GRAY);
Color::Modifier dark_gray(Color::FG_DARK_GRAY);
Color::Modifier light_red(Color::FG_LIGHT_RED);
Color::Modifier light_green(Color::FG_LIGHT_GREEN);
Color::Modifier light_yellow(Color::FG_LIGHT_YELLOW);
Color::Modifier light_blue(Color::FG_LIGHT_BLUE);
Color::Modifier light_magenta(Color::FG_LIGHT_MAGENTA);
Color::Modifier light_cyan(Color::FG_LIGHT_CYAN);
Color::Modifier white(Color::FG_WHITE);
Color::Modifier bold(Color::BOLD);
Color::Modifier underline(Color::UNDERLINE);
Color::Modifier blink(Color::BLINK);
Color::Modifier reset_bold(Color::RESET_BOLD);
Color::Modifier reset_underline(Color::RESET_UNDERLINE);
Color::Modifier reset_blink(Color::RESET_BLINK);
Color::Modifier reset(Color::RESET);