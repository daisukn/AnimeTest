//
//  main.cpp
//  AnimeTest
//
//  Created by Daisuke Nishimori on 2020/03/14.
//  Copyright © 2020 Daisuke Nishimori. All rights reserved.
//

#include <iostream>
#include "AniMesh.hpp"
#include "App.hpp"
#include <SDL2/SDL.h>



int main(int argc, const char * argv[]) {
    
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "Failed to init SDL\n";
        return -1;
    }
    
    App* a = new App();
    
    if(!a->Create())
        return -1;
    
    while(a->Loop());
    
    a->Release();
    return 0;
}
