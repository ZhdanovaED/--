#include <iostream>
#include <vector>
#include "svg.h"
void svg_begin(double width, double height) {
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_end() {
    cout << "</svg>\n";
}

void svg_text(double left, double baseline, string text) {
     cout << "<text x='"<<left<<"' y='"<<baseline<<"'>"<<text<<"</text>";}

void svg_rect(double x, double y, double width, double height,string stroke= "black", string fill= "black"){
    cout<< "<rect x='"<<x<<"' y='"<<y<<"' width='"<<width<<"' height='"<<height<<"' stroke='"<<stroke<<"' fill='"<<fill<<"'/>";}

double scaling(const vector<size_t>& bins, double block, double IMAGE_WIDTH, double TEXT_LEFT){
    double max;
    max=-1;
    for (size_t bin: bins){
        if (bin>max)
            max=bin;
    }

    block = ((IMAGE_WIDTH-TEXT_LEFT) /max);
    return block;
}
size_t text_reflection_check (size_t IMAGE_WIDTH , size_t TEXT_WIDTH , size_t TEXT_LEFT){
    size_t text_reflection;
    return text_reflection=IMAGE_WIDTH + TEXT_WIDTH - TEXT_LEFT;
}
void show_histogram_svg(const vector<size_t>& bins) {
    const auto block= 10;
    const auto IMAGE_WIDTH = 420;
    const auto TEXT_LEFT = 40;
    double BLOCK_WIDTH = scaling(bins, block, IMAGE_WIDTH, TEXT_LEFT);
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 10;
    const auto BIN_HEIGHT = (IMAGE_HEIGHT/bins.size());
    size_t text_reflection = text_reflection_check (IMAGE_WIDTH, TEXT_WIDTH , TEXT_LEFT);
    size_t histogram_reflection;

    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    double top = 0;
    for (size_t bin : bins) {
    const double bin_width = BLOCK_WIDTH * bin;
    histogram_reflection = IMAGE_WIDTH-bin_width-TEXT_LEFT;
    svg_rect(histogram_reflection , top, bin_width, BIN_HEIGHT,"darkviolet","#9400D3");
    svg_text(text_reflection, top + TEXT_BASELINE, to_string(bin));

    top += BIN_HEIGHT;
}
    svg_end();
}
