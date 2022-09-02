#include "../include/image.h"
#include <fstream>
#include <iostream>
#include <math.h>

using namespace dip;

pgm &pgm::load(std::string file_dir)
{
    // Check input file name extension.
    std::string name_extentsion = file_dir.substr(file_dir.length() - 4);
    if (name_extentsion != ".pgm")
    {
        throw std::runtime_error("Input image must be: .pgm");
    }

    // Create file stream
    std::ifstream in_ImFile;

    in_ImFile.open(file_dir);

    if (!in_ImFile.is_open())
    {
        throw std::runtime_error("Input image not found.");
    }

    // Parser, parse through the input file
    std::string token;  // current token
    std::string ltoken; // last token

    for (int cnt = 0; in_ImFile.peek() != EOF; ++cnt)
    {
        in_ImFile >> token;

        if (cnt == 2)
        {
            /**
             * @brief Initialize image matrix when cnt == 2 (got width and height)
             *
             * @param ltoken = width
             * @param token = height
             */
            this->init(std::stoi(token), std::stoi(ltoken));
        }
        else if (cnt == 3)
        {
            this->color_depth = std::stoi(token);
        }
        else if (cnt > 3)
        {
            const unsigned int &curr_h = floor((cnt - 4) / this->width());
            const unsigned int &curr_w = (cnt - 4) % this->width();

            if (curr_w < this->width() && curr_h < this->height())
                this->at(curr_h, curr_w) = std::stoi(token);
        }
        ltoken = token;
    }

    in_ImFile.close();

    return *this;
}

void pgm::write(std::string export_dir)
{
    if (this->width() == 0 || this->height() == 0)
    {
        std::cout << "DIP: Can not write from empty matrix.\n";
        return;
    }

    std::ofstream exportFile;

    exportFile.open(export_dir);

    if (!exportFile.is_open())
    {
        throw std::runtime_error("Could not export with given export directory.");
    }

    exportFile << "P2" // "P2" : pgm format
               << " " << this->width() << " " << this->height() << " "
               << color_depth << std::endl;
    for (int i = 0; i < this->height(); ++i)
    {
        if (i > 0)
            exportFile << std::endl;

        for (int j = 0; j < this->width(); ++j)
        {
            if (j > 0)
                exportFile << " ";

            exportFile << this->at(i, j);
        }
    }

    exportFile.close();
}

unsigned int pgm::ColorDepth() const
{
    return color_depth;
}

void pgm::setColorDepth(unsigned int new_value)
{
    color_depth = new_value;
}

pgm &pgm::copy(pgm &target)
{
    this->clear();
    init(target.height(), target.width());
    this->color_depth = target.ColorDepth();

    for (int y = 0; y < this->height(); ++y)
    {
        for (int x = 0; x < this->width(); ++x)
        {
            double clone_pix = target.at(y, x);
            this->at(y, x) = clone_pix;
        }
    }

    return *this;
}

pgm &pgm::rotate(double degree)
{
    // Tons of problems arose with this rotation
    // to fix this, explore:
    // And read the thesis:
    // Rotations in 2D and 3D discrete spaces

    double rad = (degree / 180.0) * 3.14156;
    pgm new_im(this->height(), this->width());
    new_im.color_depth = this->ColorDepth();

    int center_x = this->width() / 2;
    int center_y = this->height() / 2;

    for (int y = 0; y < this->height(); ++y)
    {
        for (int x = 0; x < this->width(); ++x)
        {
            // linear algebra things
            int new_x = floor((x - center_x) * cos(rad) - (y - center_y) * sin(rad)) + center_x;
            int new_y = floor((x - center_x) * sin(rad) + (y - center_y) * cos(rad)) + center_y;

            if (new_x < width() && new_y < height())
            {
                double clone_numb = this->at(y, x);
                new_im.at(new_y, new_x) = clone_numb;
            }
        }
    }

    this->clear();
    this->copy(new_im);

    return *this;
}