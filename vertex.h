#ifndef VERTEX_H
#define VERTEX_H
#include <cstdlib>
#include <glm/glm.hpp>
#include <vector>
#include <ctime>
#include <iostream>
#include <GL/glew.h>

using namespace std;
using glm::vec3;

class Vertex
{
public:
    Vertex() {}
    Vertex(const vec3&, const vec3&);

    inline vec3* GetPos() { return &m_pos; }
    inline vec3* GetColor() { return &m_color; }

    virtual ~Vertex();
private:
    vec3 m_pos;
    vec3 m_color;
};

#endif // VERTEX_H
