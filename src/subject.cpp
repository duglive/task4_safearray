﻿////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief     Definition of some methods for class Subject
/// \author    Sergey Shershakov
/// \version   0.2.0
/// \date      30.01.2017
///            This is a part of the course "Algorithms and Data Structures" 
///            provided by  the School of Software Engineering of the Faculty 
///            of Computer Science at the Higher School of Economics.
///
///
////////////////////////////////////////////////////////////////////////////////


#include "subject.h"



namespace xi {

    std::ostream& operator<<(std::ostream& outs, const Subject& subj)
    {
        outs << subj.name << ": " << subj.title << "\n";

        int index = 0;
        int maxSubj = subj.description.getCapacity();

        while (index < maxSubj && subj.description[index] != "")
            outs << subj.description[index++] << "\n";

        return outs;
    }


    std::istream& operator>>(std::istream& ins, Subject& subj)
    {
        std::string t = "";
        int i = 0;

        while ((!t.empty()) && (std::getline(ins, t)))
        {
            if (i == 0)
            {
                subj.name = t;
                i++;
            }

            else if (i == 1)
            {
                subj.title = t;
                i++;
            }

            else
            {
                subj.description[i++ -2] = t;
            }
        }

        return ins;
    }

} // namespace xi

