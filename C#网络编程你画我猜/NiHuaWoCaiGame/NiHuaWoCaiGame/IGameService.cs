using System;
using System.Collections.Generic;
using System.Linq;
using System.Media;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;

namespace NiHuaWoCaiGame
{
        //需要服务端实现的协定
        [ServiceContract(Namespace = "GameExample",
            
          CallbackContract = typeof(IGameServiceCallback))]
        public interface IGameService
        {
            [OperationContract(IsOneWay = true)]
            void Login(string userName , string passWord , int id);

            [OperationContract(IsOneWay = true)]
            void Logout(string userName);

            [OperationContract(IsOneWay = true)]
            void SitDown(string userName, int index, int side);

            [OperationContract(IsOneWay = true)]
            void GetUp(int index, int side);

            [OperationContract(IsOneWay = true)]
            void Start(string userName, int index, int side);

            [OperationContract(IsOneWay = true)]
            void Talk(int index, string userName, string message);

            [OperationContract(IsOneWay = true)]
            void sendPoints(List<int[]> points, string color);
            [OperationContract(IsOneWay = true)]
            void sendButtonInfo(string color);

            [OperationContract(IsOneWay = true)]
             void sendQuestion(int id , int presentId);

            [OperationContract(IsOneWay = true)]
            void changeQuestionRole(int nextId);

            [OperationContract(IsOneWay = true)]
             void Win();
            [OperationContract(IsOneWay = true)]
            void play();
            [OperationContract(IsOneWay = true)]
            void stop();
       
    }

        //需要客户端实现的接口
        public interface IGameServiceCallback
        {
            [OperationContract(IsOneWay = true)]
            void ShowLogin(string loginUserName, int id , int maxTables  );

            [OperationContract(IsOneWay = true)]
            void ShowLogout(string userName);

            [OperationContract(IsOneWay = true)]
            void ShowSitDown(string userName, int side);

            [OperationContract(IsOneWay = true)]
            void ShowGetUp(string userName, int side);

            [OperationContract(IsOneWay = true)]
            void ShowStart(int side);

            [OperationContract(IsOneWay = true)]
            void ShowTalk(string userName, string message);

            [OperationContract(IsOneWay = true)]
            void GameStart();

            [OperationContract(IsOneWay = true)]
            void ShowWin(string message);

            [OperationContract(IsOneWay = true)]
            void UpdateTablesInfo(string tablesInfo, int userCount);

            [OperationContract(IsOneWay = true)]
             void showSendPoints(List<int[]> points, string color);
            [OperationContract(IsOneWay = true)]
             void showSendButtonInfo(string color);

            [OperationContract(IsOneWay = true)]
             void showSendQuestion(string s);

             [OperationContract(IsOneWay = true)]
             void showChangeQuestionRole(string userName, int nextId);
             [OperationContract(IsOneWay = true)]
             void showPlay();
             [OperationContract(IsOneWay = true)]
             void showStop();
    }
}