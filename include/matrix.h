#ifndef MAT_H_
#define MAT_H_

#include <functional>

namespace dip
{
    class matrix
    {
        typedef double intensity;

        intensity **head;
        unsigned int i_width;
        unsigned int i_height;

    protected:
        void init(unsigned int, unsigned int);

    public:
        matrix() : head(0), i_width(0), i_height(0) {}   // Empty matrix constructor
        matrix(unsigned int height, unsigned int width); // Constructor with predefined width and height
        ~matrix();

    public: // Intensity manipulation
        intensity &at(int y, int x);

    public: // Object's getter
        unsigned int width() const;
        unsigned int height() const;

    public: // Miscellaneous (Misc)
        void print() const;
        void forall(const std::function<void(intensity &_ENTRY_ALIAS_)> &f);
        void clear();
        virtual matrix& copy(const matrix& target);
    };
}

#endif