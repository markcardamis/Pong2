//
//  TextureHolder.cpp
//  Pong2
//
//  Created by Mark Cardamis on 14/3/20.
//  Copyright © 2020 Mark Cardamis. All rights reserved.
//

#include "TextureHolder.h"
#include <assert.h>

TextureHolder* TextureHolder::m_s_Instance = nullptr;

TextureHolder::TextureHolder()
{
    assert(m_s_Instance == nullptr);
    m_s_Instance = this;
}

Texture& TextureHolder::getTexture(string const& filename)
{
    // Get a reference to m_Texture using m_s_Instance
    auto& m = m_s_Instance->m_Textures;
    
    // Create an iterator to hold key value pair
    auto keyValuePair = m.find(filename);
    
    // Find a match
    if (keyValuePair != m.end())
    {
        return keyValuePair->second;
    }
    else
    {
        auto& texture = m[filename]; // Create a new key value pair
        texture.loadFromFile(filename);
        return texture;
    }
}
