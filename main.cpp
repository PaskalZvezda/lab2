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

void print_ip(const std::vector<int>& ip) {
    for (size_t i = 0; i < ip.size(); ++i) {
        std::cout << ip[i] << (i == ip.size() - 1 ? "" : ".");
    }
    std::cout << "\n";
}

int main()
{
    #ifdef _WIN32
        SetConsoleCP(65001);
        SetConsoleOutputCP(65001);
    #endif

    // 1. Открываем файл ip_filter.tsv
    std::ifstream file("C:/Users/Admin/Documents/Lab2/ip_filter.tsv");

    // Проверка: удалось ли найти и открыть файл
    if (!file.is_open()) {
        std::cerr << "Ошибка: Не удалось открыть файл 'ip_filter.tsv'." << std::endl;
        std::cerr << "Убедитесь, что файл находится в той же папке, что и исполняемый файл или проект." << std::endl;
        return 1;
    }

    std::vector<std::vector<int>> ip_pool;
    std::string line;

    // 2. Читаем данные из файла построчно
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        // Разделяем по табуляции и берем только первый столбец (IP)
        std::vector<std::string> v = split(line, '\t');
        if (v.empty()) continue;

        // Разделяем IP по точкам и переводим в числа
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
        if (std::any_of(ip.begin(), ip.end(), [](int part){ return part == 46; })) {
            print_ip(ip);
        }
    }
    return 0;
}
