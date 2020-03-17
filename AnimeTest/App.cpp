
#include "App.hpp"
#include <iostream>


bool App::Loop(){
    
    SDL_Event event;
       while (SDL_PollEvent(&event))
       {
           switch (event.type)
           {
                   
           case SDL_QUIT:
                   return false;
           }
       }

       // ESCキーで終了
       const Uint8* state = SDL_GetKeyboardState(NULL);
       if (state[SDL_SCANCODE_ESCAPE])
       {
           return false;
       }
       
    
    
    glClearColor(0.2f, 0.2f, 0.8f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    

    

    SDL_GL_SwapWindow(lpWnd);
    return true;
}

bool App::Release(){
    
    SDL_GL_DeleteContext(lpGL);
    SDL_DestroyWindow(lpWnd);
    return true;
}



bool App::Create()
{
     strTitle        = "title";    // ウィンドウタイトル
     ScreenWidth     = 1024;  // スクリーン幅
     ScreenHeight    = 768; // スクリーン高さ
     
    

     
     // OpenGL プロファイル, バージョン
     SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
     SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
     SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

     // ダブルバッファリング
     SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
     // RGBAチャンネル
     SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
     SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
     SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
     SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
     // ハードウェアアクセラレーション有効化
     SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
     
     
     //ウインドウ生成
     lpWnd = SDL_CreateWindow(strTitle.c_str(), 100, 100, static_cast<int>(ScreenWidth), static_cast<int>(ScreenHeight), SDL_WINDOW_OPENGL );
     if (!lpWnd )
     {
         std::cout << "Unable to create window\n"<< std::endl;
         return false;
     }
     
     
     // OpenGL コンテキスト生成
     lpGL = SDL_GL_CreateContext(lpWnd);
     
     // GLEW初期化
     glewExperimental = GL_TRUE;
    
     if (glewInit() != GLEW_OK)
     {
         std::cout << "Failed to initialize GLEW\n" << std::endl;
         return false;
     }

    return true;
}

