#ifndef PGDIRECTOR_H
#define PGDIRECTOR_H
#include "line.h"
#include "llist.h"
#include "llist.cpp"

#define PI 3.14159
#define PI2 (PI * 2)

#define SEED_SIZE 64
#define MAX_URAND (unsigned int)100
#define MIN_URAND (unsigned int)0
// The height that the continental shelf will be created at
#define STARTING_HEIGHT 0
#define ISLAND_RADIUS 0.7
// Number of vertices in the starting island
#define STARTING_COAST_RESOLUTION 40

// Color of continental shelf
#define SHELF_COLOR vec3(0, 1, 1)

class PGDirector
{
public:
    PGDirector();

    void Seed();
    void Generate(double);
    void Load();
    void Draw();
    void AddLine(const Line&);
    void AppendLine(const vec3&);

    // Functions used in Generate()
    void CreateStartingIsland();
    void DeformCoastline();

    virtual ~PGDirector();
private:
    vector<vec3> m_points;
    vector<vec3> m_colors;
    vector<unsigned int> seed;

    vector<Line> m_lines;

    unsigned int m_urand(unsigned int, unsigned int);
    unsigned int urand();

    void printSeed();

    enum
    {
        POSITION_VB,
        COLOR_VB,

        NUM_BUFFERS
    };

    unsigned int m_drawCount;

    GLuint m_vertexArrayObject;
    GLuint m_vertexArrayBuffers[NUM_BUFFERS];
};

#endif // PGDIRECTOR_H
