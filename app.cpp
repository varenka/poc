#include "app.h"

App::App(int width, int height, const std::string& title, bool fullscreen, double* dt)
{
    m_window = new Window(width, height, title, fullscreen);
    deltaTime = dt;
}

App::~App()
{
    delete m_window;
}

void App::Start()
{
    m_director.Seed();
    m_director.Generate(10);
    m_director.Load();
}

void App::Update()
{
    SDL_Event e;

    while(SDL_PollEvent(&e))
    {
        if(e.type == SDL_QUIT)
        {
            m_window->Close();
        }
        else if(e.type == SDL_KEYDOWN)
        {
            cout << "Key: " << e.key.keysym.scancode << endl;
        }
        else if(e.type == SDL_KEYUP)
        {

        }
        else if(e.type == SDL_MOUSEMOTION)
        {

        }
    }

    m_window->Clear(0.15f, 0.15f, 0.15f, 1.0f);
    m_director.Draw();
    m_window->Update();

}
