//
//  TextureHolder.h
//  Pong2
//
//  Created by Mark Cardamis on 14/3/20.
//  Copyright © 2020 Mark Cardamis. All rights reserved.
//

#ifndef TextureHolder_h
#define TextureHolder_h

#include <SFML/Graphics.hpp>
#include <map>

using namespace sf;
using namespace std;

class TextureHolder
{
private:
    map<string,Texture> m_Textures;
    static TextureHolder* m_s_Instance;
    
public:
    TextureHolder();
    static Texture& getTexture(string const& filename);
};

#endif /* TextureHolder_h */
