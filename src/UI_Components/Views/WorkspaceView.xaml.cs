using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using System.Runtime.InteropServices;

namespace Windows12.UI_Components.Views
{
    public partial class WorkspaceView : UserControl
    {
        // P/Invoke interfaces routing frontend state signals down into native C++ CorePC DLL handles
        [DllImport("CorePC_Workspace.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern bool SetDevWorkspaceState(bool active);

        public WorkspaceView()
        {
            this.InitializeComponent();
        }

        private void OnDevModeToggled(object sender, RoutedEventArgs e)
        {
            if (sender is ToggleSwitch toggleSwitch)
            {
                bool isSwitchedOn = toggleSwitch.IsOn;
                
                // Fire native invocation to activate Telemetry Suppression and Service Suspension layers immediately
                SetDevWorkspaceState(isSwitchedOn);
            }
        }
    }
}
