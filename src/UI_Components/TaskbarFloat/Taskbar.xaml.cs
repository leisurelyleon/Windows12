using Microsoft.UI.Xaml.Controls;
using Microsoft.UI.Xaml.Input;
using Microsoft.UI.Xaml;
using Windows.Foundation;

namespace Windows12.UI_Components.TaskbarFloat
{
    public sealed partial class Taskbar : UserControl
    {
        private bool _isDragging = false;
        private Point _pointerOffset;

        public Taskbar()
        {
            this.InitializeComponent();
        }

        private void OnPointerPressed(object sender, PointerRoutedEventArgs e)
        {
            _isDragging = true;
            _pointerOffset = e.GetCurrentPoint(this).Position;
            this.CapturePointer(e.Pointer);
        }

        private void OnPointerMoved(object sender, PointerRoutedEventArgs e)
        {
            if (!_isDragging) return;

            var currentPoint = e.GetCurrentPoint(this.Parent as UIElement);
            var canvas = this.Parent as Canvas;

            if (canvas != null)
            {
                double newX = currentPoint.Position.X - _pointerOffset.X;
                double newY = currentPoint.Position.Y - _pointerOffset.Y;

                Canvas.SetLeft(this, newX);
                Canvas.SetTop(this, newY);
            }
        }

        private void OnPointerReleased(object sender, PointerRoutedEventArgs e)
        {
            _isDragging = false;
            this.ReleasePointerCapture(e.Pointer);
            
            // Invoke the layout intelligence to correct alignment
            DynamicDock.EvaluateProximity(this, Canvas.GetLeft(this), Canvas.GetTop(this));
        }

        private void OnStartMenuClicked(object sender, RoutedEventArgs e)
        {
            // Fires an IPC signal to the WindowManager to spawn the StartMenu overlay
        }
    }
}
