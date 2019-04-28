using System;
using System.Collections.Generic;
using System.Linq;
using System.Media;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;

namespace NiHuaWoCaiGame
{
    // 注意: 使用“重构”菜单上的“重命名”命令，可以同时更改代码和配置文件中的类名“GameService”。
    public class GameService : IGameService
    {     
        public static string presentQuestion;
        public static int presentId = 1;
        public static string presentUser;
        int max = 0;
        int pscore = 0;
        public string winusername;
        public SoundPlayer sp = new SoundPlayer(@"G:\演示程序\try\NiHuaWoCaiGame\NiHuaWoCaiGame\Resources\play.wav");

        public GameService()
        {
            if (CC.Users == null)
            {
                CC.Users = new List<User>();
                CC.Rooms = new Room[CC.maxRooms];
                for (int i = 0; i < CC.maxRooms; i++)
                {
                    CC.Rooms[i] = new Room();
                }
            }
        }

        public void Login(string userName, string passWord , int id)
        {
            OperationContext context = OperationContext.Current;
            IGameServiceCallback callback = context.GetCallbackChannel<IGameServiceCallback>();
            User newUser = new User(userName, passWord, id , callback);
            CC.Users.Add(newUser);
            foreach (var user in CC.Users)
            {
                user.callback.ShowLogin(userName, id, CC.maxRooms);
            }
            SendRoomsInfoToAllUsers();
        }

        /// <summary>用户退出</summary>
        public void Logout(string userName)
        {
            User logoutUser = CC.GetUser(userName);
            foreach (var user in CC.Users)
            {
                //不需要发给退出用户
                if (user.UserName != logoutUser.UserName)
                {
                    user.callback.ShowLogout(userName);
                }
            }
            CC.Users.Remove(logoutUser);
            logoutUser = null; //将其设置为null后，WCF会自动关闭该客户端
            SendRoomsInfoToAllUsers();
        }

        /// <summary>用户入座,参数：用户名,桌号,座位号</summary>
        public void SitDown(string userName, int index, int side)
        {
            User p = CC.GetUser(userName);
            p.Index = index;
            p.Side = side;
            //if (p.Side == -1 && p.Index == -1) return;
            CC.Rooms[index].players[side] = p;
            //告诉入座玩家入座信息
            p.callback.ShowSitDown(userName, side);

            int twoSide = (side + 1) % 3;  //同一桌的另两个玩家
            int threeSide = (side + 2) % 3;

            User p1 = CC.Rooms[index].players[twoSide];
            User p2 = CC.Rooms[index].players[threeSide];

            if (p1 != null)
            {
                if (p2 != null)
                {
                    //告诉入座玩家另两个玩家是谁
                    p.callback.ShowSitDown(p1.UserName, twoSide);
                    p1.callback.ShowSitDown(p2.UserName, threeSide);
                    p.callback.ShowSitDown(p2.UserName, threeSide);
                    //告诉另两个玩家入座玩家是谁
                    p1.callback.ShowSitDown(p.UserName, side);
                    p2.callback.ShowSitDown(p.UserName, side);
                    p2.callback.ShowSitDown(p1.UserName, twoSide);
                }
            }
            //重新将游戏室各桌情况发送给所有用户
            SendRoomsInfoToAllUsers();
        }

        /// <summary>用户离开座位退出,参数：桌号,座位号,游戏是否已经开始</summary>
        public void GetUp(int index, int side)
        {
            User p0 = CC.Rooms[index].players[side];
            User p1 = CC.Rooms[index].players[(side + 1) % 3];
            User p2 = CC.Rooms[index].players[(side + 2) % 3];
            p0.callback.ShowGetUp(p0.UserName, side);
            CC.Rooms[index].players[side] = null; //注意该语句执行后p0!=null
            if (p1 != null)
            {
                if (p2 != null)
                {
                    p1.callback.ShowGetUp(p0.UserName, side);
                    p1.IsStarted = false;
                    p1.callback.ShowGetUp(p2.UserName, (side + 2) % 3);
                    p1.IsStarted = false;
                    p2.callback.ShowGetUp(p0.UserName, side);
                    p2.IsStarted = false;
                    p2.callback.ShowGetUp(p1.UserName, (side + 1) % 3);
                    p2.IsStarted = false;
                }

            }
            //重新将游戏室各桌情况发送给所有用户
            SendRoomsInfoToAllUsers();
        }

        /// <summary>该用户单击了开始按钮,参数：用户名,桌号,座位号</summary>
        public void Start(string userName, int index, int side)
        {
            User p0 = CC.Rooms[index].players[side];
            p0.IsStarted = true;
            //if (index == -1 && side == -1) return;
            p0.callback.ShowStart(side);
            int twoSide = (side + 1) % 3;
            int threeSide = (side + 2) % 3;//对方座位号
            User p1 = CC.Rooms[index].players[twoSide];
            User p2 = CC.Rooms[index].players[threeSide];
            if (p1 != null)
            {
                if (p2 != null)
                {
                    p1.callback.ShowStart(twoSide);
                    p2.callback.ShowStart(threeSide);
                    if (p1.IsStarted)
                    {
                        if (p2.IsStarted)
                        {
                            p0.callback.GameStart();
                            p1.callback.GameStart();
                            p2.callback.GameStart();
                        }
                    }
                }
            }
        }

        /// <summary>客户端发来的对话信息,参数：桌号,发送者用户名，对话内容</summary>
        public void Talk(int index, string userName, string message)
        {
            User p0 = CC.Rooms[index].players[0];
            User p1 = CC.Rooms[index].players[1];
            User p2 = CC.Rooms[index].players[2];
            if (message.Equals(presentQuestion))
            {
                foreach (var v in CC.Users)
                {
                    if (v.UserName.Equals(userName))
                    {
                        v.score += 10;
                        pscore = v.score;
                    }
                }
                if(p0 != null) p0.callback.ShowTalk("this time winner is", userName + "\n total score is:" + pscore);
                if (p1 != null) p1.callback.ShowTalk("this time winner is", userName + "\n total score is:" + pscore);
                if (p2 != null) p2.callback.ShowTalk("this time winner is", userName + "\n total score is:" + pscore);
                int x = ++presentId;
                if (x % 3 == 0) changeQuestionRole(3);
                else
                {
                     changeQuestionRole(x % 3);
                }
             //   if (x == 3)
            //    {
                    //flag = false;
                    
                    foreach (var user in CC.Users)
                    {
                        if (max < user.score)
                        {
                            max = user.score;
                            winusername = user.UserName;
                        }
                    }
                   // if (p0 != null) p0.callback.ShowWin("the last winner is:" + winer);
                   // if (p1 != null) p1.callback.ShowWin("the last winner is:" + winer);
                   // if (p2 != null) p2.callback.ShowWin("the last winner is:" + winer);
              //  }
            }
            if (p0 != null) p0.callback.ShowTalk(userName, message);
            if (p1 != null) p1.callback.ShowTalk(userName, message);
            if (p2 != null) p2.callback.ShowTalk(userName, message);
        }

        public void changeQuestionRole(int nextId)
        {
            foreach (var v in CC.Users)
            {
                v.callback.showChangeQuestionRole(presentUser, nextId);
            }
        }

        /// <summary>每座位用一位表示，0表示无人，1表示有人</summary>
        private string GetTablesInfo()
        {
            string str = "";
            for (int i = 0; i < CC.Rooms.Length; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    str += CC.Rooms[i].players[j] == null ? "0" : "1";
                }
            }
            return str;
        }

        /// <summary>将当前游戏室情况发送给所有用户</summary>
        private void SendRoomsInfoToAllUsers()
        {
            int userCount = CC.Users.Count;
            string roomInfo = this.GetTablesInfo();
            foreach (var user in CC.Users)
            {
                try
                {
                    user.callback.UpdateTablesInfo(roomInfo, userCount);
                }
                catch (Exception ex)
                { }
            }
        }

        public void sendPoints(List<int[]> points, string color)
        {
            foreach (var user in CC.Users)
            {
                user.callback.showSendPoints(points, color);
            }
        }
       
        public void sendButtonInfo(string color)
        {
            foreach (var user in CC.Users)
            {
                user.callback.showSendButtonInfo(color);
            }
        }

        public void sendQuestion(int id, int presentId)
        {
            foreach (var v in CC.Users)
            {
                if (v.Id == id && id == presentId)
                {
                    v.callback.showSendQuestion(Question.getquestion());
                    presentQuestion = Question.presentQuestion;
                    presentUser = v.UserName;
                    presentId = v.Id;
                }
            }
        }

        public void Win()
        {
            foreach (var v in CC.Users)
            {
                if (winusername != null)
                {
                    v.callback.ShowWin("the last winner is:" + winusername);
                    v.callback.ShowWin("游戏结束。");
                }
            }
        }   
        public void play()
        {
            sp.Load();
            sp.Play();
            
        }
        public void stop()
        {

            sp.Stop();   
            
        }
    }
}
