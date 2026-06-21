#pragma once
#include <string_view>

namespace ShellHost::Retro {

    enum class ClassicSkin {
        WindowsXP_Luna,
        Windows7_Aero
    };

    class RetroShellManager {
    public:
        RetroShellManager() = default;
        ~RetroShellManager() = default;

        void EngageRetroLayer(bool enable);
        bool ApplyClassicSkin(ClassicSkin skin);

    private:
        bool m_retroLayerActive{false};
        ClassicSkin m_activeSkin{ClassicSkin::Windows7_Aero};
    };

} // namespace ShellHost::Retro
