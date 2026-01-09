// #include <graphics.h>
// #include <conio.h>
#include "raylib.h"
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
// define pointer struct, containing postion colour
struct Point
{
    double x, y;
    Color color;
};

// screen size
const int xScreen = 1200;
const int yScreen = 800;

// constant variance
// const double PI = 3.1415926535;
const double E_CONST = 2.71828;

// particle parameter
const double average_distance = 0.162;
const int quantity = 2000;
const int circles = 210;
const int frames = 20;

// define colours
Color particleColors[] = 
{
    /*
    // cyan-based colour
    (Color){0, 255, 255, 255},
    (Color){0, 240, 240, 255},
    (Color){0, 220, 220, 255},
    (Color){0, 200, 200, 255},
    (Color){0, 180, 180, 255},
    (Color){0, 160, 160, 255},
    (Color){0, 140, 140, 255}
    */

   // pink-based colour
    (Color){255, 182, 193, 255},
    (Color){255, 105, 180, 255},
    (Color){255, 20, 147, 255},
    (Color){219, 112, 147, 255},
    (Color){199, 21, 133, 255},
    (Color){255, 192, 203, 255},
    (Color){220, 20, 60, 255}
};

// dot storage array
std::vector<Point> origin_points(quantity);
std::vector<Point> points(circles * quantity);
RenderTexture2D frameTextures[frames];

// switch of cooridate system
double screen_x(double x)
{
    return x + xScreen / 2;
}

double screen_y(double y)
{
    return -y + yScreen / 2;
}

// random number in given range
int create_random(int x1, int x2)
{
    if(x2 > x1) return rand() % (x2 - x1 + 1) + x1;
    return x1;
}

Color AdjustBrightness(Color c, double factor) {
    if (factor <= 0) factor = 0.1;
    unsigned char r = (unsigned char)(c.r / factor);
    unsigned char g = (unsigned char)(c.g / factor);
    unsigned char b = (unsigned char)(c.b / factor);
    return (Color){r, g, b, 255};
}

// create particle
void create_data()
{
    // Cardioid
    // int index = 0;
    int origin_count = 0;
    double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0;
    for(double radian  = 0.01; radian <= 2 * PI; radian += 0.005)
    {
        x2 = 16 * pow(sin(radian), 3);
        y2 = 13 * cos(radian) - 5 * cos(2 * radian) - 2 * cos(3 * radian) - cos(4 * radian);

        double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        if(distance > average_distance && origin_count < quantity)
        {
            x1 = x2; y1 = y2;
            origin_points[origin_count].x = x2;
            origin_points[origin_count].y = y2;
            origin_count++;
        }
    }

    // dynamic particle
    int current_points_index = 0;
    for(double size = 0.1, lightness = 1.5; size <= 20; size += 0.1)
    {
        double success_p = 1 / (1 + pow(E_CONST, 8 - size / 2));
        if(lightness > 1) lightness -= 0.0025;

        for(int i = 0; i < origin_count; i++)
        {
            if(success_p > (double) create_random(0, 100) / 100.0 && current_points_index < circles * quantity)
            {
                Color baseColor = particleColors[create_random(0, 6)];
                points[current_points_index].color = AdjustBrightness(baseColor, lightness);

                points[current_points_index].x = size * origin_points[i].x + create_random(-4, 4);
                points[current_points_index].y = size * origin_points[i].y + create_random(-4, 4);
                current_points_index++;
            }
        }
    }

    int total_points = current_points_index;

    for(int frame = 0; frame < frames; frame++)
    {
        frameTextures[frame] = LoadRenderTexture(xScreen, yScreen);
        BeginTextureMode(frameTextures[frame]);
        ClearBackground(BLACK);
        
        for(int index = 0; index < total_points; index++)
        {
            double x = points[index].x, y = points[index].y;
            double distance = sqrt(x * x + y * y);
            double distance_increase = -0.0009 * distance * distance + 0.35714 * distance + 5;
            double x_increase = distance_increase * x / distance / (frame + 1);
            double y_increase = distance_increase * y / distance / (frame + 1);

            double draw_x = points[index].x + x_increase;
            double draw_y = points[index].y + y_increase;

            DrawCircle(screen_x(draw_x), screen_y(draw_y), 1, points[index].color);
        }

        for(double size = 17; size < 23; size += 0.3)
        {
            for(int i = 0; i <origin_count; i++)
            {
                if((create_random(0, 100) / 100.0 > 0.6 && size >= 20) || (size < 20 && create_random(0, 100) / 100.0 > 0.95))
                {
                    double x, y;
                    if(size >= 20)
                    {
                        x = origin_points[i].x * size + create_random(-frame * frame / 5 - 15, frame * frame / 5 + 15);
                        y = origin_points[i].y * size + create_random(-frame * frame / 5 - 15, frame * frame / 5 + 15);
                    }
                    else
                    {
                        x = origin_points[i].x * size + create_random(-5, 5);
                        y = origin_points[i].y * size + create_random(-5, 5);
                    }
                    DrawCircle(screen_x(x), screen_y(y), 1, particleColors[create_random(0, 6)]);
                }  
            }
        }
        EndTextureMode();
    }
}

int main()
{
    InitWindow(xScreen, yScreen, "Mac-Version Particle Heart");
    InitAudioDevice();
    SetTargetFPS(60);
    srand((unsigned int)time(NULL));

    Font customFont = LoadFontEx("GreatVibes-Regular.ttf", 96, 0, 0);
    Music bgm = LoadMusicStream("Inuyasha - To Love's End - Erhu Cover by Eliott Tordo_MP3.mp3");

    PlayMusicStream(bgm);
    SetMusicVolume(bgm, 0.5f);

    create_data();
    int frame = 0;
    bool extend = true;
    int frameCounter = 0;

    while (!WindowShouldClose()) 
    {
        UpdateMusicStream(bgm);
        BeginDrawing();
        ClearBackground(BLACK);

        Rectangle sourceRec = { 0.0f, 0.0f, (float)frameTextures[frame].texture.width, (float)-frameTextures[frame].texture.height };
        Rectangle destRec = { 0.0f, 0.0f, (float)xScreen, (float)yScreen };
        Vector2 origin = { 0.0f, 0.0f };
        DrawTexturePro(frameTextures[frame].texture, sourceRec, destRec, origin, 0.0f, WHITE);

        const char* text = "xxxx\n11111";
        int fontSize = 50;
        int spacing = 2;
    
        Vector2 textSize = MeasureTextEx(customFont, text, fontSize, spacing);
        Vector2 textPos;
    

        textPos.x = xScreen / 2 - textSize.x / 2;
        textPos.y = yScreen / 2 - textSize.y / 2;

        DrawTextEx(customFont, text, textPos, fontSize, spacing, Fade(PURPLE, 0.9f));

        EndDrawing();

        frameCounter++;
        if (frameCounter >= 2) 
        {
            frameCounter = 0;
            if (extend) 
            {
                if (frame == frames - 1) extend = false;
                else frame++;
            } 
            
            else 
            {
                if (frame == 0) extend = true;
                else frame--;
            }
        }
    }

    for (int i = 0; i < frames; i++) 
    {
        UnloadRenderTexture(frameTextures[i]);
    }
    
    UnloadFont(customFont);
    UnloadMusicStream(bgm);
    CloseWindow();

    return 0;
}