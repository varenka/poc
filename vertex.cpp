#include "vertex.h"

Vertex::Vertex(const vec3& pos = vec3(0, 0, 0), const vec3& col = vec3(1, 1, 1))
{
    m_pos = pos;
    m_color = col;
}

Vertex::~Vertex()
{
    //dtor
}
