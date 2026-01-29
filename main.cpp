#include <iostream>
#include <clocale>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include "ip_filter.h"
#ifdef _WIN32
#include <windows.h>
#endif

void print_ip(const std::vector<int>& ip) { // вывод ответа
    for (size_t i = 0; i < ip.size(); ++i) {
        std::cout << ip[i] << (i == ip.size() - 1 ? "" : ".");
    }
    std::cout << "\n";
}

int main()
{
    #ifdef _WIN32       //чтобы сборка работала
        SetConsoleCP(65001);
        SetConsoleOutputCP(65001);
    #endif
    std::ifstream file("C:/Users/Admin/Documents/Lab2/ip_filter.tsv");
    std::vector<std::vector<int>> ip_pool;
    std::string line;

    while (std::getline(file, line)) {  // читаем файл и парсим строчки
        if (line.empty()) continue;
        std::vector<std::string> v = split(line, '\t');
        if (v.empty()) continue;
        std::vector<std::string> parts = split(v.at(0), '.');
        if (parts.size() == 4) {
            std::vector<int> ip_numeric;
            for (const auto& p : parts) {
                ip_numeric.push_back(std::stoi(p));
            }
            ip_pool.push_back(ip_numeric);
        }
    }
    file.close();

    std::cout << "Обратная лексикографическая сортировка:\n\n";
    std::sort(ip_pool.begin(), ip_pool.end(), std::greater<std::vector<int>>());
    for (const auto& ip : ip_pool) print_ip(ip);

    std::cout << "\nФильтр по первому байту (1):\n\n";
    for (const auto& ip : ip_pool) {
        if (ip[0] == 1) print_ip(ip);
    }

    std::cout << "\nФильтр по первому (46) и второму (70) байтам:\n\n";
    for (const auto& ip : ip_pool) {
        if (ip[0] == 46 && ip[1] == 70) print_ip(ip);
    }

    std::cout << std::endl << "\nФильтр по всем байтам (46) :\n\n";
    for (const auto& ip : ip_pool) {
        if (ip[0] == 46 || ip[1] == 46 || ip[2] == 46 || ip[3] == 46) {
            print_ip(ip);
        }
    }
    return 0;
}
