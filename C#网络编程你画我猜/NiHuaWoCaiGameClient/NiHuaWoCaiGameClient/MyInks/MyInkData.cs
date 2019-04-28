using System.Windows.Media;

namespace NiHuaWoCaiGameClient.MyInks
{
    public enum InkType { 曲线 }
    public enum InkStylusType { 圆笔 }
    public enum InkClorType { 红色, 蓝色, 绿色 }

        public class MyInkData
        {
            public Brush inkBrush;//画刷
            public Pen inkPen;//画笔
            public double inkRadius;
            public Color inkColor;//笔尖颜色
            public InkStylusType inkStylusType;//笔尖类型

        public MyInkData Clone()
            {
                MyInkData data = new MyInkData()
                {
                    inkRadius = this.inkRadius,
                    inkColor = this.inkColor,  
                };
               return data;
          }
     }
}