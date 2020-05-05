#ifndef Jeans_h
#define Jeans_h
#include <stdio.h>
#include <string>

enum class Jeans_colors{
    white, blue, black, maroon
};

enum class Jeans_sizes{
    small=0, medium=1, large=2, xlarge=3
};

class Jeans{
    Jeans_colors color;
    Jeans_sizes size;
public:
    Jeans();
    Jeans(Jeans_colors c, Jeans_sizes s);
    bool operator==(const Jeans &jn);
    
    Jeans_colors get_color() const;
    Jeans_sizes get_size() const;
};

std::ostream& operator<<(std::ostream& o, const Jeans& jn);

#endif
