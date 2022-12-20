#include <ostream>
namespace Color {
    enum Code {
        FG_RED      = 31,
        FG_GREEN    = 32,
        FG_BLUE     = 34,
        FG_DEFAULT  = 39,
        BG_RED      = 41,
        BG_GREEN    = 42,
        BG_BLUE     = 44,
        BG_DEFAULT  = 49,
        FG_BLACK    = 30,  
        FG_YELLOW   = 33,
        FG_BRIGHT_RED = 91,
        FG_BRIGHT_GREEN = 92,
        FG_BRIGHT_YELLOW = 93,
        BG_YELLOW   = 43,
        BG_BRIGHT_RED = 101,
        BG_BRIGHT_GREEN = 102,
        BG_BRIGHT_YELLOW = 103
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