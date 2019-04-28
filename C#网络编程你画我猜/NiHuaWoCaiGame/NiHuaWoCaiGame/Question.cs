using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NiHuaWoCaiGame
{
    class Question
    {
        public static string presentQuestion = "__";
        public static string[] question = { "房子", "树", "猴子","钢笔" };
        public static string getquestion()
        {
            string str = "";
            int num = question.Length;
            Random r = new Random();
            int x = r.Next(0, num );
            str = question[x];
            presentQuestion = str;
            return str;
        }
    }
}
