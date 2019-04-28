using NiHuaWoCaiGameClient.GameServiceReference;
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
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.ComponentModel;
using System.ServiceModel;
using NiHuaWoCaiGameClient.MyInks;
using System.Windows.Controls.Ribbon;
using System.Media;

namespace NiHuaWoCaiGameClient
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window, IGameServiceCallback
    {
        //private bool final = false;
        private static int id = 1;
        //public int music = 0;
        // SoundPlayer sp = new SoundPlayer("play.wav");
        public string userName
        {
            get { return textBoxUserName.Text; }
            set { textBoxUserName.Text = value; }
        }
        public string PassWord
        {
            get { return passwordbox.Password; }
            set { passwordbox.Password = value; }
        }
        public int Id { set; get; }
        public int tableSide = -1;
        public int tableIndex = -1; ////房间中所坐的游戏桌号，-1表示未进入房间
        public Border[,] rooms;
        public bool isGameStart = false;

        public GameServiceClient client;
        public int maxTables;
        private string color;
        int i = 0;

        System.Windows.Threading.DispatcherTimer timer = new System.Windows.Threading.DispatcherTimer();

        public MainWindow()
        {
            InitializeComponent();
            this.Closing += MainWindow_Closing;
            ink1.MouseUp += ink1_MouseUp;
            ChangeSelect("红色");
            ChangeSelect("6");
            color = "红色";
            ChangeRoomsVisible(false);
            ChangeTableVisible(false);
            ChangeGameVisible(false);
            passwordbox.Password = "123456";
            timer.Tick += Timer_Tick;
            timer.Interval = TimeSpan.FromMilliseconds(1000);
            textBoxUserName.Text = this.userName;
            nosound.IsEnabled = true;
            sound.IsEnabled = false;
        }
        private delegate void UpdateProgressBarDelegate(System.Windows.DependencyProperty dp, Object value);
        private void beginImport()
        {
            progressbar.Maximum = 100;
            progressbar.Value = 0;

            UpdateProgressBarDelegate updatePbDelegate = new UpdateProgressBarDelegate(progressbar.SetValue);

            for (int i = 0; i < 100; i++)
            {
                Dispatcher.Invoke(updatePbDelegate, System.Windows.Threading.DispatcherPriority.Background, new object[] { System.Windows.Controls.ProgressBar.ValueProperty, Convert.ToDouble(i + 1) });
            }
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            if (progressbar.Value == progressbar.Maximum)
            {
                timer.Stop();
                ChangeGameVisible(false);
                client.Win();
                progressbar.Value = 0;
            }
            progressbar.Value += 2;
        }

        private void ChangeGameVisible(bool visible)
        {
            if (visible == false)
            {
                stackPanelRoomTip.Visibility = System.Windows.Visibility.Collapsed;
            }
            else
            {
                stackPanelRoomTip.Visibility = System.Windows.Visibility.Visible;
            }
        }

        private void ChangeTableVisible(bool visible)
        {
            if (visible == false)
            {
                GridTable.Visibility = System.Windows.Visibility.Collapsed;
            }
            else
            {
                GridTable.Visibility = System.Windows.Visibility.Visible;
            }
        }

        private void ink1_MouseUp(object sender, MouseButtonEventArgs e)
        {
            StylusPointCollection sPoints = ink1.Strokes[ink1.Strokes.Count - 1].StylusPoints;
            int[][] pointList = new int[sPoints.Count][];
            for (int i = 0; i < sPoints.Count; i++)
            {
                pointList[i] = new int[2];
                pointList[i][0] = (int)sPoints[i].ToPoint().X;
                pointList[i][1] = (int)sPoints[i].ToPoint().Y;
            }
            client.sendPoints(pointList, color);
        }

        public void ChangeRoomsVisible(bool visible)
        {
            if (visible == false)
            {
                gridRooms.Visibility = Visibility.Collapsed;
            }
            else
            {
                gridRooms.Visibility = Visibility.Visible;
            }
        }

        private void MainWindow_Closing(object sender, CancelEventArgs e)
        {
            ChangeState(btnLogin, true, btnLogout, false);
            if (client != null)
            {
                if (tableIndex != -1) //如果在房间内，要求先返回大厅
                {
                    MessageBox.Show("请先返回大厅，然后再退出");
                    e.Cancel = true;
                }
                else
                {
                    try
                    {
                        client.Logout(userName); //从大厅退出
                    }
                    catch (Exception ex)
                    { }
                }
            }
        }

        public void ChangeState(Button btnLogin, bool v1, Button btnLogout, bool v2)
        {
            btnLogin.IsEnabled = v1;
            btnLogout.IsEnabled = v2;
        }

        //在某个座位坐下时引发的事件
        public void RoomSide_MouseDown(object sender, MouseButtonEventArgs e)
        {
            btnLogout.IsEnabled = false;
            Border border = e.Source as Border;
            if (border != null)
            {
                string s = border.Tag.ToString();
                tableIndex = int.Parse(s[0].ToString());
                tableSide = int.Parse(s[1].ToString());
                client.SitDown(userName, tableIndex, tableSide);
            }

        }

        private void AddColorMessage(string str, SolidColorBrush color)
        {
            TextBlock t = new TextBlock();
            t.Text = str;
            t.Foreground = color;
            listBoxMessage.Items.Add(t);
        }

        public void AddMessage(string str)
        {
            TextBlock t = new TextBlock();
            t.Text = str;
            t.Foreground = Brushes.Blue;
            listBoxMessage.Items.Add(t);
        }

        public void RibbonRadioButton_Checked(object sender, RoutedEventArgs e)
        {
            RibbonRadioButton rrb = e.Source as RibbonRadioButton;
            string parent = (rrb.Parent as RibbonGroup).Header.ToString();
            if (parent == "笔尖颜色")
            {
                color = rrb.Label.ToString();
            }
            Assist.rrb = rrb;
            ButtonManage(rrb);
            client.sendButtonInfo(rrb.Label.ToString());
        }

        private void ButtonManage(RibbonRadioButton rrb)
        {
            string parent = (rrb.Parent as RibbonGroup).Header.ToString();
            if (parent == "笔尖颜色")
            {
                color = rrb.Label.ToString();
            }
            rrb.IsChecked = true;
            ChangeSelect(rrb.Label.ToString());
        }

        private void ChangeSelect(string selectedName)
        {
            ink1.SetInkAttributes(selectedName);
        }

        private void btnLogin_Click(object sender, RoutedEventArgs e)//单击登录按钮引发的事件
        {
            if (textBoxUserName.Text == null)
            {
                MessageBox.Show("请输入用户名！");
                     
            }
            else if (passwordbox.Password.ToString() != "123456")
            {
                MessageBox.Show("密码不正确！");
            }       
            else
            {
                this.Cursor = Cursors.Wait;
                userName = textBoxUserName.Text;
                InstanceContext context = new InstanceContext(this);
                client = new GameServiceReference.GameServiceClient(context);

                serviceTextBlock.Text = "服务端地址:" + client.Endpoint.ListenUri.ToString();
                try
                {
                    client.Login(textBoxUserName.Text, passwordbox.Password, id++);
                    ChangeState(btnLogin, false, btnLogout, true);
                    client.sendQuestion(id - 1, 1);
                    this.Id = id - 1;
                }
                catch (Exception ex)
                {

                    MessageBox.Show("与服务端连接失败：" + ex.Message);
                    return;
                }

                this.Cursor = Cursors.Arrow;
            }

        }
        private void btnLogout_Click(object sender, RoutedEventArgs e)//单击退出按钮引发的事件
        {
            //if(final)
            //{
            //    StartWindow t = new StartWindow();
            //    t.Show();
            //}                         
            this.Close();
        }
        private void btnStart_Click(object sender, RoutedEventArgs e)
        {
            client.Start(userName, tableIndex, tableSide);
            btnStart.IsEnabled = false;
        }

        private void btnExit_Click(object sender, RoutedEventArgs e)//返回大厅
        {
            client.GetUp(tableIndex, tableSide);
            //this.tableIndex = -1;
            //this.tableSide = -1;
            ChangeState(btnStart, true, btnLogout, true);
            //listBoxMessage.Items.Clear();
            //ChangeTableVisible(false);
            //ChangeGameVisible(true);
            //CreateTables();
            //final = !final;
        }

        private void textBoxTalk_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.Key == Key.Enter)
            {
                client.Talk(tableIndex, userName, textBoxTalk.Text);
                textBoxTalk.Text = "";
            }
        }

        private void btnSend_Click(object sender, RoutedEventArgs e)
        {
            client.Talk(tableIndex, userName, textBoxTalk.Text);
            textBoxTalk.Text = "";
        }

        #region  创建游戏桌
        public void CreateTables()
        {
            this.rooms = new Border[maxTables, 3];
            //创建游戏大厅中的房间（每房间一个游戏桌）
            for (int i = 0; i < maxTables; i++)
            {
                int j = i + 1;


                StackPanel sp = new StackPanel()
                {
                    Orientation = Orientation.Horizontal,
                    Margin = new Thickness(5)
                };
                TextBlock text = new TextBlock()
                {
                    Text = "房间" + (i + 1),
                    VerticalAlignment = System.Windows.VerticalAlignment.Center,
                    Width = 40
                };
                rooms[i, 0] = new Border()
                {
                    Tag = i + "0",
                    Background = Brushes.White,
                    Child = new Image()
                    {
                        Source = ((Image)this.Resources["player"]).Source,
                        Height = 25
                    }
                };
                Image image = new Image()
                {
                    Source = ((Image)this.Resources["table"]).Source,
                    Height = 25
                };

                StackPanel sp1 = new StackPanel()
                {
                    Orientation = Orientation.Vertical,
                    Margin = new Thickness(5)
                };
                rooms[i, 2] = new Border()
                {
                    Tag = i + "2",
                    Background = Brushes.White,
                    Child = new Image()
                    {
                        Source = ((Image)this.Resources["player"]).Source,
                        Height = 25
                    },
                    Margin = new Thickness(65, -11, 0, 0)
                };

                rooms[i, 1] = new Border()
                {
                    Tag = i + "1",
                    Background = Brushes.White,
                    Child = new Image()
                    {
                        Source = ((Image)this.Resources["player"]).Source,
                        Height = 25
                    }
                };
                rooms[i, 0].MouseDown += RoomSide_MouseDown;
                rooms[i, 1].MouseDown += RoomSide_MouseDown;
                rooms[i, 2].MouseDown += RoomSide_MouseDown;
                sp.Children.Add(text);
                sp.Children.Add(rooms[i, 0]);
                sp1.Children.Add(rooms[i, 2]);
                sp.Children.Add(image);
                sp.Children.Add(rooms[i, 1]);
                listboxRoom.Items.Add(sp);
                listboxRoom.Items.Add(sp1);
            }
        }
        #endregion

        public void CreatPlayers(int i)
        {
            Random r = new Random();
            int player = r.Next(1, 3);
            string[] players = { "player1", "player2", "player3" };
            StackPanel sp = new StackPanel()
            {
                Orientation = Orientation.Horizontal,
                Margin = new Thickness(5)
            };
            TextBlock text = new TextBlock()
            {
                Text = "玩家" + (i + 1),
                VerticalAlignment = System.Windows.VerticalAlignment.Center,
                Width = 40
            };
            Image image1 = new Image()
            {
                Source = ((Image)this.Resources[players[player]]).Source,
                Height = 25
            };
            TextBlock textscore = new TextBlock()
            {
                VerticalAlignment = System.Windows.VerticalAlignment.Center,
                Width = 40
            };
            sp.Children.Add(text);
            sp.Children.Add(image1);
            listboxPlayer.Items.Add(sp);

        }

        /// <summary>有用户登录</summary>
        public void ShowLogin(string loginUserName, int id, int maxTables)
        {
            if (loginUserName == userName)
            {
                ChangeRoomsVisible(true);
                this.maxTables = maxTables;
                CreateTables();
            }
            AddMessage("id：" + id + loginUserName + "进入大厅。");
        }
        public void ShowLogout(string userName)
        {
            AddMessage(userName + "退出大厅。");
        }
        /// <summary>用户入座</summary>
        public void ShowSitDown(string userName, int side)
        {

            if (side == tableSide)
            {
                isGameStart = false;
                btnStart.IsEnabled = true;
                btnLogout.IsEnabled = false;
                listboxRoom.IsEnabled = false;
                textBlockRoomNumber.Text = "桌号：" + (tableIndex + 1);
                ChangeTableVisible(true);

            }
            if (side == 0)
            {
                AddMessage(string.Format("{0}在房间{1}入座。", userName, tableIndex + 1));
                CreatPlayers(i++);
            }
            else if (side == 1)
            {
                AddMessage(string.Format("{0}在房间{1}入座。", userName, tableIndex + 1));
                CreatPlayers(i++);
            }
            else
            {
                AddMessage(string.Format("{0}在房间{1}入座。", userName, tableIndex + 1));
                CreatPlayers(i++);
            }

        }

        public void ShowGetUp(string userName, int side)
        {

            if (side == tableSide)
            {
                timer.Stop();
                isGameStart = false;
                btnLogout.IsEnabled = true;
                ChangeRoomsVisible(true);//返回大厅后允许再坐到另一个位置
                AddMessage(this.userName + "返回大厅。");
                tableIndex = -1;
                tableSide = -1;
                ChangeGameVisible(false);
                ChangeTableVisible(false);
                listboxPlayer.Items.Clear();


            }
            else
            {
                if (isGameStart)
                {
                    AddMessage(userName + "逃回大厅，游戏终止。");
                    isGameStart = false;
                    btnStart.IsEnabled = true;
                    ChangeGameVisible(false);
                    ChangeRoomsVisible(true);//返回大厅后允许再坐到另一个位置
                }
                else
                {
                    AddMessage(userName + "返回大厅。");
                    ChangeRoomsVisible(true);//返回大厅后允许再坐到另一个位置
                }

            }
        }
        public void ShowStart(int side)
        {

        }

        public void ShowTalk(string userName, string message)
        {
            AddColorMessage(string.Format("{0}：{1}", userName, message), Brushes.Black);
        }

        public void GameStart()
        {
            this.isGameStart = true;
            AddMessage("游戏开始！");
            ChangeGameVisible(true);
            timer.Start();
        }

        public void ShowWin(string message)
        {
            AddColorMessage("\n" + message + "\n", Brushes.Red);
            btnStart.IsEnabled = true;
            this.isGameStart = false;

        }

        public void UpdateTablesInfo(string tablesInfo, int userCount)
        {
            textBlockMessage.Text = string.Format("在线人数：{0}", userCount);
            for (int i = 0; i < maxTables; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (tableIndex == -1)
                    {
                        if (tablesInfo[3 * i + j] == '0')
                        {
                            rooms[i, j].Child.Visibility = System.Windows.Visibility.Hidden;
                            rooms[i, j].Child.IsEnabled = true;
                        }
                        else
                        {
                            rooms[i, j].Child.Visibility = System.Windows.Visibility.Visible;
                            rooms[i, j].Child.IsEnabled = false;
                        }
                    }
                    else
                    {
                        rooms[i, j].Child.IsEnabled = false;
                        if (tablesInfo[3 * i + j] == '0')
                        {
                            rooms[i, j].Child.Visibility = System.Windows.Visibility.Hidden;
                        }
                        else rooms[i, j].Child.Visibility = System.Windows.Visibility.Visible;
                    }
                }
            }
        }

        public void showSendPoints(int[][] points, string color)
        {
            StylusPointCollection allPoint = new StylusPointCollection();
            for (int i = 0; i < points.GetLength(0); i++)
            {
                StylusPoint p = new StylusPoint(points[i][0], points[i][1]);
                allPoint.Add(p);
            }
            InkObjectStroke obj2 = null;
            InkObject obj1 = new InkCurve(ink1, true);
            obj2 = new InkCurveStroke(obj1, allPoint);
            ink1.Strokes.Add(obj2);
        }

        private void passwordbox_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.Key == Key.Enter)
            {
                if (textBoxUserName.Text == null)
                {
                    MessageBox.Show("请输入用户名！");

                    if (passwordbox.Password != "123456")
                    {
                        MessageBox.Show("密码不正确！");
                    }
                }
                else
                {
                    this.Cursor = Cursors.Wait;
                    userName = textBoxUserName.Text;
                    InstanceContext context = new InstanceContext(this);
                    client = new GameServiceReference.GameServiceClient(context);

                    serviceTextBlock.Text = "服务端地址:" + client.Endpoint.ListenUri.ToString();
                    try
                    {
                        client.Login(textBoxUserName.Text, passwordbox.Password, id);
                        ChangeState(btnLogin, false, btnLogout, true);
                    }
                    catch (Exception ex)
                    {

                        MessageBox.Show("与服务端连接失败：" + ex.Message);
                        return;
                    }

                    this.Cursor = Cursors.Arrow;
                }
            }
        }
        public void showSendQuestion(string s)
        {
            lb_QuestionAndRole.Content = "请画出：" + s;
        }

        public void showSendButtonInfo(string color)
        {
            ButtonManage(Assist.rrb);
        }

        public void showChangeQuestionRole(string userName, int nextId)
        {
            if (!userName.Equals(this.userName))
            {
                if (this.Id == nextId) client.sendQuestion(nextId, nextId);
            }
            else
            {
                lb_QuestionAndRole.Content = "";
            }
        }
        public void showPlay()
        {
           if(nosound.IsEnabled==false)
           {
               client.play();
           }
        }
        public void showStop()
        {
            if(sound.IsEnabled==false)
            {
                client.stop();
            }
        }

        private void help_MouseMove(object sender, MouseEventArgs e) //游戏帮助
        {
            string str = "\n本游戏每3个人一个房间。游戏规则：在规定时间里，服务器随机出题，只有一个人知道\n" +
                "另外两个人猜，不断循环，猜对者得分加10，猜错不得分。\n" + "时间到，游戏结束，得分最高者胜利。\n";
            MessageBox.Show(str, "帮助信息");
        }

        private void sound_Click(object sender, RoutedEventArgs e)//音乐停止
        {
            //sp.Stop();       
            nosound1.Visibility = System.Windows.Visibility.Collapsed;
            sound1.Visibility = System.Windows.Visibility.Visible;
            sound.IsEnabled = false;
            nosound.IsEnabled = true;
            showStop();
            //music = 2;
        }

        private void nosound_Click(object sender, RoutedEventArgs e)//音乐播放
        {
            //sp.Load();
            //sp.Play();
            nosound1.Visibility = System.Windows.Visibility.Visible;
            sound1.Visibility = System.Windows.Visibility.Collapsed;
            nosound.IsEnabled = false;
            sound.IsEnabled = true;
            showPlay();
            //music = 1;
        }
    }
}
