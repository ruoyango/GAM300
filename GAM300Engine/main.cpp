#pragma warning(disable : 28251)

#include "application.h"
#include "ecs/ecs.h"


#if _DEBUG
#pragma comment( linker, "/subsystem:console" )
int main(int argc, const char** argv) {
    
    return WinMain(GetModuleHandle(NULL), NULL, GetCommandLineA(), 0);
}
#else
#pragma comment( linker, "/subsystem:windows" )
#endif

TDS::Application* g_Application {nullptr};

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)				
{																							
    if (g_Application != NULL)																
    {																						
        g_Application->handleMessages(hWnd, uMsg, wParam, lParam);								
    }																						
    return (DefWindowProc(hWnd, uMsg, wParam, lParam));										
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    
    const wchar_t classname[] = L"TDSWindowClass"; //class name

    g_Application = new TDS::Application(hInstance,nCmdShow,classname, WndProc);
    g_Application->Initialize();
    g_Application->initImgui();
    g_Application->Update();
    g_Application->~Application();
    delete g_Application;

    return 0;
}
