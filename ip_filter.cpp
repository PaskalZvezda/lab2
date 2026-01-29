#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream> 

std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;
    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));
        start = stop + 1;
        stop = str.find_first_of(d, start);
    }
    r.push_back(str.substr(start));
    return r;
}

void print_ip(auto ip) {
        std::cout << ip[0] << "." << ip[1] << "."<< ip[2] << "."<< ip[3] << std::endl;
}

int main()
{
    system("chcp 65001 > nul");
    std::ifstream file("ip_filter.tsv");
    std::vector<std::vector<int>> ip_pool;
    std::string line;
    while (std::getline(file, line)) {
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

    std::cout << "Обратная лексикографическая сортировка" << std::endl << std::endl;
    std::sort(ip_pool.begin(), ip_pool.end(), std::greater<std::vector<int>>());
    for (auto ip : ip_pool) print_ip(ip);

    std::cout << std::endl  << "Фильтр по первому (1) байту" << std::endl << std::endl;

    for (auto ip : ip_pool) {
        if (ip[0] == 1) print_ip(ip);
    }

    std::cout << std::endl << "Фильтр по первому (46) и второму байту (70)" << std::endl << std::endl;
    for (auto ip : ip_pool) {
        if (ip[0] == 46 && ip[1] == 70) print_ip(ip);
    }

    std::cout << std::endl << "Фильтр по любому байту (46)" << std::endl << std::endl;
    for (auto ip : ip_pool) {
        if ((ip[0] == 46) || (ip[1] == 46) || (ip[2] == 46) || (ip[3] == 46)) print_ip(ip);
    }
    return 0;
}