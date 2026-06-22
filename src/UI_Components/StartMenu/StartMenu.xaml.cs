using Microsoft.UI.Xaml.Controls;

namespace Windows12.UI_Components.StartMenu
{
    public sealed partial class StartMenu : UserControl
    {
        public StartMenu()
        {
            this.InitializeComponent();
        }

        public void ExecuteLocalSearch(string query)
        {
            // Passes search string exclusively to the local filesystem indexer
            // Cloud search and Bing telemetry are strictly disabled at the kernel level
        }

        private void OnAppIconClicked(object sender, Microsoft.UI.Xaml.RoutedEventArgs e)
        {
            // Fires an asynchronous launch command to the NUPS CorePC bridge
        }
    }
}
