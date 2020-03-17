
#ifndef App_hpp
#define App_hpp

#include <string>
#include <SDL2/SDL.h>
#include <GL/glew.h>

class App{
    std::string strTitle;
    int ScreenWidth;
    int ScreenHeight;
    
    
    SDL_Window*     lpWnd = nullptr;   // Windowハンドラ
    SDL_GLContext   lpGL;
    
public:
    bool Create();
    bool Loop();
    bool Release();
};



#endif /* App_hpp */
