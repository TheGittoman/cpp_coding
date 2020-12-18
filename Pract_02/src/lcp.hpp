#ifndef LCP_HPP
#define LCP_HPP

namespace lcp
{
    ////////////////////////////////////////////// Chapter 6 >
    // 6.8a Pointer Arithmetic and array indexing
    int *find(int *arr, int *arr_end, int value); // returns int pointer # 2

    ////////////////////////////////////////////// Chapter 8 >
    class Point2d
    {
    private:
        double m_x, m_y;
    public:
        Point2d() : m_x{0}, m_y{0} {}
        Point2d(double x, double y) : m_x{x}, m_y{y} {}

        void print() const;
    };

    int run(); // main function for testing
}

#endif