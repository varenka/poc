#ifndef LINE_H
#define LINE_H
#include "vertex.h"

class Line
{
public:
    Line(const Vertex&, const Vertex&);

    inline Vertex* GetOrigin() { return &m_origin; }
    inline Vertex* GetEndpoint() { return &m_endpoint; }

    virtual ~Line();
private:
    Vertex m_origin;
    Vertex m_endpoint;
};

#endif // LINE_H
