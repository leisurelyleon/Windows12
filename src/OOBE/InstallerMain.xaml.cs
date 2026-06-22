using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using System.Runtime.InteropServices;

namespace Windows12.OOBE
{
    public sealed partial class InstallerMain : Window
    {
        // Interop hook to the C++ CorePC installation orchestrator
        [DllImport("OOBE_Orchestrator.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern bool ExecuteCleanInstall(string username, string passwordHash);

        public InstallerMain()
        {
            this.InitializeComponent();
        }

        private async void OnBrowserSelectClicked(object sender, RoutedEventArgs e)
        {
            var browserDialog = new BrowserSelectDialog();
            browserDialog.XamlRoot = this.Content.XamlRoot;
            await browserDialog.ShowAsync();
        }

        private void OnInitializeSystemClicked(object sender, RoutedEventArgs e)
        {
            string user = LocalAccountName.Text;
            string pass = LocalAccountPassword.Password; // In production, hash securely via TPM

            if (!string.IsNullOrWhiteSpace(user))
            {
                // Dispatch native deployment
                ExecuteCleanInstall(user, pass);
            }
        }
    }
}
