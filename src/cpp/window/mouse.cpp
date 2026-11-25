#include "window/window.h"
#include "window/mouse.h"

MouseManager::MouseManager()
{
    vertical_Texture.loadFromFile("asset/sprite/vertical_cursor.png");
    horizontal_Texture.loadFromFile("asset/sprite/horizontal_cursor.png");
}

MouseManager::~MouseManager()
{

}

void MouseManager::Set_cursor(CursorType type)
{
    
}