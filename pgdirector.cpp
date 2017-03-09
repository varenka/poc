#include "pgdirector.h"

ostream& operator<<(ostream& os, const vec3& vec)
{
    return os << "( " << vec.x << ", " << vec.y << ", " << vec.z << " )";
}

PGDirector::PGDirector()
{
    m_drawCount = 0;
}

PGDirector::~PGDirector()
{
    glDeleteVertexArrays(1, &m_vertexArrayObject);
}

unsigned int PGDirector::urand()
{
    return rand();
}

/**

Random uint between min and max

**/
unsigned int PGDirector::m_urand(unsigned int min, unsigned int max)
{
    return rand() % max + min;
}

void PGDirector::printSeed()
{
    for(unsigned int i = 0; i < seed.size(); i++)
    {
        cout << seed[i] << " ";
    }
    cout << endl;
}

/**

Generates a random seed

**/
void PGDirector::Seed()
{
    cout << "Generating seed:" << endl;
    for(unsigned int i = 0; i < SEED_SIZE; i++)
    {
        seed.push_back(m_urand(MIN_URAND, MAX_URAND));
    }
    printSeed();
}

/**

Generates a procedural terrain mesh from a seed

    width: the distance from the origin on either side the mesh will reach

**/
void PGDirector::Generate(double width)
{
    CreateStartingIsland();
}

void PGDirector::CreateStartingIsland()
{
    double radiansPerSegment = PI2 / STARTING_COAST_RESOLUTION;
    for(double theta = 0; theta < PI2; theta += radiansPerSegment)
    {
        cout << "Creating new line:" << endl;
        Vertex origin(vec3(cos(theta), sin(theta), STARTING_HEIGHT), SHELF_COLOR);
        theta += radiansPerSegment;
        Vertex endpoint(vec3(cos(theta), sin(theta), STARTING_HEIGHT), SHELF_COLOR);
        cout << "\t" << *origin.GetPos() << endl;
        cout << "\t" << *endpoint.GetPos() << endl;
        AddLine(Line(origin, endpoint));
    }
}

void PGDirector::AddLine(const Line& l)
{
    m_lines.push_back(l);

    m_drawCount += 2;
}

/**

Loads the generated buffer of lines into an opengl buffer

**/
void PGDirector::Load()
{
    // Setup data so that it can be loaded
    for(unsigned int i = 0; i < m_lines.size(); i++)
    {
        m_points.push_back(*m_lines[i].GetOrigin()->GetPos());
        m_colors.push_back(*m_lines[i].GetOrigin()->GetColor());
        m_points.push_back(*m_lines[i].GetEndpoint()->GetPos());
        m_colors.push_back(*m_lines[i].GetEndpoint()->GetColor());
    }

    // Create vertex array for all of our points
    glGenVertexArrays(1, &m_vertexArrayObject);

    glBindVertexArray(m_vertexArrayObject);

    glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);

        // Add position data
        glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]);
        glBufferData(GL_ARRAY_BUFFER, m_points.size() * sizeof(m_points[0]), &m_points[0], GL_STATIC_DRAW);

    // Create vertex attribute array for position data
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

        // Add color data
        glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[COLOR_VB]);
        glBufferData(GL_ARRAY_BUFFER, m_colors.size() * sizeof(m_colors[0]), &m_colors[0], GL_STATIC_DRAW);

    // Create color attribute array
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindVertexArray(0);

    // Set line width
    glLineWidth(0.4f);

    cout << "Positions: " << endl;
    for(unsigned int i = 0; i < m_points.size(); i++)
    {
        cout << "\t" << m_points[i] << endl;
    }
    cout << "Colors: " << endl;
    for(unsigned int i = 0; i < m_colors.size(); i++)
    {
        cout << "\t" << m_colors[i] << endl;
    }

}

/**

Draws the loaded buffer on the screen

**/
void PGDirector::Draw()
{
    glBindVertexArray(m_vertexArrayObject);

    cout << "Drawing " << m_drawCount << " vertices" << endl;
    glDrawArrays(GL_LINES, 0, m_drawCount);

    glBindVertexArray(0);
}
