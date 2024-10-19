//
// Created by Violet on 24-10-18.
//

#include "Manager.h"

Manager::Manager()
{
    for (int i = 0; i < NUMBER; ++i)
    {
        Competitor competitor;
        competitor.m_name += static_cast<char>('A'+i);
        top12.push_back(i+10000001);
        m_competitors.insert(make_pair(i+10000001, competitor));
    }
}

void Manager::show_menu()
{
    string l1 = " Welcome to the speech contest! ";
    string l2 = " 1.Contest start! ";
    string l3 = " 2.Check formal contests' records. ";
    string l4 = " 3.Clean all records! ";
    string l5 = " 0.Exit! ";

    cout.fill('*');
    cout << setw(60) << "\n";
    cout << setw(30+static_cast<int>(l1.size()) / 2) << l1 << setw(30-static_cast<int>(l1.size()) / 2) << "\n";
    cout << setw(30+static_cast<int>(l2.size()) / 2) << l2 << setw(30-static_cast<int>(l2.size()) / 2) << "\n";
    cout << setw(30+static_cast<int>(l3.size()) / 2) << l3 << setw(30-static_cast<int>(l3.size()) / 2) << "\n";
    cout << setw(30+static_cast<int>(l4.size()) / 2) << l4 << setw(30-static_cast<int>(l4.size()) / 2) << "\n";
    cout << setw(30+static_cast<int>(l5.size()) / 2) << l5 << setw(30-static_cast<int>(l5.size()) / 2) << "\n";
    cout << setw(60) << "\n";
    cout.fill(' ');
}

void Manager::exit()
{
    cout << "Good bye! \n";
    std::exit(0);
}

void Manager::draw()
{
    cout << "\nSeason" << m_season << ". \n";
    cout << "Result: ";
    if (m_season == 1)
    {
        std::random_shuffle(top12.begin(), top12.end());
        for (const auto i: top12)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    else if (m_season == 2)
    {
        std::random_shuffle(top6.begin(), top6.end());
        for (const auto i: top6)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Manager::compete()
{
    cout << "Season" << m_season << "start! \n";
    vector<int> top;
    multimap<double, int, greater<double>> temp;

    if (m_season == 1)
    {
        top = top12;
    }
    else if (m_season == 2)
    {
        top = top6;
    }
    for (auto i = top.begin(); i < top.end(); ++i)
    {
        deque<double> d;
        for (int j = 0; j < 10; ++j)
        {
            double score = static_cast<double>(rand()%4001+6000) / 100;
            d.push_back(score);
        }
        sort(d.begin(), d.end());
        d.pop_back();
        d.pop_front();
        double average = accumulate(d.begin(), d.end(), 0.0) / static_cast<double>(d.size());
        m_competitors[*i].m_scores[m_season-1] = average;
        temp.insert(make_pair(average, *i));
        cout << m_competitors[*i].m_name << ": " << average << ". \n";
    }
    int count = 0;
    for (auto &t: temp)
    {
        if (m_season == 1 && count < 6)
        {
            top6.push_back(t.second);
        }
        else if (m_season == 2 && count < 3)
        {
            top3.push_back(t.second);
        }
        ++count;
    }
    cout << "Season" << m_season << " is over! \n\n";
}

void Manager::show_score()
{
    cout << "The contestants who have advanced are as follows. \n";
    vector<int> v;
    if (m_season == 1)
    {
        v = top6;
    }
    else if (m_season == 2)
    {
        v = top3;
    }
    for (auto i: v)
    {
        cout << "Competitor: " << i << " name: " << m_competitors[i].m_name << " score: " << m_competitors[i].m_scores[m_season-1] << endl;
    }
}

void Manager::save()
{
    ofstream ofs(FILENAME, ios_base::out|ios_base::app);

    for (auto i: top3)
    {
        ofs << i << "," << m_competitors[i].m_scores[1] << ",";
    }
    ofs << endl;

    ofs.close();
    cout << "Saved! \n";
    file_empty = false;
}

void Manager::start_contest()
{
    draw();
    compete();
    show_score();
    ++m_season;
    draw();
    compete();
    show_score();
    save();
}

void Manager::load()
{
    ifstream ifs(FILENAME, ios_base::in);
    if (!ifs.is_open())
    {
        file_empty = true;
        cout << "\nFile is not exist. \n";
        ifs.close();
        return;
    }
    string line;
    while (getline(ifs, line))
    {
        file_empty = false;
        vector<string> v;
        istringstream iss(line);
        string token;
        while (getline(iss, token, ','))
        {
            v.push_back(token);
        }
        m_record.emplace(m_record.size(), v);
    }
    if (file_empty)
    {
        cout << "\nFile is empty. \n";
    }
    ifs.close();
}

void Manager::show()
{
    for (int i = 0; i < m_record.size(); ++i)
    {
        cout << "Contest" << i << ": "
            << "top1: " << m_record[i][0] << " score: " << m_record[i][1] << " "
            << "top2: " << m_record[i][2] << " score: " << m_record[i][3] << " "
            << "top3: " << m_record[i][4] << " score: " << m_record[i][5] << " " << endl;
    }
}

void Manager::clear()
{
    cout << "Are you sure? \n1. Sure, \n2. Not. \n";
    int select;
    cin >> select;

    if (select == 1)
    {
        ofstream ofs(FILENAME, ios_base::trunc);
        ofs.close();
        cout << "Cleared! \n";
    }
}
