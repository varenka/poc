#include <iostream>
#include "app.h"
#include "shader.h"

#define WIDTH 640
#define HEIGHT 640

using namespace std;

int main()
{
    srand(time(NULL));

    double dtime = 0.1;
    double start = 0.1;

    App app(WIDTH, HEIGHT, "Proof of concept", false, &dtime);

    app.Start();

    Shader shader("./res/line");
    shader.Bind();

    llist<double> test;

    test.push_back(0);
    test.push_back(1);
    test.push_back(2);
    test.push_back(4);
    test.push_back(5);
    test.push_back(6);
    test.push_back(7);
    test.push_back(8);

    test.insert(2, 3);

    test.print();

    double* array = test.data();



    delete[] array;

    while(!app.IsClosed())
    {
        start = clock();

        app.Update();

        dtime = ( clock() - start ) / (double)CLOCKS_PER_SEC;
    }

    return 0;
}
