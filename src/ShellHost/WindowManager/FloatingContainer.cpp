#include <cstdint>

namespace ShellHost::WindowManager {

    class FloatingContainer {
    public:
        FloatingContainer(uint64_t handle) : m_handle(handle) {}

        void UpdatePosition(int32_t deltaX, int32_t deltaY) {
            // [UNANCHORED COORDINATE SHIFT]
            m_posX += deltaX;
            m_posY += deltaY;
            
            // Constrain floating elements so they cannot be dragged completely out of the viewport bounds
            EnforceScreenBoundaries();
        }

        void ElevateZOrder() {
            // Bring floating container to the absolute top of the rendering stack upon touch engagement
            m_zOrder = 999; 
        }

    private:
        uint64_t m_handle;
        int32_t m_posX{100}, m_posY{100};
        int32_t m_zOrder{1};

        void EnforceScreenBoundaries() {
            // Logic to prevent the unanchored UI block from getting lost off-screen
        }
    };

} // namespace ShellHost::WindowManager
