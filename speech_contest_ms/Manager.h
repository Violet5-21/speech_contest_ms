//
// Created by Violet on 24-10-18.
//

#ifndef SPEECH_CONTEST_MS_MANAGER_H
#define SPEECH_CONTEST_MS_MANAGER_H

#include "Competitor.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <random>
#include <ctime>
#include <string>
#include <vector>
#include <map>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::vector;
using std::map;
using std::multimap;
using std::deque;
using std::make_pair;
using std::random_shuffle;
using std::greater;
using std::accumulate;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::ios_base;

const int NUMBER = 12;
const string FILENAME("speech_contest_top3.csv");

class Manager
{
private:
    vector<int> top12;
    vector<int> top6;
    vector<int> top3;
    int m_season = 1;
    map<int, Competitor> m_competitors;
    map<int, vector<string>> m_record;
    bool file_empty  = true;
public:
    Manager();
    static void show_menu();
    static void exit();
    void draw();
    void compete();
    void show_score();
    void save();
    void start_contest();
    void load();
    void show();
    static void clear();
    ~Manager() = default;
};

#endif //SPEECH_CONTEST_MS_MANAGER_H
