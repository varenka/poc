#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <fstream>
#include <iostream>
#include <string>

class Shader
{
public:
    Shader();
    Shader(const std::string& fileName);

    void Bind();

    virtual ~Shader();
private:
    /// Fragment shader, vertex shader
    static const unsigned int NUM_SHADERS = 2;

    /*
    enum
    {
        TRANSFORM_U,

        NUM_UNIFORMS
    };
    */

    GLuint m_program;
    GLuint m_shaders[NUM_SHADERS];
    //GLuint m_uniforms[NUM_UNIFORMS];
};

#endif // SHADER_H
