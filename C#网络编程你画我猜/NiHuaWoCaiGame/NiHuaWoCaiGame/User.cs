namespace NiHuaWoCaiGame
{
    public class User
    {
        public string UserName { get; set; }
        public string PassWord { get; set; }

        public readonly IGameServiceCallback callback;

        /// <summary>用户是否坐到某一桌的座位上</summary>
        public bool IsSitDown { get; set; }

        /// <summary>用户所坐的桌号(-1:大厅)</summary>
        public int Index { get; set; }

        /// <summary>用户所坐的座位号</summary>
        public int Side { get; set; }

        /// <summary>是否已经开始游戏</summary>
        public bool IsStarted { get; set; }

        public int Id { get; set; }

        public int score { get; set; }

        public User(string userName, string password , int id , IGameServiceCallback callback)
        {
            this.UserName = userName;
            this.PassWord = password;
            this.callback = callback;
            this.Id = id;
            this.score = 0;
        }
    }
}