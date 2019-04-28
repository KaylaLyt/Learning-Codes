using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace NiHuaWoCaiGameClient
{
    /// <summary>
    /// StartWindow.xaml 的交互逻辑
    /// </summary>
    public partial class StartWindow : Window
    {
        public StartWindow()
        {
            InitializeComponent();
        }
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            start("User1", 0, 0);
            start("User2", 800, 0);
            start("User3", 300, 300);
        }

        private void start(string username,int left, int top)
        {
            MainWindow w = new MainWindow();
            w.textBoxUserName.Text = username;          
            w.Left = left;
            w.Top = top;
            w.Show();
            this.Close();
        }
    }
}
