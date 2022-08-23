#include "../include/pgm.h"
#include <fstream>
#include <iostream>

using namespace dip;

pgm &pgm::load(std::string file_dir)
{
    std::string name_extentsion = file_dir.substr(file_dir.length() - 4);
    if (name_extentsion != ".pgm")
    {
        throw std::runtime_error("Input image must be: .pgm");
    }

    std::ifstream text_im;

    text_im.open(file_dir);
    if (!text_im.is_open())
    {
        throw std::runtime_error("Input image not found.");
    }

    std::string element;

    unsigned int cnt = 0;
    unsigned int curr_w = 0;
    unsigned int curr_h = 0;

    while (text_im.peek() != EOF)
    {
        text_im >> element;
        cnt += 1;

        switch (cnt)
        {
        case 1:
            continue;
        case 2:
        {
            curr_w = std::stoi(element);
            break;
        }

        case 3:
        {
            curr_h = std::stoi(element);
            break;
        }

        case 4:
        {
            this->init(curr_w, curr_h);
            curr_w = curr_h = 0;
            break;
        }
        default:
        {
            if (curr_w % this->width() == 0)
                curr_h += 1;

            this->at(curr_w % this->width(), curr_h) = std::stod(element);
            break;
        }
        }
    }

    text_im.close();

    return *this;
}