#ifndef APP_H
#define APP_H
#include "window.h"
#include "pgdirector.h"

class App
{
public:
    App(int width, int height, const std::string& title, bool fullscreen, double* dt);

    double* deltaTime;

    void Start();
    void Update();

    bool IsClosed() { return m_window->IsClosed(); }

    Window* GetWindow() { return m_window; }

    virtual ~App();
private:
    Window* m_window;
    PGDirector m_director;
};

#endif // APP_H
