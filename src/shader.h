#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <GL/glew.h>
#include <glm.hpp>
#include "utils.h"

struct ShaderProgramSource
{
    std::string VertexSource;
    std::string FragmentSource;
};

class Shader
{
private:
    std::string filepath;
    unsigned int rendererId;
    std::unordered_map<std::string, int> uniformLocationCache;

public:
    Shader(const std::string& filepath);
    ~Shader();

    void bind() const;
    void unbind() const;
    void setUniform1i(const std::string& name, int value);
    void setUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
    void setUniformMat4f(const std::string& name, const glm::mat4& matrix);

private:
    ShaderProgramSource parseShader();
    unsigned int compileShader(unsigned int type, const std::string& source);
    unsigned int createShader(const std::string& vertexShader, const std::string& fragmentShader);
    int getUniformLocation(const std::string& name);
};

#endif