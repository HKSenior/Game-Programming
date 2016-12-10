#ifndef __PLATFORMER_HPP__
#define __PLATFORMER_HPP__

#include "Game.hpp"
#include "vec.h"
#include "Shader.hpp"
#include "Matrix.hpp"
#include "Rectangle.hpp"
#include <SDL2_image/SDL_image.h>

#define FIXED_TIMESTEP 0.0166666f
#define MAX_TIMESTEPS 6

class Platformer : public Game {
public:
    
    // Constructors and Destructors
    Platformer(float w, float h, const char* name);
    Platformer(const char* name);
    ~Platformer();
    
    // Overload functions
    void setup();
    bool processEvents();
    void update();
    void render();
    
    // Methods
    void draw();
    
private:
    
    // Methods
    void init();
    GLuint LoadTexture(const char *image_path);

    // For animations
    float lastFrameTicks = 0.0f;
    float angle = 0.0f;
    float elapsed = 0.0f;
    
    // Flags
    bool pause = false;
    
    // Data
    
        // Shader
        Shader* shader = nullptr;
    
        // Matrices
        Matrix model, view, projection;
    
        // Texture ID's
        GLuint tex1;
    
        // Players
        Rectangle* player1 = nullptr;
        Rectangle* player2 = nullptr;
};

#endif /* __PLATFORMER_HPP__ defined */
