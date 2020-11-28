#include "menu-example.h"

#include <iostream>

OpenGlExample::Example::MenuExample::MenuExample()
{
    std::cout << "constructor" << std::endl;
}

OpenGlExample::Example::MenuExample::~MenuExample()
{
    std::cout << "destructor" << std::endl;
}

void OpenGlExample::Example::MenuExample::tick()
{

    std::cout << "tick" << std::endl;
}

void OpenGlExample::Example::MenuExample::render()
{

    std::cout << "render" << std::endl;
}

void OpenGlExample::Example::MenuExample::renderImGui()
{

    std::cout << "renderImGui" << std::endl;
}
