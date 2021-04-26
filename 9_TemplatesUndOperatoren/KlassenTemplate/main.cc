#include "KlassenTemplate.h"

int main()
{
    Statistic<float> stat1;

    stat1.push_next_sample(1.0f);
    stat1.push_next_sample(2.0f);
    stat1.push_next_sample(3.0f);
    stat1.push_next_sample(4.0f);
    stat1.push_next_sample(5.0f);
    stat1.push_next_sample(6.0f);

    stat1.print_data();

    return 0;
}
