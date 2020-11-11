#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <stb_image.h>
#include "utils.h"

class Texture
{
private:
    unsigned int rendererId;
    std::string filepath;
    unsigned char* localBuffer;
    int width;
    int height;
    int bytesPerPixel;

public:
    Texture(const std::string& path);
    ~Texture();

    void bind(unsigned int slot = 0) const;
    void unbind() const;

    inline int getWidth() const { return width; }
    inline int getHeight() const { return height; }
};


#endif