#include "histogram.h"
#include "svg.h"
#include <cassert>

void test_positive()
{
    double min = 0;
    double max = 0;
    find_minmax({1, 2, 3}, min, max);
    assert(min == 1);
    assert(max == 3);
}

void test_negative()
{
    double min=0;
    double max=0;
    find_minmax({-1,-2,-3},min,max);
    assert(max == -1);
    assert(min == -3);
}
void test_same()
{
    double min = 0;
    double max = 0;
    find_minmax({3, 3, 3}, min, max);
    assert(min == 3);
    assert(max == 3);
}

void test_one()
{
    double min = 0;
    double max = 0;
    find_minmax({2}, min, max);
    assert(min == 2);
    assert(max == 2);
}

void test_empty()
{
    double min = 0;
    double max = 0;
    find_minmax({}, min, max);
    assert(min == 0);
    assert(max == 0);
}

void test_text_reflection()
{
    size_t text_reflection;
    text_reflection=text_reflection_check(400,20,20);
    assert(text_reflection == 400);
}

void test_histogram_reflection()
{
    size_t histogram_reflection;
    show_histogram_svg({1,1,1});
    assert(histogram_reflection == 0);
}
int main()
{
    test_positive();
    test_negative();
    test_same();
    test_one();
    test_empty();
    test_histogram_reflection();
    test_text_reflection();

}
