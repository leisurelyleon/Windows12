#pragma once
#include <atomic>
#include <cstdint>

namespace ShellHost::Compositor {

    enum class ThemeAesthetic {
        SunsetGradient,
        DarkCarbon,
        RetroMapped
    };

    class CompositorEngine {
    public:
        CompositorEngine();
        ~CompositorEngine() = default;

        bool InitializeDisplayPipeline();
        void RenderFrame();
        void SetVisualTheme(ThemeAesthetic theme);
        
        [[nodiscard]] bool IsPipelineActive() const;

    private:
        void ComputeSunsetGradients();
        void ApplyCarbonTextureOverlay();

        std::atomic<bool> m_pipelineActive{false};
        ThemeAesthetic m_currentTheme{ThemeAesthetic::SunsetGradient};
        uint64_t m_frameCount{0};
    };

} // namespace ShellHost::Compositor
