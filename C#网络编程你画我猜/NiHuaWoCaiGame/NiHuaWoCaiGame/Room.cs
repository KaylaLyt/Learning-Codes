using System;

namespace NiHuaWoCaiGame
{
    public class Room
    {
      
        /// <summary>保存同一房间的三个玩家</summary>
        public User[] players { get; set; }

        public System.Timers.Timer timer { get; set; }

        public Room()
        {
            players = new User[3];
        }    
    }
}