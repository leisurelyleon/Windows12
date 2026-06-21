#include "RetroShellManager.h"
#include <iostream>

namespace ShellHost::Retro {

    extern void InjectClassicGDIHooks(ClassicSkin skin);
    extern void TeardownClassicGDIHooks();

    void RetroShellManager::EngageRetroLayer(bool enable) {
        m_retroLayerActive = enable;
        if (m_retroLayerActive) {
            std::cout << "[RetroShell] Engaging legacy UI layer mapping." << std::endl;
            ApplyClassicSkin(m_activeSkin);
        } else {
            TeardownClassicGDIHooks();
        }
    }

    bool RetroShellManager::ApplyClassicSkin(ClassicSkin skin) {
        m_activeSkin = skin;
        if (!m_retroLayerActive) return false;

        switch (m_activeSkin) {
            case ClassicSkin::WindowsXP_Luna:
                std::cout << "[RetroShell] Re-mapping compositor textures to Classic Blue Luna assets." << std::endl;
                break;
            case ClassicSkin::Windows7_Aero:
                std::cout << "[RetroShell] Initializing translucent glass blur shaders for classic layout simulation." << std::endl;
                break;
        }

        InjectClassicGDIHooks(m_activeSkin);
        return true;
    }

} // namespace ShellHost::Retro
