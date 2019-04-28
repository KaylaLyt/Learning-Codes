using Microsoft.Win32;
using System;
using System.IO;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Ink;
using System.Windows.Input;
using System.Windows.Media;

namespace NiHuaWoCaiGameClient.MyInks
{
    public class MyInkCanvas : InkCanvas
    {
        private InkObject ink;
        public MyInkData myData;
        public DrawingAttributes inkDA;

        /// <summary>
        /// 背景曲线填充的用的颜色。默认为透明色
        /// </summary>
        public Color fillColor;

        /// <summary>
        /// 要显示的墨迹是否来自墨迹文件
        /// </summary>
        public bool isFromFileInk = false;

        /// <summary>
        /// 初始化墨迹类型和笔尖信息，其初值必须与RibbonTab中的默认选项相同
        /// </summary>
        public MyInkCanvas()
        {
            fillColor = Colors.Transparent;
            this.myData = new MyInkData()
            {
                inkRadius = 6.0,
                inkColor = Colors.Red,
            };
            UpdateInkParams();
            SetInkAttributes(InkType.曲线.ToString());
        }

        /// <summary>
        /// 根据墨迹类型和笔尖信息，设置MyInkCanvas中的相关参数
        /// </summary>
        private void UpdateInkParams()
        {
            if (isFromFileInk)
            {
                return;
            }
            this.ClearSelected();
            inkDA = new DrawingAttributes()
            {
                Color = myData.inkColor,
                Width = 2 * myData.inkRadius,
                Height = 2 * myData.inkRadius,
                StylusTip = StylusTip.Ellipse,
                IgnorePressure = true,
                FitToCurve = false
            };
            this.DefaultDrawingAttributes = inkDA;
            this.UseCustomCursor = false;
            this.DynamicRenderer = ink;
        }
        
        /// <summary>当从文件中加载墨迹时，会自动调用此方法</summary>
        protected override void OnStrokesReplaced(InkCanvasStrokesReplacedEventArgs e)
        {
            isFromFileInk = true;
            StrokeCollection strokes = e.NewStrokes.Clone();
            this.Strokes.Remove(e.NewStrokes);
            base.OnStrokesReplaced(e);

            foreach (var v in strokes)
            {
                this.Strokes.Remove(v);
                Guid id = v.GetPropertyDataIds()[0];
                string[] s = ((string)v.GetPropertyData(id)).Split('#');
                MyInkData data = new MyInkData();
                for (int i = 0; i < s.Length; i++)
                {
                    string[] property = s[i].Split(':');
                    data.inkStylusType = (InkStylusType)Enum.Parse(typeof(InkStylusType), property[1]);
                    switch (property[0])
                    {
                        case "inkName":
                            this.SetInkAttributes(property[1]);
                            break;
                        case "inkRadius":
                            data.inkRadius = double.Parse(property[1]);
                            break;
                        case "inkColor":
                            string[] c = property[1].Split(',');
                            data.inkColor = Color.FromArgb(byte.Parse(c[0]), byte.Parse(c[1]), byte.Parse(c[2]), byte.Parse(c[3]));
                            break;
                          
                    }
                }
                ink.inkTool = ink.CreateFromInkData(data);
                InkCanvasStrokeCollectedEventArgs args = new InkCanvasStrokeCollectedEventArgs(v);
                this.OnStrokeCollected(args);
            }
        }

        /// <summary>当收集墨迹时，会自动调用此方法</summary>
        protected override void OnStrokeCollected(InkCanvasStrokeCollectedEventArgs e)
        {
            this.Strokes.Remove(e.Stroke);
            ink.CreateNewStroke(e);
            MyInkData data = ink.InkStroke.inkTool;
            StringBuilder sb = new StringBuilder();
            sb.AppendFormat("inkName:{0}#", ink.inkType);
            sb.AppendFormat("inkRadius:{0}#", data.inkRadius);
            Color c = data.inkColor;
            sb.AppendFormat("inkColor:{0},{1},{2},{3}#", c.A, c.R, c.G, c.B);
            sb.AppendFormat("inkStylusType:{0}#", data.inkStylusType);
            ink.InkStroke.AddPropertyData(Guid.NewGuid(), sb.ToString());
            this.Strokes.Add(ink.InkStroke);
            InkCanvasStrokeCollectedEventArgs args = new InkCanvasStrokeCollectedEventArgs(ink.InkStroke);
            base.OnStrokeCollected(args);
        }

        /// <summary>清除笔画的选择状态，将所有笔画都变为不选择</summary>
        private void ClearSelected()
        {
            foreach (Stroke aStroke in Strokes)
            {
                aStroke.DrawingAttributes.Color = fillColor;
            }
        }


        /// <summary>初始化墨迹绘制时需要的信息</summary>
        public void SetInkAttributes(string name)
        {
            ink = new InkCurve(this, true);
            UpdateInkParams();
            this.EditingMode = InkCanvasEditingMode.Ink;
            isFromFileInk = false;
            this.myData.inkStylusType = InkStylusType.圆笔;
            UpdateInkParams();
            this.EditingMode = InkCanvasEditingMode.Ink;
            
            switch (name)
            {
                //---------------笔尖颜色---------------------
                case "红色":
                    isFromFileInk = false;
                    myData.inkColor = Colors.Red;
                    UpdateInkParams();
                    this.EditingMode = InkCanvasEditingMode.Ink;
                    break;
                case "绿色":
                    isFromFileInk = false;
                    myData.inkColor = Colors.Green;
                    UpdateInkParams();
                    this.EditingMode = InkCanvasEditingMode.Ink;
                    break;
                case "蓝色":
                    isFromFileInk = false;
                    myData.inkColor = Colors.Blue;
                    UpdateInkParams();
                    this.EditingMode = InkCanvasEditingMode.Ink;
                    break;
                //---------------笔尖大小------------------------
                case "2":
                case "6":
                case "12":
                    isFromFileInk = false;
                    myData.inkRadius = double.Parse(name);
                    UpdateInkParams();
                    this.EditingMode = InkCanvasEditingMode.Ink;
                    break;
                //---------------橡皮擦---------------------
                //case "墨迹擦除":
                //    isFromFileInk = false;
                //    this.UseCustomCursor = false;
                //    foreach (Stroke v in Strokes)
                //    {
                //        v.DrawingAttributes.Color = Colors.RoyalBlue;
                //    }
                //    this.EditingMode = InkCanvasEditingMode.EraseByPoint;
                //    break;
                //case "笔画擦除":
                //    isFromFileInk = false;
                //    this.UseCustomCursor = false;
                //    foreach (Stroke v in Strokes)
                //    {
                //        v.DrawingAttributes.Color = Colors.RoyalBlue;
                //    }
                //    this.EditingMode = InkCanvasEditingMode.EraseByStroke;
                //    break;
                case "全部删除":
                    isFromFileInk = false;
                    this.UseCustomCursor = false;
                    this.Strokes.Clear();
                    this.EditingMode = InkCanvasEditingMode.None;
                    break;
            }
        }

        /// <summary>从墨迹文件中加载墨迹笔画</summary>
        public void LoadInkFromFile(string fileName)
        {
            if (!File.Exists(fileName))
            {
                MessageBox.Show(string.Format("文件（{0}）不存在,自动加载失败。", fileName));
                return;
            }
            LoadInk(fileName);
        }

        /// <summary>从墨迹文件中加载墨迹笔画</summary>
        public void LoadInkFromFile()
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.InitialDirectory = Environment.CurrentDirectory;
            ofd.Filter = "墨迹文件|*.isf|所有文件|*.*";
            if (ofd.ShowDialog() == false)
            {
                return;
            }
            LoadInk(ofd.FileName);
        }

        private void LoadInk(string fileName)
        {
            FileStream fs = null;
            try
            {
                fs = new FileStream(fileName, FileMode.Open, FileAccess.Read);
                StrokeCollection strokes = new StrokeCollection(fs);
                this.Strokes = strokes;
                this.isFromFileInk = true;
            }
            catch (Exception ex)
            {
                MessageBox.Show("加载失败：" + ex.StackTrace);
            }
            finally
            {
                if (fs != null) fs.Close();
            }
        }

        /// <summary>将墨迹笔画保存到墨迹文件中</summary>
        public void SaveInkToFile()
        {
            string fileName = "ink2.isf";
            SaveFileDialog sfd = new SaveFileDialog();
            sfd.InitialDirectory = Environment.CurrentDirectory;
            sfd.Filter = "墨迹文件|*.isf|所有文件|*.*";
            sfd.FileName = System.IO.Path.Combine(sfd.InitialDirectory, fileName);
            if (sfd.ShowDialog() == false)
            {
                return;
            }
            fileName = sfd.FileName;
            FileStream fs = null;
            try
            {
                fs = new FileStream(fileName, FileMode.Create);
                this.Strokes.Save(fs);
            }
            catch (Exception ex)
            {
                MessageBox.Show("保存失败：" + ex.StackTrace);
            }
            finally
            {
                if (fs != null) fs.Close();
            }
        }
    }
}