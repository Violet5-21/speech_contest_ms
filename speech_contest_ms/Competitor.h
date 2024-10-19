//
// Created by Violet on 24-10-18.
//

#ifndef SPEECH_CONTEST_MS_COMPETITOR_H
#define SPEECH_CONTEST_MS_COMPETITOR_H

#include <string>

using std::string;

class Competitor
{
public:
    string m_name = "Competitor";
    double m_scores[2] = {0, 0};

    Competitor() = default;
    ~Competitor() = default;
};

#endif //SPEECH_CONTEST_MS_COMPETITOR_H
