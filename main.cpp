#include "ip_filter.h"
#include <windows.h> // Для SetConsoleCP

// print_ip можно оставить тут или тоже вынести в .h
void print_ip(const std::vector<int>& ip) {
    for (size_t i = 0; i < ip.size(); ++i) {
        std::cout << ip[i] << (i == ip.size() - 1 ? "" : ".");
    }
    std::cout << "\n";
}

int main()
{
    // ... весь ваш код main ...
    // только уберите реализацию split, она теперь берется из ip_filter.h
    
    // ...
    return 0;
}