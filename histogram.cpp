#include "histogram.h"
#include <vector>
void find_minmax(const vector<double>& numbers, double& min, double& max)
{
    if(numbers.size()==0)
    {
        return;
    }
    else{
    min=numbers[0];
    max=numbers[0];
    for (size_t i=1; i<numbers.size(); i++)
    {
        if (min>numbers[i])
        {
            min=numbers[i];
        }
        if (max<numbers[i])
        {
            max=numbers[i];
        }}}
}
vector<size_t> make_histogram(const vector<double>& numbers, size_t bin_count){
    double min, max;
    find_minmax(numbers, min, max);
    vector<size_t>count(bin_count,0);
    for (double x: numbers){
        size_t bin_index=(size_t)(x-min)*(bin_count)/(max-min);
        if (bin_index==bin_count)
        {
            bin_index--;
        }
        count[bin_index]++;}
    return count;
}
