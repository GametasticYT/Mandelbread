#include <raylib-cpp.hpp>
#include <complex>
#include <ctime>

int main()
{
    int screenWidth = 1500;
    int screenHeight = 1000;

    int maxIter = 50;
    int iter;
    
    char txtMouseX[50];
    char txtMouseY[50];

    std::complex<double> C(0, 0);
    std::complex<double> a(0, 0);
    std::complex<double> Z(0, 0);

    raylib::Color pixelColor;
    std::srand(std::time(nullptr));

    raylib::Camera2D cam({1200, 500}, {0, 0}, 0.0, 1.0);

    raylib::Window w(screenWidth, screenHeight, "MeinSchönesFindow");
    // SetTargetFPS(60);

    while(!w.ShouldClose())
    {
        BeginDrawing();
        BeginMode2D(cam);
            ClearBackground(RAYWHITE);

            for(int y = -screenHeight; y < screenHeight; y++)
            {
                for(int x = -screenWidth; x < screenWidth; x++)
                {
                    C = {(x / 500.0), (y / 500.0)};
                    Z = C;
                    for(iter = 0; iter < maxIter; iter++)
                    {
                        Z = std::pow(Z, 2) + C;
                        
                        if(Z.imag() > 4 || Z.real() > 4)
                        {
                            break;
                        }
                    }
                    
                    pixelColor = (raylib::Color){(iter * 11) % 255, (iter * 21) % 255, (iter * 22) % 255, 255};
                    DrawPixel(x, y, pixelColor);
                    

                }
            }
            DrawFPS(20 - 1200, 20 - 500);
        EndMode2D();
        EndDrawing();
    }

    return 0;
}