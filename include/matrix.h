#ifndef MAT_H_
#define MAT_H_

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
        matrix()
            : head(0), i_width(0), i_height(0) {}
        matrix(unsigned int width, unsigned int height);
        ~matrix();
        intensity &at(int, int);

        unsigned int width();
        unsigned int height();
    public:
        void print();
    };
}

#endif