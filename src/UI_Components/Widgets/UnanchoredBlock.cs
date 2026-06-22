using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using Microsoft.UI.Xaml.Input;

namespace Windows12.UI_Components.Widgets
{
    public class UnanchoredBlock : ContentControl
    {
        private bool _isManipulating = false;

        public UnanchoredBlock()
        {
            this.ManipulationMode = ManipulationModes.TranslateX | ManipulationModes.TranslateY;
            this.ManipulationStarted += OnBlockManipulationStarted;
            this.ManipulationDelta += OnBlockManipulationDelta;
            this.ManipulationCompleted += OnBlockManipulationCompleted;
        }

        private void OnBlockManipulationStarted(object sender, ManipulationStartedRoutedEventArgs e)
        {
            _isManipulating = true;
            // Elevate Z-Index so the dragged block always renders on top
            Canvas.SetZIndex(this, 100); 
        }

        private void OnBlockManipulationDelta(object sender, ManipulationDeltaRoutedEventArgs e)
        {
            if (!_isManipulating) return;

            double newX = Canvas.GetLeft(this) + e.Delta.Translation.X;
            double newY = Canvas.GetTop(this) + e.Delta.Translation.Y;

            Canvas.SetLeft(this, newX);
            Canvas.SetTop(this, newY);
        }

        private void OnBlockManipulationCompleted(object sender, ManipulationCompletedRoutedEventArgs e)
        {
            _isManipulating = false;
            Canvas.SetZIndex(this, 10); // Return to standard layer height
        }
    }
}
