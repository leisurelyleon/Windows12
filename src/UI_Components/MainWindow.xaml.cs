using Microsoft.UI.Xaml;
using Microsoft.UI.Windowing;
using WinRT.Interop;

namespace Windows12.UI_Components
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            this.InitializeComponent();
            ConfigureExtendsIntoTitleBar();
        }

        private void ConfigureExtendsIntoTitleBar()
        {
            var hWnd = WindowNative.GetWindowHandle(this);
            var windowId = Microsoft.UI.GetWindowIdFromWindowHandle(hWnd);
            var appWindow = AppWindow.GetFromWindowId(windowId);

            if (appWindow != null)
            {
                // Suppress standard legacy title bar parameters to render clean edge-to-edge layouts
                appWindow.TitleBar.ExtendsContentIntoTitleBar = true;
                appWindow.ResizeTo(1920, 1080);
            }
        }
    }
}
