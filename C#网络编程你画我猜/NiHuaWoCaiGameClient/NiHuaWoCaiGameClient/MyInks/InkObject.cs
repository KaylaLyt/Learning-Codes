using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Ink;
using System.Windows.Input;
using System.Windows.Input.StylusPlugIns;
using System.Windows.Media;

namespace NiHuaWoCaiGameClient.MyInks
{
    public abstract class InkObject : DynamicRenderer
    {
        public MyInkCanvas myInkCanvas { get; private set; }
        public InkObjectStroke InkStroke { protected set; get; }
        public InkType inkType { get; protected set; }
        public MyInkData inkTool;
        protected Point previousPoint;
        public DrawingAttributes inkDA;
        private bool isInkColorAtEnd = true;

        public abstract void CreateNewStroke(InkCanvasStrokeCollectedEventArgs e);
        public abstract Point Draw(Point first, MyInkData tool, DrawingContext dc, StylusPointCollection points);

        [ThreadStatic]
        protected Brush brush = new SolidColorBrush(Colors.Gray);

        public InkObject(MyInkCanvas myInkCanvas, bool isInkColorAtEnd)
        {
            this.myInkCanvas = myInkCanvas;
            this.isInkColorAtEnd = isInkColorAtEnd;
            brush.Opacity = 0.09;
            inkTool = CreateFromInkData(myInkCanvas.myData);
            inkDA = myInkCanvas.inkDA.Clone();
            this.DrawingAttributes = inkDA;
        }

        public MyInkData CreateFromInkData(MyInkData data)
        {
            MyInkData tool = data.Clone();
            tool.inkBrush = null;
            if (isInkColorAtEnd)
            {
                GradientStopCollection c = new GradientStopCollection()
                {
                    new GradientStop(Colors.White, 0.05),
                    new GradientStop(Colors.Gold, 0.15),
                    new GradientStop(data.inkColor, 1.0),
                };
                tool.inkBrush = new SolidColorBrush(data.inkColor);
                Brush b = tool.inkBrush;
                tool.inkPen = new Pen(b, tool.inkRadius * 0.5);
            }
            else
            {
                tool.inkBrush = new SolidColorBrush(data.inkColor);
                tool.inkPen = new Pen(tool.inkBrush, tool.inkRadius * 0.5);
            }
            return tool;
        }

        protected double GetStylusInkDistance(MyInkData data, out Size size)
        {
            double width = data.inkRadius; ;
            double height = data.inkRadius;
            size = new Size(width, height);
            double distance = Math.Max(size.Width, size.Height) * 1.5 + 10;
            return distance;
        }

        protected override void OnStylusDown(RawStylusInput rawStylusInput)
        {
            myInkCanvas.isFromFileInk = false;
            inkTool = CreateFromInkData(myInkCanvas.myData);
            inkDA = myInkCanvas.inkDA.Clone();
            this.DrawingAttributes = inkDA;
            previousPoint = new Point(double.NegativeInfinity, double.NegativeInfinity);
            base.OnStylusDown(rawStylusInput);
        }

        protected override void OnStylusUp(RawStylusInput rawStylusInput)
        {
            base.OnStylusUp(rawStylusInput);
            this.InkStroke = null;
        }
    }

    // 注意InkObjectStroke类中的属性、方法不能和InkObject中的属性、方法共用，
    // 而应该通过克隆分别定义，否则将会导致呈现效果和预想的不一致。
    // 这是因为InkObjectStroke类中的inkData是“本次绘制使用的墨迹数据”，而InkObject类中是“下次绘制将要使用的墨迹数据”。
    //另外,OnDraw和DrawCore中绘制的内容可能相同，也可能不相同
    public class InkObjectStroke : Stroke
    {
        protected InkObject ink;
        public MyInkData inkTool;

        public InkObjectStroke(InkObject ink, StylusPointCollection stylusPoints)
            : base(stylusPoints)
        {
            this.ink = ink;
            inkTool = ink.CreateFromInkData(ink.inkTool);
            this.DrawingAttributes = ink.inkDA.Clone();
            this.DrawingAttributes.Color = ink.myInkCanvas.fillColor;
        }

        protected virtual void RemoveDirtyStylusPoints()
        {
            if (StylusPoints.Count > 2)
            {
                for (int i = StylusPoints.Count - 2; i > 0; i--)
                {
                    StylusPoints.RemoveAt(i);
                }
            }
        }
    }
}