#include "line.h"

Line::Line(const Vertex& origin, const Vertex& endpoint)
{
    m_origin = origin;
    m_endpoint = endpoint;
}

Line::~Line()
{
    //dtor
}
